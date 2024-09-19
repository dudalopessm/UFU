#include <stdio.h>
#include <stdlib.h>

//Leia quatro notas, calcule a média aritmética e imprima o resultado.

int main()
{
    float n1, n2, n3, n4, media;
    printf("Digite suas quatro notas:\n");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    media = (n1 + n2 + n3 + n4) / 2;

    printf("O resultado da media das quatro notas digitadas eh: %f.\n", media);

    system("pause");
    return 0;
}