#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

typedef struct no{
    Numeros item;
    struct no *prox;
}No;

typedef struct no* Lista;

Lista *criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    (*l) = NULL;
    return l;
}

int inserirInicio(Lista *l, Numeros it) {
    if (l == NULL) return 2;
    No *no = (No*)malloc(sizeof(No));
    no->item = it;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerItem(Lista *l, int it) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *ant;
    No *no = (*l);
    while (no != NULL && no->item.n1 != it) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) return 3;
    if (no == (*l)) {
        (*l) = no->prox;
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 0;
}

int buscaElemento(Lista *l, int it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = (*l);
    if (no->item.n1 == it) {
        return 0; //item encontrado
    } else {
        return buscaElemento(&(no->prox), it);
    }
}

int tamanho (Lista *l) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 0;
    return 1+tamanho(&(*l)->prox);
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

void mostrar(Lista *l) {
    if (l != NULL) {
        if (listaVazia(l) != 0) {
            No *no = (*l);
            mostrar(&(no->prox));
            printf(" %d ", no->item.n1);
        }
    }
}

int UltimoElem(Lista *l, int *saida) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *n = (*l);
    if (n->prox == NULL) {
        *saida = n->item.n1;
        return 0;
    }
    return UltimoElem(&(n->prox), saida);
}

void Reverso(Lista *l) {
    if (l != NULL) {
        if (listaVazia(l) != 0) {
            No *no = (*l);
            printf(" %d ", no->item.n1);
            Reverso(&(no->prox));
        }
    }
}

int Soma(Lista *l) {
    if (listaVazia(l) == 0) return 0;
    No *no = (*l);
    return no->item.n1+Soma(&(no->prox));
}

int RemocaoTodos(Lista *l, int it) {
    if (*l == NULL) return 1;
    No *no = *l;
    if (no == NULL) {
        return 0;
    } else if (no->item.n1 == it) {
        *l = no->prox;
        free(no);
        return RemocaoTodos(l, it);
    } else {
        return RemocaoTodos(&(no->prox), it);
    }
}


void limpar (Lista *l) {
    if (l != NULL) {
        No *atual = (*l);
        while (atual != NULL) {
            No *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}