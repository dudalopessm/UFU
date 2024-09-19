#ifndef LAB08_AED1_LAB_H
#define LAB08_AED1_LAB_H
typedef struct numeros Numeros;
struct numeros {
    int n1;
};

typedef struct no* Lista;

Lista *criar();

void limpar (Lista *l);

int inserirInicio(Lista *l, Numeros it);
int tamanho(Lista *l);
int buscaElemento(Lista *l, int it);
int removerItem(Lista *l, int it);

int UltimoElem(Lista *l, int *saida);
int Soma(Lista *l);
void Reverso(Lista *l);
int RemocaoTodos(Lista *l, int it); //elemento pode ser a cabeça, estar na cauda e pode nao estar na lista (3 possibilidades). verifico se está na cabeça e ai apago, e entao procuro ele de novo na cauda (chamo a funcao na cauda), para quando chega no vazio (caso base).

int listaVazia(Lista *l);

void mostrar(Lista *l);

#endif //LAB08_AED1_LAB_H