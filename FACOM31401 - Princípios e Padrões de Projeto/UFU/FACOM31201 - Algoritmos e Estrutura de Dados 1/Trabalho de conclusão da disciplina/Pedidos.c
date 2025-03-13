#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct noPed {
    Cliente dados;
    Pratos pedido;
    struct noPed *prox;
}NoPed;

typedef struct fila{
    NoPed *inicio;
    NoPed *fim;
    int qtd;
}Fila;

Fila *criarFilaPed() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->qtd = 0;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int inserirPedido(Fila *f, Cliente cli, Pratos p) {
    if (f == NULL) return 2;
    NoPed *noPed = (NoPed*)malloc(sizeof(NoPed));
    noPed->dados = cli;
    noPed->pedido = p;
    noPed->prox = NULL;
    if (filaVazia(f) == 0) {
        f->inicio = noPed;
    } else {
        f->fim->prox = noPed;
    }
    f->fim = noPed;
    f->qtd++;
    return 0;
}

int removerPedido(Fila *f, Cliente *cli, Pratos *p) {
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    *cli = f->inicio->dados;
    *p = f->inicio->pedido;
    Fila *fila = f;
    if (fila->inicio == fila->fim) {
        fila->fim = NULL;
    }
    fila->inicio = fila->inicio->prox;
    f->qtd--;
    free(fila);
    return 0;
}

int tamanhoFila(Fila *f) {
    if (f == NULL) return 1;
    return f->qtd;
}

int filaVazia(Fila *f) {
    if (f == NULL) return 2;
    if (f->qtd == 0) return 0;
    else return 1;
}

void mostrarPedidos(Fila *f) {
    if (f != NULL) {
        int i = 1, q;
        Fila *itens = f;
        Cliente cliped;
        Pratos pratoped;
        q = tamanhoFila(itens);
        printf("\nPedidos: ");
        while (q > 0) {
            if (removerPedido(itens, &cliped, &pratoped) == 0) {
                printf("\n");
                printf("\n -------- Pedido %d --------", i);
                printf("\nPrato: %s", pratoped.nome);
                printf("\nIngredientes: %s", pratoped.ingredientes);
                printf("\nCliente: %s", cliped.nome);
                i++;
                q--;
                inserirPedido(itens, cliped, pratoped);
            }
        }
    }
}