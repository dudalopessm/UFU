#include <stdio.h>
int main () {
    printf("\n\n######## Bem vindo! ########");
    printf("\n\nDigite a quantidade de numeros que ira informar: ");
    int x, t = 0, r1 = 0, r2 = 0;
    setbuf (stdin, NULL);
    scanf("%d", &x);
    int v[x];
    printf("\n\nAssim que voce digitar 10, o loop para digitacao de numeros ira parar!");
    for (int i = 0; i < x; i++) {
        setbuf (stdin, NULL);
        printf("\n\nDigite o %d numero: ", i + 1);
        scanf("%d", &v[i]);
         if (v[i] == 10) {
            break;
        } else if (v[i] < 10) {
            r1 = r1 + 1;
        } else {
            r2 = r2 + v[i];
        }
        t = t + 1;
    }
    printf("\n\nCalculando...");
    printf("\n\nVoce digitou %d numeros!", t);
    printf("\n\nA soma gerada foi %d e voce digitou %d numeros menores que 10.", r2, r1);
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}