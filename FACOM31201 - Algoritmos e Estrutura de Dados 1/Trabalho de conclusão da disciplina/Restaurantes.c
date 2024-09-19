#include "Restaurantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noR {
    Restaurante item;
    struct noR *prox;
}NoR;

typedef struct listaR {
    NoR *inicio;
    int codrest;
    int codprato;
}ListaR;

ListaR *criarRest() {
    ListaR *l = (ListaR*)malloc(sizeof(ListaR));
    l->inicio = NULL;
    l->codrest = 1;
    l->codprato = 1;
    return l;
}

int inserirRest(ListaR *l, Restaurante rest) {
    if (l == NULL) return 2;
    NoR *no = (NoR*)malloc(sizeof(NoR));
    no->item = rest;
    no->item.cardapio = criarP();
    no->item.pedidos = criarFilaPed();
    no->item.identificacao = l->codrest; //primeiro restaurante é o 1 e os seguintes sao os proximos
    l->codrest++; //incrementa o codigo para que o prox restaurante tenha id diferente
    no->prox = l->inicio;
    l->inicio = no;
    return 0;
}

int removerRest(ListaR *l, Restaurante rest) {
    if (l == NULL) return 1;
    if (listaVaziaR(l) == 0) return 2;
    NoR *no = l->inicio;
    NoR *aux = NULL;
    while(no != NULL) {
        if(strcmp(no->item.CNPJ, rest.CNPJ) != 0) {
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
        l->inicio = no->prox;
    }
    free(no);
    return 0;
}

int geracaoCod(ListaR *l) {
    int codigo;
    if (l == NULL) return 1;
    codigo = l->codprato;
    (l->codprato)++;
    return codigo;
}

int buscaEmailRest(ListaR *l, char *em) {
    if (l == NULL) return 1;
    if (listaVaziaR(l) == 0) return 2;
    NoR *no = l->inicio;
    while (no != NULL) {
        if (strcmp(no->item.email, em) != 0) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 3;
}

int buscaItemRest(ListaR *l, char *it) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 3;
    NoR *no = l->inicio;
    while (no != NULL) {
        if (strcmp(no->item.CNPJ, it) != 0) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int buscaRest(ListaR *l, char *aux, Restaurante *rest) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *no = l->inicio;
    if (no == NULL) return 3;
    while (no != NULL) {
        if (strcmp(no->item.email, aux) != 0) {
            no = no->prox;
        } else {
            break;
        }
    }
    *rest = no->item;
    return 0;
}

int achaRest(ListaR *l, int id, Restaurante *rest) {
    if (l == NULL) return 2;
    if (listaVaziaR(l) == 0) return 1;
    NoR *no = l->inicio;
    if (no == NULL) return 3;
    while (no != NULL) {
        if (no->item.identificacao != id) {
            no = no->prox;
        } else {
            break;
        }
    }
    *rest = no->item;
    return 0;
}

int achaRestId(ListaR *l, int id) {
    if (l == NULL) return 1;
    if (listaVaziaR(l) == 0) return 2;
    NoR *no = l->inicio;
    if (no == NULL) return 4;
    while (no != NULL) {
        if (no->item.identificacao != id) {
            no = no->prox;
        } else {
            return 0;
        }
    }
    return 3;
}

int acharPrato(ListaR *l, int cod, Restaurante *rest) {
    if (l == NULL) return 1;
    if(listaVaziaR(l) == 0) return 2;
    NoR *no = l->inicio;
    while (no != NULL) {
        if (buscaItemPrato(no->item.cardapio, cod) != 0) {
            no = no->prox;
        } else {
            break;
        }
    }
    *rest = no->item;
    return 0;
}

int listaVaziaR(ListaR *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL) return 0;
    return 1;
}

void mostrarR(ListaR *l, char *cat) {
    if (l != NULL) {
        NoR *no = l->inicio;
        if (strcmp(cat, "Nao listado") == 0) {
            while (no != NULL) {
                printf("\n- %d. %s", no->item.identificacao, no->item.nomeRest);
                no = no->prox;
            }
        } else {
            while (no != NULL) {
                if (strcmp(no->item.categoria, cat) == 0) {
                    printf("\n- %d. %s - %s", no->item.identificacao, no->item.nomeRest, no->item.categoria);
                }
                no = no->prox;
            }
        }
    }
}

void mostrarPratosRest(ListaR *l) {
    if (l != NULL) {
        NoR *no = l->inicio;
        while (no != NULL) {
            mostrarPratos(no->item.cardapio);
            no = no->prox;
        }
    }
}
