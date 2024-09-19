#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Receba a altura do degrau de uma escada e a altura que se deseja subir. Calcule e imprima quantos degraus sao necessários para subir a escada toda.

int main ()
{
    int D, d, t;
    printf("Digite a altura do degrau da escada em que esta: \n");
    scanf("%d", &d);

    printf("Digite a altura do degrau da escada que deseja chegar: \n");
    scanf("%d", &D);

    t = D - d;

    printf("Sao necessarios subir %d degraus para subir a escada.\n", t);

    system("pause");
    return 0;
}