#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
//#include <windows.h>
//#include <conio.h>
#include "Candidatos.h"
#include "VetorCandidatos.h"

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
  
int main(){
    VetorCandidatos *vet = lerArquivoVetor("database_aa.txt"); 

    VetorCandidatos *testes;

    /*
        testes = buscaBinariaGenero(buscaBinariaEstado(vet, "SP"), "MASCULINO");
    imprimeVetorInteiro(testes);
    */
   printf("\n---------------------------------------------------------------------------------------");
    //Buscar os dados dos candidatos de um dado estado
    printf("\nBuscar os dados dos candidatos de um dado estado");
    testes = buscaBinariaEstado(vet, "MG");
    imprimeVetorInteiro(testes);
    printf("\n---------------------------------------------------------------------------------------");
    //Dado um estado, buscar os dados dos candidatos de uma dada cidade
    printf("Dado um estado, buscar os dados dos candidatos de uma dada cidade");
    testes = buscaBinariaCidade(vet, "SAO PAULO", "SP");
    imprimeVetorInteiro(testes);
    printf("\n---------------------------------------------------------------------------------------");
    // Dado um estado e uma cidade, buscar os dados do(a) candidato(a) de um dado número
    printf("\nDado um estado e uma cidade, buscar os dados do(a) candidato(a) de um dado número");
    testes = buscaBinariaNumero(buscaBinariaCidade(vet, "SAO PAULO", "SP"), "10900");
    imprimeVetorInteiro(testes);
    printf("\n---------------------------------------------------------------------------------------");
    // obter listagens adicionais das informações dos candidatos: por gênero, por partido, ou por cor/raça.
    printf("\nBuscar os dados dos candidatos de dado genero de um dado estado");
    testes = buscaBinariaGenero(buscaBinariaEstado(vet, "SP"), "MASCULINO");
    imprimeVetorInteiro(testes);
    printf("\n---------------------------------------------------------------------------------------");
    printf("\nBuscar os dados dos candidatos de dado genero de uma dada cidade");
    testes = buscaBinariaGenero(buscaBinariaCidade(vet, "SAO PAULO", "SP"), "FEMININO");
    imprimeVetorInteiro(testes);
    printf("\nBuscar os dados dos candidatos de dado genero de um dado numero de uma cidade");
    testes = buscaBinariaGenero((buscaBinariaNumero(buscaBinariaCidade(vet, "SAO PAULO", "SP"), "10900")), "FEMININO");
    imprimeVetorInteiro(testes);
    printf("\nBuscar os dados dos candidatos de dado genero de um dado numero de um estado");
    testes = buscaBinariaGenero((buscaBinariaNumero(buscaBinariaEstado(vet, "SP"),"10900")), "FEMININO");
    imprimeVetorInteiro(testes);
    printf("\n---------------------------------------------------------------------------------------");

    printf("\n");
    system("pause");
    return 0;
}

/*
time_t iniBubbOrd;
time_t fimBubbOrd;
double tempo_totalBubbOrd;
iniBubbOrd = clock();
***********************************************
************ funcao a ser medida***************
***********************************************
fimBubbOrd = clock();
tempo_totalBubbOrd= (double)(fimBubbOrd-iniBubbOrd)/CLOCKS_PER_SEC;
*/