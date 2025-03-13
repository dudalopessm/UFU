#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conjuntos.h"

int main () {
    printf("######## Conjuntos com TAD ########");
    Conj *con1, *con2;
    int *A, *B, tA, tB;
    //criando conjunto A
    printf("\n\n");
    scanf("%d", &tA);
    A = (int*)malloc(sizeof(int)*tA);
    printf("\n\n");
    for (int i = 0; i < tA; i++) {
        scanf("%d", &A[i]);
    }
    printf("\n\n");
    con1 = conj_cria(tA, A);
    free(A);
    conj_ver(con1);
    //criando conjunto B
    printf("\n\n");
    scanf("%d", &tB);
    B = (int*)malloc(sizeof(int)*tB);
    printf("\n\n");
    for (int i = 0; i < tB; i++) {
        scanf("%d", &B[i]);
    }
    printf("\n\n");
    con2 = conj_cria(tB, B);
    free(B);
    conj_ver(con2);
    printf("\n\n");
    //atribuicao de valores a conjuntos
    int C[3] = {7, 8, 19};
    int D[3] = {53, 81, 13};
    conj_atribuivet(con1, 3, C);
    printf("\n\n");
    conj_atribuivet(con2, 3, D);
    printf("\n\n");
    conj_ver(con1);
    printf("\n\n");
    conj_ver(con2);
    printf("\n\n");
    //remocao de valores de conjuntos
    conj_remove(con1, 4);
    conj_remove(con2, 2);
    conj_ver(con1);
    printf("\n\n");
    conj_ver(con2);
    printf("\n\n");
    //operacoes com conjuntos
    Conj *uni, *inter, *dif1, *dif2;
    uni = uniao(con1, con2);
    printf("\n\n");
    conj_ver(uni);
    printf("\n\n");
    inter = intersec(con1, con2);
    conj_ver(inter);
    printf("\n\n");
    dif1 = diferen(con1, con2);
    conj_ver(dif1);
    printf("\n\n");
    dif2 = diferen(con2, con1);
    conj_ver(dif2);
    printf("\n\n");
    //liberacao de memoria
    conj_libera(con1);
    conj_libera(con2);
    conj_libera(uni);
    conj_libera(inter);
    conj_libera(dif1);
    conj_libera(dif2);
    //fim
    printf("\n\n######## Obrigada por usar. ########");
    printf("\n\n");
    return 0;
}