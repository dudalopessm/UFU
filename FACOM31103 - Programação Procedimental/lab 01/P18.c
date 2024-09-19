#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Leia o valor de um angulo em graus e apresente-o convertido em radianos.

int main ()
{
    double R,G;
    const double pi = 3.14159265359;

    printf("Digite o valor do angulo em graus:\n");
    scanf("%lf", &G);

    R = G * pi/180;

    printf("O angulo em radianos equivale a %.5lf.\n", R);

    system("pause");
    return 0;
}