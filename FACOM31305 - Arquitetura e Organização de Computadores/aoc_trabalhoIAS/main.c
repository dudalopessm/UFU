#include <stdio.h>
#include <stdlib.h>
#define N 5
//vetor idades e vetor somas, somas = somatório de todas as idades do vetor idades menos a da posição em que está
int SomaPosteriores(int i, int vetor[], int n) {
    int s = 0;
    for (int j = i+1; j < n; j++) {
        s = s + vetor[j];
    }
    return s;
}
int SomaAnteriores(int i, int vetor[], int n) {
    int s = 0;
    for(int j = 0; j < i; j++) {
            s = s + vetor[j];
    }
    return s;
}
int main()
{
    printf("----- Somatoria de idades -----\n");
    int idades[N] = {10,14,16,18,13};
    int somas[N];
    int i, j, somatemp = 0;
    printf("\nVetor de idades: ");
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("| %d | ", idades[i]);
    }
    for (i = 0; i < N; i++) {
            somas[i] = SomaAnteriores(i,idades,N) + SomaPosteriores(i,idades,N);
    }
    printf("\nVetor de somas: ");
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("| %d | ", somas[i]);
    }
    return 0;
}
