-- Verifique a tabela chat
SELECT * FROM chat;

SELECT * FROM req_amizade WHERE recebe_username = 'Starlight' AND envia_username = 'DragonSlayer';

UPDATE req_amizade SET status = 'Aceita' WHERE  recebe_username = 'Starlight' AND envia_username = 'DragonSlayer';

SELECT * FROM chat ORDER BY envia_username ASC;

UPDATE req_amizade SET status = 'Recusada' WHERE  recebe_username = 'Starlight' AND envia_username = 'DragonSlayer';

SELECT * FROM chat ORDER BY envia_username ASC;