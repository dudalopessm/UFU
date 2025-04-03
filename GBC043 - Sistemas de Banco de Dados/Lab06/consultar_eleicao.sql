SET search_path TO eleicao_2024;

-- b) Quais os nomes na urna e números na urna dos candidatos da cidade de 'UBERLÂNDIA' em ordem DESC de nome.
SELECT nm_urna_candidato, nr_candidato FROM candidato
WHERE nm_ue = 'UBERLÂNDIA'
ORDER BY nm_urna_candidato DESC;

-- c) Quais os nomes dos candidatos do estado do Acre que nasceram antes de 01/jan/1954.
SELECT nm_candidato FROM candidato
WHERE sg_uf = 'AC' AND dt_nascimento < '01/01/1954';

-- d) Quais os nomes na urna dos candidatos que tem 'LULA' ou 'BOLSONARO' como parte do nome.
SELECT nm_urna_candidato FROM candidato
WHERE nm_urna_candidato LIKE '%LULA%' OR
nm_urna_candidato LIKE '%BOLSONARO%';

-- e) Quais os nomes dos candidatos e a descrição do grau de instrução dos candidatos da cidade 'CASA BRANCA' do estado de São Paulo.
SELECT nm_candidato, ds_grau_instrucao
FROM candidato cand, grau_instrucao grau
WHERE cand.nm_ue = 'CASA BRANCA' AND cand.sg_uf = 'SP'
AND grau.cd_grau_instrucao = cand.cd_grau_instrucao;

-- f) Quais os nomes das candidatas ao cargo de vereadora e as siglas dos seus partidos concorrendo na cidade de 'CUIABÁ'.
SELECT nm_candidato, sg_partido
FROM candidato cand, partido part, genero gen, cargo carg
WHERE cand.cd_genero = gen.cd_genero
AND gen.ds_genero = 'FEMININO'
AND cand.cd_cargo = carg.cd_cargo
AND carg.ds_cargo = 'VEREADOR'
AND cand.nr_partido = part.nr_partido
AND cand.nm_ue = 'CUIABÁ';

-- g) Qual a descrição da ocupação dos candidatos do partido cuja sigla é 'PSDB' no estado da Bahia. Valores repetidos não devem ser exibidos.
SELECT DISTINCT ds_ocupacao
FROM candidato cand, ocupacao oc, partido part
WHERE cand.cd_ocupacao = oc.cd_ocupacao
AND cand.nr_partido = part.nr_partido
AND part.sg_partido = 'PSDB'
AND sg_uf = 'BA';

-- h) Quais os nomes na urna, os números na urna, as siglas dos partidos, a descrição da coligação dos candidatos aos cargos de prefeito e vice-prefeito das capitais da região sudeste.
SELECT NM_URNA_CANDIDATO, NR_CANDIDATO, SG_PARTIDO, DS_COLIGACAO
FROM CANDIDATO, COLIGACAO, PARTIDO, CARGO
WHERE UPPER(CANDIDATO.NM_UE) IN ('SÃO PAULO', 'ESPIRITO SANTO', 'RIO DE JANEIRO', 'BELO HORIZONTE')
AND CANDIDATO.CD_CARGO = CARGO.CD_CARGO
AND (CARGO.DS_CARGO = 'PREFEITO' OR CARGO.DS_CARGO ='VICE-PREFEITO')
AND CANDIDATO.NR_PARTIDO = PARTIDO.NR_PARTIDO
AND CANDIDATO.SQ_COLIGACAO = COLIGACAO.SQ_COLIGACAO;

-- i) Quais os nomes, as siglas dos partidos, as descrições dos bens e os valores dos bens dos candidatos ao cargo de 'PREFEITO' da cidade de 'SÃO PAULO'.
SELECT NM_CANDIDATO, SG_PARTIDO, DS_TIPO_BEM_CANDIDATO, VR_BEM_CANDIDATO
FROM CANDIDATO, BEM_CANDIDATO, CARGO, PARTIDO
WHERE CANDIDATO.NM_UE = 'SÃO PAULO'
AND CANDIDATO.CD_CARGO = CARGO.CD_CARGO
AND CARGO.DS_CARGO = 'PREFEITO'
AND CANDIDATO.NR_PARTIDO = PARTIDO.NR_PARTIDO
AND CANDIDATO.SQ_CANDIDATO = BEM_CANDIDATO.SQ_CANDIDATO;

-- j) Quais os nomes dos candidatos cuja data de nascimento não foi informada.
SELECT nm_candidato, dt_nascimento
FROM candidato
WHERE dt_nascimento IS NULL;

-- k) Quais os nomes, as siglas dos partidos, as descrições do estado civil, a descrição da ocupação das candidatas ao cargo de 'PREFEITO' das capitais do sudeste.
SELECT NM_CANDIDATO,SG_PARTIDO,DS_ESTADO_CIVIL,DS_OCUPACAO
FROM CANDIDATO C, PARTIDO P, OCUPACAO O, GENERO G, ESTADO_CIVIL E
WHERE DS_GENERO = 'FEMININO'
AND C.CD_GENERO = G.CD_GENERO
AND C.NR_PARTIDO = P.NR_PARTIDO
AND C.CD_ESTADO_CIVIL=E.CD_ESTADO_CIVIL
AND C.CD_OCUPACAO=O.CD_OCUPACAO
AND UPPER(NM_UE) IN ('BELO HORIZONTE ','RIO DE JANEIRO','SÃO PAULO','VITÓRIA');

-- l) Apresente o enunciado, o comando SQL, e o resultado da execução do comando para mais duas consultas que você julgue interessante (devem ser diferentes das apresentadas na lista e devem envolver a junção de pelo menos 2 tabelas).
-- 1. Quais os nomes e as siglas dos partidos dos candidatos a prefeitos de ‘ROMARIA’
SELECT NM_CANDIDATO, SG_PARTIDO
FROM CANDIDATO, PARTIDO, CARGO
WHERE CANDIDATO.NM_UE = 'ROMARIA'
AND CANDIDATO.CD_CARGO = CARGO.CD_CARGO
AND CARGO.DS_CARGO = 'PREFEITO'
AND CANDIDATO.NR_PARTIDO = PARTIDO.NR_PARTIDO;

-- 2. Qual o estado civil dos candidatos da cidade de ‘UBERLANDIA’, com a cor raça ‘PRETA’.
SELECT DS_ESTADO_CIVIL
FROM CANDIDATO, ESTADO_CIVIL, COR_RACA
WHERE CANDIDATO.CD_COR_RACA = COR_RACA.CD_COR_RACA
AND COR_RACA.DS_COR_RACA = 'PRETA'
AND CANDIDATO.CD_ESTADO_CIVIL = ESTADO_CIVIL.CD_ESTADO_CIVIL
AND CANDIDATO.NM_UE = 'UBERLÂNDIA';