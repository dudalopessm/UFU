#include <stdio.h>
#include <stdlib.h>

//) Faça um programa que leia um número inteiro e o imprima, então leia um número real e também o imprima.

int main (void) 
{
    int x = 18;
    float y = 3.1415;

    printf("%d %.4f\n", x, y);
    printf("A variavel x tem valor igual a: %d.\n", x);
    printf("A variavel y tem valor igual a: %.4f.\n", y);

    system("pause");
    return 0;
}