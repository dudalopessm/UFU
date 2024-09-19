#include <stdio.h>
#include <stdlib.h>

//Efetue a leitura de três valores e apresente como resultado a soma dos quadrados dos três valores lidos.

int main ()
{
    float n1, n2, n3, soma;
    printf("Digite tres numeros reais:\n");
    scanf("%f %f %f", &n1, &n2, &n3);

    soma = (n1*n1)+(n2*n2)+(n3*n3);

    printf("O resultado da soma dos quadrados desses numeros eh:%.3f.\n", soma);
    
    system("pause");
    return 0;
}