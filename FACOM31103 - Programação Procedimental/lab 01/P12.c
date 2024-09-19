#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Faça um programa que leia o valor de um produto e imprima esse valor com um desconto de 15%.


int main ()
{
    float v, t;
    printf("Digite o valor do produto:\n");
    scanf("%f", &v);

    t = v * 0.85;

    printf("O valor do produto com desconto de 15 por cento aplicado eh %.2f.\n", t);

    system("pause");
    return 0;
}