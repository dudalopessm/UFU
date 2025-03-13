#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void troca(char *frase, int t, int *q, char a) {
    int i;
    for (int i = 0; i < t; i++) {
        if (frase[i] == a) {
            frase[i] = '*';
            *q = *q + 1;
        }
    }
}
int main () {
    printf("\n\n######## Codificacao de string ########");
    int n, quant;
    quant = 0;
    printf("\n\nDigite o tamanho da string: ");
    setbuf(stdin, NULL);
    scanf("%d", &n);
    char *palavra, aux;
    palavra = (char*)malloc(n*sizeof(char));
    printf("\n\nInsira a string: ");
    setbuf(stdin, NULL);
    fgets(palavra, n, stdin);
    printf("\n\nInsira um caractere: ");
    scanf(" %c", &aux);
    n = strlen(palavra);
    troca(palavra, n, &quant, aux);
    printf("\n\nA quantidade de trocas foi %d.", quant);
    printf("\n\nA nova string corresponde a: %s", palavra);
    free(palavra);
    printf("\n\n######## Obrigada por usar! ########");
    return 0;
}