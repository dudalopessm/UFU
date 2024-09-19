#include <stdio.h>
#include <math.h>

// Construa um programa que calcule a quantidade de meses necessários para que o valor pertencente a Bob iguale ou ultrapasse o valor pertencente a Alan.

int main () {

    int n;

    double ra, rb, va, vb;

    va = vb = 0;

    printf("Alan recebe um salario de R$3.000,00, enquanto Bob recebe um salario de R$2.000,00.\n");
    printf("Todo mes, Alan aplica metade de seu salario numa caderneta de poupanca, que rende 0.0039 ao mes, enquanto Bob aplica metade de seu salario em um fundo de acoes que lhe rende 0.05 ao mes.\n");
    printf("Quantos meses sao necessarios para o valor que Bob juntou ultrapasse ou iguale o valor de Alan?\n");

    for (n = 0; n >= 0; n++) {
        va = va + 1500 * pow(1.0039, n);
        vb = vb + 1000 * pow(1.05, n);
        if (vb >= va) {
            printf("Foram necessarios %d meses.\n", n);
            break;
        }
    }

    return 0;

}