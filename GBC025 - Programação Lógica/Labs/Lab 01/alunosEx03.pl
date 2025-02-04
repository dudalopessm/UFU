aluno(joao,ppi).
aluno(pedro,ppi).
aluno(maria,ppiii).
aluno(rui,ppiii).
aluno(manuel,ppiii).
aluno(pedro,ppiii).
aluno(rui,ppiv).
estuda(joao).
estuda(maria).
estuda(manuel).
fazppiii(X) :- aluno(X, ppiii),estuda(X).