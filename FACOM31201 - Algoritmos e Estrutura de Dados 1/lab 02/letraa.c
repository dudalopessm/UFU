#include <stdio.h>
#include <stdlib.h>
int main () {
    printf("\n\n######## Alocacao dinamica ########");
    int *vet;
    vet = (int*)malloc(5*sizeof(int));
    if (vet == NULL) return 0;
    printf("\n\nEscreva 5 numeros inteiros: ");
    for (int i = 0; i < 5; i++) {
        setbuf(stdin, NULL);
        scanf("%d", &vet[i]);
    }
    printf("\n\nOs numeros digitados foram: |");
    for (int i = 0; i < 5; i++) {
        printf(" %d |", vet[i]); 
    }
    free(vet);
    printf("\n\n######## Obrigada por usar! ########");
    printf("\n");
    return 0;
}