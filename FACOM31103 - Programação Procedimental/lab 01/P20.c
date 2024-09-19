#include <stdio.h>
#include <stdlib.h>

//Implemente um programa em C que calcule o ano de nascimento de uma pessoa a partir de sua idade e do ano atual.

int main ()
{
    int a, i, nasc, nasc1;
    char c;

    printf("Voce ja fez aniversario? Digite y se sim ou n se nao.\n");
    scanf("%c", &c);

    printf("Digite a idade da pessoa:\n");
    scanf("%d", &i);

    printf("Digite o ano atual:\n");
    scanf("%d", &a);

    nasc = a - i;
    nasc1 = (a - i) - 1;

    if (c == 'n')  {
        printf("Seu ano de nascimento eh %d.\n", nasc1);
    } else {
        printf("Seu ano de nascimento eh %d.\n", nasc);
    }

    system("pause");
    return 0;
}
