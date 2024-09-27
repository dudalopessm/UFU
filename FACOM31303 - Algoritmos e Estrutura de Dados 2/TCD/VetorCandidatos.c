#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VetorCandidatos.h"

typedef struct vetorCandidatos {
    int len; 
    int quant_elem;
    Candidato **vetCandidatos;
}VetorCandidatos;

typedef struct candidato Candidato;

VetorCandidatos *criarVetorCandidato(){
    VetorCandidatos * vet = malloc(sizeof(VetorCandidatos));
    vet->len = 0;
    vet->quant_elem = 0;
    vet->vetCandidatos = NULL;
    return vet;
}

VetorCandidatos *lerArquivoVetor(char *enderecoArquivo){
    FILE *file = fopen(enderecoArquivo,"r");
    if(file == NULL){
        printf("Erro ao ler o arquivo\n");
        return NULL;
    }
    VetorCandidatos *vet = criarVetorCandidato();
    char estadoCandidato[2], cidadeCandidato[50],numeroCandidato[10],cargoCandidato[15],nomeCandidato[60],nomeNaUrna[60],siglaPartido[10],generoCandidato[20],grauCandidato[20],corCandidato[10];
    while(fscanf(file, "%2[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];",estadoCandidato, cidadeCandidato,numeroCandidato,cargoCandidato,nomeCandidato,nomeNaUrna,siglaPartido,generoCandidato,grauCandidato,corCandidato)){
        inserirCandidatos(vet, criaCandidato(estadoCandidato, cidadeCandidato,numeroCandidato,cargoCandidato,nomeCandidato,nomeNaUrna,siglaPartido,generoCandidato,grauCandidato,corCandidato));
    }
    fclose(file);
    return vet;
} 

int inserirCandidatos(VetorCandidatos *vet, Candidato *novoCandidato){
    if(vet == NULL|| novoCandidato == NULL) 
        return false;
    if (vet->len == 0){
        vet->len += 5;
        vet->vetCandidatos = (Candidato **) malloc(sizeof(Candidato*)*vet->len);
    }
    if(vet->quant_elem >= vet->len){
        vet->len += 5;
        vet->vetCandidatos = (Candidato **) realloc(vet->vetCandidatos,sizeof(Candidato*)*vet->len); 
        if(vet->vetCandidatos == NULL)
            return false;
    }
    vet->vetCandidatos[vet->quant_elem] = novoCandidato;
    /*
     (Candidato *)malloc(tamanhoCandidato());
    if(vet->vetCandidatos[vet->quant_elem] == NULL)
        return false;
    memccpy(vet->vetCandidatos[vet->quant_elem],novoCandidato,0,tamanhoCandidato());
    */
    vet->quant_elem++;
    return true;
}

//--------------------------------------------------------------------- ORDENAÇÃO ------------------------------------------------------------
//ordenação deve ser feita ao mesmo tempo -> no estado deve estar ordenado por cidade e na cidade deve estar ordenada por numero
int ordenacao(VetorCandidatos *vet, int opcao){
    int j, i, h = 1;
    int  n = vet->quant_elem;
    Candidato *temp;
    do {h = h * 3 + 1;} while(h < n);
    switch (opcao)
    {
    case 1: //estado
        do{
            h /= 3;
            for(i = h; i < n; i++){
                
                temp = vet->vetCandidatos[i];
                j = i;
                while(strcmp(getEstadoCandidato(vet->vetCandidatos[j-h]),getEstadoCandidato(temp)) > 0){
                    vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                    j -= h;
                    if(j < h) break;
                }
                vet->vetCandidatos[j] = temp;
            }
        } while (h != 1);
        return true;
        break;
    case 2://cidade
        do{
        h /= 3;
            for(i = h; i < n; i++){
                
                temp = vet->vetCandidatos[i];
                j = i;
                while(strcmp(getCidadeCandidato(vet->vetCandidatos[j-h]),getCidadeCandidato(temp)) > 0){
                    vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                    j -= h;
                    if(j < h) break;
                }
                vet->vetCandidatos[j] = temp;
            }
        } while (h != 1);
        return true;
        break;
    case 3://numero do candidato
        do{
        h /= 3;
        for(i = h; i < n; i++){
            
            temp = vet->vetCandidatos[i];
            j = i;
            while(strcmp(getNumeroCandidato(vet->vetCandidatos[j-h]),getNumeroCandidato(temp)) > 0){
                vet->vetCandidatos[j] = vet->vetCandidatos[j - h];
                j -= h;
                if(j < h) break;
            }
            vet->vetCandidatos[j] = temp;
        }
        } while (h != 1);
        return true;
        break;
    default:
        return false;
    }
    return true;
}


//--------------------------------------------------------------------- BUSCAS ------------------------------------------------------------
//dado um estado, buscar dados de um candidato -> mostra todos os candidatos de um estado e depois busca dados de um candidato 
int buscaBinariaAuxEstado(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return -1;
    char *estaux = getEstadoCandidato(vet[meio]);
    if(strcmp(estaux, chave) == 0) {
        return meio;
    }
    else if(strcmp(estaux, chave) < 0) 
        return buscaBinariaAuxEstado(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstado(vet, inf, meio-1, chave);
}
VetorCandidatos* buscaBinariaEstado(VetorCandidatos *vet, char *chave) {
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    VetorCandidatos *resultado = criarVetorCandidato();
    int posicao = buscaBinariaAuxEstado(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
    int i = posicao;
    while (strcmp(getEstadoCandidato(vet->vetCandidatos[i]), chave)==0)
    {
        i--;
    }
    i++;
    while (strcmp(getEstadoCandidato(vet->vetCandidatos[i]), chave)==0){
        inserirCandidatos(resultado, vet->vetCandidatos[i]);
    }
    return resultado;
}
//dado um estado, buscar dados de um candidato de uma cidade
int buscaBinariaAuxCidade(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return -1;
    char *cidaux = getCidadeCandidato(vet[meio]);
    if(strcmp(cidaux, chave) == 0) {
        return meio;
    }
    else if(strcmp(cidaux, chave) < 0) 
        return buscaBinariaAuxCidade(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxCidade(vet, inf, meio-1, chave);
}
VetorCandidatos* buscaBinariaCidade(VetorCandidatos *vetPrincipal, char *chave, char *estado) { 
    VetorCandidatos *vet = buscaBinariaEstado(vetPrincipal,estado); //aqui a gente passa o vetor de estados já achado para buscar cidade
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    VetorCandidatos *resultado = criarVetorCandidato();
    int posicao = buscaBinariaAuxCidade(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
    int i = posicao;
    while (strcmp(getCidadeCandidato(vet->vetCandidatos[i]), chave)==0)
    {
        i--;
    }
    i++;
    while (strcmp(getCidadeCandidato(vet->vetCandidatos[i]), chave)==0){
        inserirCandidatos(resultado, vet->vetCandidatos[i]);
    }
    return resultado;
}
//dado um estado e uma cidade, buscar dados de um candidato de um dado número
Candidato* buscaBinariaAuxNumero(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return NULL;
    char *numaux = getNumeroCandidato(vet[meio]);
    if(strcmp(numaux, chave) == 0)
        return vet[meio];
    else if(strcmp(numaux, chave) < 0) 
        return buscaBinariaAuxNumero(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxNumero(vet, inf, meio-1, chave);
}
Candidato* buscaBinariaNumero(VetorCandidatos *vetPrincipal, char *chave, char *cidade,char *estado) { 
    VetorCandidatos *vet = buscaBinariaCidade(vetPrincipal, cidade,estado);//aqui a gente passa o vetor de cidades já achado anteriormente
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    return buscaBinariaAuxNumero(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
}
/*
Usando as funções criadas no item B, o usuário possa escolher obter listagens
adicionais das informações dos candidatos: por gênero, por partido, ou por cor/raça. 
*/
//Cor
int buscaBinariaAuxEstadoCor(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return -1;
    char *coraux = getCor(vet[meio]);
    if(strcmp(coraux, chave) == 0) {            
        return meio;
    }
    else if(strcmp(coraux, chave) < 0) 
        return buscaBinariaAuxEstadoCor(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoCor(vet, inf, meio-1, chave);
}
VetorCandidatos* buscaBinariaEstadoCor(VetorCandidatos *vetPrincipal, char *chave, char *estado) {
    VetorCandidatos *vet = buscaBinariaEstado(vetPrincipal,estado);
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    VetorCandidatos *resultado = criarVetorCandidato();
    int posicao = buscaBinariaAuxEstadoCor(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
    int i = posicao;
    while (strcmp(getCor(vet->vetCandidatos[i]), chave)==0)
    {
        i--;
    }
    i++;
    while (strcmp(getCor(vet->vetCandidatos[i]), chave)==0){
        inserirCandidatos(resultado, vet->vetCandidatos[i]);
    }
    return resultado;
}
Candidato* buscaBinariaAuxEstadoCidadeCor(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return NULL;
    char *coraux = getCor(vet[meio]);
    if(strcmp(coraux, chave) == 0)
        return vet[meio];
    else if(strcmp(coraux, chave) < 0) 
        return buscaBinariaAuxEstadoCidadeCor(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoCidadeCor(vet, inf, meio-1, chave);
}
Candidato* buscaBinariaEstadoCidadeCor(VetorCandidatos *vetPrincipal, char *chave, char *cidade,char *estado) { 
    VetorCandidatos *vet = buscaBinariaCidade(vetPrincipal, cidade,estado);//aqui a gente passa o vetor de cidades já achado anteriormente
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    return buscaBinariaAuxEstadoCidadeCor(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
}
//Gênero
int buscaBinariaAuxEstadoGenero(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return -1;
    char *generoaux = getGenero(vet[meio]);
    if(strcmp(generoaux, chave) == 0) {
        return meio;
    }
    else if(strcmp(generoaux, chave) < 0) 
        return buscaBinariaAuxEstadoGenero(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoGenero(vet, inf, meio-1, chave);
}
VetorCandidatos* buscaBinariaEstadoGenero(VetorCandidatos *vetPrincipal, char *chave, char *estado) {
    VetorCandidatos *vet = buscaBinariaEstado(vetPrincipal, estado);
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    VetorCandidatos *resultado = criarVetorCandidato();
    int posicao = buscaBinariaAuxEstadoGenero(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
    int i = posicao;
    while (strcmp(getGenero(vet->vetCandidatos[i]), chave)==0)
    {
        i--;
    }
    i++;
    while (strcmp(getGenero(vet->vetCandidatos[i]), chave)==0){
        inserirCandidatos(resultado, vet->vetCandidatos[i]);
    }
    return resultado;
}
Candidato* buscaBinariaAuxEstadoCidadeGenero(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return NULL;
    char *genaux = getGenero(vet[meio]);
    if(strcmp(genaux, chave) == 0)
        return vet[meio];
    else if(strcmp(genaux, chave) < 0) 
        return buscaBinariaAuxEstadoCidadeGenero(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoCidadeGenero(vet, inf, meio-1, chave);
}
Candidato* buscaBinariaEstadoCidadeGenero(VetorCandidatos *vetPrincipal, char *chave, char *cidade,char *estado) { 
    VetorCandidatos *vet = buscaBinariaCidade(vetPrincipal, cidade,estado); //aqui a gente passa o vetor de cidades já achado anteriormente
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    return buscaBinariaAuxEstadoCidadeGenero(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
}
//Sigla partido 
int buscaBinariaAuxEstadoPartido(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return -1;
    char *partaux = getPartido(vet[meio]);
    if(strcmp(partaux, chave) == 0) {            
        return meio;
    }
    else if(strcmp(partaux, chave) < 0) 
        return buscaBinariaAuxEstadoPartido(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoPartido(vet, inf, meio-1, chave);
}
VetorCandidatos* buscaBinariaEstadoPartido(VetorCandidatos *vetPrincipal, char *chave, char *estado) {
    VetorCandidatos *vet = buscaBinariaEstado(vetPrincipal,estado);
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    VetorCandidatos *resultado = criarVetorCandidato();
    int posicao = buscaBinariaAuxEstadoPartido(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
    int i = posicao;
    while (strcmp(getPartido(vet->vetCandidatos[i]), chave)==0)
    {
        i--;
    }
    i++;
    while (strcmp(getPartido(vet->vetCandidatos[i]), chave)==0){
        inserirCandidatos(resultado, vet->vetCandidatos[i]);
    }
    return resultado;
}
Candidato* buscaBinariaAuxEstadoCidadePartido(Candidato **vet, int inf, int sup, char *chave) {
    int meio = (inf+sup)/2;
    if(inf > sup)
        return NULL;
    char *coraux = getPartido(vet[meio]);
    if(strcmp(coraux, chave) == 0)
        return vet[meio];
    else if(strcmp(coraux, chave) < 0) 
        return buscaBinariaAuxEstadoCidadePartido(vet, meio+1, sup, chave);
    else 
        return buscaBinariaAuxEstadoCidadePartido(vet, inf, meio-1, chave);
}
Candidato* buscaBinariaEstadoCidadePartido(VetorCandidatos *vetPrincipal, char *chave, char *cidade,char *estado) { 
    VetorCandidatos *vet = buscaBinariaCidade(vetPrincipal, cidade,estado);//aqui a gente passa o vetor de cidades já achado anteriormente
    if(vet == NULL)
        return NULL;
    if(vet->quant_elem == 0)
        return NULL;
    return buscaBinariaAuxEstadoCidadePartido(vet->vetCandidatos, 0, vet->quant_elem-1, chave);
}

//--------------------------------------------------------------------- IMPRESSAO ------------------------------------------------------------
void imprimeVetorInteiro(VetorCandidatos *vet){
    for(int i=0; i<vet->quant_elem;i++){
        imprimeCandidato(vet->vetCandidatos[i]);
    }
}