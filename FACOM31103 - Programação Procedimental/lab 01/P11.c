#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Escreva um programa C que leia os catetos de um triângulo retângulo e calcule sua hipotenusa.

int main ()
{
    float a, b, c;
    printf("Digite o valor dos dois catetos do triangulo retangulo:\n");
    scanf("%f %f", &b, &c);

    a = sqrt (pow(b,2.0) + pow(c,2.0));

    printf("A hipotenusa do triangulo retangulo eh: %.2f.\n", a);

    system ("pause");
    return 0;
}