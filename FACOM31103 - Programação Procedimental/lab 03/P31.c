#include <stdio.h>

// Escreva um programa que leia um número inteiro positivo e imprima os 5 primeiros múltiplos de 3 desse número.

int main(void) {

    int i, n, resto;

    printf("Escreva um numero:\t");
    scanf("%d", &n);

    resto = n % 3;

    printf("Os multiplos de %d e 3 sao:\n", n);

    for (i = 1; i < 6; i++) {
    if (resto == 0) {
        printf("%d", n*i);
    } else {
        printf("%d", n*3*i);
    } }

    return 0;

}
