#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

/*
Referências:
- Função CenterText: - https://stackoverflow.com/questions/15312482/how-to-center-text-in-c-console
                     - https://learn.microsoft.com/en-us/windows/console/setconsolecursorposition?redirectedfrom=MSDN
                     - https://cboard.cprogramming.com/c-programming/163828-how-center-text-using-printf.html                     
*/

typedef struct candidato{
    char estadoCandidato[2];
    char cidadeCandidato[50];
    char numeroCandidato[10];
    char cargoCandidato[15];
    char nomeCandidato[60];
    char nomeNaUrna[60];
    char siglaPartido[10];
    char generoCandidato[20];
    char grauCandidato[20];
    char corCandidato[10];
}Candidato;

Candidato *criaCandidato(char *estado, char *cidade, char *num, char *cargo, char *nomeCandidato, char *nomeUrna, char *sigla, char *genero, char *grau, char *cor) {
    Candidato *end = malloc(sizeof(Candidato));
    strcpy(end->estadoCandidato, estado);
    strcpy(end->cidadeCandidato, cidade);
    strcpy(end->numeroCandidato, num);
    strcpy(end->cargoCandidato, cargo);
    strcpy(end->nomeCandidato, nomeCandidato);
    strcpy(end->nomeNaUrna, nomeUrna);
    strcpy(end->siglaPartido, sigla);
    strcpy(end->generoCandidato, genero);
    strcpy(end->grauCandidato, grau);
    strcpy(end->corCandidato, cor);
    return end;
}
char *getEstadoCandidato(Candidato *cand){
    return cand->estadoCandidato;
}
char *getCidadeCandidato(Candidato *cand){
    return cand->estadoCandidato;
}
char *getNumeroCandidato(Candidato *cand){
    return cand->numeroCandidato;
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

void destroiCandidato(Candidato *it) {
    free(it);
}

void imprimeCandidato(Candidato *it) {
    CenterText("Candidato");
    printf("\nNome: %s", it->nomeCandidato);
    printf("\nEstado: %s", it->estadoCandidato);
    printf("\nCidade: %s", it->cidadeCandidato);
    printf("\nNúmero: %s", it->numeroCandidato);
    printf("\nCargo almejado: %s", it->cargoCandidato);
    printf("\nNome na urna eleitoral: %s", it->nomeNaUrna);
    printf("\nSigla do partido: %s", it->siglaPartido);
    printf("\nGenero: %s", it->generoCandidato);
    printf("\nGrau de escolaridade: %s", it->grauCandidato);
    printf("\nCor do candidato: %s", it->corCandidato);
}

void CenterText(const char *text) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    int textLength = strlen(text);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    int posX = (consoleWidth - textLength) / 2;
    int posY = consoleInfo.dwCursorPosition.Y;
    COORD newPos;
    newPos.X = posX;
    newPos.Y = posY;
    SetConsoleCursorPosition(console, newPos);
    printf("%s", text);
}