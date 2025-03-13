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
#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------- FUNCOES AUXILIARES --------------------------------------//
/*
    FUNCAO stripWhitespaceCand:

        A funcao cria pega uma string e retira os espacos em brancos da string e retorna a propria sting modificada sem os espacoes em brancos, 
        ela foi criada para casos especificos na manipuacao de strings

*/
char *stripWhitespaceCand(char *str)
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

/*
    FUNCAO extrairToken:

        A funcao extraiToken de delimita um parametro de parada para os valores de leitura dentro de um arquivo ao passar a linha e o delimitador esperado dentro da funcao rettornando assim a "palavra" do arquivo em questao, palavra se refere a um ponteiro para char com o conteudo lido
*/
char *extrairToken(char *linha, char *token, const char *delimitador)
{
    strcpy(token, strtok(linha, delimitador));
    return token;
}
// ------------------------------------- ESTRUTURA DE CANDIDATOS --------------------------------------//
/*
    ESTRUTURA CANDIDATO:
        Estrutura de candidato retirada do arquivo disponibilizado pela professora Maria Camila, contendo os daods correspondentes do candidato em questão
*/
typedef struct candidato{
    char estadoCandidato[3];
    char cidadeCandidato[50];
    char numeroCandidato[50];
    char cargoCandidato[50];
    char nomeCandidato[50];
    char nomeNaUrna[50];
    char siglaPartido[50];
    char generoCandidato[50];
    char grauCandidato[50];
    char corCandidato[50];
}Candidato;

// ------------------------------------- FUNCOES SOBRE CANDIDATOS --------------------------------------//
/*
    FUNCAO CRIA CANDIDATO:

        A funcao cria candidato, aloca memoria para um candidato e guarda nas suas variaveis os valores passados como parametro e depois realiza o retorno do ponteiro criado
*/
Candidato *criaCandidato(char *estado, char *cidade, char *num, char *cargo, char *nomeCandidato, char *nomeUrna, char *sigla, char *genero, char *grau, char *cor) {
    Candidato *end = malloc(sizeof(Candidato));
    if (end == NULL) {
        return NULL;  
    }
    strncpy(end->estadoCandidato, estado, sizeof(end->estadoCandidato) - 1);
    end->estadoCandidato[sizeof(end->estadoCandidato) - 1] = '\0';
    strncpy(end->cidadeCandidato, cidade, sizeof(end->cidadeCandidato) - 1);
    end->cidadeCandidato[sizeof(end->cidadeCandidato) - 1] = '\0';
    strncpy(end->numeroCandidato, num, sizeof(end->numeroCandidato) - 1);
    end->numeroCandidato[sizeof(end->numeroCandidato) - 1] = '\0';
    strncpy(end->cargoCandidato, cargo, sizeof(end->cargoCandidato) - 1);
    end->cargoCandidato[sizeof(end->cargoCandidato) - 1] = '\0';
    strncpy(end->nomeCandidato, nomeCandidato, sizeof(end->nomeCandidato) - 1);
    end->nomeCandidato[sizeof(end->nomeCandidato) - 1] = '\0';
    strncpy(end->nomeNaUrna, nomeUrna, sizeof(end->nomeNaUrna) - 1);
    end->nomeNaUrna[sizeof(end->nomeNaUrna) - 1] = '\0';
    strncpy(end->siglaPartido, sigla, sizeof(end->siglaPartido) - 1);
    end->siglaPartido[sizeof(end->siglaPartido) - 1] = '\0';
    strncpy(end->generoCandidato, genero, sizeof(end->generoCandidato) - 1);
    end->generoCandidato[sizeof(end->generoCandidato) - 1] = '\0';
    strncpy(end->grauCandidato, grau, sizeof(end->grauCandidato) - 1);
    end->grauCandidato[sizeof(end->grauCandidato) - 1] = '\0';
    strncpy(end->corCandidato, cor, sizeof(end->corCandidato) - 1);
    end->corCandidato[sizeof(end->corCandidato) - 1] = '\0';

    stripWhitespaceCand(end->estadoCandidato);
    stripWhitespaceCand(end->cidadeCandidato);
    stripWhitespaceCand(end->numeroCandidato);
    stripWhitespaceCand(end->cargoCandidato);
    stripWhitespaceCand(end->nomeCandidato);
    stripWhitespaceCand(end->nomeNaUrna);
    stripWhitespaceCand(end->estadoCandidato);
    stripWhitespaceCand(end->siglaPartido);
    stripWhitespaceCand(end->generoCandidato);
    stripWhitespaceCand(end->grauCandidato);
    stripWhitespaceCand(end->corCandidato);

    return end;
}

/*
    FUNCOES GET:

        As funcoes de get apenas realizam a operacao de retorno de dados do candidato, pois, como nao temos acesso a estrutura no header, nao temos como saber a priori, quais os 
        dados guardados nos candidatos
*/
char *getEstadoCandidato(Candidato *cand){
    return cand->estadoCandidato;
}
char *getCidadeCandidato(Candidato *cand){
    return cand->cidadeCandidato;
}
char *getNumeroCandidato(Candidato *cand){
    return cand->numeroCandidato;
}
char *getCargo(Candidato *cand){
    return cand->cargoCandidato;
}
char *getNomeCompleto(Candidato *cand){
    return cand->nomeCandidato;
}
char *getNomeUrna(Candidato *cand){
    return cand->nomeNaUrna;
}
char *getGrau(Candidato *cand){
    return cand->grauCandidato;
}
char *getGenero(Candidato *cand){
    return cand->generoCandidato;
}
char *getPartido(Candidato *cand){
    return cand->siglaPartido;
}
char *getCor(Candidato *cand){
    return cand->corCandidato;
}

// ------------------------------------- FUNCAO PARA COMPARACAO DE CANDIDATOS --------------------------------------//
/*
    FUNCAO comparaCandidatos:

        Funcao de comparação de candidatos, usando como parametro o estado, depois a cidade e por fim o número de candidato, essa função foi usada em ordenação dos dados e na inserção de dados nas estruturas de arvore AVL e ABB
        
*/
int comparaCandidatos(Candidato *a, Candidato *b) {
    int cmp = strcmp(getEstadoCandidato(a), getEstadoCandidato(b));
    if (cmp != 0) {
        return cmp;
    }
    cmp = strcmp(getCidadeCandidato(a), getCidadeCandidato(b));
    if (cmp != 0) {
        return cmp;
    }
    return strcmp(getNumeroCandidato(a), getNumeroCandidato(b));
}

/*
    FUNCAO destroiCandidato:

        Funcao de liberar o candidato a fim de quando quisermos espaço de memoria seja liberado de alguma das estruturas ela seja liberada corretamente
        
*/
void destroiCandidato(Candidato *it) {
    free(it);
}


// ------------------------------------- FUNCAO DE IMPRESSAO DE CANDIDATOS --------------------------------------//
/*
    FUNCAO imprimeCandidato:

        Funcao de imprimeCandidato imprime todos os dados de um dado candidato
        
*/
void imprimeCandidato(Candidato *candidato) {
        if (candidato == NULL) {
        printf("Candidato invalido.\n");
        return;
    }
    printf("\n\n");
    printf("\n%35s", "Candidato");
    printf("\n");
    printf("Estado:            %40s\n", candidato->estadoCandidato);
    printf("Cidade:            %40s\n", candidato->cidadeCandidato);
    printf("Cargo:             %40s\n", candidato->cargoCandidato);
    printf("Nome Completo:     %40s\n", candidato->nomeCandidato);
    printf("Nome de Urna:      %40s\n", candidato->nomeNaUrna);
    printf("Sigla do Partido:  %40s\n", candidato->siglaPartido);
    printf("Genero:            %40s\n", candidato->generoCandidato);
    printf("Grau de Instrucao: %40s\n", candidato->grauCandidato);
    printf("Cor/Raca:          %40s\n", candidato->corCandidato);
    printf("Numero:            %40s\n", candidato->numeroCandidato);
    printf("___________________________________________________________________");
    printf("\n\n");
}