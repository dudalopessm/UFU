/*

  TRABALHO DE BUSCA DE DADOS DE CANDIDATOS DA ELEICAO DE 2024
  
    GRUPO: Eduarda Lopes (12311BCC033), Lucas Matos (12311BCC024) e Matheus Vinicius (12311BCC018)

    PROFESSOR: Maria Camila Nardoni

    DISCIPLINA: FACOM31303 - ALGORITMOS E ESTRUTURA DE DADOS 2 

    SEMESTRE: 2024.1 

    CREDITOS: - IMPLEMENTACAO DE ARVORE BINARIA UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula10-Arvores.pdf -> creditos ao professor Andre Backes
              - IMPLEMENTACAO DE ARVORE AVL UTILIZADA: https://www.facom.ufu.br/~backes/gsi011/Aula11ArvoreAVL.pdf-> creditos ao professor Andre Backes
              - FUNCAO AUXILIAR STRIPWHITESPACE: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way -> stackoverflow

*/
#include "Candidatos.h"
#include "AVLCandidatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// ------------------------------------- FUNCOES AUXILIARES --------------------------------------//

/*
    FUNCAO stripWhitespaceAVL:

        Mesmo funcionamento da funcao stripWhitespaceCand em Candidatos.C

*/
char *stripWhitespaceAVL(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = '\0';

    return str;
}

/*
    FUNCAO maior:

        retorna o maior numero entre a e b

*/
int maior(int a, int b)
{
    return (a > b) ? a : b;
}

// ------------------------------------- ESTRUTURA ARVORE AVL --------------------------------------//

/*
    Estrutura  Arvore AVL:

        A Arvore AVL é definida como um no raiz e nos filhos a esquerda e a direita, com pequena alteracao da informacao contida como sendo um *Candidato e o a altura do NO em relação aos seus filhos.

*/
struct NO
{
    Candidato *info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

// ------------------------------------- FUNCOES RELACIONADAS AS ARVORES --------------------------------------//

/*
    FUNCAO maior_ArvAVL:

        Retorna maior candidato pelo sistema de comparaCandidato()

*/
Candidato *maior_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return NULL;
    if ((*raiz)->dir == NULL)
        return (*raiz)->info;
    return maior_ArvAVL(&((*raiz)->dir));
}

/*
    FUNCAO menor_ArvAVL:

        Retorna menor candidato pelo sistema de comparaCandidato()

*/
Candidato *menor_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return NULL;
    if ((*raiz)->esq == NULL)
        return (*raiz)->info;
    return menor_ArvAVL(&((*raiz)->esq));
}

/*
    FUNCAO alt_NO:

        Funcao que retorna a altura do NO em relacao aos seus filhos

*/
int alt_NO(struct NO *no)
{
    if (no == NULL)
        return -1;
    else
        return no->alt;
}

/*
    FUNCAO altura_ArvAVL:

        Funcao que retorna a altura da arvore AVL inteira

*/
int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return alt_esq + 1;
    else
        return alt_dir + 1;
}

/*
    FUNCAO fatorBalanceamento_NO:

        Funcao que retorna fator de balanceamento de um dado No (2, 1 ou 0)

*/
int fatorBalanceamento_NO(struct NO *no)
{
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

/*
    FUNCAO verFatorAux:

        Funcao de debug que verifica a existencia de fatores de balancemanto em toda a arvore

*/
void verFatorAux(ArvAVL *raiz, int n, char *nome)
{
    if (*raiz == NULL || raiz == NULL)
    {
        printf("\n%s | Nao existe em %d.", nome, n - 1);
        return;
    }
    printf("\n %s |Fator balanceamento: %d | %d", nome, fatorBalanceamento_NO(*raiz), n);
    verFatorAux(&((*raiz)->dir), n + 1, "Dir");
    verFatorAux(&((*raiz)->esq), n + 1, "Esq");
}

/*
    FUNCAO verFator:

        Funcao de debug que verifica a existencia de fatores de balancemanto em toda a arvore

*/
void verFator(ArvAVL *raiz)
{
    verFatorAux(raiz, 0, "raiz");
}

/*
    FUNCAO RotacaoLL:

        Funcao que realiza uma rotacao simples a direita de um determinado no da arvore

*/
void RotacaoLL(ArvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;

    *raiz = no;
}

/*
    FUNCAO RotacaoRR:

        Funcao que realiza uma rotacao simples a esquerda de um determinado no da arvore

*/
void RotacaoRR(ArvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;

    *raiz = no;
}

/*
    FUNCAO RotacaoRL:

        Funcao que realiza uma rotacao simples direita e depois realiza uma rotacao simples a esquerda de um determinado no

*/
void RotacaoRL(ArvAVL *raiz)
{
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

/*
    FUNCAO RotacaoLR:

        Funcao que realiza uma rotacao simples esquerda e depois realiza uma rotacao simples a direita de um determinado no

*/
void RotacaoLR(ArvAVL *raiz)
{
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

/*
    FUNCAO procuraMenor:

        Funcao que procura o menor No dentro de uma arvore e retorna ele

*/
struct NO *procuraMenor(struct NO *raiz)
{
    struct NO *n1 = raiz;
    struct NO *n2 = raiz->esq;

    while (n2 != NULL)
    {
        n1 = n2;
        n2 = n2->esq;
    }

    return n1;
}

// ------------------------------------- CRIACAO E DESTRUICAO DE ARVORES AVL --------------------------------------//

/*
    Funcao  cria_ArvAVL:

        A funcao aloca memoria para a estrutura de ArvAVL e retona o ponteiro resultade para raiz

*/

ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

/*
    Funcao  libera_NO_ArvAVL:

        A funcao faz a liberaçpao dos dados de um dado No, contendo o candidato, de maneira recursiva ate que o no em questao seja igual a NULL

*/
void libera_NO_ArvAVL(struct NO *no)
{
    if (no == NULL)
        return;
    libera_NO_ArvAVL(no->esq);
    libera_NO_ArvAVL(no->dir);
    destroiCandidato(no->info);
    free(no);
    no = NULL;
}

/*
    Funcao  libera_ArvAVL:

        A funcao faz a liberaçpao dos dados de uma dada arvore usando a funcao auxiliar libera_NO_ArvAVL, para a liberacao das ramificacoes da arvore e por fim liberando a raiz

*/
void libera_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    libera_NO_ArvAVL(*raiz);
    free(raiz);
    *raiz = NULL;
}

// ------------------------------------- INSERCAO E REMOCAO DE DADOS --------------------------------------//

/*
    Funcao de Insercao:

        - A funcao de insercao em AVL é uma funcao recursiva que realiza a comparacao entre o candidadato a ser inserido e o valor da raiz.
        - Caso essa comparacao seja maior que zero, fazemos a chamada da insercao novamente com a raiz sendo o subarvore a direita e verificamos se ela foi 1.
        - Caso seja, verificamos se é necessario fazer o balanceamento da arvore com rotacoes RR e RL
        - Caso essa comparacao seja menor que zero, fazemos a chamada da insercao novamente com a raiz sendo o subarvore a esquerda e verificamos se ela foi 1.
        - Caso seja, verificamos se é necessario fazer o balanceamento da arvore com rotacoes LL e LR
        - Se verificarmos se alguma raiz foi nula, inserirmos o candidato na posicao correspondente e retornamos 1
        - Nao esquecemos que ao fim precisamos sempre atualizar a altura da arvore ao fim de cada laco
*/
int insere_ArvAVL(ArvAVL *raiz, Candidato *cand)
{
    if (raiz == NULL)
        return 0;
    int res;

    if (*raiz == NULL)
    {
        struct NO *novo = malloc(sizeof(struct NO));

        if (novo == NULL)
            return 0;

        novo->info = cand;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;

        *raiz = novo;

        return 1;
    }

    struct NO *atual = *raiz;
    if (comparaCandidatos(cand, atual->info) < 0)
    {
        if ((res = insere_ArvAVL(&(atual)->esq, cand)) == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {
                if (comparaCandidatos(cand, (*raiz)->esq->info) < 0)
                {
                    RotacaoLL(raiz);
                }
                else
                {
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else if (comparaCandidatos(cand, atual->info) > 0)
    {
        if ((res = insere_ArvAVL(&(atual)->dir, cand)) == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {
                if (comparaCandidatos((*raiz)->dir->info, cand) < 0)
                {
                    RotacaoRR(raiz);
                }
                else
                {
                    RotacaoRL(raiz);
                }
            }
        }
    }
    else
    {
        // Valor duplicado
        return 0;
    }

    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;

    return res;
}

/*
    Funcao de Remocao:

        - A funcao de remocao em AVL é uma funcao recursiva que realiza a comparacao entre o candidadato a ser removido e o valor da raiz.
        - Caso essa comparacao seja maior que zero, fazemos a chamada da remocao novamente com a raiz sendo o subarvore a direita e verificamos se ela foi 1.
        - Caso seja, verificamos se é necessario fazer o balanceamento da arvore com rotacoes RR e RL
        - Caso essa comparacao seja menor que zero, fazemos a chamada da remocao novamente com a raiz sendo o subarvore a esquerda e verificamos se ela foi 1.
        - Caso seja, verificamos se é necessario fazer o balanceamento da arvore com rotacoes LL e LR
        - Caso essa comparacao seja igual a zero, removemos o candidato na posicao correspondente e retornamos 1
        - Nao esquecemos que ao fim precisamos sempre atualizar a altura da arvore ao fim de cada laco
*/
int remove_ArvAVL(ArvAVL *raiz, Candidato *cand)
{
    if (raiz == NULL || *raiz == NULL)
        return 0;

    int res;
    int cmp = comparaCandidatos(cand, (*raiz)->info);

    if (cmp < 0)
    {
        if ((res = remove_ArvAVL(&(*raiz)->esq, cand)) == 1)
        {
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {

                if (alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))
                {
                    RotacaoRR(raiz);
                }
                else
                {
                    RotacaoRL(raiz);
                }
            }
        }
    }
    else if (cmp > 0)
    {
        if ((res = remove_ArvAVL(&(*raiz)->dir, cand)) == 1)
        {
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {
                if (alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                {
                    RotacaoLL(raiz);
                }
                else
                {
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            struct NO *oldNo = (*raiz);
            if ((*raiz)->esq != NULL)
                (*raiz) = (*raiz)->esq;
            else
                (*raiz) = (*raiz)->dir;
            libera_NO_ArvAVL(oldNo);
        }
        else
        {
            struct NO *temp = procuraMenor((*raiz) = (*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if (fatorBalanceamento_NO((*raiz)) >= 2)
            {
                if (alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                {
                    printf("\n Rotacao LL");
                    RotacaoRR(raiz);
                }
                else
                {
                    printf("\n Rotacao LR");
                    RotacaoRL(raiz);
                }
            }
        }
        if (*raiz != NULL)
        {
            (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
        }

        return 1;
    }
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;

    return res;
}

// ------------------------------------- FUNCOES DE IMPRESAO EM ARVORES AVL --------------------------------------//

/*
    Funcao preOrdem_ArvAVL:

        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime a raiz
            - Imprime o filho a esquerda
            - Imprime o filho a direita
        
*/
void preOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL || *raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        imprimeCandidato((*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*
    Funcao emOrdem_ArvAVL:
    
        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime o filho a esquerda
            - Imprime a raiz
            - Imprime o filho a direita
        
*/
void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        imprimeCandidato((*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*
    Funcao posOrdem_ArvAVL:
    
        A funcao faz a impressao de forma recursiva seguindo a ordem:
            - Imprime o filho a esquerda
            - Imprime o filho a direita
            - Imprime a raiz
        
*/
void posOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL) {
        printf("\033[47;30m\nCandidato(s) nao encontrado(s).\033[0m\n");
        return;
    }
    if (*raiz != NULL)
    {
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        imprimeCandidato((*raiz)->info);
    }
}


// ------------------------------------- FUNCOES DE BUSCA --------------------------------------//
/*
    Funcoes de Busca:

        - Como ideia central da busca em uma arvore binaria, eh o retorno de uma nova arvore, que vamos chamar de copia, com os candidado que queremos buscar, 
        nisso ao verificamos qual o tipo dado queremos buscar, se for estado a busca eh dada de uma forma, senao for ela eh dada de maneira diferente. 
        - Busca estado: Como sabemos que os dados por estado, cidade e numero pela maneira que as insercoes estao sendo feitas, podemos comparar estado da raiz com o estado 
        buscado, caso a comparacao feita pelo strcmp() seja menor do que zero buscamos na raiz a direita, caso seja maior do que zero buscamos na raiz a esquerda, por fim se for 
        igual a zero fazemos a insercao em copia e buscamos em ambas as subarvores.
        - Busca gera: Como sabemos que os dados por estado, cidade e numero pela maneira que as insercoes estao sendo feitas, os dados podem estar tanto na arvore a esquerda quanto 
        na arvore a direita entao apenas comparamos dado da raiz com o dado buscado, caso a comparacao feita pelo strcmp() seja igual a zero fazemos a insercao em copia e 
        depois buscamos em ambas as subarvores.
        - Esse processo eh repetido ate que todas as ocorrencias do dado seja encontrado na arvore.
        
*/

// Busca estado
void buscaEstadoAVLAux(ArvAVL *raiz, char *estado, ArvAVL *copia)
{
    if (raiz == NULL || *raiz == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getEstadoCandidato((*raiz)->info)), estado);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        buscaEstadoAVLAux(&((*raiz)->dir), estado, copia);
        buscaEstadoAVLAux(&((*raiz)->esq), estado, copia);
        return;
    }
    else if (cmp < 0)
    {
        return buscaEstadoAVLAux(&((*raiz)->dir), estado, copia);
    }
    else
        return buscaEstadoAVLAux(&((*raiz)->esq), estado, copia);
}

ArvAVL *buscaEstadoAVL(ArvAVL *raiz, char *estado)
{

    ArvAVL *copia = cria_ArvAVL();

    buscaEstadoAVLAux(raiz, estado, copia);

    return copia;
}

// Busca Cidade
void buscaCidadeAVLAux(ArvAVL *raiz, char *cidade, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getCidadeCandidato((*raiz)->info)), cidade);

    if (cmp == 0)
    {

        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
        
    }
    buscaCidadeAVLAux(&((*raiz)->dir), cidade, copia);
    buscaCidadeAVLAux(&((*raiz)->esq), cidade, copia);
}

ArvAVL *buscaCidadeAVL(ArvAVL *raiz, char *cidade)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaCidadeAVLAux(raiz, cidade, copia);

    return copia;
}

// Busca Numero
void buscaNumeroAVLAux(ArvAVL *raiz, char *numero, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getNumeroCandidato((*raiz)->info)), numero);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaNumeroAVLAux(&((*raiz)->dir), numero, copia);
    buscaNumeroAVLAux(&((*raiz)->esq), numero, copia);
}

ArvAVL *buscaNumeroAVL(ArvAVL *raiz, char *numero)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaNumeroAVLAux(raiz, numero, copia);

    return copia;
}

// Busca genero
void buscaGeneroAVLAux(ArvAVL *raiz, char *genero, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getGenero((*raiz)->info)), genero);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }

    buscaGeneroAVLAux(&((*raiz)->dir), genero, copia);
    buscaGeneroAVLAux(&((*raiz)->esq), genero, copia);
}

ArvAVL *buscaGeneroAVL(ArvAVL *raiz, char *genero)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaGeneroAVLAux(raiz, genero, copia);

    return copia;
}

// Busca Partido
void buscaPartidoAVLAux(ArvAVL *raiz, char *partido, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getPartido((*raiz)->info)), partido);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaPartidoAVLAux(&((*raiz)->dir), partido, copia);
    buscaPartidoAVLAux(&((*raiz)->esq), partido, copia);
}

ArvAVL *buscaPartidoAVL(ArvAVL *raiz, char *partido)
{
    ArvAVL *copia = cria_ArvAVL();
    buscaPartidoAVLAux(raiz, partido, copia);

    return copia;
}

// Busca Cor/Raca
void buscaCorRacaAVLAux(ArvAVL *raiz, char *corRaca, ArvAVL *copia)
{
    if (raiz == NULL || *(raiz) == NULL)
        return;

    int cmp = strcmp(stripWhitespaceAVL(getCor((*raiz)->info)), corRaca);

    if (cmp == 0)
    {
        insere_ArvAVL(copia, criaCandidato(getEstadoCandidato((*raiz)->info), getCidadeCandidato((*raiz)->info), getNumeroCandidato((*raiz)->info), getCargo((*raiz)->info), getNomeCompleto((*raiz)->info), getNomeUrna((*raiz)->info), getPartido((*raiz)->info), getGenero((*raiz)->info), getGrau((*raiz)->info), getCor((*raiz)->info)));
    }
    buscaCorRacaAVLAux(&((*raiz)->dir), corRaca, copia);
    buscaCorRacaAVLAux(&((*raiz)->esq), corRaca, copia);
}

ArvAVL *buscaCorRacaAVL(ArvAVL *raiz, char *corRaca)
{
    ArvAVL *copia = cria_ArvAVL();

    buscaCorRacaAVLAux(raiz, corRaca, copia);

    return copia;
}

// ------------------------------------- FUNCAO DE LEITURA DE ARQUIVO --------------------------------------//
/*
    FUNCAO lerArquivoAVL:
    
        - Recebe uma string que sinaliza qual arquivo deve ser lido
        - Extrai dados de candidatos pela funcao extrairToken
        - Insere os candidatos de forma sequencial por meio da funcao insere_ArvVL que recebe a arvore AVL e que recebera o candidato e a criacao do candidato 
        - O candidato a ser inserido eh criado na propria chamada da funcao que insere o candidato no vetor
        
*/

ArvAVL *lerArquivoAVL(char *enderecoArquivo)
{
    FILE *arq = fopen(enderecoArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao ler do arquivo.\n");
        return NULL;
    }
    ArvAVL *arv = cria_ArvAVL();

    char estado[3];
    char cidade[100];
    char numero[50];
    char cargo[100];
    char nomeCompleto[100];
    char nomeUrna[100];
    char siglaPartido[50];
    char genero[50];
    char grauDeInstrucao[50];
    char cor_raca[50];
    int ct = 0;
    char linha[500];
    while (fgets(linha, sizeof(linha), arq))
    {
        extrairToken(linha, estado, ";");
        extrairToken(NULL, cidade, ";");
        extrairToken(NULL, numero, ";");
        extrairToken(NULL, cargo, ";");
        extrairToken(NULL, nomeCompleto, ";");
        extrairToken(NULL, nomeUrna, ";");
        extrairToken(NULL, siglaPartido, ";");
        extrairToken(NULL, genero, ";");
        extrairToken(NULL, grauDeInstrucao, ";");
        extrairToken(NULL, cor_raca, "\n");
        insere_ArvAVL(arv, criaCandidato(estado, cidade, numero, cargo, nomeCompleto, nomeUrna, siglaPartido, genero, grauDeInstrucao, cor_raca));
        // printf("\n%d", ct);
        ct++;
    }
    fclose(arq);
    return arv;
}