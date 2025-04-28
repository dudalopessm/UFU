/*
Questão 2
Escreva um programa em Prolog que:
- Leia um arquivo chamado dados.txt contendo números (um número por linha).
- Copie apenas os números pares para um arquivo chamado pares.txt.
- E copie apenas os números ímpares para um arquivo chamado impares.txt.

Importante: você não pode usar mod/2 diretamente no read, tem que ler a linha, converter para número se necessário e depois testar.
*/

/* O que fazer?:
    1. abrir e fechar os arquivos: dados, pares, impares -> dados só para leitura, pares e impares só para escrita
    2. separar os números em ímpares ou pares
    3. se for impar: escrever no impares. se for par: escrever no par. 
*/

inicio :- % abertura e fechamento de arquivos, guarda conteúdo deles em uma variável
    open('2dados.txt', read, D),
    open('2pares.txt', write, P),
    open('2impares.txt', write, I),
    processa(D, P, I),
    close(D),
    close(P),
    close(I).

processa(D, P, I) :- at_end_of_stream(D), !. % quando chega ao fim do arquivo para de processar
processa(D, P, I) :- 
    read(D, Nro), % lê o que está na linha do arquivo
    (
        Nro mod 2 =:= 0 -> % se nro mod 2 = 0 então escreve no P. se não, escreve no I. -> é if-then-else em prolog
        write(P, Nro), nl(P) ;
        write(I, Nro), nl(I) 
        ),
    processa(D, P, I). % chamada recursiva até o fim do arquivo