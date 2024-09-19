#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conjuntos.h"

struct conjunto {
    int t;
    int *a;
};

Conj* conj_cria(int t, int *a) {
    Conj* con = (Conj*)malloc(sizeof(Conj));
    if (con != NULL) {
        con->t = t;
        con->a = malloc(t * sizeof(int));
        if (con->a != NULL) {
            memcpy(con->a, a, t * sizeof(int));
        } else {
            free(con);
            con = NULL;
        }
    }
    return con;
}

void conj_libera (Conj* con) {
    free(con);
}

void conj_atribuivet (Conj* con, int t, int *a) {
    int *aux, tamaux;
    tamaux = (con->t) + t;
    aux = (int*)malloc(sizeof(int)*tamaux);
    int i, j, k = 0, n = 0, tam = 0;
    for (i = 0; i < con->t; i++) {
        aux[k] = con->a[i];
        k++;
    }
    for (j = 0; j < t; j++) {
        int duplicate = 0;
        for (n = 0; n < k; n++) {
            if (a[j] == aux[n]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            aux[k] = a[j];
            k++;
        }
    }
    aux = (int*)realloc(aux, sizeof(int)*k);
    con->t = k;
    con->a = (int*)realloc(con->a, sizeof(int)*con->t);
    for (i = 0; i < con->t; i++) {
        con->a[i] = aux[i];
    }
    free(aux);
}

void conj_ver(Conj* con) {
    for (int i = 0; i < (con->t); i++) {
        printf(" %d", (con->a[i]));
    }
}

void conj_remove(Conj* con, int in) {
    int i;
    for  (i = in; i < ((con->t) - 1); i++) {
        (con->a[i]) = (con->a[i+1]);
    }
    con->a = (int*)realloc(con->a, sizeof(int)*((con->t) - 1));
    con->t = con->t - 1;
}

Conj* uniao(Conj* con, Conj* con2) {
    int tamu, *a;
    tamu = (con->t) + (con2->t);
    Conj *uni = conj_cria(tamu, a);
    int i, j, k = 0, n = 0, tam = 0;
    for (i = 0; i < con->t; i++) {
        uni->a[k] = con->a[i];
        k++;
    }
    for (j = 0; j < con2->t; j++) {
        int ach = 0;
        for (n = 0; n < k; n++) {
            if (con2->a[j] == uni->a[n]) {
                ach = 1;
                break;
            }
        }
        if (!ach) {
            uni->a[k] = con2->a[j];
            k++;
        }
    }
    uni->t = k;
    uni->a = (int*)realloc(uni->a,sizeof(int)*uni->t);
    return uni;
}

Conj* intersec(Conj* con, Conj* con2){
    int *a, ti;
    ti = (con->t) + (con2->t);
    Conj *inter = conj_cria(ti, a);
    int i, j, k = 0;
    for (i = 0; i < (con->t); i++) {
        for (j = 0; j < (con2->t); j++) {
            if ((con->a[i]) == (con2->a[j])) {
                inter->a[k] = con->a[i];
                k++;
            }
        }
    }
    inter->t = k;
    inter->a = (int*)realloc(inter->a, sizeof(int)*inter->t);
    return inter;
}

Conj* diferen(Conj* con, Conj* con2) {
    int *di;
    int tam = 0;
    int i, j;
    for (i = 0; i < con->t; i++) {
        int unique = 1;
        for (j = 0; j < con2->t; j++) {
            if (con->a[i] == con2->a[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            tam++;
        }
    }
    di = malloc(sizeof(int) * tam);
    if (!di) {
        return NULL;
    }
    int k = 0;
    for (i = 0; i < con->t; i++) {
        int unique = 1;
        for (j = 0; j < con2->t; j++) {
            if (con->a[i] == con2->a[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            di[k] = con->a[i];
            k++;
        }
    }
    Conj *dif = conj_cria(tam, di);
    free(di);
    return dif;
}