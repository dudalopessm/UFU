#include <stdio.h>

//Faça um programa para verificar se um determinado número inteiro é divisível por 3 ou 5, mas não simultaneamente pelos dois.

int main () {

    int n, r3, r5;

    printf("Digite um numero inteiro:\t");
    scanf("%d", &n);

    r3 = n % 3;
    r5 = n % 5;

    if (r3 == 0 && r5 == 0) {
        printf("O numero %d eh divisivel por 3 e por 5.\n", n);
    } else if (r3 == 0 && r5 > 0) {
        printf("O numero %d eh divisivel apenas por 3.\n", n);
    } else if (r3 > 0 && r5 == 0) {
        printf("O numero %d eh divisivel apenas por 5.\n", n);
    } else {
        printf("O numero %d nao eh divisivel nem por 3 e nem por 5.\n", n);
    }

    return 0;

}