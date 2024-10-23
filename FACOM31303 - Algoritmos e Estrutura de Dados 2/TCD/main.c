/*
    TRABALHO DE BUSCA DE DADOS DE CANDIDATOS DA ELEICAO DE 2024
    GRUPO: Eduarda Lopes (12311BCC033), Lucas Matos (12311BCC) e Matheus
   Vinicius (12311BCC) PROFESSOR: Maria Camila DISCIPLINA: FACOM31303 -
   ALGORITMOS E ESTRUTURA DE DADOS 2 SEMESTRE: 2024.1 CRÉDITOS: - IMPLEMENTAÇÃO
   DE ÁRVORE BINÁRIA UTILIZADA:
   https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> créditos ao
   professor André Backes
              - IMPLEMENTAÇÃO DE ÁRVORE AVL UTILIZADA:
   https://www.facom.ufu.br/~backes/gsi011/Aula11ArvoreAVL.pdf-> créditos ao
   professor André Backes
              - FUNÇÃO AUXILIAR STRIPWHITESPACE:
   https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
   -> stackoverflow
*/
// ------------------------------------- BIBLIOTECAS
// --------------------------------------//
#include "ABBCandidatos.h"
#include "AVLCandidatos.h"
#include "Candidatos.h"
#include "VetorCandidatos.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// ------------------------------------- VARIÁVEIS GLOBAIS
// --------------------------------------//
#define true 1
#define false 0
char arq[] = "database_Eleicao.txt";
// ------------------------------------- FUNÇÕES
// --------------------------------------// função que verifica se a opção está
// dentro do intervalo dado
int verifica(int op, int i, int j) {
  if (op >= i && op <= j) {
    return true;
  } else
    return false;
}

// função que sinaliza a opção inválida
void opcaoInvalida() { printf("\nOpcao invalida. Tente novamente."); }

// função que determina a tela inicial do programa - pergunta ao usuário qual
// arquivo deseja carregar
char *Inicio() {
  int crtl;
  printf("\033[1;33m\n===================== BEM VINDO AO BUSCA CANDIDATOS "
         "======================\n\033[0m");
  int op = 0;

  do {
    printf("\nEscolha qual arquivo deseja carregar - o padrao corresponde a "
           "tabela de candidatos disponibilizada pelo TSE ");
    printf("\nDeseja carregar: \n");
    printf("\n1. O arquivo padrao \n");
    printf("\n2. O um novo arquivo \n ");
    printf("\nDigite o numero correspondente a opcao: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);
    crtl = verifica(op, 1, 2);
    if (!crtl) {
      opcaoInvalida();
    }
  } while (crtl != true);
  FILE *teste;
  do {
    if (op == 1) {
      return arq;
    } else {
      printf("\nDigite o caminho do arquivo: ");
      setbuf(stdin, NULL);
      char *end = (char *)malloc(sizeof(char) * 256);
      fgets(end, 256, stdin);
      end[strcspn(end, "\n")] = '\0';
      teste = fopen(end, "r");
      if (teste != NULL)
        fclose(teste);
      return end;
    }
  } while (teste != NULL);
  fclose(teste);
  return NULL;
}

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
// auxilia a escolha do usuário
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
    scanf(" %c", &opsub);
    while (getchar() != '\n')
      ;
    if (opsub == 'A' || opsub == 'a' || opsub == 'B' || opsub == 'b' ||
        opsub == 'C' || opsub == 'c' || opsub == 'D' || opsub == 'd') {
      controle = 1;
    } else {
      opcaoInvalida();
      controle = 0;
    }
  } while (!controle);
  if (opsub == 'A' || opsub == 'a')
    return 4;
  else if (opsub == 'B' || opsub == 'b')
    return 5;
  else if (opsub == 'C' || opsub == 'c')
    return 6;
  else if (opsub == 'D' || opsub == 'd')
    return 0;
  return 13;
}

// menu que captura qual opção de busca o usuário deseja
int menuBusca() {
  int op;
  int controle;
  printf("\n");
  printf("\033[1;32m===================== BUSCAR UM CANDIDATO "
         "======================\n\033[0m");
  printf("\n");
  printf("Casos disponiveis: ");
  printf("\n0. Sair do programa");
  printf("\n1. Buscar dados de um candidato de um estado");
  printf(
      "\n2. Dado um estado, buscar dados de um candidato de uma dada cidade");
  printf("\n3. Dado um estado e uma cidade, buscar dados de um candidato de um "
         "dado numero");
  do {
    printf("\nOpcao que deseja testar: ");
    scanf(" %d", &op);
    while (getchar() != '\n')
      ;
    controle = verifica(op, 0, 3);
    if (!controle) {
      opcaoInvalida();
    }
  } while (!controle);
  switch (op) {
  case 0:
    return 0;
  case 1:
    controle = escolherFiltro();
    if (controle == 0)
      return 1;
    return controle; // 4, 5 ou 6
  case 2:
    controle = escolherFiltro();
    if (controle == 0)
      return 2;
    return controle + 3; // 7, 8 ou 9
  case 3:
    controle = 0;
    if (controle == 0)
      return 3;
    return controle + 6; // 10, 11 ou 12
  }
  return 13;
}

// funções para retornar dados digitados - nomes de cidades, estados, partidos,
// numeros, etc
void maiusculo(char *palavra) {
  int i = 0;
  while (palavra[i] != '\0') {
    palavra[i] = toupper(palavra[i]);
    i++;
  }
}
char *digitaEstado() {
  printf("\nDigite o estado desejado (sigla com 2 letras): ");
  char *est = malloc(4 * sizeof(char));
  if (est == NULL)
    return NULL;
  scanf(" %s", est);
  while (getchar() != '\n')
    ;
  maiusculo(est);
  return est;
}
char *digitaCidade() {
  char *cid = malloc(50 * sizeof(char));
  if (cid == NULL)
    return NULL;
  printf("\nDigite a cidade desejada: ");
  scanf(" %[^\n]", cid);
  while (getchar() != '\n')
    ;
  maiusculo(cid);
  return cid;
}
char *digitaNumero() {
  char *num = malloc(100 * sizeof(char));
  if (num == NULL)
    return NULL;
  int i;
  printf("\nDigite o numero desejado: ");
  scanf(" %d", &i);
  // inteiro para string
  sprintf(num, "%i", i);

  return num;
}
char *digitaCor() {
    printf("\nDigite a cor desejada: ");
    char *cor = malloc(50*sizeof(char));
    if(cor == NULL)
        return NULL;
    scanf(" %[^\n]", cor);
      while (getchar() != '\n')
        ;
      maiusculo(cor);
    maiusculo(cor);
    return cor;
}
char *digitaGenero() {
  char *gen = malloc(50 * sizeof(char));
  if (gen == NULL)
    return NULL;
  printf("\nDigite o genero desejado: ");
  scanf(" %s", gen);
  while (getchar() != '\n')
    ;
  maiusculo(gen);
  return gen;
}
char *digitaPartido() {
  char *part = malloc(50 * sizeof(char));
  if (part == NULL)
    return NULL;
  printf("\nDigite o partido desejado: ");
  scanf(" %s", part);
  while (getchar() != '\n')
    ;
  maiusculo(part);
  return part;
}

// funções para o cálculo do tempo

void calculoTempo(time_t *timeInicial, time_t *timeFinal, double *time_total) {
  for (int i = 0; i < 3; i++) {
    time_total[i] = (double)(timeFinal[i] - timeInicial[i]) / CLOCKS_PER_SEC;
  }
  printf("====================================================\n");
  printf("|                  Estatisticas                    |\n");
  printf("====================================================\n");
  printf("|      ESTRUTURAS   |    Tempo (segundos)          |\n");
  printf("====================================================\n");
  printf("| Arvore AVL        |   %16.5lf           |\n", time_total[0]);
  printf("| Arvore Binaria    |   %16.5lf           |\n", time_total[1]);
  printf("| Vetor             |   %16.5lf           |\n", time_total[2]);
  printf("====================================================\n");
}

//__________________________________________________________________________________________________//

// ------------------------------------- MAIN
// --------------------------------------//
int main() {
  // parte inicial - mostra tela de inicio e marca os tempos de abertura de cada
  // estrutura de dados
  time_t *timeInicial = (time_t *)malloc(sizeof(time_t) * 3);
  time_t *timeFinal = (time_t *)malloc(sizeof(time_t) * 3);
  double *tempo_total = (double *)malloc(sizeof(double) * 3);

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

  // system("cls");
  printf("\nArquivo carregado nas estruturas de dados com sucesso!");
  printf("\n");
  calculoTempo(timeInicial, timeFinal, tempo_total);

  // ------------------------------------- BUSCAS
  // --------------------------------------//

  int opcaoBusca;
  opcaoBusca = -1;
  VetorCandidatos *retornoVet;
  ArvBin *retornoABB;
  ArvAVL *retornoAVL;
  char *estado, *cidade, *numero, *cor, *genero, *partido;

  while (opcaoBusca != 0) {
    opcaoBusca = menuBusca();
    switch (opcaoBusca) {
    case 0:
      printf("\nSaindo do programa...");
      break;
    case 1: // busca por estado somente
      // system("cls");
      printf("\033[1;37m\n===================== BUSCA POR ESTADO "
             "======================\n\033[0m");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaEstado(vet, estado);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);

      printf("\n");
      break;
    case 2: // busca por estado e cidade
      // system("cls");
      printf("\033[1;37m\n===================== BUSCA POR ESTADO E CIDADE "
             "======================\n\033[0m");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cidade = digitaCidade();
      if (cidade != NULL) {
        printf("\nCidade digitada: %s", cidade);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaCidade(vet, cidade, estado);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCidadeABB(retornoABB, cidade);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);

      break;
    case 3: // busca por numero dado um estado e cidade
      // system("cls");
      printf("\033[1;37m\n===================== BUSCA POR NUMERO DADO UM "
             "ESTADO E UMA CIDADE ======================\n\033[0m");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cidade = digitaCidade();
      if (cidade != NULL) {
        printf("\nCidade digitada: %s", cidade);
      }

      numero = digitaNumero();
      if (numero != NULL) {
        printf("\nNumero digitado: %s", numero);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaCidade(vet, cidade, estado);
      retornoVet = buscaBinariaNumero(retornoVet, numero);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCidadeABB(retornoABB, cidade);
      retornoABB = buscaNumeroABB(retornoABB, numero);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
      retornoAVL = buscaNumeroAVL(retornoAVL, numero);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);
      printf("\n");

      calculoTempo(timeInicial, timeFinal, tempo_total);

      break;
    case 4: // busca por cor dado apenas um estado
      // system("cls");
      printf("\n");
      printf("\033[1;96m===================== FILTRAR POR COR DADO UM ESTADO "
             "======================\033[0m\n");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cor = digitaCor();
      if (cor != NULL) {
        printf("\nCor digitada: %s", cor);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaEstado(vet, estado);
      retornoVet = buscaBinariaCor(retornoVet, cor);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCorRacaABB(retornoABB, cor);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCorRacaAVL(retornoAVL, cor);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);

      printf("\n");

      break;
    case 5: // busca por genero dado apenas um estado
      // system("cls");
      printf("\n");
      printf("\033[1;95m===================== FILTRAR POR GENERO DADO UM "
             "ESTADO ======================\033[0m\n");
      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      genero = digitaGenero();
      if (genero != NULL) {
        printf("\nGenero digitado: %s", genero);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaEstado(vet, estado);
      retornoVet = buscaBinariaGenero(retornoVet, genero);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaGeneroABB(retornoABB, genero);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaGeneroAVL(retornoAVL, genero);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);
      printf("\n");

      break;
    case 6: // busca por partido dado apenas um estado
      // system("cls");
      printf("\n");
      printf("\033[1;91m===================== FILTRAR POR PARTIDO DADO UM "
             "ESTADO ======================\033[0m\n");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      partido = digitaPartido();
      if (partido != NULL) {
        printf("\nPartido digitado: %s", partido);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaEstado(vet, estado);
      retornoVet = buscaBinariaPartido(retornoVet, partido);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaPartidoABB(retornoABB, partido);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaPartidoAVL(retornoAVL, partido);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);
      printf("\n");

      break;
    case 7: // busca por cor dado um estado e uma cidade
      // system("cls");
      printf("\n");
      printf("\033[1;96m===================== FILTRAR POR COR DADO UM ESTADO E "
             "UMA CIDADE ======================\033[0m\n");
      estado = digitaEstado();

      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cidade = digitaCidade();
      if (cidade != NULL) {
        printf("\nCidade digitada: %s", cidade);
      }

      cor = digitaCor();
      if (cor != NULL) {
        printf("\nCor digitada: %s", cor);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaCidade(vet, cidade, estado);
      retornoVet = buscaBinariaCor(retornoVet, cor);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCidadeABB(retornoABB, cidade);
      retornoABB = buscaCorRacaABB(retornoABB, cor);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
      retornoAVL = buscaCorRacaAVL(retornoAVL, cor);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);
      printf("\n");

      break;
    case 8: // busca por genero dado um estado e uma cidade
      // system("cls");
      printf("\n");
      printf("\033[1;95m===================== FILTRAR POR GENERO DADO UM "
             "ESTADO E UMA CIDADE ======================\033[0m\n");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cidade = digitaCidade();
      if (cidade != NULL) {
        printf("\nCidade digitada: %s", cidade);
      }

      genero = digitaGenero();
      if (genero != NULL) {
        printf("\nGenero digitado: %s", genero);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaCidade(vet, cidade, estado);
      retornoVet = buscaBinariaGenero(retornoVet, genero);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCidadeABB(retornoABB, cidade);
      retornoABB = buscaGeneroABB(retornoABB, genero);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
      retornoAVL = buscaGeneroAVL(retornoAVL, genero);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);

      printf("\n");

      break;
    case 9: // busca por partido dado um estado e uma cidade
      // system("cls");
      printf("\n");
      printf("\033[1;91m===================== FILTRAR POR PARTIDO DADO UM "
             "ESTADO E UMA CIDADE ======================\033[0m\n");

      estado = digitaEstado();
      if (estado != NULL) {
        printf("\nEstado digitado: %s", estado);
      }

      cidade = digitaCidade();
      if (cidade != NULL) {
        printf("\nCidade digitada: %s", cidade);
      }

      partido = digitaPartido();
      if (partido != NULL) {
        printf("\nPartido digitado: %s", partido);
      }

      timeInicial[0] = clock();
      retornoVet = buscaBinariaCidade(retornoVet, cidade, estado);
      retornoVet = buscaBinariaPartido(retornoVet, partido);
      timeFinal[0] = clock();

      timeInicial[1] = clock();
      retornoABB = buscaEstadoABB(bin, estado);
      retornoABB = buscaCidadeABB(retornoABB, cidade);
      retornoABB = buscaPartidoABB(retornoABB, partido);
      timeFinal[1] = clock();

      timeInicial[2] = clock();
      retornoAVL = buscaEstadoAVL(arv, estado);
      retornoAVL = buscaCidadeAVL(retornoAVL, cidade);
      retornoAVL = buscaPartidoAVL(retornoAVL, partido);
      timeFinal[2] = clock();

      printf("\033[1m\n========================== Vetor "
             "==========================\n\033[0m");
      imprimeVetorInteiro(retornoVet);
      printf("\033[1m\n========================== Arvore Binaria de Busca "
             "==========================\n\033[0m");
      emOrdem_ArvBin(retornoABB);
      printf("\033[1m\n========================== Arvore Balanceada - AVL "
             "==========================\n\033[0m");
      emOrdem_ArvAVL(retornoAVL);

      calculoTempo(timeInicial, timeFinal, tempo_total);

      printf("\n");

      break;
    default:
      printf("\nErro ao processar opcao no menu.");
      break;
    }
  }

  // ------------------------------------- LIBERAÇÃO ESTRUTURAS USADAS
  // --------------------------------------//

  // Strings auxiliares
  free(estado);
  free(cidade);
  free(numero);
  free(genero);
  free(cor);
  free(partido);

  // Estruturas de calculo de tempo
  free(timeInicial);
  free(timeFinal);
  free(tempo_total);

  // AVL, Arvore Binaria e vetor
  libera_ArvAVL(retornoAVL);
  libera_ArvBin(retornoABB);
  libera_vetor(retornoVet);
  libera_ArvAVL(arv);
  libera_ArvBin(bin);
  libera_vetor(vet);

  // -----------------------------------------------------------------------------------------------
  // // fim
  printf("\n");
  // system("pause");
  return 0;
}