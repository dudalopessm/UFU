SET search_path TO facepage;

-- Mostrar o nome de cada comunidade, os membros presente nela, a quantidade de membros por comunidade, o total de membros de toda a comunidade e a quantidade de comunidades que cada membro participa (em uma mesma consulta)
SELECT comunidade, membro, count(*) FROM membros_comunidade
GROUP BY CUBE(comunidade, membro)
ORDER BY comunidade, membro;

-- Mostrar quantas contas empresariais e quantas pessoais existem na rede social
SELECT
    (SELECT COUNT(*) FROM empresarial) AS quantidade_empresariais,
    (SELECT COUNT(*) FROM pessoal) AS quantidade_pessoais;

-- Mostrar qual conta tem mais páginas associadas ao perfil
SELECT u.username, COUNT(*) AS total_paginas
FROM usuario_conta u
	INNER JOIN pagina p ON u.username = p.criador
GROUP BY u.username
ORDER BY total_paginas DESC
LIMIT 1;

-- Maior pontuação do ranking, o jogo correspondente e o usuário que realizou (Separado por jogo)

SELECT jogo, username, pontuacao AS maior_pontuacao
FROM ranking
WHERE posicao_ranking = 1
ORDER BY jogo;

-- Mostrar a pontuação do ranking, o jogo correspondente e o usuário que realizou (Separado por jogo)

SELECT jogo, username, pontuacao AS menor_pontuacao
FROM ranking R
WHERE posicao_ranking = (SELECT MAX(posicao_ranking) 
        FROM ranking R2 
        WHERE R2.jogo = R.jogo)
ORDER BY jogo;


-- Mensagens do chat com número de mensagens entre 2 e 10

SELECT chat_envia_username, chat_recebe_username
FROM mensagem
GROUP BY chat_envia_username, chat_recebe_username
HAVING COUNT(*) BETWEEN 2 AND 10
ORDER BY chat_envia_username, chat_recebe_username;

-- Descrição e título da comunidade com mais membros
CREATE VIEW contagem_membros_comunidades AS
	SELECT comunidade, COUNT(*) AS total_membros
    	FROM membros_comunidade
    	GROUP BY comunidade;

CREATE VIEW comunidades_mais_populares AS 
    SELECT comunidade, total_membros
    	FROM contagem_membros_comunidades
    	WHERE total_membros = (SELECT MAX(total_membros) FROM contagem_membros_comunidades);

SELECT c.nome_comunidade, c.descricao, cmp.total_membros
	FROM comunidade c
		INNER JOIN comunidades_mais_populares cmp ON c.nome_comunidade = cmp.comunidade;

-- Listar topicos criados entre setembro e dezembro do ano de 2023
SELECT t.comunidade, t.membro AS autor, t.titulo, t.descricao, t.data
	FROM topico t
	WHERE t.data BETWEEN '2023-09-01' AND '2023-12-01';

-- Quantas requisições de amizade tem cada status

SELECT r.status, COUNT(*) AS quantidade
FROM req_amizade r
GROUP BY r.status;

-- Quais grupos de amigos podem ver quais páginas

SELECT g.nome AS nome_grupo, p.nome AS nome_pagina, p.criador AS criador_pagina
	FROM grupo_amigos g INNER JOIN pode_ver pv ON g.codigo = pv.codigo_grupo 
	INNER JOIN pagina p ON pv.nome = p.nome AND pv.criador = p.criador
ORDER BY g.codigo, p.nome;

-- Páginas com as maiores taxas de conversão, rejeição e cliques
SELECT nome, criador, taxa_conversao, 'taxa_conversao' AS tipo_metrica
FROM propaganda
WHERE taxa_conversao = (SELECT MAX(taxa_conversao) FROM propaganda)

UNION

SELECT nome, criador, taxa_rejeicao, 'taxa_rejeicao' AS tipo_metrica
FROM propaganda
WHERE taxa_rejeicao = (SELECT MAX(taxa_rejeicao) FROM propaganda)

UNION

SELECT nome, criador, taxa_cliques, 'taxa_cliques' AS tipo_metrica
FROM propaganda
WHERE taxa_cliques = (SELECT MAX(taxa_cliques) FROM propaganda);