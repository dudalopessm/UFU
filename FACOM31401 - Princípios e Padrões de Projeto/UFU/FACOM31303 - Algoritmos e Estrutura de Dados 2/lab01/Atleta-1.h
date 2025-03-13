#ifndef ATLETA_H_INCLUDED
#define ATLETA_H_INCLUDED
/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Estrutura de listas adaptada do codigo disponivel em: https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/Clientes.c e https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/Clientes.h
*/

typedef struct atleta
{
    char nome[40];
    char nacionalidade[30];
    int medalhas;
    float premiacao;
} Atleta;

typedef struct noA *ListaA;

ListaA *criarAtleta();

ListaA *importarArqAtletas();
int exportarArqAtletas(ListaA *l, Atleta it);

int inserirAtleta(ListaA *l, Atleta atl);

int removerAtleta(ListaA *l, Atleta atl);

int listaVaziaA(ListaA *l);

int quantidadeElementos(ListaA *l);

void mostrarAtletas(ListaA *l);

void bubbleSort(ListaA *l, int opcao);

void selectionSort(ListaA *l, int opcao);

#endif // ATLETA_H_INCLUDED
