#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

struct str{
    int t;
    char *frase;
};

Str* str_cria(int n, char *frase) {
    Str* s = (Str*) malloc(sizeof(Str));
    if (s != NULL) {
        s->t = n;
        s->frase = frase;
    }
    return s;
}

void str_libera (Str* s) {
    free(s);
}

void str_acessa (Str* s, int *n, char *frase) {
    *n = s->t;
    *frase = s->frase[*n];
}

void str_atribui (Str* s, int n, char *frase) {
    s->t = n;
    s->frase = frase;
}

int tamanho(Str* s) {
    s->t = strlen(s->frase);
    return s->t;
}

int contagem(Str *s, char a) {
    int result;
    result = 0;
    for (int i = 0; i < (s->t); i++) {
        if ((s->frase[i]) ==  a) {
            result += 1;
        }
    }
    return result;
}

void str_exibe(Str* s) {
    printf("%s", (s->frase));
}
