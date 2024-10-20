#include <stdio.h>
#include <stdlib.h>

#define N 512

int main() {
    int **A, **B, **C;
    A = (double **)malloc(N * sizeof(double *));
    B = (double **)malloc(N * sizeof(double *));
    C = (double **)malloc(N * sizeof(double *));
    int soma;

    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    printf("Iniciando preenchimento...\n");
    int valor = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = valor;
            B[i][j] = valor;
            valor++;
        }
    }
    printf("\nMatriz A preenchida!\n");
    printf("\nMatriz B preenchida!\n");

    printf("\nIniciando multiplicacao de matrizes A*B pelo metodo IJK...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            soma = 0;
            for (int k = 0; k < N; k++) {
                soma = soma + (A[i][k] * B[k][j]);
            }
            C[i][j] = soma;
        }
    }

    printf("\nMetodo IJK concluido!");

    printf("\nIniciando multiplicacao de matrizes A*B pelo metodo IKJ...\n");
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            soma = 0;
            for (int j = 0; j < N; j++) {
                soma = soma + (A[i][k] * B[k][j]);
            }
            C[i][k] = soma;
        }
    }
    printf("\nMetodo IKJ concluido!");

    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    printf("\n");

    system("pause");
    return 0;
}
