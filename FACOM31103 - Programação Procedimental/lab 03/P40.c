#include <stdio.h>

// Escreva um programa em C que leia 5 números inteiros e os armazene em um vetor. Imprima o vetor, o maior elemento e a posição que ele se encontra.

int main() {
    int vetor[5];
    int maior;
    int posicao;

    for (int i = 0; i < 5; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    posicao = 0;

    for (int i = 1; i < 5; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("Vetor inserido: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("O maior elemento equivale a %d e esta na posicao %d.\n", maior, posicao+1);

    return 0;

}