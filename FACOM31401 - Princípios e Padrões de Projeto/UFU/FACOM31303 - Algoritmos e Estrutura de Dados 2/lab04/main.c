#include "Enderecos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018
*/

char arq[] = "database_Enderecos.txt";

void Inicio() {
    system("cls");
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\nImplementacao da busca binaria em arquivos");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair");
    printf("\n1. Ver database");
    printf("\n2. Procurar por um CEP");
    printf("\n");
}

void Opcao() {
    printf("\nDigite a opcao desejada: ");
}

int main(){
    printf("\nLendo arquivo...");
    VetorEndereco *vetEnd = lerArquivoEnderecos(arq);
    printf("\nLeitura concluida!");
    printf("\nOrdenando...");
    shellSort(vetEnd); // Informações do vetor serão ordenadas em ordem crescente de acordo com o CEP
    /*
    O algoritmo shellSort foi utilizado devido a sua maior rapidez em uma database extremamente longa, conforme o mostrado no site:
    https://www.toptal.com/developers/sorting-algorithms
    */
    printf("\nOrdenacao concluida!");
    Enderecos *aux;
    int menuprincipal, controle, op;
    char cepProcura[10];
    do {
        Inicio();
        Opcao();
        scanf("%d", &menuprincipal);
        switch(menuprincipal) {
            case 0: 
                system("cls");
                printf("\nObrigada por usar! Encerrando...");
                break;
            case 1:
                system("cls");
                printf("\n******** Todos os enderecos disponiveis ********");
                do {
                    mostrarTela(vetEnd);
                    printf("\nPara retornar digite 0: ");
                    scanf("%d", &controle);
                }while(controle == 1);
                break;
            case 2:
                system("cls");
                printf("\n******** Procura por CEP ********");
                printf("\nDigite o CEP (formato 12345-678): ");
                setbuf(stdin, NULL);
                fgets(cepProcura, 10, stdin); 
                cepProcura[strcspn(cepProcura, "\n")] = '\0';
                printf("\nCEP inserido: %s\n", cepProcura);
                controle = 1;
                setbuf(stdin, NULL);
                aux = buscaBinaria(vetEnd, cepProcura);
                if(aux != NULL) {
                    do {
                        mostrarUni(aux);
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                } else {
                    do {
                        printf("\nEndereco nao encontrado!");
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                }
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.");
                break;
        }
    }while(menuprincipal);
    return 0;
}