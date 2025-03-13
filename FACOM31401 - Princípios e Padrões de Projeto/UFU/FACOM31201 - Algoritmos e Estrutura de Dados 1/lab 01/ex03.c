#include <stdio.h>
int main () {
    printf("\n\n######## Calculadora para dois numeros reais ########");
    float n1, n2, res;
    char op;
    printf("\n\nDigite um operador aritmetico: ");
    setbuf (stdin, NULL);
    scanf("%c", &op);
    printf("\n\nAgora, digite o primeiro numero da operacao desejada: ");
    setbuf (stdin, NULL);
    scanf("%f", &n1);
    printf("\n\nDigite o segundo numero da operacao desejada: ");
    setbuf (stdin, NULL);
    scanf("%f", &n2);
    printf("\n\n\nCalculando seu resultado...");
    if (op == '+') {
        res = n1 + n2;
    } else if (op == '-') {
        res = n1 - n2;
    } else if (op == '*') {
        res = n2 * n1;
    } else if (op == '/') {
        if (n1 > n2) {
            res = n1 / n2;
        } else {
            res = n2 / n1;
        }
    } else {
        printf("\n\nOpcao invalida!");
    }
    printf("\n\nO resultado da operacao escolhida eh %.2f.", res);
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}