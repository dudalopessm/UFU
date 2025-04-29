% Carrega os modulos a serem usados no site
:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_files)).
:- use_module(library(http/http_parameters)).
:- use_module(library(http/html_write)).

% Carrega a base de dados de pedidos
:- ensure_loaded('kb.pl').

% Configura os handlers
:- http_handler(root(.), http_reply_from_files('.', []), [prefix]).
:- http_handler('/opcao_01', executar_opcao_01, [method(post)]).
:- http_handler('/opcao_02', executar_opcao_02, [method(post)]).
:- http_handler('/opcao_03', executar_opcao_03, [method(post)]).
:- http_handler('/opcao_04', executar_opcao_04, [method(post)]).
:- http_handler(root('style.css'), http_reply_file('style.css', []), []).

% Inicia o servidor
server(Port) :-
    http_server(http_dispatch, [port(Port)]).

% Resposta HTML pos forms
resposta_html(Titulo, Mensagem) :-
    reply_html_page(
        [ title(Titulo),
          link([rel('stylesheet'), type('text/css'), href('/style.css')], [])
        ],
        [ h1('Gerenciador de Telefones'),
          div([class(container)], [
              div([id(resposta)], [
                  h2(Mensagem),
                  br([]),
                  a([href('/'), class('btn-voltar')], 'Voltar')
              ])
          ])
        ]
    ).

salvar_telefones :-
    tell('kb.pl'),
    listing(telefone_de/2),
    told.

verificar_telefone(Telefone, Telefone_integer) :-
    % Verifico se é atom(de acordo com a implementacao de ler_string é)
    atom(Telefone),
    atom_chars(Telefone, Chars),

    % Para cada um dos caracteres em Chars execute is_digit
    maplist(is_digit, Chars),

    % Condicao de ter EXATOS 8 numeros
    length(Chars, 8),
    atom_number(Telefone, Telefone_integer),
    between(10000000, 99999999, Telefone_integer).

is_digit(Char) :-
    char_type(Char, digit).

formatar_mensagem(Mensagem, Args, MensagemFormatada) :-
    format(atom(MensagemAtom), Mensagem, Args),
    atom_string(MensagemAtom, MensagemFormatada).

% Obter o número de telefone do assinante apartir do seu nome
executar_opcao_01(Request) :- 
    !,
    http_parameters(Request,
        [ nome(NomeAtom, [atom])
        ]),
    downcase_atom(NomeAtom, Nome),
    (   
        
        telefone_de(Nome, Telefone) 
        -> 
            formatar_mensagem('Telefone de ~w: ~w', [Nome, Telefone], MensagemFormatada),
            resposta_html('Consulta realizada', MensagemFormatada)
        ;
        formatar_mensagem('Telefone de ~w nao existe na base de dados.', [Nome], MensagemFormatada),
        resposta_html('Erro', MensagemFormatada)
    ).

% Cadastrar um novo assinante valido no sistema
executar_opcao_02(Request) :-
    http_parameters(Request,
        [ nome(NomeAtom, [atom]),
        telefone(Telefone, [atom])
        ]),
        downcase_atom(NomeAtom, Nome),
    (   
        verificar_telefone(Telefone, TelefoneInteger) ->
        (   
            telefone_de(Nome, _) ->
            formatar_mensagem('Erro: O nome ~w ja existe na base!', [Nome], MensagemFormatada),
            resposta_html('Erro', MensagemFormatada)
        ;   
            telefone_de(_, TelefoneInteger) ->
            resposta_html('Erro', 'Erro: Este telefone ja esta cadastrado para outro assinante!')
        ;   
            assertz(telefone_de(Nome, TelefoneInteger)),
            salvar_telefones,
            formatar_mensagem('Assinante ~w com telefone ~d adicionado com sucesso.', [Nome, TelefoneInteger], MensagemFormatada),
            resposta_html('Cadastro', MensagemFormatada)
        )
    ;   
    resposta_html('Erro', 'Erro: Telefone deve conter exatamente 8 degitos numericos!')
    ).

% Atualizar um novo assinante apartir do seu numero de telefone
executar_opcao_03(Request) :-
    http_parameters(Request,
        [ nome(NomeAtom, [atom]),
        telefone(NovoTelefone, [atom])
        ]),
        downcase_atom(NomeAtom, Nome),
    (   
        telefone_de(Nome, _) 
        -> 
        (   
            verificar_telefone(NovoTelefone, Telefone_integer) -> 
                (
                    telefone_de(_, Telefone_integer) ->resposta_html('Erro', 'Erro: Este telefone ja esta cadastrado para outro assinante!')
                    ;
                    retract(telefone_de(Nome, _)),
                    assertz(telefone_de(Nome, Telefone_integer)),
                    salvar_telefones,
                    resposta_html('Atualizacao', 'Telefone atualizado com sucesso!')
                )
                
            ;
            resposta_html('Erro', 'Erro: Telefone deve conter exatamente 8 digitos numericos!')
        )
        
    ;   
        formatar_mensagem('Assinante ~w nao encontrado!', [Nome], MensagemFormatada),
        resposta_html('Erro', MensagemFormatada)
    ).

% Remover assinante do sistema
executar_opcao_04(Request) :-
    http_parameters(Request,
        [ nome(NomeAtom, [atom])
        ]),
        downcase_atom(NomeAtom, Nome),
    (   
        retractall(telefone_de(Nome, _)) ->
        salvar_telefones,
        formatar_mensagem('Assinante ~w removido com sucesso!', [Nome], MensagemFormatada),
        resposta_html('Atualizacao', MensagemFormatada)
    ;   
        formatar_mensagem('Assinante ~w nao encontrado!', [Nome], MensagemFormatada),
        resposta_html('Erro', MensagemFormatada)
    ).

% Inicia o servidor
:- initialization(server(8000)).
:- at_halt(http_stop_server(8000, [])).