#include <stdio.h>
#include <string.h>
int idade (int n, int a) {
    return a - n;
}
int main () {
    printf("\n\n######## Adivinhador de idade ########");
    int nasc, atual, anos;
    char aniv[4];
    printf("\n\nDigite seu ano de nascimento: ");
    setbuf (stdin, NULL);
    scanf("%d", &nasc);
    printf("\n\nAgora, digite o ano atual: ");
    setbuf (stdin, NULL);
    scanf("%d", &atual);
    printf("\n\nJa fez aniversario? Digite sim ou nao: ");
    setbuf (stdin, NULL);
    fgets(aniv, 4, stdin);
    if (strcmp(aniv,"sim") == 0 || strcmp(aniv,"Sim") == 0 || strcmp(aniv,"SIM") == 0|| strcmp(aniv,"SIm") == 0 || strcmp(aniv,"SiM") == 0) {
        anos = idade(nasc, atual);
    } else {
        anos = idade(nasc, atual) - 1;
    }
    printf("\n\nCalculando sua idade...");
    printf("\n\nVoce tem %d anos e tera %d anos daqui 30 anos!", anos, anos + 30);
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}