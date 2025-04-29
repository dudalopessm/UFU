:- use_module(library(http/thread_httpd)). % servidor
:- use_module(library(http/http_dispatch)). % rotas
:- use_module(library(http/http_parameters)). % parâmetros requisição
:- use_module(library(http/html_write)). % resposta html

:- http_handler(root(.), http_reply_from_files('C:/Faculdade/Quarto_Periodo/PROLOG/prova', []), [prefix]). % rota default para arquivos
:- http_handler(root(calcula), calcular, []). % rota para cálculo fatorial

/*
Rotas definidas pelo http_handler.

Cada requisição ativa uma função (calcular).

A função processa os dados e responde com o resultado.
*/

servidor(Porta) :- http_server(http_dispatch, [port(Porta)]). % inicia servidor

calcular(Nro) :- 
    http_parameters(Nro, [nro(NA, [])]), % função http_parameters SEMPRE recebe uma variavel e uma lista como segundo parametro
                                         % pois requisições podem retornar vários valores de uma vez. por isso, nro é tratado como lista 
    atom_number(NA, N), % converte átomo 'NA' para número real N
    fatorial(N, Resultado), % calcula fatorial
    open('fatorial.txt', append, Saida), % modo append = conteudo adicionado no final do arquivo
    format(Saida, "~w~n", [Resultado]), %~w escreva próximo argumento como está;~n pule uma linha ao terminar
    close(Saida),
    mensagem(N, Resultado). % mensagem html

fatorial(0, 1).
fatorial(N, R) :- 
    N > 0,
    N1 is N - 1,
    fatorial(N1, R1),
    R is N * R1.

mensagem(N, Resultado) :-
    reply_html_page( % gera resposta html
                     % reply_html_page(Head, Body) com body sempre em uma lista []
        title('Resultado do Fatorial'), 
        [
            h2('Calculo feito:'),
            p([N, '!', ' = ', Resultado]),
            p(a([href='/site.html'], 'Voltar'))
        ]
    ).