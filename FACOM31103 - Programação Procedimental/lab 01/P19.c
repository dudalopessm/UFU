#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Faça um programa para ler as dimensões de um terreno (comprimento C e largura L), bem como o preço do metro do arame, P. Calcule e imprima o custo para cercar o terreno com uma cerca de 5 fios.

int main ()
{
    float c, l, p, custo;
    printf("Digite o comprimento e a largura do terreno em metros:\n");
    scanf("%f %f", &c , &l);

    printf("Digite o preco por metro do arame:\n");
    scanf("%f", &p);

    custo = ((2*c)+(2*l))*5*p;

    printf("O custo para cercar o terreno com 5 fios desse arame eh %.2f.\n", custo);

    system("pause");
    return 0;
}