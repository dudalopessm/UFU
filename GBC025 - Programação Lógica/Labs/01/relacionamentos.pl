pai(carlos,ana).
pai(carlos,juliana).
pai(joao,carlos).
homem(pedro).
homem(carlos).
mulher(ana).
mulher(juliana).
filha(X,Y) :- pai(Y,X),mulher(X).
filho(X,Y) :- pai(Y,X),homem(X).
