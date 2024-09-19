#include <stdio.h>

//Determine se um determinado ano lido é bissexto. Um ano é bissexto se for divisível por 400, ou se for divisivel por 4 e não for divisível por 100. Por exemplo: 1988, 1992, 1996.

int main () {
    int ano, resto1, resto2, resto3;

    printf("Digite o ano que deseja saber se eh bissexto:\n");
    scanf("%d", &ano);

    resto1 = ano % 400;
    resto2 = ano % 4;
    resto3 = ano % 100;

    if(resto1 == 0){
        printf("O ano %d eh bissexto.\n", ano);
    } else if (resto2 == 0 && resto3 > 0) {
        printf("O ano %d eh bissexto.\n", ano);
    } else {
        printf("O ano %d nao eh bissexto.\n", ano);
    }

    return 0;
}
