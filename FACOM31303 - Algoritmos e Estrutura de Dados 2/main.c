#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Candidatos.h"
#include "VetorCandidatos.h"
  
int main(){
    CenterText("teste");
    printf("\n");
    system("pause");
    return 0;
}

/*
time_t iniBubbOrd;
time_t fimBubbOrd;
double tempo_totalBubbOrd;
iniBubbOrd = clock();
***********************************************
************ funcao a ser medida***************
***********************************************
fimBubbOrd = clock();
tempo_totalBubbOrd= (double)(fimBubbOrd-iniBubbOrd)/CLOCKS_PER_SEC;
*/