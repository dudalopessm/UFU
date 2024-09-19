#include <stdio.h>

// Escreva um programa que faça a leitura de vários números inteiros, até que se digite um número negativo. O programa tem que retornar o maior e o menor número lido.

int main () {

    int i, n, n1, n2;

    printf("Digite numeros inteiros:\t");
    scanf("%d", &n);

    n1 = n;
    n2 = n;

    if (n < 0) {
        printf("Nao existe menor e maior, pois o primeiro numero digitado nao eh positivo.\n");
    }

    for (i = 0; i < 1; i--) {
        printf("Digite numeros inteiros:\t");
        scanf("%d", &n);

        if (n > n1){
            n1 = n;
        } else if (n < n2) {
            n2 = n;
        } if (n < 0) {
            printf("O maior numero eh %d e o menor numero eh %d.\n", n1, n2); 
            break;
        }
    }

    return 0;

}
