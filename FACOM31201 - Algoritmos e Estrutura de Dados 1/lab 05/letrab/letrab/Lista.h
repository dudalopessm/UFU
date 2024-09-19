#ifndef Lista_h
#define Lista_h
#define MAX 100

struct aluno {
    int mat;
    char nome[30];
    float n1;
};
typedef struct aluno Aluno;

typedef struct lista Lista;

Lista *criar();
Lista *Reversa(Lista *l, Lista *r);

void limpar (Lista *l);

int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);
int inserirPosicao(Lista *l, Aluno it, int pos);

int removerInicio (Lista *l);
int removerFim (Lista *l);
int removerPosicao (Lista *l, int pos);
int removerItem (Lista *l, int mat);

int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao(Lista *l, int posicao, Aluno *it);

int listaVazia(Lista *l);
int listaCheia(Lista *l);

int ContemItem (Lista *l, Aluno it);

int ContaItem(Lista *l, Aluno it);

int tamanho(Lista *l);

void mostrar(Lista *l);

void liberar(Lista *l);

#endif