#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include <string.h>
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
    printf("\n2. Grafo com 10 cidades aciclico");
    printf("\n3. Grafo com 10 cidades que possui ciclos");
}

void Opcao() {
    printf("\nDigite a opcao desejada: ");
}

int main(){
    Grafo *grafo50 = lerArquivoGrafo("grafo50Cidades.txt",50);
    Grafo *grafoAciclico = lerArquivoGrafo("grafoAciclico.txt",50);
    Grafo *grafoCiclico = lerArquivoGrafo("grafoCiclico.txt",50);
    Cidade c1 , c2;
    Peso p;
    int menuprincipal, controle, op, aux, tam;
    do {
        Inicio();
        Opcao();
        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        printf("Digite a distancia entre as cidades:");
                        setbuf(stdin, NULL);
                        scanf("%f", &p);
                        insereVertice(grafo50,&c2);
                        insereAresta(grafo50,c1,c2,p);
                        exibeGrafo(grafo50);
                        //inserção de aresta, mostrar que operação deu certo
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //inserção de aresta, mostrar que operação deu certo
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                         c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        printf("Digite a distancia entre as cidades:");
                        setbuf(stdin, NULL);
                        scanf("%f", &p);

                        insereVertice(grafoAciclico, &c1);
                        insereVertice(grafoAciclico, &c2);
                        insereAresta(grafoAciclico,c1,c2,p);
                        exibeGrafo(grafoAciclico);

                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //inserção de aresta, mostrar que operação deu certo
                          printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                         c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        printf("Digite a distancia entre as cidades:");
                        setbuf(stdin, NULL);
                        scanf("%f", &p);

                        insereVertice(grafoCiclico, &c1);
                        insereVertice(grafoCiclico, &c2);
                        insereAresta(grafoCiclico,c1,c2,p);
                        exibeGrafo(grafoCiclico);

                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';

                        removeAresta(grafo50,c1,c2);
                        exibeGrafo(grafo50);
                        
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //remoção de aresta, mostrar que operação deu certo

                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
    
                        removeAresta(grafoAciclico,c1,c2);
                        exibeGrafo(grafoAciclico);

                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //remoção de aresta, mostrar que operação deu certo
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                    
                        removeAresta(grafoCiclico,c1,c2);
                        exibeGrafo(grafoCiclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        //busca rodovia e informar quilometragem
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        arestaExiste(grafo50,c1,c2);

                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //busca rodoviar e informar quilometragem
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        arestaExiste(grafoAciclico,c1,c2);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //busca rodoviar e informar quilometragem
                        printf("Digite a primeira cidade:");
                        setbuf(stdin, NULL);
                        fgets(c1.nomecidade, 50, stdin);
                        printf("Digite a segunda cidade:");
                        setbuf(stdin, NULL);
                        fgets(c2.nomecidade, 50, stdin);
                        c1.nomecidade[strcspn(c1.nomecidade, "\n")] = '\0';
                        c2.nomecidade[strcspn(c2.nomecidade, "\n")] = '\0';
                        arestaExiste(grafoCiclico,c1,c2);

                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        exibe100(grafo50);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //listar cidades
                        exibe100(grafoAciclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //listar cidades
                        exibe100(grafoCiclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        buscaEmProfundidadeCores(grafo50);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //verificar ciclos do grafo
                        buscaEmProfundidadeCores(grafoAciclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //verificar ciclos do grafo
                        buscaEmProfundidadeCores(grafoCiclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
                setbuf(stdin, NULL);
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
                        exibeGrafo(grafo50);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 2:
                    do {
                        //visualizar grafo
                        exibeGrafo(grafoAciclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &controle);
                    }while(controle == 1);
                    break;
                case 3:
                    do {
                        //visualizar grafo
                        exibeGrafo(grafoCiclico);
                        printf("\nPara retornar digite 0: ");
                        setbuf(stdin, NULL);
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
    } while(menuprincipal);

    liberaGrafo(grafoAciclico);
    liberaGrafo(grafoCiclico);
    liberaGrafo(grafo50);

    return 0;
}