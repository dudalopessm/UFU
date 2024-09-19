#include <stdio.h>
#include <stdlib.h>

//Leia um número inteiro e imprima o seu antecessor e o seu sucessor.

int main ()
{
    float n, ant, suc;
    printf("Digite um numero real:\n");
    scanf("%f", &n);

    ant = n - 1;
    suc = n + 1;

    printf("O antecessor desse numero eh %.1f e o seu sucessor eh %.1f.\n", ant, suc);
    
    system("pause");
    return 0;
}