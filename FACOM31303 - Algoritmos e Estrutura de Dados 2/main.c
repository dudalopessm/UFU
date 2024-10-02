#include "Enderecos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Lucas Matos Rodrigues 12311BCC024
Eduarda Lopes Santos Moura 12311BCC033
Matheus Vinicius Maximo Santos 12311BCC018

IMPLEMENTAÇÃO DE ÁRVORES UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> créditos ao professor André Backes
*/

/*
No programa principal:
1. Leia o arquivo texto completo e preencha uma ABB. Apresente pesquisas por CEP. Para cada CEP
encontrado, deve-se exibir na tela a respectiva entrada completa: CEP, sigla do estado, nome da cidade e endereço.
 Apresente a altura da ABB, a entrada completa do maior CEP e a entrada completa do menor CEP.
2. Leia as primeiras 20 linhas do arquivo texto e preencha uma ABB.
 Exiba os CEPs considerando os percursos central, préfixado e pós-fixado.
*/

char arq[] = "database_Enderecos.txt";

void Inicio() {
    //system("cls");
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\nImplementacao da busca binaria em arvores");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair");
    printf("\n1. Leia as primeiras 20 linhas do arquivo texto e preencha uma ABB. Exiba os CEPs considerando os percursos central, préfixado e pós-fixado.");
    printf("\n2. Procurar por um CEP.");
    printf("\n3. Apresente a altura da ABB, a entrada completa do maior CEP e a entrada completa do menor CEP.");
    printf("\n");
}

void Opcao() {
    printf("\nDigite a opcao desejada: ");
}

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}

int main() {
    Enderecos *aux;
    int menuprincipal = 1, controle, op;
    char cepProcura[10];
    Inicio();
    Opcao();
    scanf("%d", &menuprincipal);
    switch (menuprincipal) {
        case 0: {
            //system("cls");
            printf("\nObrigada por usar! Encerrando...");
            break;
        }
        case 1: {
            int menu1;
            ArvBin *arv20 = lerArquivoEnderecos(arq, 1);
            system("cls");
            printf("Selecione o tipo de percurso\n 1. Pre-fixado\n 2. Pos-fixado\n 3. Central\n");
            scanf("%d", &menu1);
            printf("\n******** Todos os enderecos disponiveis ********");
            switch (menu1) {
                case 1:
                    printf("\n**************PRE--FIXADO***************\n");
                    preOrdem_ArvBin(arv20);
                    break;
                case 2:
                    printf("\n**************POS-FIXADO***************\n");
                    posOrdem_ArvBin(arv20);
                    break;
                case 3:
                    printf("\n**************PERCURSOS CENTRAIS***************\n");
                    emOrdem_ArvBin(arv20);
                    break;
                default:
                    printf("\nOpcao invalida. Tente novamente.");
                    break;
            }
            break;
        }
        case 2: {
            ArvBin *arvEnd1 = lerArquivoEnderecos(arq, 0);
            system("cls");
            printf("\n******** Procura por CEP ********");
            printf("\nDigite o CEP (formato 12345-678): ");
            setbuf(stdin, NULL);                
            fgets(cepProcura, 10, stdin); 
            cepProcura[strcspn(cepProcura, "\n")] = '\0';
            printf("\nCEP inserido: %s\n", cepProcura);
            setbuf(stdin, NULL);
            aux = busca_ArvBin(arvEnd1, cepProcura);

            if (aux != NULL) {
                mostrarUni(aux);
            } else {
                printf("\nEndereco nao encontrado!");
            }
            break;
        }
        case 3: {
            ArvBin *arvEnd = lerArquivoEnderecos(arq, 0);
            system("cls");
            printf("\n******** Apresente a altura da ABB, a entrada completa do maior CEP e a entrada completa do menor CEP ********");
            int aux1;
            aux1 = altura_ArvBin(arvEnd);
            printf("\nAltura da ABB: %d", aux1);
            printf("\nMaior CEP: ");
            mostrarUni(maior_ArvBin(arvEnd));
            printf("\nMenor CEP: ");
            mostrarUni(menor_ArvBin(arvEnd));
            break;
        }
        default:
            printf("\nOpcao invalida. Tente novamente.");
            break;
    }
    return 0;
}

