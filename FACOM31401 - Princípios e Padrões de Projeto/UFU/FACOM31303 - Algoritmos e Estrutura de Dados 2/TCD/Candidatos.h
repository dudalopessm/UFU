#ifndef CANDIDATOS_H
#define CANDIDATOS_H
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

typedef struct candidato Candidato;

Candidato *criaCandidato(char *estado, char *cidade, char *num, char *cargo, char *nomeCandidato, char *nomeUrna, char *sigla, char *genero, char *grau, char *raca);

char *extrairToken(char *linha, char *token, const char *delimitador);
char *getEstadoCandidato(Candidato *cand);
char *getCidadeCandidato(Candidato *cand);
char *getNumeroCandidato(Candidato *cand);
char *getCargo(Candidato *cand);
char *getNomeCompleto(Candidato *cand);
char *getNomeUrna(Candidato *cand);
char *getGrau(Candidato *cand);
char *getGenero(Candidato *cand);
char *getPartido(Candidato *cand);
char *getCor(Candidato *cand);
void destroiCandidato(Candidato *it);
int comparaCandidatos(Candidato *a, Candidato *b);

void imprimeCandidato(Candidato *it);

#endif //CANDIDATOS_H