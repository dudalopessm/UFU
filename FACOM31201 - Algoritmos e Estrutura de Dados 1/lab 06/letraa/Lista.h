#ifndef Lista_h
#define Lista_h

struct aluno {
    int mat;
    char nome[30];
    float n1;
};

typedef struct aluno Aluno;

typedef struct lista Lista;

Lista *criar ();
Lista *concatena (Lista *l1, Lista *l2);

void limpar (Lista *l);

int inserirInicio (Lista *l, Aluno it);
int inserirFim (Lista *l, Aluno it);
int inserirPosicao (Lista *l, Aluno it, int pos);

int removerInicio (Lista *l);
int removerFim (Lista *l);
int removerPosicao (Lista *l, int pos);
int removerItem (Lista *l, int mat);

int buscarItemChave (Lista *l, int chave, Aluno *retorno);
int buscarPosicao (Lista *l, int posicao, Aluno *retorno);

int listaVazia (Lista *l);

int ContemItem (Lista *l, Aluno it);

void mostrar (Lista *l);

void liberar (Lista *l);

int tamanho (Lista *l);

#endif