#include <stdio.h>
#include <stdlib.h>
float potencia(float a, float b) {
    float result;
    result = 0;
    if (b < 1) {
        return 1;
    } else {
        result = a * potencia(a, (b-1));
    }
    return result;
}
int main () {
    printf("\n\n######## Potenciacao por modularizacao ########");
    float x, y, r;
    printf("\n\nDigite o numero que sera a base: ");
    scanf("%f", &x);
    printf("\n\nDigite o numero que sera o expoente: ");
    scanf("%f", &y);
    r = potencia(x,y);
    printf("\n\nO resultado corresponde a: %.2f", r);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}