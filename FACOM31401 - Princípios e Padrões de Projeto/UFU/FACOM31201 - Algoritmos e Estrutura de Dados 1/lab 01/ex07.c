#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
    printf("\n\n######## Matrizes ########");
    printf("\n\nA matriz gerada sera impressa.");
    printf("\n\nGerando...");
    printf("\n");
    int mat[5][10], aux[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            mat[i][j] = rand() % (99 + 1);
            printf("%3d | ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        aux[i] = 0;
        for (int j = 0; j < 10; j++) {
            aux[i] = mat[i][j] + aux[i];
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("\n\nA soma da linha %d corresponde a %d.", i + 1, aux[i]);
    }
    printf("\n");
    printf("\n\nMultiplicando cada elemento da matriz pela soma da linha correspondente...");
    printf("\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            mat[i][j] = aux[i] * mat[i][j];
            printf("%3d | ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n######## Obrigada por usar o software! ########");
    printf("\n");
    return 0;
}