sociedade(joao).
sociedade(suzana).
sociedade(basilio).
sociedade(elvira).
socio(X) :- homem(X),sociedade(X).
socia(Y) :- mulher(Y),sociedade(Y).
casamento(joao, suzana).
mulher(suzana).
mulher(elvira).
homem(joao).
homem(basilio).
irmandade(elvira, basilio).
irma(X,Y) :- mulher(X),irmandade(X,Y).
irmao(X,Y) :- homem(X),irmandade(Y,X).