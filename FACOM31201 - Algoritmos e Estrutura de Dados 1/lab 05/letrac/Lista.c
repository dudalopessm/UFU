#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int total;
    int max;
    Aluno *valores;
}Lista;

Lista *criar(int max) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if (l != NULL) {
        l->total = 0;
        l->max = max;
        l->valores = (Aluno*)malloc(max*sizeof(Aluno));
    }
    return l;
}

Lista *Reversa(Lista *l, Lista *r) {
    if (r == NULL) return r;
    if (l == NULL) return l;
    if (listaVazia(l) == 0) return l;
    int i, j;
    j = 0;
    for (i = l->total - 1; i >= 0; i--) {
        inserirPosicao(r, l->valores[i], j);
        j++;
    }
    return r; 
}

void limpar(Lista *l) {
    if (l != NULL) l->total = 0;
}

int inserirInicio(Lista *l, Aluno it) {
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    for (i = l->total - 1; i >= 0; i--) {
        l->valores[i+1] = l->valores[i];
    } //posicao da frente recebe posicao anterior a ela
    l->valores[0] = it;
    l->total++;
    return 0;
}
int inserirFim(Lista *l, Aluno it) {
    int i;
    if (l == NULL) return 1;
    if (listaCheia(l) == 0) return 2;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}
int inserirPosicao(Lista *l, Aluno it, int pos) {
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    if ((pos < 0) || (pos > l->max)) return 3;
    if (pos >= l->total) {
        return inserirFim(l, it);
    }
    for (i = l->total; i > pos; i--) {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[pos] = it;
    l->total++;
    return 0;
}

int removerInicio (Lista *l) {
    int i;
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    for (i = 0; i < l->total - 1; i++) {
        l->valores[i] = l->valores[i+1];
    } //a posicao que esta atras recebe o valor da que esta na frente
    l->total--;
    return 0;
}
int removerFim (Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    l->total--;
    return 0;
}
int removerPosicao (Lista *l, int pos) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if ((pos < 0) || (pos >= l->max)) return 3;
    if (pos >= l->total) {
        return removerFim(l);
    }
    for (i = pos; i < l->total - 1; i++) {
        l->valores[i] = l->valores[i+1]; //se der errado essa funcao modifica i+1 por i-1
    }
    l->total--;
    return 0;
}
int removerItem (Lista *l, int mat) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    int i, k = 0;
    while (i < l->total && l->valores[i].mat != mat) {
        i++;
    }
    if (i == l->total) return 3; //elemento nao encontrado
    for (k = i; k < l->total - 1; k++) {
        l->valores[k] = l->valores[k+1];
    }
    l->total--;
    return 0;
}

int buscarItemChave(Lista *l, int chave, Aluno *retorno) {
    int i;
    if (l == NULL) return 1;
    if (listaCheia(l) == 0) return 2;
    for (i = 0; i < l->total; i++) {
        if (l->valores[i].mat == chave) {
            *retorno = l->valores[i];
            return 0;
        }
    }
    return 3;
}
int buscarPosicao(Lista *l, int posicao, Aluno *it) {
    if (l == NULL || posicao <= 0 || posicao > l->total) return 1;
    if (listaVazia(l) == 0) return 2;
    *it = l->valores[posicao-1];
    return 0;
}

int listaCheia (Lista *l) {
    if (l == NULL) return 2;
    if (l->total == l->max) return 0;
    else return 1;
}
int listaVazia(Lista *l) {
    if (l == NULL) return 1;
    if (l->total == 0) return 0;
    else return 1;
}

void mostrar(Lista *l) {
    int i;
    if (l != NULL) {
        printf("[");
        for (i = 0; i < l->total; i++) {
            printf(" {%d, ", l->valores[i].mat);
            printf("%s, ", l->valores[i].nome);
            printf("%.2f}", l->valores[i].n1);
        }
        printf("]\n");
    }
}

int tamanho(Lista *l) {
    if (l == NULL) return 1;
    return l->total;
}

void liberar(Lista *l) {
    free(l);
}

int ContemItem(Lista *l, Aluno it) {
    if (l == NULL) return 3;
    if (listaVazia(l) == 0) return 2;
    
    int i;
    for (i = 0; i < l->total; i++) {
        if (l->valores[i].mat == it.mat) {
            return 0; // item encontrado
        }
    }
    return 1; //item nao encontrado
}

int ContaItem(Lista *l, Aluno it) {
    if (l == NULL) return 1;
    if (listaVazia(l)) return 2;
    
    int i, contagem;
    contagem = 0;
    for (i = 0; i < l->total; i++) {
        if (l->valores[i].mat == it.mat) {
            contagem++;
        }
    }
    return contagem;
}
