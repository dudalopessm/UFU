#include <stdio.h>

// Faça um programa que receba dois números A e B e calcule a soma dos números pares desse intervalo de números, incluindo os números digitados.

int main () {

    int i, A, B, soma, restoA, restoB;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d", &A);
    scanf("%d", &B);

    soma = 0;
    restoA = A % 2;
    restoB = B % 2;

    if (restoA == 0 && restoB == 0) {
        soma = A + B;
        if (A < B) {
            for (A+=2; A < B; A+=2) {
                soma = soma + A;
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        } else if (A > B) {
            for (B+=2; B < A; B+=2) {
                soma = soma + B;
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        }
    } else if (restoA == 0 && restoB > 0) {
        soma = A;
        if (A < B) {
            for (A+=2; A < B; A+=2) {
                soma = soma + A;
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        } else if (A > B) {
            for (B; B < A; B++) {
                if (B % 2 == 0) {
                    soma = soma + B;
                }
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        }
    } else if (restoA > 0 && restoB == 0) {
        soma = B;
        if (A < B) {
            for (A; A < B; A++) {
                if (A % 2 == 0) {
                    soma = soma + A;
                }
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        } else if (A > B) {
            for (B+=2; B < A; B+=2) {
                soma = soma + B;
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        }
    } else if (restoA > 0 && restoB > 0) {
        soma = 0;
        if (A < B) {
            for (A; A < B; A++) {
                if (A % 2 == 0) {
                    soma = soma + A;
                }
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        } else if (A > B) {
            for (B; B < A; B++) {
                if (B % 2 == 0) {
                    soma = soma + B;
                }
            } printf("A soma dos numeros pares do intervalo de numeros digitado corresponde a %d.\n", soma);
        }
    }

    return 0;

}