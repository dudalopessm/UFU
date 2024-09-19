typedef struct fila Fila;
typedef struct Inteiros{
    int n;
}Inteiros;
Fila *criar();
Fila *intercala(Fila *f1, Fila *f2);
void limpar(Fila *f);
int inserir(Fila *f, int it);
int remover(Fila *f, int *it);
int consultar(Fila *f, Inteiros *it);
int tamanho(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void mostrar(Fila *f);