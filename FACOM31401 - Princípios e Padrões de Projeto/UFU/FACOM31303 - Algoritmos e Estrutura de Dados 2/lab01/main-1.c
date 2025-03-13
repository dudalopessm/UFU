#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atleta-1.h"
/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Menu adaptado do codigo disponivel em: https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/main.c
*/
void Inicio() {
    system("cls");
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\nShowcase de atletas baseado nos algoritmos BubbleSort e SelectionSort");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair");
    printf("\n1. Cadastrar atleta");
    printf("\n2. Ver lista de atletas");
    printf("\n3. Showcase em ordem de premiacao");
    printf("\n4. Showcase em ordem decrescente de medalhas");
    printf("\n5. Showcase em ordem alfabetica");
    printf("\n");
}
void Opcao() {
    printf("\nDigite a opcao desejada: ");
}
int main()
{
    int menuprincipal;
    int controle, op, aux, tam,metdOrd;
    ListaA *lA;
    lA = importarArqAtletas();
    Atleta p1;
    do {
        Inicio();
        Opcao();
        scanf("%d", &menuprincipal);
        system("cls");
        switch(menuprincipal) {
        case 0:
            system("cls");
            printf("\nObrigada por usar! Encerrando...");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.");
            break;
        case 1:
            system("cls");
            printf("\nInsira o nome: ");
            setbuf(stdin, NULL);
            fgets(p1.nome, 40, stdin);
            p1.nome[strcspn(p1.nome, "\n")] = '\0';
            setbuf(stdin, NULL);
            printf("\nInsira a nacionalidade: ");
            setbuf(stdin, NULL);
            fgets(p1.nacionalidade, 30, stdin);
            p1.nacionalidade[strcspn(p1.nacionalidade, "\n")] = '\0';
            setbuf(stdin, NULL);
            printf("\nInsira a quantidade de medalhas: ");
            scanf("%d", &p1.medalhas);
            printf("\nInsira a premiacao: ");
            scanf("%f", &p1.premiacao);
            controle = inserirAtleta(lA, p1);
            aux = exportarArqAtletas(lA, p1);
            system("cls");
            if (controle == 0) {
                printf("\nCadastro efetuado.");
                system("cls");
            } else {
                printf("\nErro ao cadastrar.");
                system("cls");
            }
            break;
        case 2:
            controle = 1;
            do {
                system("cls");
                printf("\n-------- Lista de atletas desorganizada --------");
                mostrarAtletas(lA);
                printf("\nPara retornar digite 0: ");
                scanf("%d", &controle);
            }while(controle == 1);
            system("cls");
            break;
        case 3:
            printf("Qual metodo de ordenacao?\n");
            printf("0. SelectionSort\n");
            printf("1. BubbleSort\n");
            scanf("%d", &metdOrd);
            if(metdOrd = 0)
            selectionSort(lA, 1);
            else
            bubbleSort(lA, 1);
            controle = 1;
            do {
                system("cls");
                printf("\n-------- Ordenacao por ordem crescente de premiacao --------");
                mostrarAtletas(lA);
                setbuf(stdin, NULL);
                printf("\nPara retornar digite 0: ");
                scanf("%d", &controle);
            }while(controle == 1);
            break;
        case 4:
            printf("Qual metodo de ordenacao?\n");
            printf("0. SelectionSort\n");
            printf("1. BubbleSort\n");
            scanf("%d", &metdOrd);
            if(metdOrd = 0)
            selectionSort(lA, 0);
            else
            bubbleSort(lA, 0);
            controle = 1;
            do {
                system("cls");
                printf("\n-------- Ordenacao por ordem decrescente de medalhas --------");
                mostrarAtletas(lA);
                printf("\nPara retornar digite 0: ");
                scanf("%d", &controle);
            }while(controle == 1);
            break;
        case 5:
            printf("Qual metodo de ordenacao?\n");
            printf("0. SelectionSort\n");
            printf("1. BubbleSort\n");
            scanf("%d", &metdOrd);
            if(metdOrd = 0)
            selectionSort(lA, 2);
            else
            bubbleSort(lA, 2);
            controle = 1;
            do {
                system("cls");
                printf("\n-------- Ordenacao por ordem alfabetica dos nomes --------");
                mostrarAtletas(lA);
                printf("\nPara retornar digite 0: ");
                scanf("%d", &controle);
            }while(controle == 1);
            break;
        }
    }while(menuprincipal);
    return 0;
}