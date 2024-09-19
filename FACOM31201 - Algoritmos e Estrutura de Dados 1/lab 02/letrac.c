#include <stdio.h>
#include <stdlib.h>
int main () {
    printf("\n\n######## Matrizes dinamicas user-friendly ########");
    int **mat, d1, d2;
    printf("\n\nEscreva a primeira dimensao da matriz: ");
    setbuf(stdin, NULL);
    scanf("%d", &d1);
    printf("\n\nEscreva a segunda dimensao da matriz: ");
    setbuf(stdin, NULL);
    scanf("%d", &d2);
    mat = (int**)malloc(d1*sizeof(int*));
    if (mat == NULL) return 0;
    for (int i = 0; i < d1; i++) {
        mat[i] = (int*)malloc(d2*sizeof(int));
        for (int j = 0; j < d2; j++) {
            printf("\n\nDigite a posicao %dx%d: ", i+1, j+1);
            setbuf(stdin, NULL);
            scanf("%d", &mat[i][j]);
        }
    }
   /* 
    printf("\n\nA matriz digitada foi:");
    printf("\n");
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            printf(" %3d | ", mat[i][j]);
        }
        printf("\n");
    }
    */
    
    float *media, n;
    n = 0;
    media = (float*)malloc(d1*sizeof(float));
    if (media == NULL) return 0;
    for (int i = 0; i < d1; i++) { 
        for (int j = 0; j < d2; j++) {
            n += mat[i][j];
            media[i] = n / (d1*1.0);
        }
        n = 0;
    }
    /*
    printf("\n\nO vetor que contem a media das linhas corresponde a: ");
    for (int i = 0; i < d1; i++) {
        printf(" %.2f ", media[i]);
    }
    */
   for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            printf("\n\nO elemento de posicao %dx%d (%d) diverge %.2f da media de sua linha.", i, j, mat[i][j], (mat[i][j] - media[i]));
        }
   }    
    free(media);
    free(mat);
    printf("\n\n######## Obrigada por usar! ########");
    printf("\n");
    return 0;
}