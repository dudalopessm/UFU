#include <stdio.h>
#include <math.h>

//Leia um número real. Se o número lido for positivo, imprima a raiz quadrada; se for negativo, imprima o numero ao quadrado.

int main (){
    double n, n1, n2;

    printf("Digite um numero real:\n");
    scanf("%lf", &n);

    if (n > 0){
        n1 = sqrt(n);
        printf("A raiz quadrada de %.2lf equivale a %.2lf.\n", n, n1);
    } else {
        n2 = pow(n, 2.0);
        printf("O numero %.2lf ao quadrado equivale a %.2lf.\n", n, n2);
    }
    
    return 0;
}