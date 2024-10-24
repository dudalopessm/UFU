#ifndef AVLCANDIDATOS_H
#define AVLCANDIDATOS_H
#include "Candidatos.h"

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

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);

int alt_NO(struct NO* no);
int altura_ArvAVL(ArvAVL* raiz);

void verFator(ArvAVL* raiz);
int fatorBalanceamento_NO(struct NO* no);

void RotacaoLL(ArvAVL *raiz);
void RotacaoRR(ArvAVL *raiz);
void RotacaoRL(ArvAVL *raiz);
void RotacaoLR(ArvAVL *raiz);

int insere_ArvAVL(ArvAVL *raiz, Candidato *cand);
int remove_ArvAVL(ArvAVL *raiz, Candidato *cand);
ArvAVL *lerArquivoAVL(char *enderecoArquivo);

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

#endif //AVLCANDIDATOS_H