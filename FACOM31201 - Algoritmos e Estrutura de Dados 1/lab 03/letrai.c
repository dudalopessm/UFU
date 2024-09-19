#include <stdio.h>
#include <stdlib.h>
void manipula(int *vetor, int t1, float *med, int *mai) {
    int i, j, soma;
    soma = 0;
    for (i = 0; i < t1; i++) {
        if (t1 == 1) {
            *mai = vetor[i];
        }
        for (j = i + 1; j < t1; j++) {
            if (vetor[i] >= vetor[j]) {
                *mai = vetor[i];
            } else {
                *mai = vetor[j];
            }
        }
        soma = soma + vetor[i];
    }
    *med = soma/t1;
}
int main () {
    printf("\n\n######## Media e maior valor de um vetor ########");
    int *vec, n, maior;
    float media;
    media = 0;
    maior = 0;
    printf("\n\nDigite o tamanho do vetor: ");
    scanf("%d", &n);
    vec = (int*)malloc(n*sizeof(int));
    printf("\n\nDigite o vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    printf("\n\nVetor digitado: ");
    for (int i = 0; i < n; i++) {
        printf("%d", vec[i]);
    }
    manipula(vec, n, &media, &maior);
    printf("\n\nA media corresponde a: %.2f e o maior valor corresponde a: %d.", media, maior);
    free(vec);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}
