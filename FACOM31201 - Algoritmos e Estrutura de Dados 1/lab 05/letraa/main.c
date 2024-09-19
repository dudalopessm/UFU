#include <stdio.h>
#include "Lista.h"
#include <stdlib.h>
//PARTICIPANTES: Eduarda Lopes, Fernando Favaro e Andreas de Castro
//MATRICULAS: 12311BCC033, 12311BCC006, 12311BCC067

int main () {
    printf("\n\n######## Lista de alunos ########");
    Lista *li;
    li = criar();
    Aluno a1 = {1, "Mariazinha", 80};
    Aluno a2 = {2, "Fernando", 50};
    Aluno a3 = {3, "Eduarda", 90};
    Aluno a4 = {4, "Gustavo", 100};
    Aluno a5 = {5, "Bibi", 60};
    int in1, in2, in3, in4, in5;
    in1 = inserirInicio(li, a1);
    in2 = inserirFim(li, a2);
    in5 = inserirFim(li, a3);
    in3 = inserirFim(li, a5);
    in4 = inserirPosicao(li, a4, 1); 
    printf("\n\nA lista encontra-se na configuracao: ");
    mostrar(li);
    int tam;
    tam = tamanho(li);
    printf("\n\nO tamanho da lista corresponde a: %d.", tam);
    int b1, b2, b3, b4;
    Aluno a6, a7;
    b1 = buscarItemChave(li, 3, &a6);
    b2 = buscarPosicao(li, 4, &a7);
    printf("\n\nFoi possivel localizar os alunos: %d e %d.", b1, b2);
    int r1, r2, r3, r4;
    r1 = removerInicio(li);
    r2 = removerFim(li);
    r3 = removerItem(li, a3.mat);
    r4 = removerPosicao(li, 4);
    printf("\n\nAgora, a lista encontra-se na configuracao: ");
    mostrar(li);
    liberar(li);
    printf("\n\n######## Obrigada por usar ########");
    printf("\n\n");
    system("pause");
    return 0;
}