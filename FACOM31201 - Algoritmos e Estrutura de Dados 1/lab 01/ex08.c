#include <stdio.h>
#include <string.h>
int main () {
    printf("\n\n######## Detectador de letras iguais ########");
    printf("\n\nDigite uma palavra: ");
    int tam, rep, i, j;
    rep = 0;
    tam = 0;
    char s[50];
    setbuf (stdin, NULL);
    fgets(s, 50, stdin);
    tam = strlen(s);
    for (i = 0; i < tam; i++) {
        for (j = i + 1; j < tam; j++) {
            if (s[i] == s[j]) {
                printf("\n\nLetras repetidas: %c", s[i]);
                rep++;
            }
        }
    }
    printf("\n\nHouve %d letras repetidas.", rep);
    printf("\n\n######## Obrigada por usar o software! ########");
    return 0;
}