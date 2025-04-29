/* Questão 1
Implemente um programa em Prolog que:
- Leia todas as linhas de um arquivo entrada.txt.
- Para cada linha, conte quantas letras vogais (a, e, i, o, u) existem.
- Escreva no arquivo saida.txt uma linha para cada linha lida, com o seguinte formato:

Original: <linha> - Vogais: <quantidade> */

/* Devo:
    1. abrir os arquivos - saida para escrita e write para leitura
    2. ler linha por linha tratando a linha como string e não como variável
    3. contar as vogais
    4. escrever na saída
    5. fechar os arquivos no final

    Assim, vou abrir os arquivos usando o predicado open/3 e read_line_to_string/2 para ler linha por linha.
Para cada linha conta-se o número de vogais e escreve-se no arquivo de saída, até encontrar o fim do arquivo.
No final, fecha-se ambos os arquivos.
*/

inicio :- % abre e fecha arquivos com o predicado open/3 e guarda o conteudo em uma variavel
% -> open(arquivo, modo, variavel)
    open('1entrada.txt', read, Entrada),
    open('1saida.txt', write, Saida),
    processa(Entrada, Saida),
    close(Entrada),
    close(Saida).

% lógica principal aqui
processa(Entrada, Saida) :- at_end_of_stream(Entrada), !. % se não há mais arquivo na entrada, a leitura para
processa(Entrada, Saida) :- 
    read_line_to_string(Entrada, Linha), % lê a linha como string, evita implementação complexa de lista
    contaVogais(Linha, Quantidade), 
    write(Saida, 'Original: '),
    write(Saida, Linha),
    write(Saida, ' - Vogais: '),
    write(Saida, Quantidade),
    nl(Saida),
    processa(Entrada, Saida). % recursiva até o fim do arquivo

contaVogais(Linha, Quantidade) :-  
    string_chars(Linha, ListaChars), % transforma string completa (Linha) para lista de caracteres (ListaChars)
    contaListaVogais(ListaChars, Quantidade). % chama a contagem de vogais, que conta por elemento da lista

contaListaVogais([], 0). % não há nenhuma vogal em uma lista vazia
contaListaVogais([H|T], Quantidade) :-
    ehVogal(H), % cabeça é vogal? se sim então:
    contaListaVogais(T, Resto), % cauda recursiva
    Quantidade is Resto + 1. % determinação do resultado
contaListaVogais([_|T], Quantidade) :- % chamada recursiva para a cauda
    contaListaVogais(T, Quantidade).

ehVogal(Char) :-
    member(Char, [a, e, i, o, u, 'A', 'E', 'I', 'O', 'U']). % caractere é membro de uma lista de caracteres só vogais