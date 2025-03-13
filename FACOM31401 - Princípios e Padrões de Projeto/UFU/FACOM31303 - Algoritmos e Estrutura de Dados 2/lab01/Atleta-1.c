#include "Atleta-1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ALUNOS
Eduarda Lopes Santos Moura - 12311BCC033
Lucas Matos Rodrigues - 12311BCC024
Matheus Vinicius Maximo Santos - 12311BCC018
-----------------------------------------------------------------------
Estrutura de listas adaptada do codigo disponivel em: https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/Clientes.c e https://github.com/dudalopessm/Trabalho_Conclusao_AED1/blob/main/Clientes.h
*/

typedef struct noA
{
    Atleta item;
    struct noA *prox;
} NoA;

typedef struct noA *ListaA;

ListaA *criarAtleta()
{
    ListaA *l = (ListaA *)malloc(sizeof(ListaA));
    (*l) = NULL;
    return l;
}

ListaA *importarArqAtletas()
{
    ListaA *l = criarAtleta();
    FILE *arq = fopen("database_atletas.txt", "r");
    if (arq == NULL)
    {
        printf("\nErro ao abrir arquivo para ler.");
        return l;
    }
    int controle;
    Atleta aux;

    while (fscanf(arq, "%[^\n]\n %[^\n]\n %d\n %f\n", aux.nome, aux.nacionalidade, &aux.medalhas, &aux.premiacao) != EOF)
    {
        controle = inserirAtleta(l, aux);
    }
    fclose(arq);
    return l;
}

int exportarArqAtletas(ListaA *l, Atleta it)
{
    FILE *arq = fopen("database_atletas.txt", "a");
    if (listaVaziaA(l) == 0)
    {
        printf("\nA lista esta vazia.");
        return 1;
    }
    fprintf(arq, "\n%s\n %s\n %d\n %f\n", it.nome, it.nacionalidade, it.medalhas, it.premiacao);
    fclose(arq);
    return 0;
}

int inserirAtleta(ListaA *l, Atleta atl)
{
    if (l == NULL)
        return 2;
    NoA *no = (NoA *)malloc(sizeof(NoA));
    if (no == NULL)
        return 1;
    no->item = atl;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerAtleta(ListaA *l, Atleta atl)
{
    if (l == NULL)
        return 2;
    if (listaVaziaA(l) == 0)
        return 1;
    NoA *ant;
    NoA *no = (*l);
    if (no == NULL)
        return 3;
    while (no != NULL && (strcmp(no->item.nome, atl.nome) != 0))
    {
        ant = no;
        no = no->prox;
    }
    if (no == (*l))
    {
        (*l) = no->prox;
    }
    else
    {
        ant->prox = no->prox;
    }
    free(no);
    return 0;
}

int listaVaziaA(ListaA *l)
{
    if (l == NULL)
        return 2;
    if ((*l) == NULL)
        return 0;
    return 1;
}

int quantidadeElementos(ListaA *l)
{
    if (l == NULL)
        return 1;
    if (listaVaziaA(l) == 0)
        return 0;
    NoA *no = (*l);
    int cont = 0;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

void mostrarAtletas(ListaA *l)
{
    if (l != NULL)
    {
        NoA *noLista = (*l);
        while (noLista != NULL)
        {
            printf("\n");
            printf("\n Nome: %s", noLista->item.nome);
            printf("\n Nacionalidade: %s", noLista->item.nacionalidade);
            printf("\n Quantidade de medalhas: %d", noLista->item.medalhas);
            printf("\n Premiacao: %.2f", noLista->item.premiacao);
            printf("\n");
            noLista = noLista->prox;
        }
    }
}

//Codigos de ordenacao feitos baseados em artigos variados do site https://stackoverflow.com e nos slides das aulas.
void bubbleSort(ListaA *l, int opcao)
{
    if (listaVaziaA(l) == 0)
        return; // Lista vazia, nada a ordenar
    int trocou;
    NoA *atual;
    NoA *anterior = NULL; // Armazena o último nó já ordenado
    NoA *fim = NULL;

    do
    {
        trocou = 0;
        atual = *l;

        while (atual->prox != fim)
        {
            NoA *proximo = atual->prox;

            if ((opcao == 0 && atual->item.medalhas < proximo->item.medalhas) ||
                (opcao == 1 && atual->item.premiacao > proximo->item.premiacao) ||
                (opcao == 2 && strcmp(atual->item.nome, proximo->item.nome) > 0))
            {

                // Troca os itens dos nós
                Atleta temp = atual->item;
                atual->item = proximo->item;
                proximo->item = temp;

                trocou = 1;
            }

            atual = atual->prox;
        }

        fim = atual; // Marca o fim da parte ordenada da lista
    } while (trocou);
}

void selectionSort(ListaA *l, int opcao)
{
    int trocou;
    NoA *atual = *l;
    NoA *eleito = atual;

    for (int j = 0; j < quantidadeElementos(l); j++)
    {
        NoA *proximo = atual->prox;
        // Loop interno para encontrar o menor/maior elemento a partir do nó atual
        for (int i = j; i < quantidadeElementos(l) - 1; i++)
        {
            if ((opcao == 0 && eleito->item.medalhas < proximo->item.medalhas) ||
                (opcao == 1 && eleito->item.premiacao > proximo->item.premiacao) ||
                (opcao == 2 && strcmp(eleito->item.nome, proximo->item.nome) > 0))
            {
                eleito = proximo;
                trocou = 1;
            }
            proximo = proximo->prox;
        }
        // Se houve um novo item elegivel, realiza a troca dos itens
        if (trocou == 1)
        {
            Atleta temp = atual->item;
            atual->item = eleito->item;
            eleito->item = temp;
        }
        atual = atual->prox;
        eleito = atual;
    }
}