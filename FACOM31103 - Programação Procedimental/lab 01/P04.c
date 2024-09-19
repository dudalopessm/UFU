#include <stdio.h>
#include <stdlib.h>

//Leia um valor em reais e a cotação do dólar. Em seguida, imprima o valor correspondente em dólares.

int main ()
{
    float reais, dolar = 4.98, resultado;
    printf("Digite um valor em reais:\n");
    scanf("%f", &reais);

    resultado = reais * dolar;

    printf("O valor correspondente em dolares equivale a: %f.\n", resultado);

    system("pause");
    return 0;
}