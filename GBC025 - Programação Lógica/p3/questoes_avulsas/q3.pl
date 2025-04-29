/*
Questão 3
Faça um programa que:
- Leia o arquivo texto.txt.
- Conte o número total de linhas que não estão vazias.
- Escreva apenas o número total no arquivo contagem.txt.
*/

/* O que fazer?
    1. abrir arquivo texto.txt e contagem.txt e fechá-los depois;
    2. interpretar linha como string.
    3. verificar se a linha é vazia ou não, se não for incrementa a contagem e se não, passa pra próxima.
*/

inicio :- % abre e fecha arquivos
    open('3texto.txt', read, T),
    open('3contagem.txt', write, C),
    processa(T, 0, Total), % começa em zero a contagem
    write(C, Total), % escreve só quando terminar toda a contagem
    close(T),
    close(C).

processa(T, ContAtual, ContFinal) :- at_end_of_stream(T), !, ContAtual = ContFinal. % se chegou até o fim, permanece a contagem feita
processa(T, ContAtual, ContFinal) :-
    read_line_to_string(T, Linha), % lê a próxima linha do arquivo como uma string
    (
        Linha == "" ->               % se a linha for vazia
            Cont = ContAtual          % mantém o contador atual (não soma nada)
        ;                             % senão
            Cont is ContAtual + 1      % incrementa o contador em 1
    ),
    processa(T, Cont, ContFinal). % chama recursivamente passando a nova contagem intermediária