#include <stdio.h>

// Faça um programa que leia 10 inteiros positivos, ignorando não positivos, e imprima sua média.

int main () {

    int i, n;
    float media, soma;

    soma = 0;

    printf("Digite 10 inteiros positivos:\n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &n);
        if (n < 0) {
            i--;
            soma = soma - n;
        }
        soma = soma + n; 
    }

    media = soma / 2;

    printf("O resultado da media desses numeros corresponde a %.2f.\n", media);

    return 0;

}