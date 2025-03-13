#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"
int main () {
    printf("######## Strings com TAD ########");
    int tam, cont;
    char a;
    Str *str;
    str = str_cria(20, "Cachorro quente");
    printf("\n\nA string digitada foi: ");
    str_exibe(str);
    tam = tamanho(str);
    printf("\n\nO tamanho da string eh: %d.", tam);
    printf("\n\nMudando a string...");
    str_atribui(str, 30, "Cachorro quente eh bom");
    printf("\n\nA nova string corresponde a: ");
    str_exibe(str);
    a = 'c';
    cont = contagem(str, a);
    printf("\n\nO caractere 'c' aparece %d vezes.", cont);
    str_libera(str);
    printf("\n\n######## Obrigada por usar. ########");
    return 0;
}