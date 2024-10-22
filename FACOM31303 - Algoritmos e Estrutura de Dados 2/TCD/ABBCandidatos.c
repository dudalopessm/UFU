#include "ABBCandidatos.h"
#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018

IMPLEMENTAÇÃO DE ÁRVORE BINÁRIA UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> créditos ao professor André Backes
FUNÇÃO AUXILIAR STRIPWHITESPACE: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way -> stackoverflow
*/

char *stripWhitespace(char *str);


typedef struct NO* ArvBin;
struct NO{
    Candidato *info;
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
    destroiCandidato(no->info);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
    *raiz = NULL;
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

int insere_ArvBin(ArvBin* raiz, Candidato *cand){
    if (raiz == NULL) return 0;
    struct NO* novo;

    novo = (struct NO*) malloc(sizeof(NO));
    if(novo == NULL) return 0;

    novo->info = cand;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL) *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while (atual != NULL) {
            ant = atual;

            if(comparaCandidatos(cand,atual->info) == 0){
                free(novo);
                return 0;
            }

            if(comparaCandidatos(cand,atual->info) > 0){
                atual = atual->dir;
            }
            else {
                atual = atual->esq;
            }
        }
        if(comparaCandidatos(cand, ant->info) > 0){
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

int remove_ArvBin(ArvBin *raiz, Candidato *valor) {
    if(raiz == NULL) 
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL) {
        if(comparaCandidatos(valor,atual->info)==0) {
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
        if(comparaCandidatos(valor,atual->info)>0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void buscaEstadoABBAux(ArvBin *raiz, char *estado, ArvBin *copia){
    if(raiz == NULL || *raiz == NULL) return;

    int cmp = strcmp(stripWhitespace(getEstadoCandidato((*raiz)->info)), estado);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        buscaEstadoABBAux(&((*raiz)->dir), estado, copia);
        buscaEstadoABBAux(&((*raiz)->esq), estado, copia);
        return;
    }
    else if(cmp < 0){
        return buscaEstadoABBAux(&((*raiz)->dir), estado, copia);
    }
    else
        return buscaEstadoABBAux(&((*raiz)->esq), estado, copia);
}

ArvBin *buscaEstadoABB(ArvBin *raiz, char *estado){

    ArvBin *copia = cria_ArvBin();

    buscaEstadoABBAux(raiz, estado, copia);

    return copia;
}

void buscaCidadeABBAux(ArvBin *raiz, char *cidade, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getCidadeCandidato((*raiz)->info)), cidade);

    if(cmp == 0){
        
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        buscaCidadeABBAux(&((*raiz)->dir), cidade, copia);
        buscaCidadeABBAux(&((*raiz)->esq), cidade, copia);
        return;
    }
    else if(cmp < 0){
        return buscaCidadeABBAux(&((*raiz)->dir), cidade, copia);
    }
    else
        return buscaCidadeABBAux(&((*raiz)->esq), cidade, copia);
}

ArvBin *buscaCidadeABB(ArvBin *raiz, char *cidade) {
    ArvBin *copia = cria_ArvBin();
    buscaCidadeABBAux(raiz, cidade, copia);
    return copia;
}

void buscaNumeroABBAux(ArvBin *raiz, char *numero, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getNumeroCandidato((*raiz)->info)), numero);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        return;
    }
    else if(cmp < 0){
        return buscaNumeroABBAux(&((*raiz)->dir), numero, copia);
    }
    else
        return buscaNumeroABBAux(&((*raiz)->esq), numero, copia);
}

ArvBin *buscaNumeroABB(ArvBin *raiz, char *numero){
    ArvBin *copia = cria_ArvBin();
    buscaNumeroABBAux(raiz, numero, copia);

    return copia;
}

void buscaGeneroABBAux(ArvBin *raiz, char *genero, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getGenero((*raiz)->info)), genero);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }

    buscaGeneroABBAux(&((*raiz)->dir), genero, copia);
    buscaGeneroABBAux(&((*raiz)->esq), genero, copia);
}

ArvBin *buscaGeneroABB(ArvBin *raiz, char *genero){
    ArvBin *copia = cria_ArvBin();
    buscaGeneroABBAux(raiz, genero, copia);

    return copia;
}

void buscaPartidoABBAux(ArvBin *raiz, char *partido, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getPartido((*raiz)->info)), partido);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaPartidoABBAux(&((*raiz)->dir), partido, copia);
    buscaPartidoABBAux(&((*raiz)->esq), partido, copia);
}

ArvBin *buscaPartidoABB(ArvBin *raiz, char *partido){
    ArvBin *copia = cria_ArvBin();
    buscaPartidoABBAux(raiz, partido, copia);

    return copia;
}

void buscaCorRacaABBAux(ArvBin *raiz, char *corRaca, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getCor((*raiz)->info)), corRaca);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaCorRacaABBAux(&((*raiz)->dir), corRaca, copia);
    buscaCorRacaABBAux(&((*raiz)->esq), corRaca, copia);
}

ArvBin *buscaCorRacaABB(ArvBin *raiz, char *corRaca){
    ArvBin *copia = cria_ArvBin();
    buscaCorRacaABBAux(raiz, corRaca, copia);

    return copia;
}

/*

ArvBin *busca_ArvBinEstado(ArvBin *raiz, char *sigla){ //AQUIIIIIII
    if(*raiz == NULL || raiz == NULL) return NULL;
    if(strcmp(getEstadoCandidato((*raiz)->info), sigla) == 0)
        return raiz;
    else if (strcmp(getEstadoCandidato((*raiz)->info), sigla) < 0) 
        return busca_ArvBinEstado(&((*raiz)->dir), sigla);
    else 
        return busca_ArvBinEstado(&((*raiz)->esq), sigla);
    return NULL;
}

*/

void preOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL||*raiz == NULL)
        return;
    if(*raiz != NULL) {
        imprimeCandidato((*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}
void emOrdem_ArvBin(ArvBin *raiz) {
    if (raiz == NULL)
        return;
    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));
        imprimeCandidato((*raiz)->info); 
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
void posOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        imprimeCandidato((*raiz)->info); 
    }
}

Candidato *maior_ArvBin(ArvBin *raiz){
    if(raiz == NULL) 
        return NULL;
    if((*raiz)->dir == NULL) 
        return (*raiz)->info;
    return maior_ArvBin(&((*raiz)->dir));
}

Candidato *menor_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return NULL;
    if((*raiz)->esq == NULL) return (*raiz)->info;
    return menor_ArvBin(&((*raiz)->esq));
}


ArvBin *lerArquivoAbb(char *enderecoArquivo) { //AQUIIIIIII
    FILE *arq = fopen(enderecoArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    ArvBin *arv = cria_ArvBin();

    char estado[3];
    char cidade[100];
    char numero[50];
    char cargo[100];
    char nomeCompleto[100];
    char nomeUrna[100];
    char siglaPartido[50];
    char genero[50];
    char grauDeInstrucao[50];
    char cor_raca[50];
    int ct = 0;
    char linha[500];
    while (fgets(linha, sizeof(linha), arq)){
        extrairToken(linha, estado, ";");
        extrairToken(NULL, cidade, ";");
        extrairToken(NULL, numero, ";");
        extrairToken(NULL, cargo, ";");
        extrairToken(NULL, nomeCompleto, ";");
        extrairToken(NULL, nomeUrna, ";");
        extrairToken(NULL, siglaPartido, ";");
        extrairToken(NULL, genero, ";");
        extrairToken(NULL, grauDeInstrucao, ";");
        extrairToken(NULL, cor_raca, "\n");
        insere_ArvBin(arv, criaCandidato(estado, cidade, numero, cargo, nomeCompleto, nomeUrna, siglaPartido, genero, grauDeInstrucao, cor_raca));
        //printf("\n%d", ct);
        ct++;
    }
    fclose(arq);
    return arv;
}

// Funcoes auxiliares

char *stripWhitespace(char *str)
{
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}