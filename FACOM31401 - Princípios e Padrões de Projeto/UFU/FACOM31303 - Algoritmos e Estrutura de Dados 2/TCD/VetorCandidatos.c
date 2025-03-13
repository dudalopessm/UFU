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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "VetorCandidatos.h"

// ------------------------------------- FUNCOES AUXILIARES --------------------------------------//
/*
    FUNCAO stripWhitespaceVet:

        Mesmo funcionamento da funcao stripWhitespaceCand em Candidatos.C

*/
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

// ------------------------------------- DECLARACAO STRUCT VETOR --------------------------------------//
/*
    ESTRUTURA VetorCandidatos:

        Temos a estrutura de um dacampo len e campo quant_elem para controle da alocacao dinamica de memoria
*/
typedef struct vetorCandidatos {
    int len; 
    int quant_elem;
    Candidato **vetCandidatos;
}VetorCandidatos;

typedef struct candidato Candidato;

// ------------------------------------- FUNCOES DE CRIACAO E LIBERACAO DE VETOR --------------------------------------//
/*
    FUNCAO criarVetorCandidato:

        Cria um vetor de candidatos e retorna um ponteiro para o inicio dele

*/
VetorCandidatos *criarVetorCandidato(){
    VetorCandidatos * vet = malloc(sizeof(VetorCandidatos));
    vet->len = 0;
    vet->quant_elem = 0;
    vet->vetCandidatos = NULL;
    return vet;
}

/*
    FUNCAO libera_vetor:
    
        Libera cada elemento do vetor e o proprio vetor

*/
void libera_vetor(VetorCandidatos *vet){
    for(int i = 0; i < vet->len; i++){
        if(vet->vetCandidatos[i] != NULL)
            destroiCandidato(vet->vetCandidatos[i]);
    }
    free(vet->vetCandidatos);
    free(vet);

}

// ------------------------------------- LEITURA DO ARQUIVO --------------------------------------//
/*
    FUNCAO lerArquivoVetor:
    
        - Recebe uma string que sinaliza qual arquivo deve ser lido
        - Extrai dados de candidatos pela funcao extrairToken
        - Insere os candidatos de forma sequencial por meio da funcao inserirCandidatos que recebe o vetor que recebera o candidato e a criacao do candidato 
        - O candidato a ser inserido eh criado na propria chamada da funcao que insere o candidato no vetor
        
*/
VetorCandidatos *lerArquivoVetor(char *enderecoArquivo)
{

    // Define o locale para portugues brasileiro (UTF-8)
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

// ------------------------------------- INSERIR CANDIDATOS --------------------------------------//
/*
    FUNCAO inserirCandidatos:

        - Essa funcao insere candidatos baseada no campo len - se for o primeiro elemento, sao alocados mais 5 espacos para preenchimento futuro por meio de um malloc
        - Se houverem mais candidatos a serem inseridos do que campos disponiveis de memoria, aloca-se mais 5 espacos para preenchimento futuro por meio de um realloc
        - No final da insercao a quantidade de candidatos eh incrementada enquanto o espaco de memoria continua com seu tamanho anterior a insercao

*/
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

// ------------------------------------- ORDENACAO --------------------------------------//
/*
    FUNCAO ordenacao:
    
        Usa o algoritmo ShellSort para ordenar os campos na seguinte ordem de prioridade: estado, cidade e numero, conforme funcao comparaCandidatos

*/
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

/*
    FUNCAO ordenacaoCor:
    
        Usa o algoritmo ShellSort para ordenar os campos pela cor
        
*/
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

/*
    FUNCAO ordenacaoGenero:
        
        Usa o algoritmo ShellSort para ordenar os campos levando em consideracao o genero
        
*/
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

/*
    FUNCAO ordenacaoPartido:
        
        Usa o algoritmo ShellSort para ordenar os campos pelo partido
        
*/
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

/*
    FUNCAO ordenacaoNumero:
        
        Usa o algoritmo ShellSort para ordenar de acordo com o numero
        
*/
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

// ------------------------------------- BUSCAS --------------------------------------//
/*
    Funcoes de BuscaBinaria:

        - Como ideia central da busca binaria eh buscar os dados em um vetor ordenado, primeiro ordenamos o vetor apatir do tipo de dado que queremos encontrar, estado, cidade, 
        cor, numero, partido, genero etc. 
        - Depois realizamos a busca com uma funcao auxiliar que ai sim nos retorna a busca em si, como existem mais de um tipo de dado, por exemplo, existe mais de um candidato em SP 
        precisamos delitar o limite inferior e superior para realizara busca isso eh feito em comparacao com o elemento que achou na busca com os elemento "para tras" e "para frente". 
        - Tendo feito essa demilitacao realizamos a insercao desses elementos em um novo vetor criado e retornamos esse vetor ordenado pela funcao de ordenacao padrao.
        - Seguindo esse padrao, isso possibilita realizar mais de uma busca na mesma linha, apenas passando novos parametros para ela. 
*/

// Busca por Estado
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
    ordenacao(vet);

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

// Busca por Cidade
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

    ordenacao(resultado); 
    return resultado; 
}

// Busca por Numero
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

// Busca por Cor
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

// Busca por Genero
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

// Busca por Partido
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

// ------------------------------------- IMPRESSAO --------------------------------------//
/*
    FUNCAO imprimeVetorInteiro:

        A Funcao imprime Vetor Inteiro, impreme stodos os dados de um certo vetor de candidatos

*/
void imprimeVetorInteiro(VetorCandidatos *vet){
    if(vet == NULL) return;
    for(int i=0; i<vet->quant_elem;i++){
        imprimeCandidato(vet->vetCandidatos[i]);
    }
}