#ifndef TCDD_PEDIDOS_H
#define TCDD_PEDIDOS_H
#include "Clientes.h"
#include "Pratos.h"
typedef struct fila Fila;

Fila *criarFilaPed(); //criação da fila de pedidos

int inserirPedido(Fila *f, Cliente cli, Pratos p); //inserção de elemento

int removerPedido(Fila *f, Cliente *cli, Pratos *p); //remoção de elemento

int tamanhoFila(Fila *f); //retorna quantos elementos tem na fila

void mostrarPedidos(Fila *f); //mostra pedidos na fila

int filaVazia(Fila *f); //verificação de status
#endif //TCDD_PEDIDOS_H