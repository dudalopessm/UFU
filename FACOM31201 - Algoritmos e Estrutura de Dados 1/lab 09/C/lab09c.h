typedef struct fila Fila;
typedef struct inteiros{
    int n;
}Inteiros;
Fila *criar();
void limpar(Fila *f);
int inserir(Fila *f, int it);
int remover(Fila *f, int *it);
int consultar(Fila *f, Inteiros *it);
int tamanho(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
int removeNegativos(Fila *f);
void mostrar(Fila *f);