#include <stdio.h>
#include <stdlib.h>

//Efetue a leitura de um número inteiro e imprima o resultado do quadrado desse número.

int main ()
{
    int x, q;

    printf("Digite um numero inteiro:\n");
    scanf("%d", &x);

    q = x * x;

    printf("O quadrado do numero inteiro %d eh %d.\n", x, q);

    system("pause");
    return 0;

}