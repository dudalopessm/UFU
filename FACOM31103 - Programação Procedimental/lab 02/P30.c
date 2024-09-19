#include <stdio.h>

//Escreva um programa que leia o código do produto escolhido no cardápio de uma lanchonete e sua quantidade. Assim, o programa deve calcular o valor a ser pago por aquele lanche. Considere que a cada execução somente será calculado um pedido. 

int main () {

    int c, q;
    float p;

    printf("Digite o codigo do produto escolhido:\t");
    scanf("%d", &c);

    printf("Digite a quantidade do produto escolhido:\t");
    scanf("%d", &q);

    if(c == 100) {
        p = 1.2 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 101){
        p = 1.3 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 102) {
        p = 1.5 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 103) {
        p = 1.2 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 104) {
        p = 1.7 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 105) {
        p = 2.2 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else if (c == 106) {
        p = 1 * q;
        printf("O preco eh de %.2f para o produto %d na quantidade %d.\n", p, c, q);
    } else {
        printf("Codigo invalido.\n");
    }

    return 0;
}