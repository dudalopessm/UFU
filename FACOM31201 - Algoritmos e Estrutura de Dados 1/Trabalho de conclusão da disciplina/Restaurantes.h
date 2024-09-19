#ifndef TCDD_RESTAURANTES_H
#define TCDD_RESTAURANTES_H
#include "Pratos.h"
#include "Pedidos.h"
typedef struct listaR ListaR;
typedef struct restaurante Restaurante;
typedef struct restaurante{
    char nomeRest[30];
    char categoria[30];
    char CNPJ[19];
    char email[30];
    char senha[10];
    int identificacao;
    ListaP *cardapio;
    Fila *pedidos;
}Restaurante;

ListaR *criarRest(); //criação da lista

int inserirRest(ListaR *l, Restaurante rest); //inserção de elemento
int removerRest(ListaR *l, Restaurante rest); //remoção de elemento

int geracaoCod(ListaR *l); //gera um codigo para o item

int buscaEmailRest(ListaR *l, char *em); //busca restaurante baseado no email retornando um inteiro
int buscaItemRest(ListaR *l, char *it); //busca restaurante baseado no CNPJ retornando um inteiro
int buscaRest(ListaR *l, char *aux, Restaurante *rest); //busca restaurante baseado no email retornando um inteiro e um item
int achaRest(ListaR *l, int id, Restaurante *rest); //busca restaurante baseado na sua identificacao (codigo) retornando um inteiro e um item
int achaRestId(ListaR *l, int id); //busca restaurante baseado na sua identificacao (codigo) retornando um inteiro
int acharPrato(ListaR *l, int cod, Restaurante *rest); //verifica se o prato existe no restaurante em questão

int listaVaziaR(ListaR *l); //verifica status da lista

void mostrarR(ListaR *l, char *cat); //mostra os restaurantes por categoria
void mostrarPratosRest(ListaR *l); //mostra o cardapio do restaurante
#endif //TCDD_RESTAURANTES_H