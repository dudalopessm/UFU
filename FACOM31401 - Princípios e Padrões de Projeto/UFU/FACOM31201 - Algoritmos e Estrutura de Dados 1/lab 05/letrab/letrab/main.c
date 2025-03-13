#include <stdio.h>
#include "Lista.h"
#include <stdlib.h>
//PARTICIPANTES: Eduarda Lopes, Fernando Favaro e Andreas de Castro
//MATRICULAS: 12311BCC033, 12311BCC006, 12311BCC067

int main () {
    printf("\n\n######## Lista de alunos ########");
    Lista *li;

    //criacao lista
    li = criar();
    Aluno a1 = {1, "Mariazinha", 80};
    Aluno a2 = {2, "Fernando", 50};
    Aluno a3 = {3, "Eduarda", 90};
    Aluno a4 = {4, "Gustavo", 100};
    Aluno a5 = {5, "Bibi", 60};
    int in1, in2, in3, in4, in5, in6;
    in1 = inserirInicio(li, a1);
    in2 = inserirFim(li, a2);
    in5 = inserirFim(li, a3);
    in3 = inserirFim(li, a5);
    in4 = inserirPosicao(li, a4, 7);
    in6 = inserirFim(li, a5); 
    printf("\n\nA lista encontra-se na configuracao: ");
    mostrar(li);

    //mostra tamanho lista
    int tam;
    tam = tamanho(li);
    printf("\n\nO tamanho da lista corresponde a: %d.", tam);

    //buscas
    int b1, b2, b3, b4;
    Aluno a6, a7;
    b1 = buscarItemChave(li, 3, &a6);
    b2 = buscarPosicao(li, 4, &a7);
    printf("\n\nFoi possivel localizar os alunos: %d e %d.", b1, b2);

    //deve conter
    int c1;
    c1 = ContemItem(li, a2);
    if (c1 == 0) {
        printf("\n\nA lista contem o aluno Fernando.");
    } else if (c1 == 1) {
        printf("\n\nA lista nao contem o aluno Fernando.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }

    //contagem de itens
    int c3;
    c3 = ContaItem(li, a5);
    printf("\n\nA lista contem a aluna Bibi %d vezes.", c3);

    //lista reversa
    Lista *rev;
    rev = criar();
    rev = Reversa(li, rev);
    printf("\n\nA lista na ordem reversa corresponde a: ");
    mostrar(rev);

    //remocoes
    int r1, r2, r3, r4;
    r1 = removerInicio(li);
    r2 = removerFim(li);
    r3 = removerItem(li, a3.mat);
    r4 = removerPosicao(li, 4);
    printf("\n\nAgora, a lista encontra-se na configuracao: ");
    mostrar(li);

    //nao deve conter
    int c2;
    c2 = ContemItem(li, a3);
    if (c2 == 0) {
        printf("\n\nA lista contem a aluna Eduarda.");
    } else if (c2 == 1) {
        printf("\n\nA lista nao contem a aluna Eduarda.");
    } else {
        printf("\n\nA funcao nao funcionou.");
    }

    //liberacao memoria
    liberar(li);
    liberar(rev);

    printf("\n\n######## Obrigada por usar ########");
    printf("\n\n");
    system("pause");
    return 0;
}