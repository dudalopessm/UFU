#ifndef AVLCANDIDATOS_H
#define AVLCANDIDATOS_H
#include "Candidatos.h"

typedef struct NO* ArvAVL;

int alt_NO(struct NO* no);
int altura_ArvAVL(ArvAVL* raiz);
void verFator(ArvAVL* raiz);

int fatorBalanceamento_NO(struct NO* no);

void RotacaoLL(ArvAVL *raiz);
void RotacaoRR(ArvAVL *raiz);
void RotacaoRL(ArvAVL *raiz);
void RotacaoLR(ArvAVL *raiz);

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);

int insere_ArvAVL(ArvAVL *raiz, Candidato *cand);
int remove_ArvAVL(ArvAVL *raiz, Candidato *cand);

ArvAVL *buscaEstadoAVL(ArvAVL *raiz, char *estado);
ArvAVL *buscaCidadeAVL(ArvAVL *raiz, char *cidade);
ArvAVL *buscaNumeroAVL(ArvAVL *raiz, char *numero);
ArvAVL *buscaGeneroAVL(ArvAVL *raiz, char *genero);
ArvAVL *buscaPartidoAVL(ArvAVL *raiz, char *partido);
ArvAVL *buscaCorRacaAVL(ArvAVL *raiz, char *corRaca);


void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

Candidato *maior_ArvAVL(ArvAVL *raiz);
Candidato *menor_ArvAVL(ArvAVL *raiz);

ArvAVL *lerArquivoAVL(char *enderecoArquivo);
#endif //AVLCANDIDATOS_H