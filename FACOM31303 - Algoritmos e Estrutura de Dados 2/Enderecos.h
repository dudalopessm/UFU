#ifndef ENDERECOS_H
#define ENDERECOS_H

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018
*/

// Definição de constantes booleanas
#define true 1
#define false 0
typedef int bool;

// Definição da estrutura de endereços - um é o elemento endereços e o outro é uma estrutura que aponta para o vetor de endereços
typedef struct Enderecos
{
    char cep[10];
    char siglaEstado[3];
    char nomeCidade[50];
    char end[100]; //end = endereço
}Enderecos;

typedef struct VetorEndereco
{
    int len; //tamanho do vetor
    int quant_elem;
    Enderecos **vetEnderecos;
} VetorEndereco;

VetorEndereco *criarVetorEnderecos();
Enderecos *criaEndereco(char *cep, char *siglaEstado,char *nomeCidade, char *endereco);

bool inserirEndereco(VetorEndereco *vet, Enderecos *novoEndereco);
void mostrarTela(VetorEndereco *vet);
void mostrarUni(Enderecos *end);
bool shellSort(VetorEndereco *vet);

Enderecos* buscaBinaria(VetorEndereco *vet, char *chave);
Enderecos* buscaBinariaAux(Enderecos **vet, int inf, int sup, char *chave);

VetorEndereco *lerArquivoEnderecos(char *enderecoArquivo);

#endif // ENDERECOS_H