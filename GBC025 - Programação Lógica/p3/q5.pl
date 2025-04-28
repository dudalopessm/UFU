/* Questão 5
- Leia todas as linhas de um arquivo entrada.txt.
- Cada linha representa uma lista de números separados por vírgula (ex: 1,2,3,4,5).
- Para cada lista:
  - Remova os números ímpares.
  - Escreva a nova lista (só com números pares) no arquivo pares.txt.
*/

/* O que fazer?
    1. abrir e fechar arquivos entrada.txt (leitura) e pares.txt (escrita)
    2. ler cada linha como ?
    3. checar paridade -> se for par vai pra pares.txt
*/

inicio :- % abertura e fechamento de arquivos
    open('5entrada.txt', read, Entrada),
    open('5pares.txt', write, Saida),
    processa(Entrada, Saida),
    close(Entrada),
    close(Saida).

processa(Entrada, _) :- at_end_of_stream(Entrada), !.
processa(Entrada, Saida) :-
    /* se NÃO tiver em formato prolog no txt:
    read_line_to_string(Entrada, Linha), % cada linha = string
    split_string(Linha, ",", "", ListaStr), % string dividida pela vírgula
    maplist(number_string, ListaNumeros, ListaStr), % converte strings para números
    */
    read(Entrada, ListaNumeros), % le uma lista
    checagemNumeros(ListaNumeros, ListaPares), % manda ela pra checar paridade e retorna uma lista contendo apenas os pares
    write(Saida, ListaPares), % escreve lista de pares no arquivo 
    nl(Saida),
    processa(Entrada, Saida).

checagemNumeros([], []).
checagemNumeros([H | T], [H | Resto]) :-
    H mod 2 =:= 0,
    !, % corte para se a cabeça for par, não executar a proxima linha
    checagemNumeros(T, Resto).
checagemNumeros([_| T], Resto) :- checagemNumeros(T, Resto).