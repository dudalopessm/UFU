#include <stdio.h>
#include <string.h>
struct livro {
    char titulo[50];
    int ano, pag;
    float preco;
};
float media (int n, struct livro *Info) {
    float media;
    int soma;
    soma = 0;
    media = 0;
    for (int i = 0; i < n; i++) {
        soma = soma + Info[i].pag;
    }
    media = ((soma)/n);
    return media;
}
int main () {
    printf("\n\n######## Biblioteca digital ########");
    printf("\n\nDigite quantos livros voce quer armazenar: ");
    int n;
    scanf("%d", &n);
    struct livro Info[n];
    for (int i = 0; i < n; i++) {
        printf("\n\nDigite o titulo do %d livro: ", i + 1);
        setbuf (stdin, NULL);
        fgets(Info[i].titulo, 50, stdin);
        printf("\n\nDigite o ano do %d livro: ", i + 1);
        setbuf (stdin, NULL);
        scanf("%d", &Info[i].ano);
        printf("\n\nDigite quantas paginas o %d livro possui: ", i + 1);
        setbuf (stdin, NULL);
        scanf("%d", &Info[i].pag);
        printf("\n\nDigite o preço do %d livro: ", i + 1);
        setbuf (stdin, NULL);
        scanf("%f", &Info[i].preco);
        setbuf (stdin, NULL);
    }
    printf("\n\nA media do numero de paginas dos %d livros corresponde a: %.2f.", n, media(n, Info));
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}