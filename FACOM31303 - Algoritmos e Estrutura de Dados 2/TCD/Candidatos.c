#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char *extrairToken(char *linha, char *token, const char *delimitador)
{
    strcpy(token, strtok(linha, delimitador));
    return token;
}

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

void destroiCandidato(Candidato *it) {
    free(it);
}

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