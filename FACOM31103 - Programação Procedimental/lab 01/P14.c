#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Uma empresa contrata um encanador a R$ 30,00 por dia. Crie um programa que solicite o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo-se que são descontados 7.5% para imposto de renda.

int main ()
{
    float x, y;
    printf("Digite o numero de dias que o encanador trabalhou:\n");
    scanf("%f", &x);

    y = (30*x) * 0.925;

    printf("A quantia arrecadada pelo encanador foi de %.3f.\n", y);

    system("pause");
    return 0;
}