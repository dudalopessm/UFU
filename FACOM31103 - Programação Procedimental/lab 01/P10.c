#include <stdio.h>
#include <stdlib.h>

//Leia o tamanho do lado de um quadrado e imprima como resultado a área do quadrado.

int main ()
{
    float l, area;
    printf("Digite o tamanho do lado do quadrado:\n");
    scanf("%f", &l);

    area = l * l;

    printf("A area do quadrado de lado %.2f equivale a %.2f.\n", l, area);
    system("pause");
    return 0;
}