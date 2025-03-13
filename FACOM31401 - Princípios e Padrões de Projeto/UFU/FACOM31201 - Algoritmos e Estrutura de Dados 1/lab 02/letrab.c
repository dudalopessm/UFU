#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
    printf("\n\n######## Matrizes dinamicas aleatorias ########");
    int **mat1, **mat2;
    mat1 = (int**)malloc(3*sizeof(int*));
    if (mat1 == NULL) return 0;
    mat2 = (int**)malloc(3*sizeof(int*));
    if (mat2 == NULL) return 0;
    srand(time(NULL));
    printf("\n\nPrimeira matriz:");
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        mat1[i] = (int*)malloc(3*sizeof(int));
        for (int j = 0; j < 3; j++) {
            mat1[i][j] = rand() % (99+1);
            printf(" %3d | ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n\nSegunda matriz:");
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        mat2[i] = (int*)malloc(3*sizeof(int));
        for (int j = 0; j < 3; j++) {
            mat2[i][j] = rand() % (99+1);
            printf(" %3d | ", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int **mat3;
    mat3 = (int**)malloc(3*sizeof(int*));
    if (mat3 == NULL) return 0;
    printf("\n\nTerceira matriz:");
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        mat3[i] = (int*)malloc(3*sizeof(int));
        for (int j = 0; j < 3; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
            printf(" %3d | ", mat3[i][j]);
        }
        printf("\n");
    }
    free(mat1);
    free(mat2);
    free(mat3);
    printf("\n");
    printf("\n\n######## Obrigada por usar! ########");
    printf("\n");
    return 0;
}