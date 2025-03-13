#include "Pratos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noP {
    Pratos item;
    struct noP *prox;
}NoP;

typedef struct noP* ListaP;

ListaP *criarP() {
    ListaP *l = (ListaP*)malloc(sizeof(ListaP));
    (*l) = NULL;
    return l;
}

int inserirPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 1;
    NoP *no = (NoP*)malloc(sizeof(NoP));
    no->item = it;
    no->prox = (*l);
    (*l) = no;
    return 0;
} //insercao no inicio

int removerPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 2;
    NoP *no = (*l);
    NoP *aux = NULL;
    while(no != NULL) {
        if(no->item.codigo != it.codigo) {
            aux = no;
            no = no->prox;
        } else {
            break;
        }
    }
    if (no == NULL) return 3;
    if (aux != NULL) {
        aux->prox = no->prox;
    } else {
        (*l) = no->prox;
    }
    free(no);
    return 0;
}

int alteraPrato(ListaP *l, Pratos it) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 2;
    NoP *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL) {
        if (no->item.codigo != it.codigo) {
            no = no->prox;
        } else {
            break;
        }
    }
    if (it.preco != 0) {
        no->item.preco = it.preco;
    }
    if (it.ingredientes[0] != '-') {
        strcpy(no->item.ingredientes, it.ingredientes);
    }
    if (it.nome[0] != '-') {
        strcpy(no->item.nome, it.nome);
    }
    return 0;
}
int buscaItemPrato(ListaP *l, int cod) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 2;
    NoP *no = (*l);
    while (no != NULL) {
        if (no->item.codigo != cod) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 3;
}

int buscaPrato(ListaP *l, int cod, Pratos *it) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 2;
    NoP *no = (*l);
    if (no == NULL) return 3;
    while (no != NULL) {
        if (no->item.codigo != cod) {
            no = no->prox;
        } else {
            break;
        }
    }
    *it = no->item;
    return 0;
}

int listaVaziaP(ListaP *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

void mostrarPratos(ListaP *l) {
    if (l != NULL) {
        NoP *no = (*l);
        while (no != NULL) {
            printf("\n");
            printf("\nPrato (%d)", no->item.codigo);
            printf("\nNome: %s", no->item.nome);
            printf("\nIngredientes: %s", no->item.ingredientes);
            printf("\nPreco: %.2f reais", no->item.preco);
            no = no->prox;
        }
    }
}

void mostrarPCliente(ListaP *l) {
    if (l != NULL) {
        NoP *no = (*l);
        while (no != NULL) {
            printf("\n");
            printf("\nPrato: %s", no->item.nome);
            printf("\nCodigo do pedido: %d", no->item.codigo);
            printf("\nPreco: %.2f reais", no->item.preco);
            printf("\nQuantidade: %d", no->item.quantidade);
            no = no->prox;
        }
    }
}

float carrinho(ListaP *l) {
    if (l == NULL) return 1;
    if (listaVaziaP(l) == 0) return 2;
    float total = 0;
    NoP *no = (*l);
    while(no != NULL) {
        total = total + (no->item.preco * no->item.quantidade);
        no = no->prox;
    }
    return total;
}

void retornarPrato(ListaP *l, Pratos *it) {
    *it = (*l)->item;
}