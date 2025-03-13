#include <stdio.h>
#include <math.h>
void calculaHexagono (float l, float *area, float *perimetro) {
    *area = 3*(l*l)*sqrt(3)/2;
    *perimetro = 6*l;
}
int main () {
    printf("\n\n######## Calculadora de area e perimetro de hexagono ########");
    float l, p, a;
    printf("\n\nDigite a medida do lado do hexagono: ");
    scanf("%f", &l);
    calculaHexagono(l, &a, &p);
    printf("\n\nA area corresponde a %.2f e o perimetro corresponde a %.2f.", a, p);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}