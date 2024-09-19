#ifndef TCDD_PRATOS_H
#define TCDD_PRATOS_H
typedef struct noP* ListaP;
typedef struct pratos Pratos;
struct pratos {
    int codigo;
    char nome[30];
    char ingredientes[300];
    float preco;
    int quantidade;
    int restauranteorigem;
};

ListaP *criarP(); //criação da lista

int inserirPrato(ListaP *l, Pratos it); //inserção de elemento
int removerPrato(ListaP *l, Pratos it); //remoção de elemento

int listaVaziaP(ListaP *l); //verificação de status

int alteraPrato(ListaP *l, Pratos it); //alteração de prato

int buscaItemPrato(ListaP *l, int cod); //busca de prato baseado no seu codigo retornando um inteiro
int buscaPrato(ListaP *l, int cod, Pratos *it); //busca de prato baseado no seu codigo retornando um inteiro e um item

float carrinho(ListaP *l); //retorna o valor em dinheiro dos pedidos realizados

void mostrarPratos(ListaP *l); //mostra todos os pratos do cardapio
void mostrarPCliente(ListaP *l); //mostra os pedidos do carrinho ou ja entregues do cliente
void retornarPrato(ListaP *l, Pratos *it); //retorna um prato em um item
#endif //TCDD_PRATOS_H