#ifndef CANDIDATOS_H
#define CANDIDATOS_H
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
void CenterText(const char *text);

#endif //CANDIDATOS_H