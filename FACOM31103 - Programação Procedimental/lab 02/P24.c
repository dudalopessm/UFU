#include <stdio.h>

//Faça um programa que receba um número inteiro e verifique se este número é par ou ímpar. 

int main () {
    int n, p;

    printf("Digite um numero inteiro:\t");
    scanf("%d", &n);

    p = n % 2;

    if (p == 0)
    {
        printf("O numero %d eh par.\n", n);
    } else {
        printf("O numero %d eh impar.\n", n);
    }
    
    return 0;
    
}