SET search_path TO facepage;

-- Visão para rankings de jogos (agregação)
CREATE OR REPLACE VIEW ranking AS
SELECT 
    j.nome AS jogo,
    jg.username,
    jg.pontuacao,
    RANK() OVER (PARTITION BY j.nome ORDER BY jg.pontuacao DESC) AS posicao_ranking
FROM 
    joga jg
JOIN 
    jogo j ON jg.nome_jogo = j.nome
ORDER BY 
    j.nome, posicao_ranking;