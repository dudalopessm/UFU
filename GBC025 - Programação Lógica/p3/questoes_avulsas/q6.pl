/* Questão 6
- Leia o arquivo entrada.txt, onde cada linha é uma palavra (ex: banana, casa, prolog).
- Agrupe todas as palavras lidas numa lista.
- Ordene essa lista em ordem decrescente de tamanho da palavra.
- Escreva cada palavra na ordem certa em ordenado.txt.
*/ 

inicio :- 
    open('6entrada.txt', read, Entrada),
    open('6ordenado.txt', write, Saida),
    ler(Entrada, Lista), % unifica todas as palavras em uma unica lista
    ordenar(Lista, ListaOrd), % ordena a lista
    escrever(Saida, ListaOrd), % escreve elementos da lista ordenada no arq de saída
    close(Entrada),
    close(Saida).

ler(Entrada, []) :- at_end_of_stream(Entrada), !.
ler(Entrada, [H | T]) :-
    read_line_to_string(Entrada, H), % na cabeça cada linha = string
    ler(Entrada, T). % recursivo na cauda da lista até acabar

ordenar(Lista, ListaOrd) :- predsort(comparar, Lista, ListaOrd).

comparar(O, P1, P2) :-
    string_length(P1, L1),
    string_length(P2, L2),
    (L1 > L2 -> O = '<' ; O = '>').

escrever(_, []) :- !.   
escrever(Saida, [H | T]) :-
    write(Saida,  H),
    nl(Saida),
    escrever(Saida, T).