#ifndef TCDD_CLIENTES_H
#define TCDD_CLIENTES_H
#include "Pratos.h"
typedef struct noC* ListaC;
typedef struct cliente Cliente;
struct cliente {
    char cpf[15];
    char nome[30];
    char email[30];
    char senha[10];
    ListaP *carrinho;
    ListaP *pedidos;
    ListaP *entregues;
};

ListaC *criarCliente(); //criacao da lista

int inserirCliente(ListaC *l, Cliente cli); //insercao de elemento
int removerCliente(ListaC *l, Cliente cli); //remocao de elemento

int buscaEmailCliente(ListaC *l, char *em); //busca por email retornando apenas inteiro
int buscaCliente(ListaC *l, char *em, Cliente *cli); //busca por email retornando o cliente em um item
int procuraCliente(ListaC *l, char *aux); //busca por cpf retornando apenas inteiro

int listaVaziaC(ListaC *l); //verifica status da lista

void mostrarC(ListaC *l); //mostra clientes
#endif //TCDD_CLIENTES_H
