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
#define true 1
#define false 0
#define branco 1 
#define cinza 2
#define preto 3
typedef int bool;
typedef float Peso;

// Como se fosse o meu "Nó" e os pesos são as kilometragens entre as cidades, ou seja, entre os vertices
typedef struct cidade { 
    char nomecidade[50];
}Cidade;
typedef struct aux{
    Cidade city;
    Peso peso; //peso = numero rodovia 
    struct aux* prox;
} ElemLista;

typedef struct {
    int numVertices; //numVertices = NUMERO DE CIDADES 
    int numArestas;
    ElemLista** A;
} Grafo;

Grafo *lerArquivoGrafo(char *enderecoArquivo, int tamGrafo);
Grafo *criaGrafo();

int buscaPos(Grafo* g, Cidade cid);

void exibeGrafo(Grafo* g);
void exibe100(Grafo *g);
bool liberaGrafo(Grafo* g);

bool insereAresta(Grafo *g, Cidade v1, Cidade v2, Peso peso);
bool insereVertice(Grafo *g, Cidade *cidade);


bool removeAresta(Grafo *g, Cidade v1, Cidade v2);
bool arestaExiste(Grafo* g, Cidade v1, Cidade v2);

void buscaEmProfundidadeCores(Grafo *g);
void visitaProfundidadeCor(Grafo *g, int *cor, ElemLista *atual, ElemLista *anterior, bool *ciclo);


#endif // GRAFOS_H