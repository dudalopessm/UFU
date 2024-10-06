#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Estrutura de Grafos adaptada do material do professor da USP Prof. Dr. Luciano Antonio Digiampietri, disponivel no site: https://www.each.usp.br/digiampietri/ACH2024
*/

Grafo *lerArquivoGrafo(char *enderecoArquivo, int tamGrafo){ // no formato "<nome arquivo>.txt"
    FILE *arq = fopen(enderecoArquivo, "r");
    if(arq == NULL){
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    Cidade cidade01, cidade02;
    Peso peso;
    Grafo *g = criaGrafo();
    if(g == NULL) {
      printf("\nErro na criacao do grafo.");
      return NULL;
    }
    while (fscanf(arq, "%[^\n]\n%[^\n]\n%f\n", cidade01.nomecidade, cidade02.nomecidade, &peso) != EOF)
    {
      insereVertice(g, &cidade01);
      insereVertice(g, &cidade02);
      insereAresta(g, cidade01, cidade02, peso);
    }
    fclose(arq);
   return g;
}

int buscaPos(Grafo *g, Cidade cid){
if(g == NULL || g->A == NULL)
  return -1;
  for(int i=0; i<g->numVertices; i++){
    if(g->A[i] != NULL && g->A[i]->city.nomecidade != NULL && cid.nomecidade != NULL) {
      if (strcmp(cid.nomecidade,g->A[i]->city.nomecidade)==0) {
        printf("Encontrado na posicao %d\n", i);
        return i;
      }
    }
  }
  printf("\nCidade %s nao encontrada.", cid.nomecidade);
  return -1;
}

bool insereVertice(Grafo *g, Cidade *cidade) {
    if (g == NULL || cidade == NULL) {
        printf("Erro: Grafo ou cidade invalidos\n");
        return false;
    }
    if (buscaPos(g, *cidade) != -1) {
        printf("Vertice ja existe no grafo\n");
        return false;
    }
    if(g->A == NULL){
      g->A = (ElemLista**) malloc(sizeof(ElemLista*));
      if (g->A == NULL){
        printf("\nErro ao alocar memoria");
      }
    } else {
      g->A = (ElemLista**) realloc(g->A, sizeof(ElemLista*)*(g->numVertices+1));
    }
    g->A[g->numVertices] = (ElemLista*) malloc(sizeof(ElemLista));
    if (g->A[g->numVertices] == NULL) {
        printf("Erro: Falha na alocação de memoria\n");
        return false;
    }
    g->A[g->numVertices]->city = *cidade;
    g->A[g->numVertices]->peso = 0;
    g->A[g->numVertices]->prox = NULL;
    g->numVertices++;
    //printf("Vertice inserido com sucesso na posicao %d\n", g->numVertices - 1);
    return true;
}

Grafo *criaGrafo()
{
    Grafo *grafo = malloc(sizeof(Grafo));
    grafo->numArestas = 0;
    grafo->numVertices = 0;
    grafo->A = NULL;
    return grafo;
}

bool liberaGrafo(Grafo* g){
  if (g==NULL) return false;
  int x;
  ElemLista *atual, *apagar;
  for (x=0; x<g->numVertices; x++){
    atual = g->A[x];
    while (atual){
      apagar = atual;
      atual = atual->prox;
      free(apagar);
    }
  }
  free(g->A);
  g->numVertices = 0;
  g->numArestas = 0;
  g->A = NULL;
  return true;
}

bool insereAresta(Grafo* g, Cidade v1, Cidade v2, Peso peso){
  int v1pos=buscaPos(g, v1), v2pos = buscaPos(g, v2);	
  if(g == NULL||v1pos<0 || v2pos<0) {
    printf("\nErro: grafo invalido.");
    return false;
  }
  ElemLista *novo, *ant = NULL;
  ElemLista *atual = g->A[v1pos];
  
  while (atual && strcmp(atual->city.nomecidade,v2.nomecidade)< 0){
    ant = atual;
    atual = atual->prox;
  }

  if (atual && strcmp(atual->city.nomecidade,v2.nomecidade)==0 ) { // ja existe
    atual->peso = peso;
    return true;
  }
  novo = (ElemLista*)malloc(sizeof(ElemLista));
  if(novo == NULL) {
    printf("Falha na alocacao de memoria da aresta.");
    return false;
  }
  novo->city = v2;
  novo->peso = peso;
  if (ant){
  novo->prox = atual;
   ant->prox = novo;
  }
  else{
  novo->prox = NULL;
  atual->prox = novo;
  } 
  g->numArestas++;
  return true;
}

bool removeAresta(Grafo* g, Cidade v1, Cidade v2){
  int v1pos = buscaPos(g,v1), v2pos = buscaPos(g,v2);
  if (!g || v1pos<0 || v2pos<0|| !g->A) return false;
  ElemLista* ant = NULL;
  ElemLista* atual = g->A[v1pos];

  while (atual && strcmp(atual->city.nomecidade,v2.nomecidade)> 0){
    ant = atual;
    atual = atual->prox;
  }
  if (atual &&  strcmp(atual->city.nomecidade,v2.nomecidade)==0){
    if (ant){ ant->prox = atual->prox;}
    else{
     g->A[v1pos] = atual->prox;
    }
    free(atual);
    g->numArestas--;
    return true;
  }
  return false;
}

bool arestaExiste(Grafo* g, Cidade v1, Cidade v2){
  int v1pos = buscaPos(g,v1), v2pos = buscaPos(g,v2);
  if (!g || v1pos < 0 || v2pos < 0) return false;
  if (v1pos == v2pos){
    printf("Mesma cidade.");
    return false;
  }
  ElemLista* atual = g->A[v1pos];
  while (atual ) {
    if (atual != NULL && strcmp(atual->city.nomecidade,v2.nomecidade) == 0){
      printf("\nRodovia encontrada!"); 
      printf("\n%.2f km", atual->peso);
      return true;
    }
    atual = atual->prox;
  }
  printf("Nao existe ligacao");
  return false;
}

void exibeGrafo(Grafo* g){
  if (!g) return;
  printf("\nImprimindo grafo (vertices: %i; arestas: %i).\n", g->numVertices, g->numArestas);
  ElemLista* aux;
  int x;
  for (x=0;x<g->numVertices;x++){
    printf("\nCidade %s", g->A[x]->city.nomecidade);
    aux = g->A[x]->prox;
    while(aux != NULL) {
      printf("-> %s, %.2fkm", aux->city.nomecidade, aux->peso);
      aux = aux->prox;
    }
    printf("\n");
}
}

void exibe100(Grafo *g){
  if (!g) return;
  ElemLista* aux;
  int x;
  for (x=0;x<g->numVertices;x++){
    aux = g->A[x]->prox;
    bool veri= false;
    while (aux){
      if(aux->peso<= 100) {
        veri = true;
      }
      aux = aux->prox;
    }
    aux= g->A[x]->prox;
    if(veri == true) {
      printf("\nCidade %s", g->A[x]->city.nomecidade);
      while(aux != NULL && aux->peso<=100) {
        printf("-> %s, %.2fkm", aux->city.nomecidade, aux->peso);
        aux = aux->prox;
      }
      printf("\n");
    }
}
}

void buscaEmProfundidadeCores(Grafo *g){
  if (!g || !g->A){
    return; 
  }
  // Cria o vetor para os vertices de cores
  int *cor = (int *) malloc(sizeof(bool)*g->numVertices);
  bool ciclo = false;
  for(int i = 0; i < g->numVertices; i++)
    cor[i] = branco; //marca todos os vertices como brancos
  for(int i = 0; i < g->numVertices; i++){
    if(cor[i] == branco){
      visitaProfundidadeCor(g, cor, g->A[i], NULL, &ciclo);
    }
  }
  if(ciclo == false){
    printf("O Grafo nao possui ciclos!!");
  }
  else{
    printf("O grafo eh ciclico!!");
  }
}

void visitaProfundidadeCor(Grafo *g, int *cor, ElemLista *atual, ElemLista *anterior, bool *ciclo){
  if(!g || !atual) return;
  int atualpos = buscaPos(g, atual->city);
  ElemLista *aux = atual;
  cor[atualpos] = cinza; 
  while (aux && aux->prox){
    int auxPos = buscaPos(g, aux->prox->city);
    if ( cor[auxPos] == branco){
      visitaProfundidadeCor(g, cor, g->A[auxPos], aux, ciclo);
    }
    else if ( cor[auxPos] == cinza){
      //
      *ciclo = true;
    }
    aux = aux->prox;
  }
  cor[atualpos] = preto;
  return;
}