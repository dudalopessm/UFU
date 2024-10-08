#include "Candidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <windows.h>
// #include <conio.h>

/*
Referências:
- Função CenterText: - https://stackoverflow.com/questions/15312482/how-to-center-text-in-c-console
                     - https://learn.microsoft.com/en-us/windows/console/setconsolecursorposition?redirectedfrom=MSDN
                     - https://cboard.cprogramming.com/c-programming/163828-how-center-text-using-printf.html                     
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

Candidato *criaCandidato(char *estado, char *cidade, char *num, char *cargo, char *nomeCandidato, char *nomeUrna, char *sigla, char *genero, char *grau, char *cor) {
    Candidato *end = malloc(sizeof(Candidato));
    if (end == NULL) {
        return NULL;  // Tratamento de erro se malloc falhar
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
    return end;
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
    printf("\n\n");
}
/*
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
*/