#include <stdio.h>
#include <stdlib.h>
#include "lab09c.h"
//Fernando Favaro 12311bcc006 --- Eduarda Lopes 12311bcc033

int main() {
    Fila *fila = criar();
    inserir(fila, 1);
    inserir(fila, -1);
    inserir(fila, 10);
    inserir(fila, -2);
    inserir(fila, -10);
    inserir(fila, 4);

    mostrar(fila);

    removeNegativos(fila);

    mostrar(fila);
}