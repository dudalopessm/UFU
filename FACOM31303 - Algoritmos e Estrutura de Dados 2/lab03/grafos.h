#ifndef GRAFOS_H
#define GRAFOS_H

/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Estrutura de Grafos adaptada do material do professor da USP Prof. Dr. Luciano Antonio Digiampietri, disponivel no site: https://www.each.usp.br/digiampietri/ACH2024
*/

#define true  1
#define false 0
typedef int bool;
typedef double Peso;

typedef struct cidade {
    int id; //identificação da cidade, será apenas manipulada nas funções, não aparecerá em nenhuma circunstância pro usuário, começará no 1, função auxiliar para fazer automático
    char nomeCidade[40];
    char nomeRodovia[20];
    int numeroRodovia;
}Cidade;

// Como se fosse o meu "Nó"
typedef struct {
    int vertice;
    Cidade elementoCid;
    struct aux* prox;
    Peso peso;
} ElemLista, *PONT;

typedef struct {
    int numVertices;
    int numArestas;
    ElemLista **A;
} Grafo;

bool inicializaGrafo(Grafo* g, int vertices);
Grafo *criaGrafo();

int geraCodigoCidade(Grafo *g);

//funcoes dos arquivos 

void exibeGrafo(Grafo *g);
bool liberaGrafo(Grafo *g);

bool insereAresta(Grafo *g, int v1, int v2, Peso peso);
bool insereArestaAux(Grafo *g, int v1, int v2, Peso peso);

bool removeAresta(Grafo *g, int v1, int v2);
bool removeArestaAux(Grafo *g, int v1, int v2);

bool arestaExiste(Grafo *g, int v1, int v2);

int numeroDeVertices(Grafo *g);
bool possuiVizinhos(Grafo *g, int v);
int retornaGrauDoVertice(Grafo *g, int v);

void visitaProfundidade(Grafo *g, int atual, bool *visitado, int anterior);
void buscaEmProfundidade(Grafo *g);
void DFSCores(Grafo *g);
void visitaDFSCores(Grafo *g, int atual, int *tempo, int *cor,int *tDescoberta, int *tTermino, int *anterior);

#endif // GRAFOS_H