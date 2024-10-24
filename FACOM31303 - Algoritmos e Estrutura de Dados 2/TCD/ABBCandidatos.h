#ifndef ABBCANDIDATOS_H
#define ABBCANDIDATOS_H
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

#define true 1
#define false 0

typedef struct NO* ArvBin;

ArvBin *lerArquivoAbb(char *enderecoArquivo);

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
int remove_ArvBin(ArvBin *raiz, Candidato *valor);
struct NO* remove_atual(struct NO* atual);

int insere_ArvBin(ArvBin* raiz, Candidato *cand);

int altura_ArvBin(ArvBin* raiz);

int totalNO_ArvBin(ArvBin *raiz);

void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz); 
void posOrdem_ArvBin(ArvBin *raiz);

ArvBin *buscaEstadoABB(ArvBin *raiz, char *estado);
ArvBin *buscaCidadeABB(ArvBin *raiz, char *cidade);
ArvBin *buscaNumeroABB(ArvBin *raiz, char *numero);
ArvBin *buscaGeneroABB(ArvBin *raiz, char *genero);
ArvBin *buscaPartidoABB(ArvBin *raiz, char *partido);
ArvBin *buscaCorRacaABB(ArvBin *raiz, char *corRaca);

#endif // ABBCANDIDATOS_H