#ifndef String_h
#define String_h
typedef struct str Str;
Str* str_cria(int n, char *frase);
void str_libera (Str* s);
void str_acessa (Str* s, int *n, char *frase);
void str_atribui (Str* s, int n, char *frase);
int tamanho(Str* s);
int contagem(Str *s, char a);
void str_exibe(Str* s);
#endif