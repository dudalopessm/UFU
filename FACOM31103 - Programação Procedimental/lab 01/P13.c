#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Leia o salário de um funcionário, calcule e imprima o valor do novo salário sabendo que ele recebeu um aumento de 25%.

int main ()
{
    float s, t;
    printf("Digite o salario do funcionario:\n");
    scanf("%f", &s);

    t = s * 1.25;

    printf("O novo salario do funcionario sera %.2f.\n", t);
    
    system ("pause");
    return 0;
}