/* Questão 4 
Implemente em Prolog:
- Abra um arquivo entrada.txt.
- Leia cada linha.
- Inverta a ordem dos caracteres de cada linha (por exemplo, amor vira roma).
- Grave tudo no arquivo invertido.txt.
*/

/* O que fazer?
    1. abrir e fechar arquivos
    2. interpretar cada linha como string e cada string como lista de caracteres
    3. inverter a lista 
    4. escrever cada linha invertida no arquivo
*/

inicio :-  % abertura e fechamento de arquivos
    open('1entrada.txt', read, Entrada),
    open('4invertido.txt', write, Saida),
    processa(Entrada, Saida),
    close(Entrada),
    close(Saida).

processa(Entrada, _) :- at_end_of_stream(Entrada), !. % se termina o arquivo então termina o processamento
processa(Entrada, Saida) :-
    read_line_to_string(Entrada, Linha), % cada linha = uma string
    string_chars(Linha, Lista), % cada string = uma lista de caracteres
    inverter(Lista, ListaInvertida), % ou reverse(Lista, ListaInvertida), reverse ja inverte todos os elementos de uma lista
    string_chars(LinhaInvertida, ListaInvertida), % lista de caracteres --> string
    write(Saida, LinhaInvertida),
    nl(Saida),
    processa(Entrada, Saida).

inverter([], []).
inverter([H|T], Invertida) :-
    inverter(T, Temp), % recursivo pra cauda
    append(Temp, [H], Invertida). % adiciona elemento na ultima posição com append 