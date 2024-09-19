#include <stdio.h>
#include <string.h>

// Uma empresa vende o mesmo produto para quatro diferentes estados. Cada estado possui uma taxa diferente de imposto sobre o produto (MG 7%; SP 12%; RJ 15%; MS 8%). Faça um programa em que  o usuário entre com o valor e o estado destino do produto e o programa retorne o preço final do produto acrescido do imposto do estado em que ele será vendido. Se o estado digitado não for válido,  mostrar uma mensagem de erro.

int main () {

    float p1, p2;
    char estado[3];

    printf("Digite o preco do produto:\t");
    scanf("%f", &p1);

    printf("Digite o estado de destino:\t");
    scanf("%s", &estado);

    if (strcmp(estado, "mg") == 0 || strcmp(estado, "MG") == 0 || strcmp(estado, "Mg") == 0 || strcmp(estado, "mG") == 0) {
        p2 = p1 * 1.07;
        printf("O preco final do produto para o estado %s equivale a %.2f.\n", estado, p2);
    } else if (strcmp(estado, "sp") == 0 || strcmp(estado, "SP") == 0 || strcmp(estado, "sP") == 0 || strcmp(estado, "Sp") == 0) {
        p2 = p1 * 1.12;
        printf("O preco final do produto para o estado %s equivale a %.2f.\n", estado, p2);
    } else if (strcmp(estado, "rj") == 0 || strcmp(estado, "RJ") == 0 || strcmp(estado, "Rj") == 0 || strcmp(estado, "rJ") == 0) {
        p2 = p1 * 1.15;
        printf("O preco final do produto para o estado %s equivale a %.2f.\n", estado, p2);
    }  else if (strcmp(estado, "ms") == 0 || strcmp(estado, "MS") == 0 || strcmp(estado, "Ms") == 0 || strcmp(estado, "mS") == 0) {
        p2 = p1 * 1.08;
        printf("O preco final do produto para o estado %s equivale a %.2f.\n", estado, p2);
    } else {
        printf ("Estado invalido. Digite um estado valido para o calculo.\n");
    }

    return 0;

}