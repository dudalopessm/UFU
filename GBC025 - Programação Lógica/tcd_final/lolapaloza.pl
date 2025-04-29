:- use_module(library(readutil)).

% Carregar base de dados
:- ensure_loaded('kb.pl').

ler_opcao :-
    format('~nOPCAO: '), flush_output,
    get_char(Char),
    skip_line,
    char_code(Char, Code),
    (   
        Code =:= 53 -> 
        writeln('Saindo do sistema...'), 
        !,
        halt
    ;   
        between(49, 52, Code) ->  % Códigos ASCII de '1' a '4' (5 foi lido em cima)
        Opcao is Code - 48,
        executar_opcao(Opcao),
        fail
    ;   
        writeln('Opcao invalida! Digite apenas numeros de 1 a 5.'),
        continuar,
        fail
    ).

ler_string(Atom) :-
    ler_string_lista(ListaChars),
    atom_chars(Atom, ListaChars).

ler_string_lista(ListaChars) :-
    get_char(Char),
    (   Char = '\n' -> ListaChars = []
    ;   ler_string_lista(RestoChars),
        ListaChars = [Char | RestoChars]
    ).

salvar_telefones :-
    tell('kb.pl'),
    listing(telefone_de/2),  % Agora são 6 argumentos (sem ID e sem status)
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

continuar :-
    format('~nDigite qualquer coisa para continuar..~n'),
    flush_output,
    get_char(_).

executar_opcao(1) :- 
    !,
    writeln('== Obter telefone =='),
    write('Digite o nome do assinante: '),
    flush_output,
    ler_string(Nome),
    (
        telefone_de(Nome, Telefone) -> format('Telefone de ~w: ~w~n', [Nome, Telefone])
        ;
        format('Telefone de ~w nao existe na base de dados.~n', [Nome])
    ),
    continuar.

executar_opcao(2) :-
    writeln('== Novo assinante =='),
    write('Nome: '), flush_output, ler_string(Nome),
    write('Telefone: '), flush_output, ler_string(TelefoneStr),

    (   
        verificar_telefone(TelefoneStr, TelefoneInteger) ->
        (   
            telefone_de(Nome, _) ->
            format('Erro: O nome ~w ja existe na base!~n', [Nome])
        ;   
            telefone_de(_, TelefoneInteger) ->
            writeln('Erro: Este telefone ja esta cadastrado para outro assinante!')
        ;   
            assertz(telefone_de(Nome, TelefoneInteger)),
            salvar_telefones,
            format('Assinante ~w com telefone ~d adicionado com sucesso.~n', [Nome, TelefoneInteger])
        )
    ;   
    writeln('Erro: Telefone deve conter exatamente 8 degitos numericos!')
    ),
    continuar.

executar_opcao(3) :-
    writeln('== Modificar telefone =='),
    write('Nome do assinante: '), flush_output, ler_string(Nome),
    (   
        telefone_de(Nome, _) 
        -> 
        flush_output,
        write('Novo telefone: '), 
        flush_output, 
        ler_string(NovoTelefone),
        (   
            verificar_telefone(NovoTelefone, Telefone_integer) -> 
                (
                    telefone_de(_, Telefone_integer) ->writeln('Erro: Este telefone ja esta cadastrado para outro assinante!')
                    ;
                    retract(telefone_de(Nome, _)),
                    assertz(telefone_de(Nome, Telefone_integer)),
                    salvar_telefones,
                    writeln('Telefone atualizado com sucesso!')
                )
                
            ;
            writeln('Erro: Telefone deve conter exatamente 8 digitos numericos!')
        )
        
    ;   
        format('Assinante ~w nao encontrado!~n', [Nome])
    ),
    continuar.

executar_opcao(4) :-
    writeln('== Remover assinante =='),
    write('Nome do assinante: '), flush_output, ler_string(Nome),

    (   
        retractall(telefone_de(Nome, _)) ->
        salvar_telefones,
        format('Assinante ~w removido com sucesso!~n', [Nome])
    ;   
        format('Assinante ~w nao encontrado!~n', [Nome])
    ),
    continuar.

menu :-
    repeat,
    nl,
    format('Ola seja bem vindo(a) ao sistema de telefone Lolapaloza ~n'),
    format('~nEscolha uma das opcoes abaixo:~n~n'),

    format('1 - Obter o telefone de um assinante~n'),
    format('2 - Novo assinante~n'),
    format('3 - Modificar telefone~n'),
    format('4 - Remover assinante~n'),
    format('5 - Fim~n'),
    flush_output,
    
    ler_opcao.

?- menu.