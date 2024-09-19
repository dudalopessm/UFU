#ifndef TCDD_AVALIACOES_H
#define TCDD_AVALIACOES_H
#include "Clientes.h"
#include "Pratos.h"
#include "Restaurantes.h"
typedef struct noF* ListaF;
typedef struct feedback Feedback;
struct feedback {
    char estrelas[2]; //cliente avalia estabelecimento ou pedido de 0 a 5 estrelas
    char avaliacao[300]; //cliente escreve avaliacao
    ListaP *pedentregues; //vou avaliar o pedido, a avaliacao vai para o restaurante e fica disponivel para visualizacao para o cliente e o proprietario
};

ListaF *criarF(); //criação da lista

int inserirFeed(ListaF *l, Cliente cli, Restaurante rest, Feedback it); //insercao de elementos

int listaVaziaF(ListaF *l); //verificacao do status da lista

void mostrarFeedRest(ListaF *l, int id); //mostra informações pertinentes aos restaurantes
void mostrarFeedCli(ListaF *l, char *cliente); //mostra informações pertinentes aos clientes
#endif //TCDD_AVALIACOES_H