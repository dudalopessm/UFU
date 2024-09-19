#include <stdio.h>
#include <stdlib.h>
#include "lab09b.h"
//Fernando Favaro 12311bcc006 --- Eduarda Lopes 12311bcc033

int main() {
    Fila *fila1 = criar();
    Fila *fila2 = criar();

    inserir(fila1, 1);
    inserir(fila1, -1);
    inserir(fila1, 10);
    inserir(fila1, -2);
    inserir(fila1, -10);
    inserir(fila1, 4);

    inserir(fila2, 5);
    inserir(fila2, 6);
    inserir(fila2, 7);
    inserir(fila2, 8);
    inserir(fila2, 9);
    inserir(fila2, 15);

    mostrar(fila1);
    mostrar(fila2);
    mostrar(intercala(fila1, fila2));
}