#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Levando em consideração o printf, faça uma programa que calcule e imprima a parte do prêmio a que cada amigo tem direito.

int main ()
{
    double n1, n2, n3;
    printf("Tres amigos jogaram na loteria. O valor da aposta foi de R$40,00, sendo que o primeiro amigo contribuiu com R$20,00, o segundo com R$15,00 e o terceiro com R$5,00. Caso eles ganhem o premio de R$27.000.000,00, concordaram em reparti-lo proporcionalmente ao valor da aposta pago por cada um.\n");

    n1 = 0.5 * 27000000;
    n2 = 0.375 * 27000000;
    n3 = 0.125 * 27000000;

    printf("O primeiro amigo recebera %.1lf, o segundo recebera %.1lf e o terceiro recebera %.1lf.\n", n1, n2, n3);

    system("pause");
    return 0;
}