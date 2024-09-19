#include <stdio.h>
#include "Lista.h"
#include <stdlib.h>
//PARTICIPANTES: Eduarda Lopes, Fernando Favaro e Andreas de Castro
//MATRICULAS: 12311BCC033, 12311BCC006, 12311BCC067

int main () {
    printf("\n\n######## Lista de alunos ########");
    Lista *li1, *li2;

    //criacao lista 1
    li1 = criar();
    Aluno a1 = {1, "Mariazinha", 80};
    Aluno a2 = {2, "Fernando", 50};
    Aluno a3 = {3, "Eduarda", 90};
    Aluno a4 = {4, "Gustavo", 100};
    Aluno a5 = {5, "Bibi", 60};
    int in1, in2, in3, in4, in5, in6;
    in1 = inserirInicio(li1, a1);
    in2 = inserirFim(li1, a2);
    in5 = inserirFim(li1, a3);
    in3 = inserirInicio(li1, a5);
    in4 = inserirPosicao(li1, a4, 7);
    in6 = inserirFim(li1, a5); 
    printf("\n\nA lista encontra-se na configuracao: ");
    mostrar(li1);

    //criacao lista 2
    li2 = criar();
    Aluno a6 = {6, "Vanessao", 40};
    Aluno a7 = {7, "Laura", 90};
    Aluno a8 = {8, "Giovana", 70};
    Aluno a9 = {9, "Helme", 20};
    Aluno a10 = {10, "Andreas", 60};
    int in7, in8, in9, in10, in11, in12;
    in7 = inserirInicio(li2, a6);
    in8 = inserirFim(li2, a7);
    in9 = inserirFim(li2, a8);
    in10 = inserirInicio(li2, a10);
    in11 = inserirPosicao(li2, a9, 7);
    in12 = inserirPosicao(li2, a10, 2); 
    printf("\n\nA lista encontra-se na configuracao: ");
    mostrar(li2);

    //buscas
    int b1, b2, b3, b4;
    Aluno a11, a12, a13, a14;
    b1 = buscarItemChave(li1, 3, &a11);
    b2 = buscarPosicao(li2, 4, &a12);
    b3 = buscarItemChave(li2, 10, &a13);
    b4 = buscarPosicao(li1, 2, &a14);
    printf("\n\nFoi possivel localizar os alunos: %d e %d.", b1, b2);

    //deve conter 
    int c1;
    c1 = ContemItem(li1, a2);
    if (c1 == 0) {
        printf("\n\nA lista contem o aluno Fernando.");
    } else if (c1 == 1) {
        printf("\n\nA lista nao contem o aluno Fernando.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }
    int c3;
    c3 = ContemItem(li2, a7);
    if (c3 == 0) {
        printf("\n\nA lista contem a aluna Laura.");
    } else if (c3 == 1) {
        printf("\n\nA lista nao contem a aluna Laura.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }

    //concatenacao
    Lista *li3;
    li3 = concatena(li1, li2);
    printf("\n\nA concatenacao da lista 1 e da lista 2 corresponde a: ");
    mostrar(li3);

    //tamanhos
    int tam1, tam2, tam3;
    tam1 = tamanho(li1);
    tam2 = tamanho(li2);
    tam3 = tamanho(li3);
    printf("\n\nO tamanho da lista 1 eh %d.", tam1);
    printf("\n\nO tamanho da lista 2 eh %d.", tam2);
    printf("\n\nO tamanho da lista 3 eh %d.", tam3);

    //remocoes
    int r1, r2, r3, r4, r5, r6, r7, r8;
    r1 = removerInicio(li1);
    r2 = removerFim(li1);
    r3 = removerItem(li1, a3.mat);
    r4 = removerPosicao(li1, 4);
    r5 = removerInicio(li2);
    r6 = removerFim(li2);
    r7 = removerItem(li2, a8.mat);
    r8 = removerPosicao(li2, 1);
    printf("\n\nAgora, a lista 1 encontra-se na configuracao: ");
    mostrar(li1);
    printf("\n\nAgora, a lista 2 encontra-se na configuracao: ");
    mostrar(li2);

    //nao deve conter
    int c2;
    c2 = ContemItem(li1, a3);
    if (c2 == 0) {
        printf("\n\nA lista contem a aluna Eduarda.");
    } else if (c2 == 1) {
        printf("\n\nA lista nao contem a aluna Eduarda.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }
    int c4;
    c4 = ContemItem(li2, a10);
    if (c4 == 0) {
        printf("\n\nA lista contem o aluno Andreas.");
    } else if (c4 == 1) {
        printf("\n\nA lista nao contem o aluno Andreas.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }

    //liberacao memoria
    liberar(li1);
    liberar(li2);

    printf("\n\n######## Obrigada por usar ########");
    printf("\n\n");
    system("pause");
    return 0;
}