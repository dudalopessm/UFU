#include <stdio.h>
#include <stdlib.h>

//Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h (quilômetros por hora).

int main ()
{
    float m, conversao = 3.6, k;
    printf("Digite uma velocidade em metros por segundo:");
    scanf("%f", &m);

    k = m * conversao;
    
    printf("A velocidade digitada em metros por segundo equivale a %f quando convertida para quilometros por hora.\n", k);

    system("pause");
    return 0;
}