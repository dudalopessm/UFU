#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void contarepetidos(char *text, int t, int *quant, char *repetidos, int *t1, char *naorepet, int *t2) {
    int i, j, k, naorep, aux, aux1, aux2;
    aux1 = 0;
    aux2 = 0;
    for (i = 0; i < t; i++) {
        naorep = 0;
        for (j = i + 1; j < t; j++) {  
            if (text[i] == text[j]) {
                *quant += 1;
                aux = *quant;
                for (k = 0; k < *t1; k++) {
                    if (text[i] == repetidos[k]) {
                       *quant -= 1;
                    } 
                } if (*quant == aux) {
                    repetidos[aux1] = text[i];
                    repetidos[aux1+1] = '\0';
                    *t1 = strlen(repetidos);
                    *t1 += 1;
                    repetidos = (char*)realloc(repetidos, *t1);
                    aux1++;
                    naorepet[aux2] = text[i];
                    naorepet[aux2+1] = '\0';
                    *t2 = strlen(naorepet);
                    *t2 += 1;
                    naorepet = (char*)realloc(naorepet, *t2);
                    aux2++;
                } 
            }
        }
        for (k = 0; k < *t2; k++) {
            if (text[i] == repetidos[k]) {
                naorep += 1;
            } if (text[i] == naorepet[k]) {
                naorep += 1;
            }
        } if (naorep == 0) {
            naorepet[aux2] = text[i];
            naorepet[aux2+1] = '\0';
            *t2 = strlen(naorepet);
            *t2 += 1;
            naorepet = (char*)realloc(naorepet, *t2);
            aux2++;
        }
    }
}
int contagemcaract(char *original, int t1, char *semr, int t2, int *quant, int *tam3, char *repetidos, int t3) {
    int i, j, aux1, rep, aux2;
    quant = (int*)realloc(quant, t2);
    *tam3 = t2;
    for (i = 0; i < t2; i++) {
        aux1 = 0;
        rep = 1;
        for (j = 0; j < t3; j++) {
            if (semr[i] == repetidos[j]) {
                aux1++;
            }
        }
        if (aux1 != 0) {
            for (j = i+1; j < t1; j++) {
                if (semr[i] == original[j]) {
                    rep++;
                }
            }
        }
        quant[i] = rep;
    }
}
int main () {
    printf("\n\n######## Manipulacao de strings ########");
    char *texto, *repet, *semrepet;
    int *quantidades;
    quantidades = (int*)malloc(400*sizeof(int));
    texto = (char*)malloc(400*sizeof(char));
    printf("\n\nDigite um texto qualquer: ");
    setbuf(stdin, NULL);
    fgets(texto, 400, stdin);
    int quantrep, tam, tam1, tam2, tam3;
    tam = strlen(texto);
    repet = (char*)malloc(400*sizeof(char));
    semrepet = (char*)malloc(400*sizeof(char));
    for (int i = 0; i < 400; i++) {
        repet[i] = '*';
        semrepet[i] = '*';
    }
    tam1 = strlen(repet);
    tam2 = strlen(semrepet);
    tam3 = 400;
    quantrep = 0;
    contarepetidos(texto, tam, &quantrep, repet, &tam1, semrepet, &tam2);
    tam2 = tam2 - 2;
    contagemcaract(texto, tam, semrepet, tam2, quantidades, &tam3, repet, tam1);
    printf("\n\nVetor de nao repetidos: \n%s\n", semrepet);
    for (int i = 0; i < tam2; i++) {
        printf("%d", quantidades[i]);
    }

    free(quantidades);
    free(semrepet);
    free(repet);
    free(texto);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}