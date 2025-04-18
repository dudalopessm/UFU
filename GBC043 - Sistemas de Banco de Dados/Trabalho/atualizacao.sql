-- Vamos tomar dois usuarios pessoais para os testes de atualização no banco de dados, eles são:
-- DragonSlayer e ShadowHunter

-- Teste 1 para atualização do status de requisição de amizade

SET search_path TO facepage;

SELECT * FROM chat WHERE (recebe_username = 'DragonSlayer' AND envia_username = 'ShadowHunter') OR (envia_username = 'DragonSlayer' AND recebe_username = 'ShadowHunter');

UPDATE req_amizade SET status = 'Recusada' WHERE (recebe_username = 'DragonSlayer' AND envia_username = 'ShadowHunter') OR (envia_username = 'DragonSlayer' AND recebe_username = 'ShadowHunter');

SELECT * FROM chat WHERE (recebe_username = 'DragonSlayer' AND envia_username = 'ShadowHunter') OR (envia_username = 'DragonSlayer' AND recebe_username = 'ShadowHunter');

UPDATE req_amizade SET status = 'Aceita' WHERE  (recebe_username = 'DragonSlayer' AND envia_username = 'ShadowHunter') OR (envia_username = 'DragonSlayer' AND recebe_username = 'ShadowHunter');

SELECT * FROM chat WHERE (recebe_username = 'DragonSlayer' AND envia_username = 'ShadowHunter') OR (envia_username = 'DragonSlayer' AND recebe_username = 'ShadowHunter');

-- Teste 2 para atualizar o nome do grupo de amigos da DragonSlayer

SELECT * FROM grupo_amigos WHERE admin = 'DragonSlayer';

UPDATE grupo_amigos SET nome = 'Caçadores de Dragões' WHERE nome = 'Guilda das Feras' and admin = 'DragonSlayer';

SELECT * FROM grupo_amigos WHERE admin = 'DragonSlayer';