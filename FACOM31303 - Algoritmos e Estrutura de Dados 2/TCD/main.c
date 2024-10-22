// ------------------------------------- BIBLIOTECAS ---------------------------------------------------------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "Candidatos.h"
#include "VetorCandidatos.h"
#include "ABBCandidatos.h"
#include "AVLCandidatos.h"
// ------------------------------------- VARIÁVEIS GLOBAIS ------------------------------------------ //
#define true 1
#define false 0
/*
A. O usuário escolha um arquivo de texto para ser carregado nas estruturas de dados,
considerando cada um dos 3 casos citados. Após a carga dos dados nas estruturas, deve
ser exibido o tempo para cada uma. A função de inserção deverá ser modificada para
considerar a ordenação baseada em três campos como descrito acima.
B. O usuário escolha opções de busca de informações de candidatos:
B1) Buscar os dados dos candidatos de um dado estado
B2) Dado um estado, buscar os dados dos candidatos de uma dada cidade
B3) Dado um estado e uma cidade, buscar os dados do(a) candidato(a) de um
dado número
O resultado da busca deve ser exibido para as três situações programadas, assim como o
tempo de processamento da consulta. A função de busca deverá ser modificada para
considerar a ordenação baseada em três campos como descrito anteriormente.
C. Usando as funções criadas no item B, o usuário possa escolher obter listagens
adicionais das informações dos candidatos: por gênero, por partido, ou por cor/raça. 
*/
char arq[] = "database_Eleicao.txt";
// ------------------------------------- FUNÇÕES ---------------------------------------------------- //

/*__________________________________________________________________________________________________*/

// função que verifica se a opção está dentro do intervalo dado
int verifica (int op, int i, int j){
    if(op >=i && op <=j){
        return true;
    }
    else return false;
}

/*__________________________________________________________________________________________________*/

// função que sinaliza a opção inválida
void opcaoInvalida() {
    printf("\nOpcao invalida. Tente novamente.");
}

/*__________________________________________________________________________________________________*/

// função que determina a tela inicial do programa - pergunta ao usuário qual arquivo deseja carregar
char *Inicio() {
    int crtl;
    printf("\033[1;33m\n===================== BEM VINDO AO BUSCA CANDIDATOS ======================\n\033[0m");
    int op = 0;

    do {
    printf("\nEscolha qual arquivo deseja carregar - o padrao corresponde a tabela de candidatos disponibilizada pelo TSE ");
        printf("\nDeseja carregar: \n");
        printf("\n1. O arquivo padrao \n");
        printf("\n2. O um novo arquivo \n ");
        printf("\nDigite o numero correspondente a opcao: ");
        setbuf(stdin, NULL);
        scanf("%d",&op);
        crtl = verifica(op,1,2);
        if(!crtl) {
            opcaoInvalida();
        }
    }while(crtl!=true);
    FILE *teste;
        do{
            if(op == 1) {
                return arq;
            } 
            else {
                printf("\nDigite o caminho do arquivo: ");
                setbuf(stdin, NULL);
                char *end = (char *) malloc(sizeof(char)*256);
                fgets(end, 256, stdin);
                end[strcspn(end, "\n")] = '\0';
                teste = fopen(end, "r");
                if(teste != NULL) 
                    fclose(teste);
                    return end;
            }
        }while(teste != NULL);
    fclose(teste);
// aqui caso ficar fechando
return NULL;
}

/*__________________________________________________________________________________________________*/
/*
    SUMÁRIO DE RETORNOS DA FUNÇÃO
    0. sair
    1. busca por estado
    2. busca por cidade de um estado
    3. busca por numero de um candidato de uma cidade e estado
    4. filtro de cor da busca por estado
    5. filtro de genero da busca por estado
    6. filtro de partido da busca por estado
    7. filtro de cor da busca por cidade 
    8. filtro de genero da busca por cidade 
    9. filtro de partido da busca por cidade 
    10. filtro de cor da busca por numero
    11. filtro de genero da busca por numero
    12. filtro de partido da busca por numero
    13. erro
*/
int escolherFiltro() {
    char opsub;
    int controle;
    printf("\nDeseja adicionar algum filtro adicional?");
    printf("\n|-----------------------------------------------------|");
    printf("\n|                 Filtros adicionais                  |");
    printf("\n|-----------------------------------------------------|");
    printf("\n|  A) Filtrar candidatos por uma dada cor             |");
    printf("\n|  B) Filtrar os candidatos por um dado genero        |");
    printf("\n|  C) Filtrar os candidatos por um dado partido       |");
    printf("\n|  D) Nao desejo adicionar nenhum filtro              |");
    printf("\n|-----------------------------------------------------|");
    printf("\n");
    do {
        printf("\nQual opcao voce deseja? ");
        setbuf(stdin, NULL);
        scanf(" %c", &opsub);
        if (opsub == 'A' || opsub == 'a' || opsub == 'B' || opsub == 'b' || opsub == 'C' || opsub == 'c' || opsub == 'D' || opsub == 'd') {
            controle = 1;
        } else {
            opcaoInvalida();
            controle = 0;
        }
    }while(!controle);
    if (opsub == 'A' || opsub == 'a') return 4;
    else if (opsub == 'B' || opsub == 'b') return 5;
    else if (opsub == 'C' || opsub == 'c') return 6;
    else if (opsub == 'D' || opsub == 'd') return 0;
    return 13;
}
// menu que captura qual opção de busca o usuário deseja
int menuBusca() {
    int op;
    int controle;
    //system("cls");
    printf("\n");
    printf("\033[1;32m===================== BUSCAR UM CANDIDATO ======================\n\033[0m");
    printf("Casos disponiveis: ");
    printf("\n0. Sair do programa");
    printf("\n1. Buscar dados de um candidato de um estado");
    printf("\n2. Dado um estado, buscar dados de um candidato de uma dada cidade");
    printf("\n3. Dado um estado e uma cidade, buscar dados de um candidato de um dado numero");
    do {
        printf("\nOpcao que deseja testar: ");
        scanf("%d", &op);
        controle = verifica(op, 0, 3);
        if(!controle) {
            opcaoInvalida();
        } 
    }while(!controle);
    switch(op) {
        case 0:
            return 0;
        case 1:
            controle = escolherFiltro();
            if(controle == 0) return 1;
            return controle; // 4, 5 ou 6
        case 2:
            controle = escolherFiltro();
            if(controle == 0) return 2;
            return controle + 3; // 7, 8 ou 9
        case 3:
            printf("\nUm mesmo numero nao existe no mesmo estado e/ou cidade!");
            printf("\033[101;30m\nAtencao! Se algum filtro for aplicado, sera realizada uma busca geral - todas as cidades e estados estarao incluidos\033[0m\n");
            controle = escolherFiltro();
            if(controle == 0) return 3;
            return controle + 6; // 10, 11 ou 12
    }
    return 13;
}

/*__________________________________________________________________________________________________*/

// funções para retornar dados digitados - nomes de cidades, estados, partidos, numeros, etc
void maiusculo(char *palavra) {
    int i = 0;
    while(palavra[i] != '\0') {
        palavra[i] = toupper(palavra[i]);
        i++;
    }
}
char *digitaEstado() {
    printf("\nDigite o estado desejado (sigla com 2 letras): ");
    char *est = malloc(4 * sizeof(char));
    if(est == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(est, 4, stdin);
    setbuf(stdin, NULL);
    est[strcspn(est, "\n")] = '\0';
    maiusculo(est);
    return est;
}
char *digitaCidade() {
    printf("\nDigite a cidade desejada: ");
    char *cid = malloc(50*sizeof(char));
    if(cid == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(cid, 50, stdin);
    setbuf(stdin, NULL);
    cid[strcspn(cid, "\n")] = '\0';
    maiusculo(cid);
    return cid;
}
char *digitaNumero() {
    printf("\nDigite o numero desejada: ");
    char *num = malloc(50*sizeof(char));
    if(num == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(num, 50, stdin);
    setbuf(stdin, NULL);
    num[strcspn(num, "\n")] = '\0';
    maiusculo(num);
    return num;
}
char *digitaCor() {
    printf("\nDigite a cor desejada: ");
    char *cor = malloc(50*sizeof(char));
    if(cor == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(cor, 50, stdin);
    setbuf(stdin, NULL);
    cor[strcspn(cor, "\n")] = '\0';
    maiusculo(cor);
    return cor;
}
char *digitaGenero() {
    printf("\nDigite o genero desejado: ");
    char *gen = malloc(50*sizeof(char));
    if(gen == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(gen, 50, stdin);
    setbuf(stdin, NULL);
    gen[strcspn(gen, "\n")] = '\0';
    maiusculo(gen);
    return gen;
}
char *digitaPartido() {
    printf("\nDigite o partido desejado: ");
    char *part = malloc(50*sizeof(char));
    if(part == NULL)
        return NULL;
    setbuf(stdin, NULL);
    fgets(part, 50, stdin);
    setbuf(stdin, NULL);
    part[strcspn(part, "\n")] = '\0';
    maiusculo(part);
    return part;
}


/*__________________________________________________________________________________________________*/

// ------------------------------------- MAIN ---------------------------------------------------- //
int main(){
/*__________________________________________________________________________________________________*/
// parte inicial - mostra tela de inicio e marca os tempos de abertura de cada estrutura de dados
time_t *timeInicial = (time_t *)malloc(sizeof(time_t)*3);
time_t *timeFinal = (time_t *)malloc(sizeof(time_t)*3);
double *tempo_total = (double *)malloc(sizeof(double)*3);

char *endereco = Inicio();
timeInicial[0] = clock();
    ArvAVL *arv = lerArquivoAVL(endereco);
timeFinal[0] = clock();
timeInicial[1] = clock();
    ArvBin *bin = lerArquivoAbb(endereco);
timeFinal[1] = clock();
timeInicial[2] = clock();
    VetorCandidatos *vet = lerArquivoVetor(endereco);
timeFinal[2] = clock();

for(int i = 0; i < 4; i++){
    tempo_total[i]= (double)(timeFinal[i]-timeInicial[i])/CLOCKS_PER_SEC;
}

printf("\nArquivo carregado nas estruturas de dados com sucesso!");
printf("\n");
printf("====================================================\n");
printf("|                  Estatisticas                    |\n");
printf("====================================================\n");
printf("|   Estrutura de Dados    |    Tempo (segundos)    |\n");
printf("====================================================\n");
printf("| Arvore AVL        |   %16.3lf           |\n", tempo_total[0]);
printf("| Arvore Binaria    |   %16.3lf           |\n", tempo_total[1]);
printf("| Vetor             |   %16.3lf           |\n", tempo_total[2]);
printf("====================================================\n");

/*__________________________________________________________________________________________________*/
// realização das buscas na main

int opcaoBusca;
opcaoBusca = -1;
VetorCandidatos *retornoVet;
ArvBin *retornoABB;
ArvAVL *retornoAVL;
char *estado, *cidade, *numero, *cor, *genero, *partido;
/*
    SUMÁRIO DE RETORNOS DA FUNÇÃO
    0. sair
    1. busca por estado
    2. busca por cidade de um estado
    3. busca por numero de um candidato de uma cidade e estado
    4. filtro de cor da busca por estado
    5. filtro de genero da busca por estado
    6. filtro de partido da busca por estado
    7. filtro de cor da busca por cidade 
    8. filtro de genero da busca por cidade 
    9. filtro de partido da busca por cidade 
    10. filtro de cor da busca por numero
    11. filtro de genero da busca por numero
    12. filtro de partido da busca por numero
    13. erro
*/
while(opcaoBusca != 0) {
    opcaoBusca = menuBusca();
        switch(opcaoBusca) {
        case 0:
            printf("\nSaindo do programa...");
            break;
        case 1:
            system("cls");
            printf("\033[1;37m\n===================== BUSCA POR ESTADO ======================\n\033[0m");
            estado = digitaEstado();
            if(estado != NULL) {
                printf("\nEstado digitado: %s", estado);
            }
            retornoVet = buscaBinariaEstado(vet, estado);
            retornoABB = buscaEstadoABB(bin, estado);
            retornoAVL = buscaEstadoAVL(arv, estado);
            printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
            imprimeVetorInteiro(retornoVet);
            printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
            emOrdem_ArvBin(retornoABB);
            printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
            emOrdem_ArvAVL(retornoAVL);

        printf("\n");
        break;
    case 2:
        system("cls");
        printf("\033[1;37m\n===================== BUSCA POR ESTADO E CIDADE ======================\n\033[0m");
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        retornoVet = buscaBinariaCidade(vet, cidade, estado);
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 3:
        system("cls");
        printf("\033[1;37m\n===================== BUSCA POR NUMERO DADO UM ESTADO E UMA CIDADE ======================\n\033[0m");         estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        numero = digitaNumero();
        if(numero != NULL){
            printf("\nNumero digitado: %s", numero);
        }
        retornoVet = buscaBinariaCidade(vet,cidade,estado);
        retornoVet = buscaBinariaNumero(retornoVet, numero);

        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaNumeroABB(retornoABB, numero);

        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaNumeroAVL(retornoAVL, numero);
        
        
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 4:
        system("cls");
        printf("\n");
        printf("\033[1;96m===================== FILTRAR POR COR DADO UM ESTADO ======================\033[0m\n"); 
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cor = digitaCor();
        if(cor != NULL){
            printf("\nCor digitada: %s", cor);
        }
        retornoVet = buscaBinariaEstado(vet, estado);
        retornoVet = buscaBinariaCor(retornoVet, cor);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCorRacaABB(retornoABB, cor);
        
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCorRacaAVL(retornoAVL, cor);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 5:
        system("cls");
        printf("\n");
        printf("\033[1;95m===================== FILTRAR POR GENERO DADO UM ESTADO ======================\033[0m\n"); 
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        genero = digitaGenero();
        if(genero != NULL) {
            printf("\nGenero digitado: %s", genero);
        }
        retornoVet = buscaBinariaEstado(vet, estado);
        retornoVet = buscaBinariaGenero(retornoVet, genero);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaGeneroABB(retornoABB, genero);

        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaGeneroAVL(retornoAVL, genero);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 6:
        system("cls");
        printf("\n");
        printf("\033[1;91m===================== FILTRAR POR PARTIDO DADO UM ESTADO ======================\033[0m\n"); 
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        partido = digitaPartido();
        if(partido != NULL) {
            printf("\nPartido digitado: %s", partido);
        }
        retornoVet = buscaBinariaEstado(vet, estado);
        retornoVet = buscaBinariaPartido(retornoVet, partido);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaPartidoABB(retornoABB, partido);

        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaPartidoAVL(retornoAVL, partido);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 7:
        system("cls");
        printf("\n");
        printf("\033[1;96m===================== FILTRAR POR COR DADO UM ESTADO E UMA CIDADE ======================\033[0m\n"); 
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        cor = digitaCor();
        if(cor != NULL){
            printf("\nCor digitada: %s", cor);
        }
        retornoVet = buscaBinariaCidade(vet,cidade ,estado);
        retornoVet = buscaBinariaCor(retornoVet, cor);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaCorRacaABB(retornoABB, cor);
        
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaCorRacaAVL(retornoAVL, cor);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 8:
        system("cls");
        printf("\n");
        printf("\033[1;95m===================== FILTRAR POR GENERO DADO UM ESTADO E UMA CIDADE ======================\033[0m\n"); 
         estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        genero = digitaGenero();
        if(genero != NULL){
            printf("\nGenero digitado: %s", genero);
        }
        retornoVet = buscaBinariaCidade(vet,cidade ,estado);
        retornoVet = buscaBinariaGenero(retornoVet, genero);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaGeneroABB(retornoABB, genero);
        
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaGeneroAVL(retornoAVL, genero);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 9:
        system("cls");
        printf("\n");
        printf("\033[1;91m===================== FILTRAR POR PARTIDO DADO UM ESTADO E UMA CIDADE ======================\033[0m\n");
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        partido = digitaPartido();
        if(partido != NULL) {
            printf("\nPartido digitado: %s", partido);
        }
        retornoVet = buscaBinariaCidade(retornoVet, cidade, estado);
        retornoVet = buscaBinariaPartido(retornoVet, partido);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaPartidoABB(retornoABB, partido);

        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaPartidoAVL(retornoAVL, partido); 
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 10:
        system("cls");
        printf("\n");
        printf("\033[1;96m===================== FILTRAR POR COR DADO UM ESTADO, UMA CIDADE E UM NUMERO ======================\033[0m\n"); 
         estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitado: %s", cidade);
        }
        numero = digitaNumero();
        if(numero != NULL){
            printf("\nNumero digitado: %s", numero);
        }
        cor = digitaCor();
        if(cor != NULL){
            printf("\nCor digitada: %s", cor);
        }	
        retornoVet = buscaBinariaCidade(vet,cidade ,estado);
        retornoVet = buscaBinariaNumero(retornoVet, numero);
        retornoVet = buscaBinariaCor(retornoVet, cor);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaNumeroABB(retornoABB, numero);
        retornoABB = buscaCorRacaABB(retornoABB, cor);
        
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaNumeroAVL(retornoAVL, numero);
        retornoAVL = buscaCorRacaAVL(retornoAVL, cor);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 11:
        system("cls");
        printf("\n");
        printf("\033[1;95m===================== FILTRAR POR GENERO DADO UM ESTADO, UMA CIDADE E UM NUMERO ======================\033[0m\n"); 
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        numero = digitaNumero();
        if(numero != NULL){
            printf("\nNumero digitado: %s", numero);
        }
        genero = digitaGenero();
        if(genero != NULL){
            printf("\nGenero digitado: %s", genero);
        }
        retornoVet = buscaBinariaCidade(vet,cidade ,estado);
        retornoVet = buscaBinariaNumero(retornoVet, numero);
        retornoVet = buscaBinariaGenero(retornoVet, genero);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaNumeroABB(retornoABB, numero);
        retornoABB = buscaGeneroABB(retornoABB, genero);
        
        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaNumeroAVL(retornoAVL, numero);
        retornoAVL = buscaGeneroAVL(retornoAVL, genero);
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 12:
        system("cls");
        printf("\n");
        printf("\033[1;91m===================== FILTRAR POR PARTIDO DADO UM ESTADO, UMA CIDADE E UM NUMERO ======================\033[0m\n");
        estado = digitaEstado();
        if(estado != NULL) {
            printf("\nEstado digitado: %s", estado);
        }
        cidade = digitaCidade();
        if(cidade != NULL) {
            printf("\nCidade digitada: %s", cidade);
        }
        numero = digitaNumero();
        if(numero != NULL){
            printf("\nNumero digitado: %s", numero);
        }
        partido = digitaPartido();
        if(partido != NULL) {
            printf("\nPartido digitado: %s", partido);
        }
        retornoVet = buscaBinariaCidade(retornoVet, cidade, estado);
        retornoVet = buscaBinariaNumero(retornoVet, numero);
        retornoVet = buscaBinariaPartido(retornoVet, partido);
        
        retornoABB = buscaEstadoABB(bin, estado);
        retornoABB = buscaCidadeABB(retornoABB, cidade);
        retornoABB = buscaNumeroABB(retornoABB, numero);
        retornoABB = buscaPartidoABB(retornoABB, partido);

        retornoAVL = buscaEstadoAVL(arv, estado);
        retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
        retornoAVL = buscaNumeroAVL(retornoAVL, numero);
        retornoAVL = buscaPartidoAVL(retornoAVL, partido); 
        printf("\033[1m\n========================== Vetor ==========================\n\033[0m");
        imprimeVetorInteiro(retornoVet);
        printf("\033[1m\n========================== Arvore Binaria de Busca ==========================\n\033[0m");
        emOrdem_ArvBin(retornoABB);
        printf("\033[1m\n========================== Arvore Balanceada - AVL ==========================\n\033[0m");
        emOrdem_ArvAVL(retornoAVL);
        printf("\n");
        break;
    case 13:
        printf("\nErro ao processar opcao no menu.");
        break;
    }
}
/*__________________________________________________________________________________________________*/
// fim
printf("\n");
system("pause");
return 0;
/*__________________________________________________________________________________________________*/
}