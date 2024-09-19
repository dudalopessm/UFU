#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\n-------- Listas recursivas --------");
    Lista *li1;
    int aux = 0, list;

    //criacao da lista
    li1 = criar();
    Numeros l1 = {1};
    Numeros l2 = {2};
    Numeros l3 = {1};
    Numeros l4 = {3};
    Numeros l5 = {1};
    inserirInicio(li1, l1);
    inserirInicio(li1, l2);
    inserirInicio(li1, l3);
    inserirInicio(li1, l4);
    inserirInicio(li1, l5);
    printf("\nA lista corresponde a: ");
    mostrar(li1);
    printf("\n");

    //ultimo elemento
    int A, s;
    printf("\nO ultimo elemento da lista corresponde ao: ");
    A = UltimoElem(li1, &s);
    printf("%d.", s);

    //soma dos valores
    int B;
    B = Soma(li1);
    printf("\nA soma de todos os valores da lista corresponde a: %d.", B);

    //ordem reversa
    printf("\nElementos da lista em ordem reversa: ");
    Reverso(li1);

    //remocao de ocorrencias
    int D;
    D = RemocaoTodos(li1, 1);
    printf("\nAgora a lista apresenta-se na configuracao: ");
    mostrar(li1);

    //liberacao memoria
    limpar(li1);

    printf("\n");
    system("pause");
    return 0;
}