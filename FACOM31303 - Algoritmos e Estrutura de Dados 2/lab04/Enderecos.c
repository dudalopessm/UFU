#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enderecos.h"

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018
*/

VetorEndereco *criarVetorEnderecos()
{
    VetorEndereco *vet = malloc(sizeof(VetorEndereco));
    vet->quant_elem = 0;
    vet->len = 0;
    vet->vetEnderecos = NULL;
    return vet;
}

Enderecos *criaEndereco(char *cep, char *siglaEstado, char *nomeCidade, char *endereco)
{
    Enderecos *end = malloc(sizeof(Enderecos));
    strcpy(end->cep, cep);
    strcpy(end->siglaEstado, siglaEstado);
    strcpy(end->nomeCidade, nomeCidade);
    strcpy(end->end, endereco);
    return end;
}

bool inserirEndereco(VetorEndereco *vet, Enderecos *novoEndereco) 
{
    if (vet == NULL || novoEndereco == NULL)
        return false;

    if (vet->len == 0)
    {
        vet->len += 5;
        vet->vetEnderecos = (Enderecos **)malloc(sizeof(Enderecos *)*vet->len);
    }

    if (vet->quant_elem >= vet->len)
    {
        vet->len += 5;
        vet->vetEnderecos = (Enderecos **)realloc(vet->vetEnderecos, sizeof(Enderecos *) * vet->len);
        if (vet->vetEnderecos == NULL)
            return false;
    }

    vet->vetEnderecos[vet->quant_elem] = (Enderecos *)malloc(sizeof(Enderecos));
    if (vet->vetEnderecos[vet->quant_elem] == NULL)
        return false; 

    memcpy(vet->vetEnderecos[vet->quant_elem], novoEndereco, sizeof(Enderecos));

    vet->quant_elem += 1;

    return true;
}

Enderecos* buscaBinariaAux(Enderecos **vet, int inf, int sup, char  *chave)
{
    int meio = (inf + sup) / 2;
    if(inf > sup)
        return NULL;
    if(strcmp( vet[meio]->cep, chave) == 0)
        return vet[meio];
    else if(strcmp( vet[meio]->cep, chave) < 0)
        return buscaBinariaAux(vet, meio + 1, sup, chave);
    else 
        return buscaBinariaAux(vet, inf, meio - 1, chave);
}

Enderecos* buscaBinaria(VetorEndereco *vet, char *chave){
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    return buscaBinariaAux(vet->vetEnderecos, 0, vet->quant_elem - 1, chave);
}

void mostrarUni(Enderecos *end)
{
    printf("\n-------------------------------------------------------------------------------------");
    printf("\nCEP: %s\tEstado: %s\tNome da Cidade: %s\t Endereco: %s\n", end->cep, end->siglaEstado, end->nomeCidade, end->end);
}

void mostrarTela(VetorEndereco *vet)
{
    for(int i = 0, len = vet->quant_elem; i < len; i++){
        mostrarUni(vet->vetEnderecos[i]);
    }
}

int shellSort(VetorEndereco *vet){
    int j, i, h = 1;
    int  n = vet->quant_elem;
    Enderecos *temp;
    do {h = h * 3 + 1;} while(h < n);
    do{
        h /= 3;
        for(i = h; i < n; i++){
            
            temp = vet->vetEnderecos[i];
            j = i;
            while(strcmp(vet->vetEnderecos[j-h]->cep,temp->cep) > 0){
                vet->vetEnderecos[j] = vet->vetEnderecos[j - h];
                j -= h;
                if(j < h) break;
            }
            vet->vetEnderecos[j] = temp;
        }
    } while (h != 1);
    return 0;
}

VetorEndereco *lerArquivoEnderecos(char *enderecoArquivo) { 
    FILE *arq = fopen("database_Enderecos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    VetorEndereco *vet = criarVetorEnderecos();
    char cep[15], siglaEstado[12], nomeCidade[255], end[255];
    while (fscanf(arq, "%[^;]; %2[^;]; %[^;]; %[^\n]\n", cep, siglaEstado, nomeCidade, end) != EOF)
    {
        inserirEndereco(vet, criaEndereco(cep, siglaEstado, nomeCidade, end));
    }
    fclose(arq);
    return vet;
}