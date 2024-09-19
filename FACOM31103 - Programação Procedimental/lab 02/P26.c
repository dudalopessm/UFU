#include <stdio.h>

//Usando switch, escreva um programa que leia um inteiro entre 1 e 7 e imprima o dia da semana correspondente a este numero. Isto é: domingo, se 1; segunda-feira, se 2; e assim por diante. 

int main () {
    
    int n;

    printf("Digite o numero inteiro correspondente ao dia da semana que deseja:\t");
    scanf("%d", &n);

    switch (n) {
        case 1:
        printf("O dia equivalente ao numero %d eh domingo.\n", n);
            break;
        case 2:
        printf("O dia equivalente ao numero %d eh segunda-feira.\n", n);
            break;
        case 3:
        printf("O dia equivalente ao numero %d eh terca-feira.\n", n);
            break;
        case 4:
        printf("O dia equivalente ao numero %d eh quarta-feira.\n", n);
            break;
        case 5:
        printf("O dia equivalente ao numero %d eh quinta-feira.\n", n);
            break;
        case 6:
        printf("O dia equivalente ao numero %d eh sexta-feira.\n", n);
            break;
        case 7:
        printf("O dia equivalente ao numero %d eh sabado.\n", n);
            break;
        default:
        printf("Numero invalido.\n");
    }
    
    return 0;
    
}
