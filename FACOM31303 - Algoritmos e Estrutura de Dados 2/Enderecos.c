#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enderecos.h"

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018

IMPLEMENTAÇÃO DE ÁRVORES UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> créditos ao professor André Backes
*/

typedef struct NO* ArvBin;
struct NO{
    Enderecos *info;
    struct NO *esq;
    struct NO *dir;
}NO;

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no) {
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    destroiEnd(no->info);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int altura_ArvBin(ArvBin* raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir) 
        return alt_esq + 1;
    else 
        return alt_dir + 1;
        
}

int totalNO_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_dir+alt_esq+1);
}

int insere_ArvBin(ArvBin* raiz, Enderecos *endereco){
    if (raiz == NULL) return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(NO));
    if(novo == NULL) return 0;
    novo->info = endereco;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL) *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while (atual != NULL) {	
        
            ant = atual;
            if(strcmp(endereco->cep, atual->info->cep) == 0){
                free(novo);
                return 0;
            }
            else if(strcmp(endereco->cep, atual->info->cep) > 0){
                atual = atual->dir;
            }
            else {
                atual = atual->esq;
            }
        }
        if(strcmp(endereco->cep, ant->info->cep) > 0){
            ant->dir = novo;
        }
        else {
            ant->esq = novo;
        }
        
        
    }
    return 1;   
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL)  {
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, Enderecos *valor) {
    if(raiz == NULL) 
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL) {
        if(strcmp(valor->cep, atual->info->cep)==0) {
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else {
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(strcmp(valor->cep, atual->info->cep)>0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

Enderecos *busca_ArvBin(ArvBin *raiz, char *cep){
    if(*raiz == NULL || raiz == NULL) return NULL;
    if(strcmp((*raiz)->info->cep, cep) == 0)
        return (*raiz)->info;
    else if (strcmp((*raiz)->info->cep, cep) < 0) 
        return busca_ArvBin(&((*raiz)->dir), cep);
    else 
        return busca_ArvBin(&((*raiz)->esq), cep);
    return NULL;
}

void preOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        mostrarUni((*raiz)->info); //endereços
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}
void emOrdem_ArvBin(ArvBin *raiz) {
    if (raiz == NULL)
        return;
    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));
        mostrarUni((*raiz)->info); //endereços
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
void posOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        mostrarUni((*raiz)->info); //endereços
    }
}

Enderecos *maior_ArvBin(ArvBin *raiz){
    if(raiz == NULL) 
        return NULL;
    if((*raiz)->dir == NULL) 
        return (*raiz)->info;
    return maior_ArvBin(&((*raiz)->dir));
}

Enderecos *menor_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return NULL;
    if((*raiz)->esq == NULL) return (*raiz)->info;
    return menor_ArvBin(&((*raiz)->esq));
}


Enderecos *criaEndereco(char *cep, char *siglaEstado, char *nomeCidade, char *endereco)
{
    Enderecos *end = malloc(sizeof(Enderecos));
    strcpy(end->cep, cep);
    strcpy(end->siglaEstado, siglaEstado);
    strcpy(end->nomeCidade, nomeCidade);
    strcpy(end->end, endereco);
    return end;
}

ArvBin *lerArquivoEnderecos(char *enderecoArquivo, int op) { 
    FILE *arq = fopen("database_Enderecos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    ArvBin *vet = cria_ArvBin(); //aaaaaaaaaa
    char cep[15], siglaEstado[12], nomeCidade[255], end[255];
    int ct = 0;
    if(op == 1){
    while (fscanf(arq, "%[^;]; %2[^;]; %[^;]; %[^\n]\n", cep, siglaEstado, nomeCidade, end) != EOF && ct < 20)
    {
        printf("%d\n",ct);
        ct++;
        insere_ArvBin(vet, criaEndereco(cep, siglaEstado, nomeCidade, end));
    }
    }
    else{
        while (fscanf(arq, "%[^;]; %2[^;]; %[^;]; %[^\n]\n", cep, siglaEstado, nomeCidade, end) != EOF){
        printf("%d\n",ct);
        ct++;
        insere_ArvBin(vet, criaEndereco(cep, siglaEstado, nomeCidade, end));
    }
    }
    fclose(arq);
    return vet;
}

void destroiEnd(Enderecos *end){
    if(end == NULL) return;
    free(end);
}

void mostrarUni(Enderecos *end)
{
    printf("\n----------------------------------------------------------------");
    printf("\nCEP: %s\tEstado: %s\tNome da Cidade: %s\t Endereco: %s\n", end->cep, end->siglaEstado, end->nomeCidade, end->end);
}