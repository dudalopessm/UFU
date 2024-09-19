#include <stdio.h>
#include <stdlib.h>
int soma (int n) {
    int result;
    result = 0;
    if (n <= 1) {
        return 1;
    } else {
        result = n + soma(n-1);
    }
    return result;
}
int main () {
    printf("\n\n######## Somatorio de 1 a N ########");
    int N, r;
    printf("\n\nDigite um numero inteiro positivo: ");
    scanf("%d", &N);
    r = soma(N);
    printf("\n\nO resultado corresponde a %d.", r);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}