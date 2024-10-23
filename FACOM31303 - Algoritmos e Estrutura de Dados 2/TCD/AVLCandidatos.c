#include "Candidatos.h"
#include "AVLCandidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018

IMPLEMENTAÇÃO DE ÁRVORE AVL UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula11-ArvoreAVL.pdf-> créditos ao professor André Backes
FUNÇÃO AUXILIAR STRIPWHITESPACE: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way -> stackoverflow
*/


char *stripWhitespaceAVL(char *str);


int maior(int a, int b)
{
    return (a > b) ? a : b;
}

struct NO
{
    Candidato *info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

int alt_NO(struct NO *no)
{
    if (no == NULL)
        return -1;
    else
        return no->alt;
}

int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;
}

int fatorBalanceamento_NO(struct NO *no)
{
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

void verFatorAux(ArvAVL *raiz, int n, char *nome)
{
    if (*raiz == NULL || raiz == NULL)
    {
        printf("\n%s | Nao existe em %d.", nome, n - 1);
        return;
    }
    printf("\n %s |Fator balanceamento: %d | %d", nome, fatorBalanceamento_NO(*raiz), n);
    verFatorAux(&((*raiz)->dir), n + 1, "Dir");
    verFatorAux(&((*raiz)->esq), n + 1, "Esq");
}

void verFator(ArvAVL *raiz)
{
    verFatorAux(raiz, 0, "raiz");
}

void RotacaoLL(ArvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;

    *raiz = no;
}

void RotacaoRR(ArvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;

    *raiz = no;
}

void RotacaoRL(ArvAVL *raiz)
{
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

void RotacaoLR(ArvAVL *raiz)
{
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO_ArvAVL(struct NO *no)
{
    if (no == NULL)
        return;
    libera_NO_ArvAVL(no->esq);
    libera_NO_ArvAVL(no->dir);
    destroiCandidato(no->info);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    libera_NO_ArvAVL(*raiz);
    free(raiz);
    *raiz = NULL;
}

int insere_ArvAVL(ArvAVL *raiz, Candidato *cand)
{
    if (raiz == NULL)
        return 0;
    int res;

    if (*raiz == NULL)
    {
        struct NO *novo = malloc(sizeof(struct NO));

        if (novo == NULL)
            return 0;

        novo->info = cand;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;

        *raiz = novo;

        return 1;
    }

    struct NO *atual = *raiz;
    if (comparaCandidatos(cand, atual->info) < 0)
    {
        if ((res = insere_ArvAVL(&(atual)->esq, cand)) == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {
                if (comparaCandidatos(cand, (*raiz)->esq->info) < 0)
                {
                    RotacaoLL(raiz);
                }
                else
                {
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else if (comparaCandidatos(cand, atual->info) > 0)
    {
        if ((res = insere_ArvAVL(&(atual)->dir, cand)) == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {
                if (comparaCandidatos((*raiz)->dir->info, cand) < 0)
                {
                    RotacaoRR(raiz);
                }
                else
                {
                    RotacaoRL(raiz);
                }
            }
        }
    }
    else
    {
        // Valor duplicado
        return 0;
    }

    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;

    return res;
}

struct NO *procuraMenor(struct NO *raiz)
{
    struct NO *n1 = raiz;
    struct NO *n2 = raiz->esq;

    while (n2 != NULL)
    {
        n1 = n2;
        n2 = n2->esq;
    }

    return n1;
}

int remove_ArvAVL(ArvAVL *raiz, Candidato *cand)
{
    if (raiz == NULL || *raiz == NULL)
        return 0;

    int res;
    int cmp = comparaCandidatos(cand, (*raiz)->info);

    if (cmp < 0)
    {
        if ((res = remove_ArvAVL(&(*raiz)->esq, cand)) == 1)
        {
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {

                if (alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))
                {
                    RotacaoRR(raiz);
                }
                else
                {
                    RotacaoRL(raiz);
                }
            }
        }
    }
    else if (cmp > 0)
    {
        if ((res = remove_ArvAVL(&(*raiz)->dir, cand)) == 1)
        {
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {
                if (alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                {
                    RotacaoLL(raiz);
                }
                else
                {
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            struct NO *oldNo = (*raiz);
            if ((*raiz)->esq != NULL)
                (*raiz) = (*raiz)->esq;
            else
                (*raiz) = (*raiz)->dir;
            libera_NO_ArvAVL(oldNo);
        }
        else
        {
            struct NO *temp = procuraMenor((*raiz) = (*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {
                if (alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                {
                    printf("\n Rotacao LL");
                    RotacaoRR(raiz);
                }
                else
                {
                    printf("\n Rotacao LR");
                    RotacaoRL(raiz);
                }
            }
        }
        if (*raiz != NULL)
        {
            (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
        }

        return 1;
    }
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;

    return res;
}

void preOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL || *raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        imprimeCandidato((*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        imprimeCandidato((*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}
void posOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        imprimeCandidato((*raiz)->info);
    }
}

Candidato *maior_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return NULL;
    if ((*raiz)->dir == NULL)
        return (*raiz)->info;
    return maior_ArvAVL(&((*raiz)->dir));
}

Candidato *menor_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return NULL;
    if ((*raiz)->esq == NULL)
        return (*raiz)->info;
    return menor_ArvAVL(&((*raiz)->esq));
}

void buscaEstadoAVLAux(ArvAVL *raiz, char *estado, ArvAVL *copia)
{
    if (raiz == NULL || *raiz == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getEstadoCandidato((*raiz)->info)), estado);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        buscaEstadoAVLAux(&((*raiz)->dir), estado, copia);
        buscaEstadoAVLAux(&((*raiz)->esq), estado, copia);
        return;
    }
    else if (cmp < 0)
    {
        return buscaEstadoAVLAux(&((*raiz)->dir), estado, copia);
    }
    else
        return buscaEstadoAVLAux(&((*raiz)->esq), estado, copia);
}

ArvAVL *buscaEstadoAVL(ArvAVL *raiz, char *estado)
{

    ArvAVL *copia = cria_ArvAVL();

    buscaEstadoAVLAux(raiz, estado, copia);

    return copia;
}

void buscaCidadeAVLAux(ArvAVL *raiz, char *cidade, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getCidadeCandidato((*raiz)->info)), cidade);

    if (cmp == 0)
    {

        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        buscaCidadeAVLAux(&((*raiz)->dir), cidade, copia);
        buscaCidadeAVLAux(&((*raiz)->esq), cidade, copia);
        return;
    }
    else if (cmp < 0)
    {
        return buscaCidadeAVLAux(&((*raiz)->dir), cidade, copia);
    }
    else
        return buscaCidadeAVLAux(&((*raiz)->esq), cidade, copia);
}

ArvAVL *buscaCidadeAVL(ArvAVL *raiz, char *cidade)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaCidadeAVLAux(raiz, cidade, copia);

    return copia;
}

void buscaNumeroAVLAux(ArvAVL *raiz, char *numero, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getNumeroCandidato((*raiz)->info)), numero);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaNumeroAVLAux(&((*raiz)->dir), numero, copia);
    buscaNumeroAVLAux(&((*raiz)->esq), numero, copia);
}

ArvAVL *buscaNumeroAVL(ArvAVL *raiz, char *numero)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaNumeroAVLAux(raiz, numero, copia);

    return copia;
}

void buscaGeneroAVLAux(ArvAVL *raiz, char *genero, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getGenero((*raiz)->info)), genero);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }

    buscaGeneroAVLAux(&((*raiz)->dir), genero, copia);
    buscaGeneroAVLAux(&((*raiz)->esq), genero, copia);
}

ArvAVL *buscaGeneroAVL(ArvAVL *raiz, char *genero)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaGeneroAVLAux(raiz, genero, copia);

    return copia;
}

void buscaPartidoAVLAux(ArvAVL *raiz, char *partido, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getPartido((*raiz)->info)), partido);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaPartidoAVLAux(&((*raiz)->dir), partido, copia);
    buscaPartidoAVLAux(&((*raiz)->esq), partido, copia);
}

ArvAVL *buscaPartidoAVL(ArvAVL *raiz, char *partido)
{
    ArvAVL *copia = cria_ArvAVL();
    buscaPartidoAVLAux(raiz, partido, copia);

    return copia;
}

void buscaCorRacaAVLAux(ArvAVL *raiz, char *corRaca, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getCor((*raiz)->info)), corRaca);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaCorRacaAVLAux(&((*raiz)->dir), corRaca, copia);
    buscaCorRacaAVLAux(&((*raiz)->esq), corRaca, copia);
}

ArvAVL *buscaCorRacaAVL(ArvAVL *raiz, char *corRaca)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaCorRacaAVLAux(raiz, corRaca, copia);

    return copia;
}

ArvAVL *lerArquivoAVL(char *enderecoArquivo)
{
    FILE *arq = fopen(enderecoArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    ArvAVL *arv = cria_ArvAVL();

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
    while (fgets(linha, sizeof(linha), arq))
    {
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
        insere_ArvAVL(arv, criaCandidato(estado, cidade, numero, cargo, nomeCompleto, nomeUrna, siglaPartido, genero, grauDeInstrucao, cor_raca));
        // printf("\n%d", ct);
        ct++;
    }
    fclose(arq);
    return arv;
}

char *stripWhitespaceAVL(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = '\0';

    return str;
}