#include <stdio.h>
int divisao(int a, int b, int *resto, int *resultado) {
    if (b == 0) {
        return -1;
    } else {
        *resultado = a/b;
        *resto = a%b;
        return 0;
    }
}
int main () {
    printf("\n\n######## Calculadora de divisao ########");
    int a, b, r, resultdiv, resultfunc;
    printf("\n\nDigite o numerador: ");
    scanf("%d", &a);
    printf("\n\nDigite o denominador: ");
    scanf("%d", &b);
    resultfunc = divisao(a, b, &r, &resultdiv);
    printf("\n\nA funcao retornara -1 se nao for possivel realizar a divisao e 0 se for possivel.");
    printf("\nRetorno da funcao: %d", resultfunc);
    if (resultfunc != -1) {
        printf("\n\nQuociente: %d e resto: %d.", resultdiv, r);
    }
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}