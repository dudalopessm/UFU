/* Questão 7
- Leia um arquivo entrada.txt contendo frases.
- Para cada frase:
  - Inverta a ordem das palavras (não das letras!).
  - Escreva no arquivo invertido.txt.
*/

/*O que fazer?
    1. carregar arquivos 7entrada.txt(r) e 7invertido.txt(w)
    2. ler cada linha como string
    3. para cada linha: inverter ordem das palavras -> transformar a string em uma lista de strings?
    4. escrever resultado de cada linha invertida
    */
inicio :-
    open('7entrada.txt', read, E),
    open('7invertido.txt', write, S),
    processamento(E, S),
    close(E),
    close(S).
    
processamento(E, S) :-
    at_end_of_stream(E), !.
    
processamento(E, S) :-
    read_line_to_string(E, String),
    converteEmLista(String, ListaStrings),
    inverteLista(ListaStrings, ListaInvertida),
    escreveLista(S, ListaInvertida),
    nl(S),
    processamento(E, S).
    
converteEmLista(String, ListaStrings) :-
    split_string(String, " ", "", ListaStrings).
    
inverteLista([], []).
inverteLista([H|T], Invertida) :-
    inverteLista(T, Temp),
    append(Temp, [H], Invertida).

escreveLista(_, []) :- !.
escreveLista(S, [H]) :-
    write(S, H).
escreveLista(S, [H|T]) :-
    write(S, H),
    write(S, ' '),
    escreveLista(S, T).