-- Criação da SP para calcular o número de amigos corretamente

SET search_path TO facepage;

CREATE OR REPLACE FUNCTION calcula_nro_amigos()
RETURNS VOID AS $$
BEGIN
    UPDATE pessoal AS P
    SET nro_amg = (SELECT COUNT(*) FROM req_amizade R
        WHERE (R.recebe_username = P.username OR
            R.envia_username = P.username) AND
            R.status = 'Aceita');
			
END $$ LANGUAGE 'plpgsql';

SELECT calcula_nro_amigos();

-- Criação da SP para calcular o número de amigos corretamente

SET search_path TO facepage;

CREATE OR REPLACE FUNCTION calcula_nro_membros_comunidade()
RETURNS VOID AS $$
BEGIN
    UPDATE comunidade AS C
    SET nro_membros = (SELECT COUNT(*) FROM membros_comunidade M WHERE M.comunidade = C.nome_comunidade);
			
END $$ LANGUAGE 'plpgsql';

SELECT calcula_nro_membros_comunidade();

-- Criar uma SP para averiguar o ranking e retornar o jogador de maior pontuacao em cada jogo retornar nome e pontuação
/*
CREATE OR REPLACE FUNCTION 
ranking()
RETURNS VOID AS $$
BEGIN
    SELECT 
END $$ LANGUAGE 'plpgsql'
*/
-- Criar uma funcao que crie itens nos chats, e faça a remoção de duplicatas nas tabelas, onde caso haja 


-- Trigger para quando a requisição de amizade mudar, fazer determinadas ações como deletar o chat (caso a req seja pendente), criar um chat(solicitação seja aceita e aumentar o número de amigos)

CREATE OR REPLACE FUNCTION trigger_chats()
RETURNS TRIGGER AS $$
DECLARE
    user1 TEXT := NEW.envia_username;
    user2 TEXT := NEW.recebe_username;
BEGIN
    IF (TG_OP = 'INSERT' OR TG_OP = 'UPDATE') AND NEW.status = 'Aceita' AND old.status != 'Aceita' THEN
        IF NOT EXISTS (
            SELECT 1 FROM chat 
            WHERE (envia_username = user1 AND recebe_username = user2) 
               OR (envia_username = user2 AND recebe_username = user1)
        ) THEN
            INSERT INTO chat (nome, envia_username, recebe_username)
            VALUES (CONCAT('Chat ', user1, ' & ', user2), user1, user2);
            
            UPDATE pessoal SET nro_amg = nro_amg + 1 
            WHERE username IN (user1, user2);

            RAISE NOTICE 'Trigger req_amizade_chat ativado para criação';
        END IF;
    END IF;

    IF TG_OP = 'UPDATE' AND NEW.status != 'Aceita' AND OLD.status = 'Aceita' THEN
        DELETE FROM chat
        WHERE (envia_username = user1 AND recebe_username = user2) 
           OR (envia_username = user2 AND recebe_username = user1);
    
        UPDATE pessoal SET nro_amg = nro_amg - 1 
        WHERE username IN (user1, user2);
        RAISE NOTICE 'Trigger req_amizade_chat ativado para deleção';
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER req_amizade_chat 
BEFORE INSERT OR UPDATE ON req_amizade
FOR EACH ROW
EXECUTE FUNCTION trigger_chats();
