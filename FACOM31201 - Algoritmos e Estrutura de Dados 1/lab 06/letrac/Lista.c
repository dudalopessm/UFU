#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no { //a struct nó é o item da lista que contem duas partes: o valor (aluno) e o ponteiro para o proximo (*prox)
    Aluno valor;
    struct no *prox;
}No;

typedef struct lista { //a lista contem APENAS a struct nó, que no caso define onde é o início da lista 
    No *inicio;
}Lista;

Lista *criar () {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL; //a lista está vazia
    return l;
}

Lista *concatena (Lista *l1, Lista *l2) {
//a ideia aqui é criar outra lista que o primeiro elemento aponte para o primeiro elemento de l1 e o ultimo elemento aponte para o primeiro elemento de l2
if (l1 == NULL || l2 == NULL) return NULL; //se uma das listas nao foi criada
    Lista *l3 = criar(); 
    if (listaVazia(l1) == 0) return l2;
    if (listaVazia(l2) == 0) return l1; 
    No *no1 = l1->inicio; //o item1 aponta para o primeiro item da l1
    No *no2 = l2->inicio; //o item2 aponta para o primeiro item da l2
    while (no1 != NULL) { 
        inserirInicio(l3, no1->valor); 
        no1 = no1->prox; //passa para o proximo elemento da primeira lista
    }
    while (no2 != NULL) { 
        inserirInicio(l3, no2->valor); 
        no2 = no2->prox; //passa para o proximo elemento da segunda lista
    }
    return l3; 
}

void limpar (Lista *l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
}

int inserirInicio (Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No*)malloc(sizeof(No)); //aloca memoria para o item que eu quero colocar que no caso é o item no
    no->valor = it; //aluno a ser inserido
    no->prox = l->inicio; //endereço do proximo elemento recebe o NULL (l->inicio)
    l->inicio = no; //o NULL recebe o item inteiro, ou seja, o inicio da lista passa a ser o item no
    return 0;
}

int inserirFim (Lista *l, Aluno it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return inserirInicio(l, it); //se a lista estiver vazia, o ultimo elemento na verdade será o primeiro
    No *noLista = l->inicio; //item auxiliar criado para achar o fim da lista, recebe o primeiro elemento
    while (noLista->prox != NULL) {
        noLista = noLista->prox; //enquanto nao acho o fim da lista, o item inteiro recebe o endereço do próximo, ou seja, pulo para o próximo
    }
    No *no = (No*)malloc(sizeof(No)); //aloco a memoria do item que irei inserir
    no->valor = it; //o aluno do item que vou inserir recebe o aluno passado
    no->prox = noLista->prox; //o endereço do próximo item do item que vou inserir passa a ser o endereço do ultimo elemento achado no while
    noLista->prox = no; //o fim da lista passa a ser o item inteiro a ser inserido
    return 0;
}

int inserirPosicao (Lista *l, Aluno it, int pos) {
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if (listaVazia(l) == 0 || (pos == 0)) //se a lista for vazia ou a posicao for a primeira
        return inserirInicio(l, it); //insere o elemento no inicio
    No *noLista = l->inicio; //item que vou usar para varrer a lista recebe o primeiro item
    int p = 1;
    while ((noLista->prox != NULL) && (p != pos)) { //varre a lista desde o primeiro item ate o contador chegar a posicao
        p++; //se nao chega, p é incrementado
        noLista = noLista->prox; //se nao chega, o item que uso para varrer recebe o endereço do proximo item a ele, ou seja, passo para o próximo
    }
    No *no = (No*)malloc(sizeof(No)); //aloco memoria para o item que quero inserir
    no->valor = it; //aluno do item a ser inserido passa a ser o que foi passado
    no->prox = noLista->prox; //o endereço do proximo item ao que eu to inserindo passa a ser o que esta na posicao que quero
    noLista->prox = no; //o endereço do item que esta na posicao que eu quero passa a ser o item inteiro que eu vou inserir
    return 0;
}

int removerInicio (Lista *l) {
    if (l ==NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int removerFim (Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista->prox != NULL) {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int removerPosicao (Lista *l, int pos) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (pos < 0) return 3;
    int p = 0;
    No *noAuxiliar = NULL; //é o que eu vou varrer a lista
    No *noLista = l->inicio; //é o que eu vou apagar
    while((noLista->prox != NULL) && (p != pos)) {
        noAuxiliar = noLista; //o auxiliar recebe o item inteiro que eu quero apagar]
        noLista = noLista->prox;
        p++; //p é incrementado
    }
    if (noAuxiliar == NULL) { //significa que a lista nao tem mais de 1 elemento
        return removerInicio(l);
        } else {
            noAuxiliar->prox = noLista->prox; //o item anterior ao que quero apagar recebe o endereço do proximo item ao que eu quero apagar 
        }
        free(noLista); //apaga o item
        return 0;
}

int removerItem (Lista *l, int mat) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *noLista = l->inicio; //elemento que eu quero remover recebe o primeiro elemento da lista
    int p = 0;
    while (noLista != NULL) {
        if ((noLista->valor).mat == mat) {
            removerPosicao(l, p);
        } else {
            p++; //contador incrementado
        }
        noLista = noLista->prox; //pula para o proximo elemento
    }
    return 0;
}

int buscarItemChave (Lista *l, int chave, Aluno *retorno) {
    if (l == NULL) return 2;
    No *noLista = l->inicio;
    while (noLista != NULL) {
        if ((noLista->valor).mat == chave) {
            *retorno = noLista->valor;
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

int buscarPosicao (Lista *l, int posicao, Aluno *retorno) {
    if (l == NULL) return -1; //lista nao existe
    int p = 0;
    No *noLista = l->inicio; //elemento que eu quero achar
    while ((noLista != NULL) && (p != posicao)) {
        p++;
        noLista = noLista->prox; //o item avaliado recebe o endereço do proximo item, ou seja, passo p o prox
    }
    if (p == posicao) {
        *retorno = noLista->valor; //o aluno retornado recebe o aluno do item achado
        return 0; 
    } else {
        return -1;
    }
}

int ContemItem (Lista *l, Aluno it) {
    if (l == NULL) return 2; //lista nao existe
    if (listaVazia(l) == 0) return 1; //lista nao contem nenhum item
    No *no = l->inicio; //o item que quero achar recebe o endereço do primeiro elemento
    while ((no != NULL)) {
        if (no->valor.mat == it.mat) {
            return 0; //aluno foi achado
        }
        no = no->prox; //o item inteiro recebe o endereço do proximo item, ou seja, pulo de item
    }
    return 1; //aluno nao foi achado
}

void mostrar (Lista *l) {
    if (l != NULL) {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL) {
            printf(" {%d, ", noLista->valor.mat);
            printf("%s, ", noLista->valor.nome);
            printf("%.2f} ", noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf ("]\n");
    }
}

int listaVazia (Lista *l) {
    if (l == NULL)
        return 2; //se a lista nao foi criada
    if (l->inicio == NULL)
        return 0; //o primeiro elemento da lista é NULL, ou seja, ela está vazia
    return 1;
}

int tamanho (Lista *l) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 0;
    int p = 0;
    No *no = l->inicio;
    while (no != NULL) {
        p++;
        no = no->prox;
    }
    return p;
}

int maiornota(Lista *l, Aluno *retorno) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *no = l->inicio; //o item recebe o inicio da lista l
    int nota = 0;
    while ((no != NULL)) { //enquanto nao chega ate o fim da lista
    if (no->valor.n1 > nota) {
        nota = no->valor.n1;
        *retorno = no->valor;
    }
    no = no->prox; //o item recebe o endereço do proximo item, ou seja, pulo de item
    }
    return nota;
}


void liberar(Lista *l) {
    if (l != NULL) {
        No *atual = l->inicio;
        while (atual != NULL) {
            No *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(l);
    }
}
