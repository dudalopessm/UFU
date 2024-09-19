#include <stdio.h>
#include <stdlib.h>

//Leia um número inteiro e imprima a soma do sucessor de seu triplo com o antecessor de seu dobro.

int main ()
{
    float n, resultado;
    printf("Digite um numero real:\n");
    scanf("%f", &n);

    resultado = (3*n + 1) + (2*n - 1);

    printf("A soma entre o sucessor de seu triplo e o antecessor de seu dobro eh: %.2f.\n", resultado);

    system("pause");
    return 0;
}