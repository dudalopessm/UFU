#include "Candidatos.h"
#ifndef ABBCANDIDATOS_H
#define ABBCANDIDATOS_H
/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018

IMPLEMENTAÇÃO DE ÁRVORES UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> créditos ao professor André Backes
*/

// Definição de constantes booleanas
#define true 1
#define false 0

// Definição da estrutura de árvores 
typedef struct NO* ArvBin;

ArvBin *lerArquivoEnderecos(char *enderecoArquivo);

// Criação e remoção da árvore
ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
int remove_ArvBin(ArvBin *raiz, Candidato *valor);
struct NO* remove_atual(struct NO* atual);

// Altura da árvore
int altura_ArvBin(ArvBin* raiz);

// Quantidade de elementos da árvore
int totalNO_ArvBin(ArvBin *raiz);

// Percurso
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Pesquisa na árvore
Candidato *busca_ArvBin(ArvBin *raiz, char *cep);
#endif // ABBCANDIDATOS_H