#include "grafos.h"
#include "stdio.h"
#include "stdlib.h"

/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Estrutura de Grafos adaptada do material do professor da USP Prof. Dr. Luciano Antonio Digiampietri, disponivel no site: https://www.each.usp.br/digiampietri/ACH2024
*/

bool inicializaGrafo(Grafo *g, int vertices)
{
    if (g == NULL || vertices < 1)
        return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    g->A = (ElemLista**)malloc(sizeof(ElemLista*)*vertices);
    inicializaCidade(g->A);
    int x;
    for (x = 0; x < vertices; x++)
    {
        g->A[x] = NULL;
    }

    return true;
}

Grafo *criaGrafo()
{
    Grafo *grafo = malloc(sizeof(Grafo));
    return grafo;
}

//consertar erros das funções para inicializar cidade
//usada para auxiliar na criação da identificação automática
void inicializaCidade(ElemLista *elemento) {
    elemento->elementoCid = (Cidade*)malloc(sizeof(Cidade)); //tem que alocar memória para cidade? sim né? mas como? 
    elemento->elementoCid.id = 1;
}

//usar na iniciliazação de cada cidade pq incrementa o id com 1
int geraCodigoCidade(ElemLista *elemento) 
{ 
    if (elemento == NULL) return -2;
    int cod;
    cod = elemento->elementoCid.id;
    (elemento->elementoCid.id++);
    return cod;
}

void exibeGrafo(Grafo *g)
{
    if (!g)
        return;

    printf("\nImprimindo grafo(vertices: %i; arestas: %i).\n", g->numVertices, g->numArestas);
    ElemLista *atual;
    int x;

    for (x = 0; x < g->numVertices; x++)
    {
        printf("[%2i]", x);
        atual = g->A[x];
        while (atual)
        {
            printf(" ->%3i (%5.2f) ", atual->vertice, atual->peso);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool liberaGrafo(Grafo *g)
{
    if (g == NULL)
        return false;
    ElemLista *atual, *apagar;
    int x;
    for (x = 0; x < g->numVertices; x++)
    {
        atual = g->A[x];
        while (atual)
        {
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

bool insereAresta(Grafo *g, int v1, int v2, Peso peso)
{
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || v1 == v2)
        return false;
    if (insereArestaAux(g, v1, v2, peso))
    {
        insereArestaAux(g, v2, v1, peso);
    }
    return true;
}

bool insereArestaAux(Grafo *g, int v1, int v2, Peso peso)
{
    ElemLista *novo, *ant = NULL;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2)
    {
        atual->peso = peso;
        return true;
    }

    novo = (ElemLista *)malloc(sizeof(ElemLista));
    novo->vertice = v2;
    novo->peso = peso;
    novo->prox = atual;
    if (ant)
        ant->prox = novo;
    else
        g->A[v1] = novo;
    return true;
}

bool removeAresta(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 ||
        v1 >= g->numVertices || v2 >= g->numVertices)
        return false;
    if (removeArestaAux(g, v1, v2))
    {
        removeArestaAux(g, v2, v1);
        g->numArestas--;
        return true;
    }
    return false;
}

bool removeArestaAux(Grafo *g, int v1, int v2)
{
    ElemLista *ant = NULL;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2)
    {
        if (ant)
            ant->prox = atual->prox;
        else
            g->A[v1] = atual->prox;
        free(atual);
        return true;
    }
    return false;
}

bool arestaExiste(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices)
        return false;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
        atual = atual->prox;
    if (atual && atual->vertice == v2)
        return true;
    return false;
}

int numeroDeVertices(Grafo *g)
{
    if (g != NULL)
        return g->numVertices;
    else
        return -1;
}

bool possuiVizinhos(Grafo *g, int v)
{
    if (!g || v < 0 || v >= g->numVertices || !(g->A[v]))
        return false;
    return true;
}

int retornaGrauDoVertice(Grafo *g, int v)
{
    if (!g || v < 0 || v >= g->numVertices)
        return -1;
    int grau = 0;
    ElemLista *atual = g->A[v];
    while (atual)
    {
        grau++;
        atual = atual->prox;
    }
    return grau;
}

// Função de Busca em profundidade

void visitaProfundidade(Grafo *g, int atual, bool *visitado, int anterior)
{
    printf("Visitando vertice: %3i (anterior: %3i)\n", atual, anterior);
    visitado[atual] = true;
    ElemLista *end = g->A[atual];
    while (end)
    {
        if (!visitado[end->vertice])
            visitaProfundidade(g, end->vertice, visitado, atual);
        end = end->prox;
    }
}

void buscaEmProfundidade(Grafo *g)
{
    if (!g || g->numVertices < 1)
        return;
    int x;
    bool *visitado = (bool *)malloc(sizeof(bool) * g->numVertices);
    for (x = 0; x < g->numVertices; x++)
        visitado[x] = false;
    for (x = 0; x < g->numVertices; x++)
        if (!visitado[x])
            visitaProfundidade(g, x, visitado, -1);
    free(visitado);
}

// DFS com cores agora
/*
    Considere as seguintes cores:
        Branco - 0
        Cinza  - 1
        Preto  - 2
*/
void DFSCores(Grafo *g)
{
    if (!g || g->numVertices < 1)
        return;
    int *cor = (int *)malloc(sizeof(int) * g->numVertices);
    int *tDescoberta = (int *)malloc(sizeof(int) * g->numVertices);
    int *tTermino = (int *)malloc(sizeof(int) * g->numVertices);
    int *anterior = (int *)malloc(sizeof(int) * g->numVertices);
    int tempo = 0;
    int x;
    for (x = 0; x < g->numVertices; x++)
    {
        cor[x] = 0; // BRANCO
        tDescoberta[x] = -1;
        tTermino[x] = -1;
        anterior[x] = -1;
    }
    for (x = 0; x < g->numVertices; x++)
        if (cor[x] == 0)
            visitaDFSCores(g, x, &tempo, cor, tDescoberta, tTermino, anterior);
    printf("\nResumo da Busca em Profundidade:\n");
    printf("No\tanterior\tDescoberta\tTermino\tCor:\n");
    for (x = 0; x < g->numVertices; x++)
        printf("%2i\t%8i\t%10i\t%7i\t%3i\n", x, anterior[x],
               tDescoberta[x], tTermino[x], cor[x]);
    printf("\n");
    free(cor);
    free(tDescoberta);
    free(tTermino);
    free(anterior);
}

void visitaDFSCores(Grafo *g, int atual, int *tempo, int *cor,int *tDescoberta, int *tTermino, int *anterior)
{
    (*tempo)++;
    cor[atual] = 1; // CINZA
    tDescoberta[atual] = *tempo;
    int w;
    ElemLista *end = g->A[atual];
    while (end)
    {
        w = end->vertice;
        if (cor[w] == 0)
        { // BRANCO
            anterior[w] = atual;
            visitaDFSCores(g, w, tempo, cor, tDescoberta, tTermino, anterior);
        }
        end = end->prox;
    }
    cor[atual] = 2; // PRETO
    (*tempo)++;
    tTermino[atual] = *tempo;
}