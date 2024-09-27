#ifndef VETORCANDIDATOS_H
#define VETORCANDIDATOS_H
#define true 1
#define false 0
#include "Candidatos.h"
typedef struct vetorCandidatos VetorCandidatos;

VetorCandidatos *criarVetorCandidato();

VetorCandidatos *lerArquivoVetor(char *enderecoArquivo);

int inserirCandidatos(VetorCandidatos *vet, Candidato *novoCandidato);

int ordenacao(VetorCandidatos *vet, int opcao);

void imprimeVetor(VetorCandidatos *vet);

#endif //VETORCANDIDATOS_H