#include <stdio.h>
#include <stdlib.h>

//Peça ao usuário para digitar três valores inteiros e imprima a soma deles.

int main ()
{
    int x, y, z, soma;

    printf("Digite tres numeros inteiros:\n");

    scanf("%d %d %d", &x, &y, &z);
    
    soma = x + y + z;

    printf("O valor da soma de %d + %d + %d eh = %d.\n", x, y, z, soma);

    system("pause");
    return 0;
}