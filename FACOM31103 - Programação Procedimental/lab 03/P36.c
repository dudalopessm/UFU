#include <stdio.h>

// Faça um programa que peça ao usuário para digitar 10 valores e some-os.

int main () {

    int i;
    float n, s;

    s = 0;

    printf("Digite 10 valores para serem somados:\n");

    for (i = 0; i < 10; i++) {
        scanf("%f", &n);
        s = s + n;
    }

    printf("A soma dos dez valores corresponde a %.2f.\n", s);

    return 0;

}