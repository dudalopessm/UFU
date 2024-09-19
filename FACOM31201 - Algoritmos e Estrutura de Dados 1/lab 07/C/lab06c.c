#include <stdio.h>
#include "lab06c.h"
#include <stdlib.h>


typedef struct no {
    Aluno valor;
    struct no *prox;
}No;

typedef struct lista {
    No *inicio;
}ListaCircular;

Lista *criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return 1;
}

void Limpar(Lista *l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho(Lista *l) {
    if (l == NULL) return -1;
    if (listaVazia(l) == 0) return 0;
    No *noLista = l->inicio;
    int cont = 0;
    do {
        cont++;
        noLista = noLista->prox;
    }while (noLista != l->inicio);
    return cont;
}

void mostrar(Lista *l) {
    if (l != NULL) {
        printf("[");
        if (listaVazia(l) != 0) {
            No *noLista = l->inicio;
            do {
                printf(" {%d, ", noLista->valor.mat);
                printf("%s, ", noLista->valor.nome);
                printf("%.2f} ", noLista->valor.n1);
                noLista = noLista->prox;
            } while (noLista != l->inicio);
        }
        printf ("]\n");
    }
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL) return 0;
    else return 1;
}

int listaCheia(Lista *l) {
    return 1;
}

int iserirInicio(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0) {
        l->inicio = no;
        no->prox = no;
    }else {
        No *temp = l->inicio;
        while (temp->prox != l->inicio)
            temp = temp->prox;
        temp->prox = no;
        no->prox = l->inicio;
        l->inicio = no;
    }
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No * )malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0) {
        l->inicio = no;
        no->prox = no;
    }else {
        No *temp = l->inicio;
        while (temp->prox != l->inicio)
            temp = temp->prox;
        temp->prox = no;
        no->prox = l->inicio;
    }
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return 0;
    }
    No *no = l->inicio;
    while (no->prox != l->inicio)
        no = no->prox;
    No *temp = l->inicio;
    no->prox = temp->prox;
    l->inicio = temp->prox;
    free(temp);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return 0;
    }
    No *anterior = NULL, *no = l->inicio;
    while (no->prox != l->inicio) {
        anterior = no;
        no = no->prox;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int removerItem(Lista *l, int mat) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *anterior = NULL, *no = l->inicio;
    if((no->valor).mat == mat){
        removerInicio(l);
    }
    while (no != l->inicio && (no->valor).mat != mat){
        anterior = no;
        no = no->prox;
    }
    if (no == l->inicio) return 0;
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int buscarItem(Lista *l, int chave, Aluno *it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    while ((no->prox != l->inicio && (no->valor).mat != chave))
        no = no->prox;
    if ((no->valor).mat != chave) return 1;
    else {
        *it = no->valor;
        return 0;
    }
}