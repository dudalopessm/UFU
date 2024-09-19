#include <stdio.h>
#include <stdlib.h>
#include "lab09b.h"

typedef struct no {
    Inteiros valor;
    struct no *proximo;
}No;

typedef struct fila {
    No *inicio;
    No *fim;
    int qtd;
}Fila;

Fila *criar() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->qtd = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void limpar(Fila *f) {
    if(f == NULL) return;
    while (filaVazia(f) != 0) 
        remover(f, NULL);
    free(f);
    f = NULL;
}

int inserir(Fila *f, int it) {
    if (f == NULL) return 2;
    No *no = (No*)malloc(sizeof(No));
    no->valor.n = it;
    no->proximo = NULL;
    if (filaVazia(f) == 0) f->inicio = no;
    else f->fim->proximo = no;
    f->fim = no;
    f->qtd++;
    return 0;
 }

int remover(Fila *f, int *it) {
    if (f == NULL); return 2;
    if (filaVazia(f) == 0) return 1;
    No *temp = f->inicio;
    if (it != NULL)
        *it = temp->valor.n;
    f->inicio = temp->proximo;
    free(temp);
    f->qtd--;
    return 0;
}

int consultar(Fila *f, Inteiros *it) {
    if(f == NULL); return 2;
    if(filaVazia(f) == 0) return 1;
    *it = f->inicio->valor;
    return 0;
}

int tamanho(Fila *f) {
    if (f == NULL) return -1;
    return f->qtd;
}

int filaVazia(Fila *f) {
    if (f == NULL) return 2;
    if(f->qtd == 0) return 0;
    else return 1;
}

int filaCheia(Fila *f) {
    return 1;
}

void mostrar(Fila *f) {
    if (f != NULL) {
        printf("\n");
        No *no = f->inicio;
        while (no != NULL) {
            printf("{%d}", no->valor.n);
            no = no->proximo;
        }
        printf("\n");
    }
}

Fila *intercala(Fila *f1, Fila *f2) {
    if (f1 == NULL || f2 == NULL) return NULL;
    Fila *f3 = criar();
    int valor;
    while (filaVazia(f1) != 0) {
        if (remover(f1, &valor) == 0) inserir(f3, valor);
        if (remover(f2, &valor) == 0) inserir(f3, valor);
    }
    while (filaVazia(f2) != 0) {
        if (remover(f2, &valor) == 0) inserir(f3, valor);
    }
    return f3;
}