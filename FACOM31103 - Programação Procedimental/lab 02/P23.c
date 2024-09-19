#include <stdio.h>

//Receba o valor do salário de um trabalhador e o valor da prestação de um empréstimo. Se a prestação for maior que 30% do salário, imprima “Emprestimo nao concedido”. Caso contrário, imprima “Emprestimo concedido”.

int main () {
    float s, e, p;
    printf("Digite o valor do salario do trabalhador:\n");
    scanf("%f", &s);
    printf("Digite o valor da prestacao do emprestimo:\n");
    scanf("%f",&e);

    p = 1.3 * s;

    if(e > p){
        printf("Emprestimo nao concedido.\n");
    } else {
        printf("Emprestimo concedido.\n");
    }

    return 0;
}