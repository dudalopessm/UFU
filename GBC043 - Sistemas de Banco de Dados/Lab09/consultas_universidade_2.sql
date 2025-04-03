SET search_path TO universidade;

-- a) Qual a maior e a menor nota na disciplina de Cálculo Numérico no 1º semestre de 1998.
SELECT MAX(au.nota) AS nota_max, MIN(au.nota) AS nota_min
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN disciplina d ON au.numdisp = d.numdisp
WHERE d.nome = 'CALCULO NUMERICO'
AND au.semestre = '01/1998';

-- b) Qual o nome do aluno que obteve maior nota na disciplina de Engenharia de Software no 1º semestre de 1998. Deve retornar o nome e a nota do aluno.
SELECT MAX(au.nota) AS nota, a.nome
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN disciplina d ON au.numdisp = d.numdisp
WHERE d.nome = 'ENGENHARIA DE SOFTWARE'
AND au.semestre = '01/1998'
AND au.nota = (SELECT MAX(au.nota) FROM aula au)
GROUP BY a.nome;

-- c) Qual a média de notas do professor Marcos Salvador.
SELECT AVG(au.nota) AS nota, p.nome
FROM aula au
INNER JOIN professor p ON p.numfunc = au.numfunc
WHERE p.nome = 'MARCOS SALVADOR'
GROUP BY p.nome;

-- d) Quais os alunos que tiveram nota entre 5.0 e 7.0 em ordem alfabetica de disciplina. Deve retornar o nome do aluno, o nome da disciplina e nota referente a disciplina.
SELECT d.nome, a.nome, au.nota
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN disciplina d ON au.numdisp = d.numdisp
WHERE au.nota BETWEEN 5.0 AND 7.0
ORDER BY d.nome ASC;

-- e) Quantos alunos o professor Abgair teve no 1º semestre de 1998.
SELECT p.nome, COUNT(a.numaluno) AS quantidade_aluno
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN professor p ON au.numfunc = p.numfunc
WHERE p.nome LIKE 'ABGAIR%'
AND au.semestre = '01/1998'
GROUP BY p.nome;

-- f) Qual a média de notas e a quantidade de disciplinas cursadas pelo aluno Edvaldo Carlos Silva.
SELECT a.nome, AVG(au.nota) AS media, COUNT(au.numaluno) AS quantidade_disc
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
WHERE a.nome = 'EDVALDO CARLOS SILVA'
GROUP BY a.nome;

-- g) Quais as médias das notas, por nome de disciplina, de todos os cursos do 1º semestre de 1998 em ordem alfabética de disciplina.
SELECT d.nome AS disciplina, c.nome AS curso, AVG(au.nota) AS medias_por_disc
FROM disciplinacurso dc
INNER JOIN disciplina d ON dc.numdisp = d.numdisp
INNER JOIN curso c ON dc.numcurso = c.numcurso
INNER JOIN aula au ON dc.numdisp = au.numdisp
WHERE au.semestre = '01/1998'
GROUP BY c.nome, d.nome
ORDER BY d.nome ASC;

-- h) Quais as médias das notas, por nome de professor, no 1º semestre de 1998
SELECT p.nome AS professor, AVG(au.nota) AS medias_por_prof
FROM aula au
INNER JOIN professor p ON au.numfunc = p.numfunc
WHERE au.semestre = '01/1998'
GROUP BY p.nome;

-- i) Qual a média das notas , por disciplina, no 1º semestre de 1998 do curso de Ciência da Computação.
SELECT d.nome AS disciplina, AVG(au.nota) AS medias_por_disc
FROM disciplinacurso dc
INNER JOIN disciplina d ON dc.numdisp = d.numdisp
INNER JOIN curso c ON dc.numcurso = c.numcurso
INNER JOIN aula au ON dc.numdisp = au.numdisp
WHERE au.semestre = '01/1998'
AND c.nome = 'CIENCIA DA COMPUTACAO'
GROUP BY d.nome;

-- j) Qual foi a quantidade de créditos concluídos (considerar somente as disciplinas aprovadas) do aluno Edvaldo Carlos Silva.
SELECT a.nome, SUM(d.quantcreditos) AS soma_creditos
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN disciplina d ON au.numdisp = d.numdisp
WHERE au.nota >= 7.0
AND a.nome = 'EDVALDO CARLOS SILVA'
GROUP BY a.nome;

-- k) Quais os nomes de alunos que já completaram 70 créditos (considerar somente os aprovados na disciplina). Deve retornar os nomes dos alunos e a quantidade de créditos.
SELECT a.nome, SUM(d.quantcreditos) AS creditos_completados
FROM aula au
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN disciplina d ON au.numdisp = d.numdisp
WHERE au.nota >= 7.0
GROUP BY a.nome, d.quantcreditos
HAVING SUM(d.quantcreditos) >= 70;

-- l) Quais os nomes de alunos que cursaram o 1º semestre de 1998, pertencem ao curso de Ciência da Computação e possuem nota superior à 8.0. Deve retornar os nomes dos alunos, os nomes da disciplina e os nomes dos professores.
SELECT a.nome AS aluno, d.nome AS disciplina, p.nome AS professor
FROM disciplinacurso dc
INNER JOIN disciplina d ON dc.numdisp = d.numdisp
INNER JOIN curso c ON dc.numcurso = c.numcurso
INNER JOIN aula au ON dc.numdisp = au.numdisp
INNER JOIN aluno a ON au.numaluno = a.numaluno
INNER JOIN professor p ON au.numfunc = p.numfunc
WHERE au.nota > 8.0
AND au.semestre = '01/1998'
AND c.nome = 'CIENCIA DA COMPUTACAO'
ORDER BY a.nome ASC;