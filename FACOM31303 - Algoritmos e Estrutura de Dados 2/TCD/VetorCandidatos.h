#ifndef VETORCANDIDATOS_H
#define VETORCANDIDATOS_H
#define true 1
#define false 0
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

typedef struct vetorCandidatos VetorCandidatos;

VetorCandidatos *criarVetorCandidato();
void libera_vetor(VetorCandidatos *vet);
VetorCandidatos *lerArquivoVetor(char *enderecoArquivo);

int inserirCandidatos(VetorCandidatos *vet, Candidato *novoCandidato);

int ordenacao(VetorCandidatos *vet);
int ordenacaoCor(VetorCandidatos *vet);
int ordenacaoGenero(VetorCandidatos *vet);
int ordenacaoPartido(VetorCandidatos *vet);

int buscaBinariaAuxEstado(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos* buscaBinariaEstado(VetorCandidatos *vet, char *chave);
int buscaBinariaAuxCidade(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos* buscaBinariaCidade(VetorCandidatos *vetPrincipal, char *chave, char *estado);
int buscaBinariaAuxNumero(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos *buscaBinariaNumero(VetorCandidatos *vet, char *chave);
int buscaBinariaAuxCor(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos *buscaBinariaCor(VetorCandidatos *vet, char *chave);
int buscaBinariaAuxGenero(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos *buscaBinariaGenero(VetorCandidatos *vet, char *chave);
int buscaBinariaAuxPartido(Candidato **vet, int inf, int sup, char *chave);
VetorCandidatos *buscaBinariaPartido(VetorCandidatos *vet, char *chave);

void imprimeVetorInteiro(VetorCandidatos *vet);

#endif //VETORCANDIDATOS_H