#include <stdio.h>

// Faça um algoritmo que leia um número positivo e imprima seus divisores.
// Sabemos que os divisores positivos de um número natural n são todos os números naturais p, p > 0, tais que n dividido por p deixa resto zero.

int main () {

    int i, n, p, resto;

    p = 0;

    printf("Digite um numero positivo:\t");
    scanf ("%d", &n);

    printf("Seus divisores sao:\n");

    for (i = 1; i <= n / 2; i++) {
        resto = n % i;
        if (resto == 0) {
            p++;
            printf("%d ", i);
        } 
    }

    p++;

    printf("%d\n", n);
    printf("O total de divisores corresponde a %d.\n", p);

    return 0;

}