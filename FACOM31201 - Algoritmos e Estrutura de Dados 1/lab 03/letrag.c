#include <stdio.h>
#include <stdlib.h>
void swap (int *a, int *b) {
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
void troca(int *vet, int t) {
    for (int i = 0; i < (t/2); i++) {
        swap(&vet[i], &vet[(t - 1) - i]);
    }
}
int main () {
    printf("\n\n######## Inversao com swap ########");
    int *vetor, n;
    printf("\n\nDigite o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = (int*)malloc(n*sizeof(int));
    printf("\n\nDigite o vetor: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    troca(vetor, n);
    printf("\n\nO vetor invertido corresponde a: ");
    for (int i = 0; i < n; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n\n######## Obrigada por usar! ########");
    free(vetor);
    return 0;
}