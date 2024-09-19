#include <stdio.h>

int main () {
    printf("\n\n######## Calculadora de fatorial ########");
    printf("\n\nEntre com o valor: ");
    int n;
    setbuf (stdin, NULL);
    scanf("%d", &n);
    int i, acc;
    acc = 1;
    for (i = n; i > 0; i--) {
        acc = acc * i;
    }
    printf("\n\nO valor do fatorial de %d eh %d.", n, acc);
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}