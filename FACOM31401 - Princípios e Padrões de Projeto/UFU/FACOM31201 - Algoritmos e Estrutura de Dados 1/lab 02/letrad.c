#include <stdio.h>
#include <stdlib.h>
int impares (int t, int *vetor) {
    int resto, impar;
    resto = 0;
    impar = 0;
    for (int i = 0; i < t; i++) {
        resto = vetor[i] % 2;
        if (resto != 0) {
            impar++;
            } 
        }
    return impar;
}
int main () {
    printf("\n\n######## Vetor dinamico sem impares ########");
    int *vet, n;
    printf("\n\nDigite a quantidade de numeros que voce ira digitar: ");
    setbuf(stdin, NULL);
    scanf("%d", &n);
    vet = (int*)malloc(n*sizeof(int));
    if (vet == NULL) return 0;  
    for(int i = 0; i < n; i++) {
        printf("\n\nDigite o %d elemento do vetor: ", i + 1);
        setbuf(stdin, NULL);
        scanf("%d", &vet[i]);
    }
    int *aux, resto, imp;
    imp = impares(n, vet);
    aux = (int*)malloc((n-imp)*sizeof(int));
    if (aux == NULL) return 0; 
    for (int i = 0, j = 0; i < n; i++) {
        resto = vet[i] % 2;
        if (resto == 0) {
            aux[j] = vet[i];
            j++;
            } 
        }
    printf("\n\nVetor obtido: ");
    for (int i = 0; i < (n-imp); i++) {
        printf("|%d|", aux[i]);
    }
    printf("\n");
    free(vet);
    free(aux);
    printf("\n\n######## Obrigada por usar! ########");
    printf("\n");
    return 0;
}