:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_parameters)).
:- use_module(library(http/http_files)). 
:- use_module(library(uri)).
:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).
:- use_module(library(http/http_server_files)).

:- http_handler(root(.), http_reply_from_files('C:/Faculdade/Quarto_Periodo/PROLOG/tcd', []), [prefix]).

:- multifile user:file_search_path/2.
user:file_search_path(css, 'css').
:- http_handler(css(.), serve_files_in_directory(css), [prefix]).

:- http_handler(root(processa_pedido), processar, []).
:- http_handler(root(cancelar_pedido), cancelar, []).

:- dynamic(nomeCliente/2). 
:- dynamic(telCliente/2). 
:- dynamic(pedido/7).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

processar(R) :-
    http_parameters(R, [
        nomeCliente(C, []),
        telCliente(T, []),
        emailCliente(E, []),
        tamanho(S, []),
        ing(Is, [list(multiple)]),
        tempo(H, []),
        obs(O, [])
    ]),
    catch(
        (
            open('pedidos.pl', append, Stream),
            writeq(Stream, pedido(C, T, E, S, Is, H, O)),
            write(Stream, '.'),
            nl(Stream),
            close(Stream),
            mensagem(C, T, E, S, Is, H, O)
        ),
        _Erro,
        erro_cadastro
    ).

erro_cadastro :-
    reply_html_page(
        title('Erro ao cadastrar pedido'),
        \html_requires(css('cadastro.css')),
        [
            \navbar,
            div([class('caixa-erro')], [
                h2('Erro ao cadastrar o pedido'),
                p('Ocorreu um problema ao salvar seu pedido. Tente novamente.')
            ])
        ]
    ).



ingredientes_lista([]) --> [].
ingredientes_lista([H|T]) -->
    html([H, br([])]),
    ingredientes_lista(T). 

navbar -->
        html(nav([], 
            ul([class(navbar)], [
                li([], a([href('/site.html')], 'Menu')),
                li([], a([href('/cadastro.html')], 'Novo Pedido')),
                li([], a([href('/cancelar.html')], 'Cancelar Pedido'))
            ])
        )).
    
mensagem(C,T,E,S,Is,H,O) :-  reply_html_page(
    title('Confirmação do pedido'),
    \html_requires(css('cadastro.css')),
    [
        \navbar,   
        div([class('caixa-confirmacao')], [
            h2('Pedido Confirmado'),
            p(['Nome: ', span([], C)]),
            p(['Telefone: ', span([], T)]),
            p(['Email: ', span([], E)]),
            p(['Tamanho da Pizza: ', span([], S)]),
            p(['Ingredientes: ']), \ingredientes_lista(Is),
            p(['Horario de Entrega: ', span([], H)]),
            p(['Observacoes: ', span([], O)])
        ])
    ]
).

cancelar(R) :- http_parameters(R,[
    nomeCliente(C,[]), 
    telCliente(T,[]) 
    ]),
    consult('pedidos.pl'),
    (   retract(pedido(C, T, _, _, _, _, _)) ->
        tell('pedidos.pl'),
        listing(pedido/7),
        told,
        cancelado(C, T);   
        erro_cancelamento(C, T)
    ).

    erro_cancelamento(C, T) :-
        reply_html_page(
            title('Erro ao cancelar pedido'),
            \html_requires(css('cadastro.css')),
            [
                \navbar,
                div([class('caixa-erro')], [
                    h2('Pedido nao encontrado'),
                    p(['Nao foi possivel encontrar um pedido com o nome ', span([], C),
                       ' e telefone ', span([], T), '.']),
                    p('Verifique os dados e tente novamente.')
                ])
            ]
        ).    

cancelado(C, T) :- reply_html_page(
    title('Cancelamento do pedido'),
    \html_requires(css('cadastro.css')),
    [
        \navbar,   
        div([class('caixa-confirmacao')], [
            h2('Pedido Cancelado'),
            p(strong(['Nome: ', span([], C)])),
            p(strong(['Telefone: ', span([], T)])),
            p('Volte sempre!')
        ])
    ]
).