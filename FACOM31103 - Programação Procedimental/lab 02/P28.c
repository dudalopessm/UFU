#include <stdio.h>

//Escreva o menu de opções, como no exemplo abaixo. Leia a opção do usuário, em seguida leia 2  números reais e execute a operação escolhida sobre eles. (Escreva uma mensagem de erro se a  opção for inválida.) 

int main () {

    int o;

    printf("A opcao 1 corresponde a operacao de soma.\n");
    printf("A opcao 2 corresponde a operacao de subtracao.\n");
    printf("A opcao 3 corresponde a operacao de multiplicacao.\n");
    printf("A opcao 4 corresponde a operacao de divisao.\n");

    printf("Escolha uma opcao de 1 a 4:\t");
    scanf("%d", &o);


    float n1, n2, s, dif, p, div;

    printf("Digite dois numeros reais:\t");
    scanf("%f %f", &n1, &n2);

    if (o == 1) {
        s = n1 + n2;
        printf("Sua escolha foi de somar os numeros %.2f e %.2f, que resulta em %.2f.\n", n1, n2, s);
    } else if (o == 2) {
        dif = n1 - n2;
        printf("Sua escolha foi de subtrair os numeros %.2f e %.2f, que resulta em %.2f.\n", n1, n2, dif);
    } else if (o == 3) {
        p = n1 * n2;
        printf("Sua escolha foi de multiplicar os numeros %.2f e %.2f, que resulta em %.2f.\n", n1, n2, p);
    }  else if (o == 4 && n2 ==0) {
        printf("Sua escolha foi de dividir os numeros %.2f e %.2f, mas como %.2f eh zero, a divisao nao pode ser executada.\n", n1, n2, n2);
    }  else if (o == 4) {
        div = n1 / n2;
        printf("Sua escolha foi de dividir os numeros %.2f e %.2f, que resulta em %.2f.\n", n1, n2, div);
    } else {
        printf("Opcao invalida - numero digitado deve estar entre 1 e 4.\n");
    }

    return 0;

}
