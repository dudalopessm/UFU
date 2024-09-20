#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Menu adaptado do codigo disponivel em: https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/main.c
Estrutura de Grafos adaptada do material do professor da USP Prof. Dr. Luciano Antonio Digiampietri, disponivel no site: https://www.each.usp.br/digiampietri/ACH2024
*/

void Inicio() {
    system("cls");
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\nShowcase de cidades e rodovias utilizando a estrutura de grafos");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair");
    printf("\n1. Inserir uma nova aresta");
    printf("\n2. Remover uma aresta");
    printf("\n3. Verificar se existe rodovia ligando duas cidades");
    printf("\n4. Listar todas as cidades que possuam ligacao direta com dada cidade de ate 100km de distancia");
    printf("\n5. Verificacao de ciclos em um dado grafo");
    printf("\n6. Visualizar os grafos existentes");
    printf("\n");
}

void InfoGrafos() {
    printf("\n-------- Informacoes sobre qual grafo escolher --------");
    printf("\nEm cada opcao o usuario devera escolher um grafo ja existente entre 3 opcoes descritas abaixo:");
    printf("\n1. Grafo com 50 cidades");
    printf("\n2. Grafo com 5 cidades aciclico");
    printf("\n3. Grafo com 5 cidades que possui ciclos");
}

void Opcao() {
    printf("\nDigite a opcao desejada: ");
}

int main(){
    int menuprincipal, controle, op, aux, tam;
    Grafo *g1, *g2, *g3;
    //g1 = importar50Cidades();
    //g2 = importarCidadesAciclico();
    //g3 = importarCidadesCiclico();
    do {
        Inicio();
        Opcao();
        scanf("%d", &menuprincipal);
        switch (menuprincipal)
        {
        case 0:
            system("cls");
            printf("\nObrigada por usar! Encerrando...");
            break;
        case 1: //inserir nova aresta
            system("cls");
            printf("\n******** Inserir uma nova aresta ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //inserção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //inserção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //inserção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        case 2: //remover dada aresta
            system("cls");
            printf("\n******** Remover dada aresta ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //remoção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //remoção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //remoção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        case 3: //verificar se existe rodovia  
            system("cls");
            printf("\n******** Verificar se existe rodovia e informar sua quilometragem ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //busca rodoviar e informar quilometragem
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //busca rodoviar e informar quilometragem
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //busca rodoviar e informar quilometragem
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        case 4: //listar todas as cidades em raio de 100km
            system("cls");
            printf("\n******** Listar todas as cidades em um raio de 100km ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //listar cidades
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //listar cidades
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //listar cidades
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        case 5: //verificação de ciclos de um grafo
            system("cls");
            printf("\n******** Verificar se um grafo existente possui ciclos ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //verificar ciclos do grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //verificar ciclos do grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //verificar ciclos do grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        case 6: //visualizar grafos existentes 
            system("cls");
            printf("\n******** Visualizar grafos existentes ********");
            InfoGrafos();
            do {
                Opcao();
                scanf("%d", &op);
                if(op <=0 || op > 3) {
                    controle = 0;
                    printf("\nOpcao invalida. Voce deve escolher um grafo existente. Tente novamente.");
                } else {
                    controle = 1;
                }
            }while(controle == 0);
            switch(op) {
                case 1:
                    do {
                        //visualizar grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //visualizar grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //visualizar grafo
                        printf("\nPara retornar digite 0: ");
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                default:
                    printf("\nOpcao de grafo invalida. Tente novamente.");
                    break;
            }
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.");
            break;
        }
    }while(menuprincipal);
    //liberar grafos aqui
    return 0;
}