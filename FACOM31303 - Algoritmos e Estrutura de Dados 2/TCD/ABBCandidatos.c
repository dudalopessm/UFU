/*

  TRABALHO DE BUSCA DE DADOS DE CANDIDATOS DA ELEICAO DE 2024
  
    GRUPO: Eduarda Lopes (12311BCC033), Lucas Matos (12311BCC024) e Matheus Vinicius (12311BCC018)

    PROFESSOR: Maria Camila Nardoni

    DISCIPLINA: FACOM31303 - ALGORITMOS E ESTRUTURA DE DADOS 2 

    SEMESTRE: 2024.1 

    CREDITOS: - IMPLEMENTACAO DE ARVORE BINARIA UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> creditos ao professor Andre Backes
              - IMPLEMENTACAO DE ARVORE AVL UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula11ArvoreAVL.pdf-> creditos ao professor Andre Backes
              - FUNCAO AUXILIAR STRIPWHITESPACE: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way -> stackoverflow

*/
#include "ABBCandidatos.h"
#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------- FUNCOES AUXILIARES --------------------------------------//

/*
    FUNCAO stripWhitespace:

        Mesmo funcionamento da funcao stripWhitespaceCand em Candidatos.C

*/
char *stripWhitespace(char *str)
{
    char *end;

    while(isspace((unsigned char)*str)) str++;

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';

    return str;
}

// ------------------------------------- ESTRUTURA ARVORE BINARIA --------------------------------------//

/*
    Estrutura  Arvore Binaria:

        A Arvore binaria é definida como um no raiz e nos filhos a esquerda e a direita, com pequena alteracao da informacao contida como sendo um *Candidato

*/

typedef struct NO* ArvBin;
struct NO{
    Candidato *info;
    struct NO *esq;
    struct NO *dir;
}NO;

// ------------------------------------- CRIACAO E DESTRUICAO DE ARVORES BINARIAS --------------------------------------//

/*
    Funcao  cria_ArvBin:

        A funcao aloca memoria para a estrutura de ArvBin e retona o ponteiro resultade para raiz

*/
ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

/*
    Funcao  libera_NO:

        A funcao faz a liberaçpao dos dados de um dado No, contendo o candidato, de maneira recursiva ate que o no em questao seja igual a NULL

*/
void libera_NO(struct NO* no) {
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    destroiCandidato(no->info);
    free(no);
    no = NULL;
}

/*
    Funcao  libera_ArvBin:

        A funcao faz a liberaçpao dos dados de uma dada arvore usando a funcao auxiliar libera_NO, para a liberacao das ramificacoes da arvore e por fim liberando a raiz

*/
void libera_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
    *raiz = NULL;
}

// ------------------------------------- FUNCOES RELACIONADAS AS ARVORES --------------------------------------//

/*
    FUNCAO altura_ArvBin:

        Funcao que retorna a altura da arvore binaria inteira

*/
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


/*
    FUNCAO totalNO_ArvBin:

        Retorna o total de nos existentes na arvore

*/
int totalNO_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_dir+alt_esq+1);
}

/*
    FUNCAO maior_ArvBin:

        Retorna maior candidato pelo sistema de comparaCandidato()

*/
Candidato *maior_ArvBin(ArvBin *raiz){
    if(raiz == NULL) 
        return NULL;
    if((*raiz)->dir == NULL) 
        return (*raiz)->info;
    return maior_ArvBin(&((*raiz)->dir));
}

/*
    FUNCAO menor_ArvBin:

        Retorna menor candidato pelo sistema de comparaCandidato()

*/
Candidato *menor_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return NULL;
    if((*raiz)->esq == NULL) return (*raiz)->info;
    return menor_ArvBin(&((*raiz)->esq));
}

// ------------------------------------- INSERCAO E REMOCAO DE DADOS --------------------------------------//
/*
    Funcao de Insercao:

        - A insercao na arvore binaria funciona da seguinte maneira:
            Passo 1: Se a raiz for vazia insere na raiz
            Passo 2: Se raiz nao for vazia pedimos o retorno de comparaCandidatos(cand,raiz)
            Passo 3: Se o retorno for menor do que zero, va para o Passo 1 e considere a nova raiz como sendo o filho a esquerda de raiz
            Passo 4: Se o retorno for maior do que zero, va para o Passo 1 e considere a nova raiz como sendo o filho a direita de raiz
            Passo 5: Se o retorno for igual a zero finalize a insercao, pois, elementos duplicados nao devem ser inseridos
*/

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

/*
    Funcao de remove_atual:

        A funcao remove_atual, remove um determinado no de uma arvore ao fazer a troca dos ponteiros das raificacoes do no em questao, dependendo se as arvores a esquerda ou a direita forem iguais a NULL
*/
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

/*
    Funcao de Remocao:

        - A remocao na arvore binaria funciona da seguinte maneira:
            Passo 1: Se a raiz for retorne 0
            Passo 2: Se raiz nao for vazia pedimos o retorno de comparaCandidatos(cand,raiz)
            Passo 3: Se o retorno for menor do que zero, va para o Passo 1 e considere a nova raiz como sendo o filho a esquerda de raiz
            Passo 4: Se o retorno for maior do que zero, va para o Passo 1 e considere a nova raiz como sendo o filho a direita de raiz
            Passo 5: Se o retorno for igual a zero verifique se a raiz atual eh igual a raiz principal da arvore
            Passo 6: Se for faca remove_atual(raiz)
            Passo 7: Se nao verifique se a raiz atual eh igual a raiz anterior a atual a direita
            Passo 8: Se for faca ant->dir = remove_atual(atual)
            Passo 9: Se nao faca ant->esq = remove_atual(atual)
            
*/
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

// ------------------------------------- FUNCOES DE BUSCA --------------------------------------//
/*
    Funcoes de Busca:

        - Como ideia central da busca em uma arvore binaria, eh o retorno de uma nova arvore, que vamos chamar de copia, com os candidado que queremos buscar, 
        nisso ao verificamos qual o tipo dado queremos buscar, se for estado a busca eh dada de uma forma, senao for ela eh dada de maneira diferente. 
        - Busca estado: Como sabemos que os dados por estado, cidade e numero pela maneira que as insercoes estao sendo feitas, podemos comparar estado da raiz com o estado 
        buscado, caso a comparacao feita pelo strcmp() seja menor do que zero buscamos na raiz a direita, caso seja maior do que zero buscamos na raiz a esquerda, por fim se for 
        igual a zero fazemos a insercao em copia e buscamos em ambas as subarvores.
        - Busca gera: Como sabemos que os dados por estado, cidade e numero pela maneira que as insercoes estao sendo feitas, os dados podem estar tanto na arvore a esquerda quanto 
        na arvore a direita entao apenas comparamos dado da raiz com o dado buscado, caso a comparacao feita pelo strcmp() seja igual a zero fazemos a insercao em copia e 
        depois buscamos em ambas as subarvores.
        - Esse processo eh repetido ate que todas as ocorrencias do dado seja encontrado na arvore.
        
*/

// Busca Estado
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

// Busca Cidade
void buscaCidadeABBAux(ArvBin *raiz, char *cidade, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getCidadeCandidato((*raiz)->info)), cidade);

    if(cmp == 0){

        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaCidadeABBAux(&((*raiz)->dir), cidade, copia);
    buscaCidadeABBAux(&((*raiz)->esq), cidade, copia);
}

ArvBin *buscaCidadeABB(ArvBin *raiz, char *cidade) {
    ArvBin *copia = cria_ArvBin();
    buscaCidadeABBAux(raiz, cidade, copia);
    return copia;
}

// Busca Numero
void buscaNumeroABBAux(ArvBin *raiz, char *numero, ArvBin *copia){
    if(raiz == NULL || *(raiz) == NULL) return;

    int cmp = strcmp(stripWhitespace(getNumeroCandidato((*raiz)->info)), numero);

    if(cmp == 0){
        insere_ArvBin(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaNumeroABBAux(&((*raiz)->dir), numero, copia);
    buscaNumeroABBAux(&((*raiz)->esq), numero, copia);
}

ArvBin *buscaNumeroABB(ArvBin *raiz, char *numero){
    ArvBin *copia = cria_ArvBin();
    buscaNumeroABBAux(raiz, numero, copia);

    return copia;
}

// Busca Genero
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

// Busca Partido
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

// Busca Cor/Raca
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
// ------------------------------------- FUNCOES DE IMPRESAO EM ARVORES BINARIAS --------------------------------------//
/*
    Funcao preOrdem_ArvBin:

        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime a raiz
            - Imprime o filho a esquerda
            - Imprime o filho a direita
        
*/

void preOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL||*raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if(*raiz != NULL) {
        imprimeCandidato((*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

/*
    Funcao emOrdem_ArvBin:
    
        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime o filho a esquerda
            - Imprime a raiz
            - Imprime o filho a direita
        
*/
void emOrdem_ArvBin(ArvBin *raiz) {
    if (raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));
        imprimeCandidato((*raiz)->info); 
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

/*
    Funcao posOrdem_ArvBin:
    
        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime o filho a esquerda
            - Imprime o filho a direita
            - Imprime a raiz
        
*/
void posOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if(*raiz != NULL) {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        imprimeCandidato((*raiz)->info); 
    }
}

// ------------------------------------- FUNCAO DE LEITURA DE ARQUIVO --------------------------------------//
/*
    FUNCAO lerArquivoAbb:
    
        - Recebe uma string que sinaliza qual arquivo deve ser lido
        - Extrai dados de candidatos pela funcao extrairToken
        - Insere os candidatos de forma sequencial por meio da funcao insere_ArvBin que recebe a arvore binaria e que recebera o candidato e a criacao do candidato 
        - O candidato a ser inserido eh criado na propria chamada da funcao que insere o candidato no vetor
        
*/
ArvBin *lerArquivoAbb(char *enderecoArquivo) { 
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
    }
    fclose(arq);
    return arv;
}