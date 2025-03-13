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
float fatorial(float a) {
    float result;
    result = 0;
    if (a <= 1) {
        return 1;
    } else {
        result = a * fatorial(a-1);
    }
    return result;
}
float serietaylor (float a, float b) {
    float result;
    if (b == 0) {
        return 1;
    } else {
        result = potencia(a,b)/fatorial(b);
        return result + serietaylor(a, b-1);
    }
    return result;
}
int main () {
    printf("\n\n######## Serie de Taylor ########");
    float x, n, r1, r2;
    printf("\n\nDigite o expoente da serie de Taylor: ");
    scanf("%f", &x);
    printf("\n\nDigite a aproximacao da serie de Taylor: ");
    scanf("%f", &n);
    r1 = serietaylor(x, n);
    printf("\n\nO resultado corresponde a: %.2f.", r1);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}