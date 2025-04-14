SET search_path TO facepage;

-- Criando uma visao para os ranking

CREATE OR REPLACE VIEW ranking AS
SELECT nome, username, pontuacao FROM joga INNER JOIN jogo USING(codigo)
ORDER BY nome, pontuacao DESC;
