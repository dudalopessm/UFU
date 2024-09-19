#include <stdio.h>
#include <stdlib.h>

// Leia um valor inteiro em segundos e imprima-o em horas, minutos e segundos.

int main ()

{
    int t, d, h, min, restomin, restod, restoh;

    printf("Digite quantos segundos para converter:\n");

    scanf("%d", &t);

    d = t / 86400;

    restod = t % 86400;

    h = restod / 3600;

    restoh = restod % 3600;

    min = restoh / 60;

    restomin = restoh % 60;

    printf("%d segundos equivale a %d dias, %d horas, %d minutos e %d segundos.\n", t, d, h, min, restomin);

    system("pause");

    return 0;

}
