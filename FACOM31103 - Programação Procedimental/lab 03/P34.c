#include <stdio.h>

// Faça um programa que calcule e mostre a soma dos 50 primeiros números pares.

int main () {

    int i, n, soma;

    n = 0;
    soma = 0;

    for (i = 0; i < 50; i++) {
        n = n + 2;
        soma = n + soma;
    }

    printf("A soma dos 50 primeiros numeros pares corresponde a %d.\n", soma);

    return 0;
}