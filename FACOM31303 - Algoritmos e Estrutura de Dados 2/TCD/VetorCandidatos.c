#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "VetorCandidatos.h"

char *stripWhitespaceVet(char *str);

typedef struct vetorCandidatos {
    int len; 
    int quant_elem;
    Candidato **vetCandidatos;
}VetorCandidatos;

typedef struct candidato Candidato;

VetorCandidatos *criarVetorCandidato(){
    VetorCandidatos * vet = malloc(sizeof(VetorCandidatos));
    vet->len = 0;
    vet->quant_elem = 0;
    vet->vetCandidatos = NULL;
    return vet;
}

void libera_vetor(VetorCandidatos *vet){
    for(int i = 0; i < vet->len; i++){
        destroiCandidato(vet->vetCandidatos[i]);
    }
    free(vet->vetCandidatos);
    free(vet);

}

VetorCandidatos *lerArquivoVetor(char *enderecoArquivo)
{

    // Define o locale para português brasileiro (UTF-8)
    // setlocale(LC_ALL, "pt_BR.UTF-8");

    FILE *arq = fopen(enderecoArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    VetorCandidatos *vet = criarVetorCandidato();
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
        inserirCandidatos(vet, criaCandidato(estado, cidade, numero, cargo, nomeCompleto, nomeUrna, siglaPartido, genero, grauDeInstrucao, cor_raca));
        //printf("\n%d", ct);
        ct++;
    }

    ordenacao(vet);
    fclose(arq);

    return vet;
}

int inserirCandidatos(VetorCandidatos *vet, Candidato *novoCandidato){
    if(vet == NULL|| novoCandidato == NULL) 
        return false;
    if (vet->len == 0){
        vet->len += 5;
        vet->vetCandidatos = (Candidato **) malloc(sizeof(Candidato*)*vet->len);
    }
    if(vet->quant_elem >= vet->len){
        vet->len += 5;
        vet->vetCandidatos = (Candidato **) realloc(vet->vetCandidatos,sizeof(Candidato*)*vet->len); 
        if(vet->vetCandidatos == NULL)
            return false;
    }
    vet->vetCandidatos[vet->quant_elem] = novoCandidato;
    vet->quant_elem++;
    return true;
}

//--------------------------------------------------------------------- ORDENAÇÃO ------------------------------------------------------------
//ordenação deve ser feita ao mesmo tempo -> no estado deve estar ordenado por cidade e na cidade deve estar ordenada por numero



int ordenacao(VetorCandidatos *vet){
    int j, i, h = 1;
    int  n = vet->quant_elem;
    Candidato *temp;
    do {h = h * 3 + 1;} while(h < n);
    do{
        h /= 3;
        for(i = h; i < n; i++){
            temp = vet->vetCandidatos[i]; 
            j = i;  
            while(comparaCandidatos(vet->vetCandidatos[j-h], temp) > 0){ 
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
            vet->vetCandidatos[j] = temp;
                if(j < h) break;
            }
        }
    } while (h != 1);

    return true;
}

int ordenacaoCor(VetorCandidatos *vet)
{
    int j, i, h = 1;
    int n = vet->quant_elem;
    Candidato *temp;
    do
    {
        h = h * 3 + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            temp = vet->vetCandidatos[i];
            j = i;
            while (strcmp(getCor(vet->vetCandidatos[j - h]), getCor(temp)) > 0)
            {
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
                vet->vetCandidatos[j] = temp;
                if (j < h)
                    break;
            }
        }
    } while (h != 1);

    return true;
}

int ordenacaoGenero(VetorCandidatos *vet)
{
    int j, i, h = 1;
    int n = vet->quant_elem;
    Candidato *temp;
    do
    {
        h = h * 3 + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            temp = vet->vetCandidatos[i];
            j = i;
            while (strcmp(getGenero(vet->vetCandidatos[j - h]), getGenero(temp)) > 0)
            {
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
                vet->vetCandidatos[j] = temp;
                if (j < h)
                    break;
            }
        }
    } while (h != 1);

    return true;
}

int ordenacaoPartido(VetorCandidatos *vet)
{
    int j, i, h = 1;
    int n = vet->quant_elem;
    Candidato *temp;
    do
    {
        h = h * 3 + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            temp = vet->vetCandidatos[i];
            j = i;
            while (strcmp(getPartido(vet->vetCandidatos[j - h]), getPartido(temp)) > 0)
            {
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
                vet->vetCandidatos[j] = temp;
                if (j < h)
                    break;
            }
        }
    } while (h != 1);

    return true;
}

int ordenacaoNumero(VetorCandidatos *vet)
{
    int j, i, h = 1;
    int n = vet->quant_elem;
    Candidato *temp;
    do
    {
        h = h * 3 + 1;
    } while (h < n);
    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            temp = vet->vetCandidatos[i];
            j = i;
            while (strcmp(getNumeroCandidato(vet->vetCandidatos[j - h]), getNumeroCandidato(temp)) > 0)
            {
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
                vet->vetCandidatos[j] = temp;
                if (j < h)
                    break;
            }
        }
    } while (h != 1);

    return true;
}

//--------------------------------------------------------------------- BUSCAS ------------------------------------------------------------ 
int buscaBinariaAuxEstado(Candidato **vet, int inf, int sup, char *chave) {
    if(inf > sup)
        return -1;
    int meio = (inf+sup)/2;
    char *estaux = getEstadoCandidato(vet[meio]);
    if(strcmp(stripWhitespaceVet(estaux), stripWhitespaceVet(chave)) == 0) {
        return meio;
    }
    else if(strcmp(estaux, chave) < 0) 
        return buscaBinariaAuxEstado(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstado(vet, inf, meio-1, chave);
}

VetorCandidatos *buscaBinariaEstado(VetorCandidatos *vet, char *chave)
{
    if (vet == NULL || vet->quant_elem == 0)
        return NULL;

    stripWhitespaceVet(chave);

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxEstado(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1)
    {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; // vazio se n encontrou
    }

    int i = posicao;
    while (i >= 0 && strcmp(getEstadoCandidato(vet->vetCandidatos[i]), chave) == 0)
    {   
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(getEstadoCandidato(vet->vetCandidatos[j]), chave) == 0)
    {
        j++;
    } 

    for(int k = i + 1; k < j; k++){
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }
    return resultado;
}

int buscaBinariaAuxCidade(Candidato **vet, int inf, int sup, char *chave) {
    if (inf > sup) {
        return -1; 
    }

    int meio = (inf + sup) / 2;
    char *cidaux = getCidadeCandidato(vet[meio]);

    if (strcmp(stripWhitespaceVet(cidaux), stripWhitespaceVet(chave)) == 0) {
        return meio; 
    }
    else if (strcmp(stripWhitespaceVet(cidaux), stripWhitespaceVet(chave)) < 0) {
        return buscaBinariaAuxCidade(vet, meio + 1, sup, chave); 
    }
    else {
        return buscaBinariaAuxCidade(vet, inf, meio - 1, chave); 
    }
}

VetorCandidatos* buscaBinariaCidade(VetorCandidatos *vetPrincipal, char *chave, char *estado) { 
    VetorCandidatos *vet = buscaBinariaEstado(vetPrincipal, estado); 
    if (vet == NULL || vet->quant_elem == 0) {
        return NULL; 
    }

    stripWhitespaceVet(chave); 

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxCidade(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; 
    }

    int i = posicao;
    while (i >= 0 && strcmp(stripWhitespaceVet(getCidadeCandidato(vet->vetCandidatos[i])), stripWhitespaceVet(chave)) == 0) {
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(stripWhitespaceVet(getCidadeCandidato(vet->vetCandidatos[j])), stripWhitespaceVet(chave)) == 0) {
        j++;
    }

    for (int k = i + 1; k < j; k++) { 
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }

    ordenacao(resultado); // Ordena os resultados
    return resultado; // Retorna o vetor de candidatos encontrados
}


int buscaBinariaAuxNumero(Candidato **vet, int inf, int sup, char *chave)
{
    int meio = (inf + sup) / 2;
    if (inf > sup)
        return -1;
    char *cidaux = getNumeroCandidato(vet[meio]);
    if (strcmp(stripWhitespaceVet(cidaux), stripWhitespaceVet(chave)) == 0)
    {
        return meio;
    }
    else if (strcmp(cidaux, chave) < 0)
        return buscaBinariaAuxNumero(vet, meio + 1, sup, chave);
    else
        return buscaBinariaAuxNumero(vet, inf, meio - 1, chave);
}

VetorCandidatos *buscaBinariaNumero(VetorCandidatos *vet, char *chave)
{
    if (vet == NULL)
        return NULL;

    if (vet->quant_elem == 0)
        return NULL;

    stripWhitespaceVet(chave);

    ordenacaoNumero(vet);

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxNumero(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1)
    {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; // vazio se n encontrou
    }

    int i = posicao;
    while (i >= 0 && strcmp(getNumeroCandidato(vet->vetCandidatos[i]), chave) == 0)
    {
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(getNumeroCandidato(vet->vetCandidatos[j]), chave) == 0)
    {
        j++;
    }

    for (int k = i + 1; k < j; k++)
    {
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }

    ordenacao(resultado);

    return resultado;
}

int buscaBinariaAuxCor(Candidato **vet, int inf, int sup, char *chave)
{
    int meio = (inf + sup) / 2;
    if (inf > sup)
        return -1;
    char *cidaux = getCor(vet[meio]);
    if (strcmp(stripWhitespaceVet(cidaux), stripWhitespaceVet(chave)) == 0)
    {
        return meio;
    }
    else if (strcmp(cidaux, chave) < 0)
        return buscaBinariaAuxCor(vet, meio + 1, sup, chave);
    else
        return buscaBinariaAuxCor(vet, inf, meio - 1, chave);
}

VetorCandidatos *buscaBinariaCor(VetorCandidatos *vet, char *chave)
{
    if (vet == NULL)
        return NULL;

    if (vet->quant_elem == 0)
        return NULL;

    stripWhitespaceVet(chave);

    ordenacaoCor(vet);

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxCor(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1)
    {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; // vazio se n encontrou
    }

    int i = posicao;
    while (i >= 0 && strcmp(getCor(vet->vetCandidatos[i]), chave) == 0)
    {
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(getCor(vet->vetCandidatos[j]), chave) == 0)
    {
        j++;
    }

    for (int k = i + 1; k < j; k++)
    {
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }

    ordenacao(resultado);

    return resultado;
}

int buscaBinariaAuxGenero(Candidato **vet, int inf, int sup, char *chave)
{
    int meio = (inf + sup) / 2;
    if (inf > sup)
        return -1;
    char *cidaux = getGenero(vet[meio]);
    if (strcmp(stripWhitespaceVet(cidaux), stripWhitespaceVet(chave)) == 0)
    {
        return meio;
    }
    else if (strcmp(cidaux, chave) < 0)
        return buscaBinariaAuxGenero(vet, meio + 1, sup, chave);
    else
        return buscaBinariaAuxGenero(vet, inf, meio - 1, chave);
}

VetorCandidatos *buscaBinariaGenero(VetorCandidatos *vet, char *chave)
{
    if (vet == NULL)
        return NULL;

    if (vet->quant_elem == 0)
        return NULL;

    stripWhitespaceVet(chave);

    ordenacaoGenero(vet);

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxGenero(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1)
    {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; // vazio se n encontrou
    }

    int i = posicao;
    while (i >= 0 && strcmp(getGenero(vet->vetCandidatos[i]), chave) == 0)
    {
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(getGenero(vet->vetCandidatos[j]), chave) == 0)
    {
        j++;
    }

    for (int k = i + 1; k < j; k++)
    {
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }

    ordenacao(resultado);

    return resultado;
}

int buscaBinariaAuxPartido(Candidato **vet, int inf, int sup, char *chave)
{
    if (inf > sup) {
        return -1; 
    }

    int meio = (inf + sup) / 2;
    char *partidoAux = getPartido(vet[meio]);

    if (strcmp(stripWhitespaceVet(partidoAux), stripWhitespaceVet(chave)) == 0) {
        return meio; 
    } 
    else if (strcmp(stripWhitespaceVet(partidoAux), stripWhitespaceVet(chave)) < 0) {
        return buscaBinariaAuxPartido(vet, meio + 1, sup, chave); 
    } 
    else {
        return buscaBinariaAuxPartido(vet, inf, meio - 1, chave); 
    }
}

VetorCandidatos *buscaBinariaPartido(VetorCandidatos *vet, char *chave)
{
    if (vet == NULL || vet->quant_elem == 0) {
        return NULL; 
    }

    stripWhitespaceVet(chave); 
    ordenacaoPartido(vet);

    VetorCandidatos *resultado = criarVetorCandidato();

    int posicao = buscaBinariaAuxPartido(vet->vetCandidatos, 0, vet->quant_elem - 1, chave);

    if (posicao == -1) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return resultado; 
    }


    int i = posicao;
    while (i >= 0 && strcmp(stripWhitespaceVet(getPartido(vet->vetCandidatos[i])), stripWhitespaceVet(chave)) == 0) {
        i--;
    }

    int j = posicao;
    while (j < vet->quant_elem && strcmp(stripWhitespaceVet(getPartido(vet->vetCandidatos[j])), stripWhitespaceVet(chave)) == 0) {
        j++;
    }

  
    for (int k = i + 1; k < j; k++) {
        inserirCandidatos(resultado, vet->vetCandidatos[k]);
    }

    ordenacao(resultado); 
    return resultado; 
}

//--------------------------------------------------------------------- IMPRESSAO ------------------------------------------------------------
void imprimeVetorInteiro(VetorCandidatos *vet){
    if(vet == NULL) return;
    for(int i=0; i<vet->quant_elem;i++){
        imprimeCandidato(vet->vetCandidatos[i]);
    }
}


char *stripWhitespaceVet(char *str)
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