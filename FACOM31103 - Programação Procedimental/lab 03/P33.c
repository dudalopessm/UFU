#include <stdio.h>

// Faça um programa que leia 10 inteiros e imprima sua média.

int main () {

    int i, n;
    float media;

    n = 0;
    media = 0;

    for (i = 0; i < 10; i++) {
        printf("Escreva dez numeros inteiros:\t");
        scanf ("%d", &n);
        media = n + media; 
    }

    media = media / 2;

    printf("A media dos dez numeros digitados corresponde a %.2f", media);

    return 0;

}