#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018
*/

void mostrar(int vet[], int n){
    
    for(int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int bubbleSort(int vet[], int n, unsigned *trocas, unsigned int *comp){
    int trocou;
    int temp;
    for(int i = 0; i < n; i++){
        trocou = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(vet[j] > vet[j + 1]){
                temp       = vet[j];
                vet[j]     = vet[j + 1];
                vet[j + 1] = temp;
                *trocas = *trocas + 1;
                trocou = 1;
            }
            *comp = *comp + 1;
        }
        if(trocou == 0) break;
    }

    return 0;
}

int selectionSort(int vet[], int n, unsigned int *trocas, unsigned int *comp){
    int temp;
    int menor, i, j, flag = 0;
    for(i = 0; i < n - 1; i++){
        menor = i;

        for (j = i + 1; j <= n - 1; j++){
            if(vet[menor] > vet[j]){
                menor = j;
                flag = 1;
            }
            *comp = *comp + 1;
        }

        if(flag){
            temp       = vet[menor];
            vet[menor] = vet[i];
            vet[i]   = temp;
            *trocas = *trocas + 1;
            flag = 0;
        }
    }
    return 0;
}

int inserctionSort(int vet[], int n, unsigned int *trocas, unsigned int *comp){
    int i, j, temp;
    for(i = 1; i < n; i++){
        temp = vet[i];

        *comp = *comp + 1;
        for(j = i - 1; j>= 0 && vet[j] > temp; j--){
            vet[j+ 1] = vet[j];
            *trocas = *trocas + 1;
            *comp = *comp + 1;
        }
        vet[j + 1] = temp;
    }
    return 0;
}

int shellSort(int vet[], int n, unsigned int *trocas, unsigned int *comp){
    int j, i, h = 1;
    int temp;
    do {h = h * 3 + 1;} while(h < n);
    do{
        h /= 3;

        for(i = h; i < n; i++){
            temp = vet[i];
            j = i;
            *comp = *comp + 1;
            while(vet[j - h] > temp){
                vet[j] = vet[j - h];
                *trocas = *trocas + 1;
                j -= h;
                if(j < h) break;
                *comp = *comp + 1;
            }
            vet[j] = temp;

        }
    } while (h != 1);
    return 0;
}
int main (){
    //Criacao dos vetores necessarios
    int n = 10000;
    int *vetorOrdenado;
    int *vetorDecrescente;
    int *vetorAleatorios;
    vetorOrdenado = (int*)malloc(n*sizeof(int));
    vetorDecrescente = (int*)malloc(n*sizeof(int));
    vetorAleatorios = (int*)malloc(n*sizeof(int));
    //
    int *vetorOrdenado2;
    int *vetorDecrescente2;
    int *vetorAleatorios2;
    vetorOrdenado2 = (int*)malloc(n*sizeof(int));
    vetorDecrescente2 = (int*)malloc(n*sizeof(int));
    vetorAleatorios2 = (int*)malloc(n*sizeof(int));
    //
    int *vetorOrdenado3;
    int *vetorDecrescente3;
    int *vetorAleatorios3;
    vetorOrdenado3 = (int*)malloc(n*sizeof(int));
    vetorDecrescente3 = (int*)malloc(n*sizeof(int));
    vetorAleatorios3 = (int*)malloc(n*sizeof(int));
    //
    int *vetorOrdenado4;
    int *vetorDecrescente4;
    int *vetorAleatorios4;
    vetorOrdenado4 = (int*)malloc(n*sizeof(int));
    vetorDecrescente4 = (int*)malloc(n*sizeof(int));
    vetorAleatorios4 = (int*)malloc(n*sizeof(int));
    //
    srand(time(NULL));
    //Preenche os vetores
    for (int i=0; i<n; i++){
        int aux = rand()%500;
        vetorAleatorios[i]= aux;
        vetorAleatorios2[i]= aux;
        vetorAleatorios3[i]= aux;
        vetorAleatorios4[i]= aux;

        vetorOrdenado[i]= i+i;
        vetorOrdenado2[i]= i+i;
        vetorOrdenado3[i]= i+i;
        vetorOrdenado4[i]= i+i;

        vetorDecrescente[i]= n-(i*4);
        vetorDecrescente2[i]= n-(i*4);
        vetorDecrescente3[i]= n-(i*4);
        vetorDecrescente4[i]= n-(i*4);
    }

    unsigned int vetor_comp[12], vetor_trocas[12];

    for(int i = 0; i < 12; i++){
        vetor_trocas[i] = 0;
        vetor_comp[i] = 0;
    }

    //BubbleSort
    
    //Ordenado
    time_t iniBubbOrd;
    time_t fimBubbOrd;
    double tempo_totalBubbOrd;
    iniBubbOrd = clock();
    bubbleSort(vetorOrdenado, n, &vetor_trocas[0], &vetor_comp[0]);
    fimBubbOrd = clock();
    tempo_totalBubbOrd= (double)(fimBubbOrd-iniBubbOrd)/CLOCKS_PER_SEC;
    
    //Decrescente
    time_t iniBubbDec;
    time_t fimBubbDec;
    double tempo_totalBubbDec;
    iniBubbDec = clock();
    bubbleSort(vetorDecrescente, n, &vetor_trocas[1], &vetor_comp[1]);
    fimBubbDec = clock();
    tempo_totalBubbDec= (double)(fimBubbDec-iniBubbDec)/CLOCKS_PER_SEC;
    
    //Aleatorio 
    time_t iniBubbAle;
    time_t fimBubbAle;
    double tempo_totalBubbAle;
    iniBubbAle = clock();
    bubbleSort(vetorAleatorios, n, &vetor_trocas[2], &vetor_comp[2]);
    fimBubbAle = clock();
    tempo_totalBubbAle= (double)(fimBubbAle-iniBubbAle)/CLOCKS_PER_SEC;

    
    // SelectionSort

    //Ordenado
    time_t iniSelecOrd;
    time_t fimSelecOrd;
    double tempo_totalSelecOrd;
    iniSelecOrd = clock();
    selectionSort(vetorOrdenado2, n, &vetor_trocas[3], &vetor_comp[3]);
    fimSelecOrd = clock();
    tempo_totalSelecOrd= (double)(fimSelecOrd-iniSelecOrd)/CLOCKS_PER_SEC;
    
    //Decrescente
    time_t iniSelecDec;
    time_t fimSelecDec;
    double tempo_totalSelecDec;
    iniSelecDec = clock();
    selectionSort(vetorDecrescente2, n, &vetor_trocas[4], &vetor_comp[4]);
    fimSelecDec = clock();
    tempo_totalSelecDec= (double)(fimSelecDec-iniSelecDec)/CLOCKS_PER_SEC;
    
    //Aleatorio 
    time_t iniSelecAle;
    time_t fimSelecAle;
    double tempo_totalSelecAle;
    iniSelecAle = clock();
    selectionSort(vetorAleatorios2, n, &vetor_trocas[5], &vetor_comp[5]);
    fimSelecAle = clock();
    tempo_totalSelecAle= (double)(fimSelecAle-iniSelecAle)/CLOCKS_PER_SEC;
    
    // InsertionSort 

    //Ordenado
    time_t iniInsertOrd;
    time_t fimInsertOrd;
    double tempo_totalInsertOrd;
    iniInsertOrd = clock();
    inserctionSort(vetorOrdenado3, n, &vetor_trocas[6], &vetor_comp[6]);
    fimInsertOrd = clock();
    tempo_totalInsertOrd= (double)(fimInsertOrd-iniInsertOrd)/CLOCKS_PER_SEC;
    
    //Decrescente
    time_t iniInsertDec;
    time_t fimInsertDec;
    double tempo_totalInsertrtrtDec;
    iniInsertDec = clock();
    inserctionSort(vetorOrdenado3, n, &vetor_trocas[7], &vetor_comp[7]);
    fimInsertDec = clock();
    tempo_totalInsertrtrtDec= (double)(fimInsertDec-iniInsertDec)/CLOCKS_PER_SEC;
    
    //Aleatorio 
    time_t iniInsertAle;
    time_t fimInsertAle;
    double tempo_totalInsertAle;
    iniInsertAle = clock();
    inserctionSort(vetorAleatorios3, n, &vetor_trocas[8], &vetor_comp[8]);
    fimInsertAle = clock();
    tempo_totalInsertAle= (double)(fimInsertAle-iniInsertAle)/CLOCKS_PER_SEC;
    
    //ShellSort

    //Ordenado
    time_t iniShellOrd;
    time_t fimShellOrd;
    double tempo_totalShellOrd;
    iniShellOrd = clock();
    shellSort(vetorOrdenado4, n, &vetor_trocas[9], &vetor_comp[9]);
    fimShellOrd = clock();
    tempo_totalShellOrd= (double)(fimShellOrd-iniShellOrd)/CLOCKS_PER_SEC;
    
    //Decrescente
    time_t iniShellDec;
    time_t fimShellDec;
    double tempo_totalShellDec;
    iniShellDec = clock();
    shellSort(vetorDecrescente4, n, &vetor_trocas[10], &vetor_comp[10]);
    fimShellDec = clock();
    tempo_totalShellDec= (double)(fimShellDec-iniShellDec)/CLOCKS_PER_SEC;
    
    //Aleatorio 
    time_t iniShellAle;
    time_t fimShellAle;
    double tempo_totalShellAle;
    iniShellAle = clock();
    shellSort(vetorAleatorios4, n, &vetor_trocas[11], &vetor_comp[11]);
    fimShellAle = clock();
    tempo_totalShellAle= (double)(fimShellAle-iniShellAle)/CLOCKS_PER_SEC;

    //Tabelas
    
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("|                                        .::Tabela de tempos -  BubbleSort::.                                     |\n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| Entrada                     |      Tempo(s)             |      N. de comparacoes        |        N. de trocas   | \n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+------------------------+\n");
    printf("| 10.000 numeros ordenados    |    %.16lf     |          %u                 |              %u        |\n", tempo_totalBubbOrd, vetor_comp[0], vetor_trocas[0]);
    printf("| 10.000 numeros decrescentes |    %.16lf     |          %u            |         %u        |\n", tempo_totalBubbDec, vetor_comp[1], vetor_trocas[1]);
    printf("| 10.000 numeros aleatorios   |    %.16lf     |          %u            |         %u        |\n", tempo_totalBubbAle, vetor_comp[2], vetor_trocas[2]);
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("|                                        .::Tabela de tempos -  SeletionSort::.                                   |\n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| Entrada                     |      Tempo(s)             |      N. de comparacoes    |      N. de trocas   | \n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| 10.000 numeros ordenados    |    %.16lf     |          %u          |             %u       |\n", tempo_totalSelecOrd, vetor_comp[3], vetor_trocas[3]);
    printf("| 10.000 numeros decrescentes |    %.16lf     |          %u          |         %u        |\n", tempo_totalSelecDec, vetor_comp[4], vetor_trocas[4]);
    printf("| 10.000 numeros aleatorios   |    %.16lf     |          %u          |         %u        |\n", tempo_totalSelecAle, vetor_comp[5], vetor_trocas[5]);
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("|                                        .::Tabela de tempos -  InsertionSort::.                                  |\n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| Entrada                     |      Tempo(s)             |    N. de comparacoes   |    N. de trocas   | \n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| 10.000 numeros ordenados    |    %.16lf     |          %u          |         %u        |\n", tempo_totalInsertOrd, vetor_comp[6], vetor_trocas[6]);
    printf("| 10.000 numeros decrescentes |    %.16lf     |          %u          |         %u        |\n", tempo_totalInsertrtrtDec, vetor_comp[7], vetor_trocas[7]);
    printf("| 10.000 numeros aleatorios   |    %.16lf     |       %u         |      %u    |\n", tempo_totalInsertAle, vetor_comp[8], vetor_trocas[8]);
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("|                                        .::Tabela de tempos -  ShellSort::.                                      |\n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| Entrada                     |      Tempo(s)             |      N. de comparacoes   |        N. de trocas   | \n");
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    printf("| 10.000 numeros ordenados    |    %.16lf     |          %u           |            %u          |\n", tempo_totalShellOrd, vetor_comp[9], vetor_trocas[9]);
    printf("| 10.000 numeros decrescentes |    %.16lf     |          %u          |         %u         |\n", tempo_totalShellDec, vetor_comp[10], vetor_trocas[10]);
    printf("| 10.000 numeros aleatorios   |    %.16lf     |          %u          |         %u        |\n", tempo_totalShellAle, vetor_comp[11], vetor_trocas[11]);
    printf("+-----+--------+--------+-----+--------+--------+-----+--------+--------+-------------------+----------------------+\n");
    
    free(vetorOrdenado);
    free(vetorDecrescente);
    free(vetorAleatorios);
    free(vetorOrdenado2);
    free(vetorDecrescente2);
    free(vetorAleatorios2);
    free(vetorOrdenado3);
    free(vetorDecrescente3);
    free(vetorAleatorios3);
    free(vetorOrdenado4);
    free(vetorDecrescente4);
    free(vetorAleatorios4);
    system("pause");
    return 0;
}