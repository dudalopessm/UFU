SET search_path TO eleicao_2024;

-- a) Qual o maior e o menor valor de bem dos candidatos do estado de Minas Gerais.
SELECT MAX(vr_bem_candidato), MIN(vr_bem_candidato)
FROM candidato c INNER JOIN bem_candidato b
ON c.sq_candidato = b.sq_candidato
WHERE sg_uf = 'MG';

-- b) Qual o nome, o número do partido, o estado e a cidade do candidato que possui o maior valor de bem. Deve retornar também o valor do bem.
SELECT nm_candidato, nr_candidato, sg_uf, nm_ue, vr_bem_candidato
FROM candidato c INNER JOIN bem_candidato b
ON c.sq_candidato = b.sq_candidato
WHERE vr_bem_candidato IN (SELECT MAX(vr_bem_candidato) FROM candidato c INNER JOIN bem_candidato b
ON c.sq_candidato = b.sq_candidato);

-- c) Qual a média dos valores dos bens do candidato 'JOSE LUIZ DATENA'.
SELECT AVG(vr_bem_candidato) as media_bens
FROM candidato c INNER JOIN bem_candidato b
ON c.sq_candidato = b.sq_candidato
WHERE c.nm_candidato = 'JOSE LUIZ DATENA';

-- d) Quantos candidatos ao cargo de vereador cada estado possui. Deve retornar o estado e a quantidade considerando a ordenação em ordem alfabética por estado.
SELECT sg_uf, COUNT(car.cd_cargo) AS quantidade
FROM candidato c INNER JOIN cargo car 
ON c.cd_cargo = car.cd_cargo
WHERE car.ds_cargo = 'VEREADOR'
GROUP BY sg_uf ORDER BY(sg_uf) ASC;

-- e) Quantas candidatas do gênero feminino estão concorrendo ao cargo de vereador por capital da região sudeste.
SELECT nm_ue, COUNT(c.sq_candidato) AS quantidade_vereadoras
FROM cargo car INNER JOIN (candidato c INNER JOIN genero g ON c.cd_genero = g.cd_genero) 
ON c.cd_cargo = car.cd_cargo
WHERE car.ds_cargo = 'VEREADOR'
AND g.ds_genero = 'FEMININO'
AND UPPER(nm_ue) IN ('SÃO PAULO', 'RIO DE JANEIRO', 'VITÓRIA', 'BELO HORIZONTE')
GROUP BY nm_ue;

-- f) Quantas coligações distintas existem nas eleições de 2024.
SELECT COUNT(DISTINCT sq_coligacao) AS quantidade
FROM coligacao;

-- g) Quantas candidatas do gênero feminino estão concorrendo ao cargo de vereador por partido político na cidade de 'UBERLÂNDIA'. Devem ser exibidos no resultado a sigla do partido e a quantidade.
SELECT sg_partido, COUNT(c.sq_candidato)
FROM candidato c, partido p, genero g, cargo car
WHERE c.nr_partido = p.nr_partido
AND c.cd_genero = g.cd_genero
AND c.cd_cargo = car.cd_cargo
AND nm_ue = 'UBERLÂNDIA'
AND ds_genero = 'FEMININO'
AND ds_cargo = 'VEREADOR'
GROUP BY sg_partido ORDER BY (sg_partido) ASC;

-- h) Quais são os partidos políticos que possuem mais do que 10 candidatos do gênero feminino na cidade de 'SÃO PAULO'. Devem ser exibidos no resultado a sigla do partido e a quantidade.
SELECT sg_partido, COUNT(c.sq_candidato) AS quantidade
FROM candidato c, partido p, genero g
WHERE c.nr_partido = p.nr_partido
AND c.cd_genero = g.cd_genero
AND nm_ue = 'SÃO PAULO'
AND ds_genero = 'FEMININO'
GROUP BY sg_partido
HAVING COUNT(c.sq_candidato) > 10;

-- i) Qual a quantidade de candidatos por partido e por cor/raça concorrendo nas eleições de 2024 na cidade de 'CUIABÁ'. Deve retornar a sigla do partido, a descrição cor/raça e a quantidade.
SELECT sg_partido, ds_cor_raca, COUNT(c.sq_candidato) AS quantidade
FROM candidato c 
INNER JOIN cor_raca cor ON c.cd_cor_raca = cor.cd_cor_raca
INNER JOIN partido p ON c.nr_partido = p.nr_partido
WHERE nm_ue = 'CUIABÁ'
GROUP BY sg_partido, ds_cor_raca;

-- j) Qual o partido político com a maior quantidade de candidatos na cidade de 'BELO HORIZONTE'. Devem ser exibidos no resultado o número do partido e a quantidade.
SELECT NR_PARTIDO, COUNT(SQ_CANDIDATO) AS contagem
FROM CANDIDATO C
WHERE C.NM_UE = upper('BELO HORIZONTE')
GROUP BY NR_PARTIDO
HAVING COUNT(SQ_CANDIDATO) = (
    SELECT MAX(contagem) FROM (SELECT NR_PARTIDO, COUNT(SQ_CANDIDATO) AS contagem
                                FROM CANDIDATO C
                                WHERE C.NM_UE = upper('BELO HORIZONTE')
                                GROUP BY NR_PARTIDO
                                ORDER BY contagem DESC) foo);

-- k) Apresente o enunciado, o comando SQL, e o resultado da execução do comando para mais duas consultas que você julgue serem interessantes (devem ser diferentes das apresentadas na lista e devem envolver a junção de pelo menos 2 tabelas e group by ou aninhamento).

-- 1. Quantidade de engenheiros por partido:
SELECT SG_PARTIDO, COUNT(C.SQ_CANDIDATO)
FROM (CANDIDATO C JOIN OCUPACAO O ON O.CD_OCUPACAO = C.CD_OCUPACAO) JOIN PARTIDO P ON C.NR_PARTIDO = P.NR_PARTIDO
WHERE DS_OCUPACAO ='ENGENHEIRO'
GROUP BY P.SG_PARTIDO;

-- 2. Quantidade de candidatos que tenham 'LULA' no nome por partido no estado de MG:
SELECT P.SG_PARTIDO, COUNT(SQ_CANDIDATO) AS contagem
FROM CANDIDATO C JOIN PARTIDO P ON P.NR_PARTIDO = C.NR_PARTIDO
WHERE C.NM_CANDIDATO LIKE '%LULA%' AND
    C.SG_UF = 'MG'
GROUP BY P.SG_PARTIDO;