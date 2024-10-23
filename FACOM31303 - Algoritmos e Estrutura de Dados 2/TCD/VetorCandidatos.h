#ifndef VETORCANDIDATOS_H
#define VETORCANDIDATOS_H
#define true 1
#define false 0
#include "Candidatos.h"
typedef struct vetorCandidatos VetorCandidatos;

//inserção ordenada
VetorCandidatos *criarVetorCandidato();
void libera_vetor(VetorCandidatos *vet);
VetorCandidatos *lerArquivoVetor(char *enderecoArquivo);


int inserirCandidatos(VetorCandidatos *vet, Candidato *novoCandidato);

int ordenacao(VetorCandidatos *vet);


int ordenacaoCor(VetorCandidatos *vet);
int ordenacaoGenero(VetorCandidatos *vet);
int ordenacaoPartido(VetorCandidatos *vet);

//buscas
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

//impressão vetor inteiro para testes
void imprimeVetorInteiro(VetorCandidatos *vet);

#endif //VETORCANDIDATOS_H