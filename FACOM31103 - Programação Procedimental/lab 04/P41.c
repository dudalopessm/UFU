#include <stdio.h>

// Crie um programa que leia 5 valores inteiros e, em seguida, mostre na tela os valores lidos na ordem inversa.

int main () {

    int vetor[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor inserido: ");
    for (int i = 4; i > -1; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;

}
