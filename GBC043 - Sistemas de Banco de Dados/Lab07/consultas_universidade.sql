SET search_path TO universidade;

-- a) Todos os cursos da universidade.
SELECT * FROM curso;

-- b) Quais os nomes e telefones de alunos da cidade de São Carlos - SP em ordem DESC de nome.
SELECT nome, telefone
FROM aluno
WHERE aluno.cidade = 'SAO CARLOS - SP'
ORDER BY aluno.nome DESC;

-- c) Quais os nomes de professores que foram contratados antes de 01/jan/1993.
SELECT nome
FROM professor
WHERE professor.admissao < '01/01/1993';

-- d) Quais os nomes de alunos que iniciam com a letra 'J'.
SELECT nome
FROM aluno
WHERE aluno.nome LIKE 'J%';

-- e) Quais os nomes das disciplinas do curso de Ciência da Computação.
SELECT disciplina.nome
FROM disciplina, curso, disciplinacurso
WHERE disciplinacurso.numdisp = disciplina.numdisp
AND disciplinacurso.numcurso = curso.numcurso
AND curso.nome = 'CIENCIA DA COMPUTACAO';

-- f) Quais os nomes dos cursos que possuem no curriculum a disciplina Cálculo Numérico.
SELECT curso.nome
FROM disciplina, curso, disciplinacurso
WHERE disciplinacurso.numdisp = disciplina.numdisp
AND disciplinacurso.numcurso = curso.numcurso
AND disciplina.nome = 'CALCULO NUMERICO';

-- g) Quais os nomes das disciplina que o aluno Marcos João Casanova cursou no 1º semestre de 1998.
SELECT disciplina.nome
FROM aluno, disciplina, aula
WHERE aula.numaluno = aluno.numaluno
AND aula.numdisp = disciplina.numdisp
AND aula.semestre = '01/1998'
AND aluno.nome = 'MARCOS JOAO CASANOVA';

-- h) Quais os nomes das disciplinas que o aluno Ailton Castro foi reprovado.
SELECT disciplina.nome
FROM aluno, disciplina, aula
WHERE aula.numaluno = aluno.numaluno
AND aula.numdisp = disciplina.numdisp
AND aluno.nome = 'AILTON CASTRO'
AND aula.nota <= '7';

-- i) Quais os nomes de alunos reprovados na disciplina de Cálculo Numérico no 1º semestre de 1998.
SELECT aluno.nome
FROM aluno, disciplina, aula
WHERE aula.numaluno = aluno.numaluno
AND aula.numdisp = disciplina.numdisp
AND disciplina.nome = 'CALCULO NUMERICO'
AND aula.nota < '7'
AND aula.semestre = '01/1998';

-- j) Quais os nomes das disciplinas ministradas pelo prof. Ramon Travanti.
SELECT disciplina.nome
FROM professor, disciplina, aula
WHERE aula.numfunc = professor.numfunc
AND aula.numdisp = disciplina.numdisp
AND professor.nome = 'RAMON TRAVANTI';

-- k) Quais os nomes dos professores que já ministraram aula de Banco de Dados.
SELECT DISTINCT professor.nome
FROM professor, disciplina, aula
WHERE aula.numfunc = professor.numfunc
AND aula.numdisp = disciplina.numdisp
AND disciplina.nome = 'BANCO DE DADOS';

-- l) Quais os nomes de alunos que cursaram o 1º semestre de 1998 em ordem alfabética, em cada disciplina oferecida nesse semestre (listar também os nomes das disciplinas e os nomes dos professores que ministraram cada disciplina).
SELECT aluno.nome, disciplina.nome, professor.nome
FROM professor, disciplina, aula, aluno
WHERE aula.numfunc = professor.numfunc
AND aula.numdisp = disciplina.numdisp
AND aula.numaluno = aluno.numaluno
AND aula.semestre = '01/1998' ORDER BY aluno.nome ASC;

-- m) Quais nomes de alunos, nomes de disciplinas e notas do 1º semestre de 1998 no curso de Ciência da Computação.
SELECT aluno.nome, disciplina.nome, aula.nota
FROM curso, disciplina, aula, aluno, disciplinacurso
WHERE aula.numdisp = disciplina.numdisp
AND aula.numaluno = aluno.numaluno
AND disciplinacurso.numdisp = disciplina.numdisp
AND disciplinacurso.numcurso = curso.numcurso
AND curso.nome = 'CIENCIA DA COMPUTACAO'
AND aula.semestre = '01/1998';