#include "Avaliacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct noF {
    Feedback item;
    Cliente user;
    Restaurante alvo;
    struct noF *prox;
}NoF;

typedef struct noF* ListaF;

ListaF *criarF() {
    ListaF *l = (ListaF*)malloc(sizeof(ListaF));
    (*l) = NULL;
    return l;
}

int listaVaziaF(ListaF *l) {
    if (l == NULL) return 2;
    if ((*l) == NULL) return 0;
    return 1;
}

int inserirFeed(ListaF *l, Cliente cli, Restaurante rest, Feedback it) {
    if (l == NULL) return 2;
    NoF *no = (NoF*)malloc(sizeof(NoF));
    if (no == NULL) return 1;
    no->user = cli;
    no->alvo = rest;
    no->item = it;
    if (no->item.pedentregues == NULL) no->item.pedentregues = criarP(); //verificar se ta criando a lista se tiver dando erro
    no->prox = (*l);
    (*l) = no;
    return 0;
}

void mostrarFeedRest(ListaF *l, int id) {
    if (l != NULL) {
        NoF *noLista = (*l);
        while (noLista != NULL) {
            if (noLista->alvo.identificacao == id) {
                printf("\nUsuario: %s", noLista->user.nome);
                printf("\nEstrelas: %s", noLista->item.estrelas);
                printf("\nAvaliacao: %s", noLista->item.avaliacao);
                printf("\n");
                noLista = noLista->prox;
            } else {
                noLista = noLista->prox;
            }
        }
    }
}

void mostrarFeedCli(ListaF *l, char *cliente) {
    if (l != NULL) {
        NoF *noLista = (*l);
        while (noLista != NULL) {
            if (strcmp(noLista->user.email, cliente) == 0) {
                printf("\nRestaurante: %s", noLista->alvo.nomeRest);
                printf("\nEstrelas: %s", noLista->item.estrelas);
                printf("\nAvaliacao: %s", noLista->item.avaliacao);
                printf("\n");
                noLista = noLista->prox;
            } else {
                noLista = noLista->prox;
            }
        }
        printf("\n");
    }
}