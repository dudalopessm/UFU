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

-- SP para compartilhar uma determinada pontuação de um jogador (pessoal) de um jog especifico em um determinado chat de amigo ao qual ele participa(mensagem)

CREATE OR REPLACE FUNCTION mostrar_pontuacao(IN username_jogador pessoal.username%TYPE, IN username_recebe pessoal.username%TYPE, IN nome_jogo jogo.nome%TYPE) 
RETURNS VOID AS $$
DECLARE
    mensagem TEXT;
    existe_jogo boolean;
    pontos joga.pontuacao%TYPE;
BEGIN
    -- Verifica se o jogo existe
    SELECT EXISTS (
        SELECT 1 FROM jogo 
        WHERE nome = nome_jogo
    ) INTO existe_jogo;

    IF NOT existe_jogo THEN
        RAISE EXCEPTION 'Nenhum jogo encontrado com o nome %, revisar os parametros de entrada!', 
            nome_jogo;
    END IF;


    -- Verifica se a pontuação existe a caso exista coloca
    SELECT ranking.pontuacao INTO pontos FROM ranking
    WHERE username = ranking.username AND
        ranking.jogo = nome_jogo
    LIMIT 1;

    IF pontos IS NULL THEN
        pontos := 0;
    END IF; 

    mensagem := FORMAT('Olha %s, minha incrivel pontuação de %s no jogo %s !! Incrível não?', username_recebe, pontos, nome_jogo);

    INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES (username_recebe, username_jogador, mensagem);
END;
$$ LANGUAGE plpgsql;

-- Funcao para encontrar a media da pontuaçao de um determinado jogo

CREATE OR REPLACE FUNCTION media_pontuacao_jogo(nome_do_jogo VARCHAR(30))
RETURNS DECIMAL(10, 2) AS $$
DECLARE
    media DECIMAL(10, 2);
BEGIN
    SELECT AVG(pontuacao) INTO media
    FROM joga
    WHERE nome_jogo = nome_do_jogo;
    
    RETURN media;
END;
$$ LANGUAGE plpgsql;


-- Trigger para quando a requisição de amizade mudar, fazer determinadas ações como deletar o chat (caso a req seja pendente), criar um chat(solicitação seja aceita e aumentar o número de amigos)

CREATE OR REPLACE FUNCTION trigger_chats()
RETURNS TRIGGER AS $$
DECLARE
    user1 TEXT := NEW.envia_username;
    user2 TEXT := NEW.recebe_username;
BEGIN
    -- Para INSERT ou UPDATE quando status muda para 'Aceita'
    IF (TG_OP = 'INSERT' AND NEW.status = 'Aceita') OR 
       (TG_OP = 'UPDATE' AND NEW.status = 'Aceita' AND OLD.status != 'Aceita') THEN
        IF NOT EXISTS (
            SELECT 1 FROM chat 
            WHERE (envia_username = user1 AND recebe_username = user2) 
               OR (envia_username = user2 AND recebe_username = user1)
        ) THEN
            INSERT INTO chat (nome, envia_username, recebe_username)
            VALUES (CONCAT('Chat ', user1, ' & ', user2), user1, user2);
            
            UPDATE pessoal SET nro_amg = nro_amg + 1 
            WHERE username IN (user1, user2);

            RAISE NOTICE 'Trigger req_amizade_chat ativado para criação de chat';
        END IF;
    END IF;

    -- Para UPDATE quando status deixa de ser 'Aceita'
    IF TG_OP = 'UPDATE' AND NEW.status != 'Aceita' AND OLD.status = 'Aceita' THEN
        DELETE FROM chat
        WHERE (envia_username = user1 AND recebe_username = user2) 
           OR (envia_username = user2 AND recebe_username = user1);
    
        UPDATE pessoal SET nro_amg = nro_amg - 1 
        WHERE username IN (user1, user2);
        RAISE NOTICE 'Trigger req_amizade_chat ativado para deleção de chat';
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER req_amizade_chat 
BEFORE INSERT OR UPDATE ON req_amizade
FOR EACH ROW
EXECUTE FUNCTION trigger_chats();

-- Trigger para inserção nos chats de forma correta, no caso é a inserção de mensagens nos chats correspondentes da forma em que (A, B, mensagem) onde A recebe a mensagem, B envia a mensagem e mensagem é o conteudo da mensagem. 
-- O trigger haje para que inserçoes indevidad nao acontençam e que independente da ordem A, B ou B, A exista um chat correspondente (trigger de cima faz essa garantia olhando as requisições de amizade)

CREATE OR REPLACE FUNCTION inserir_chat_mensagem()
RETURNS TRIGGER AS $$
DECLARE
    chat_na_direcao boolean;
    chat_na_direcao_oposta boolean;
    recebe TEXT := NEW.chat_recebe_username;
    envia TEXT := NEW.chat_envia_username;
    temp_username varchar;
BEGIN

    -- Verifica se existe chat na direção A → B (recebe: A, envia: B)
    SELECT EXISTS (
        SELECT 1 FROM chat 
        WHERE recebe_username = recebe
        AND envia_username = envia
    ) INTO chat_na_direcao;

    -- Verifica se existe chat na direção oposta B → A
    SELECT EXISTS (
        SELECT 1 FROM chat 
        WHERE recebe_username = envia
        AND envia_username = recebe
    ) INTO chat_na_direcao_oposta;

    -- Se não existe chat em nenhuma direção
    IF NOT chat_na_direcao AND NOT chat_na_direcao_oposta THEN
        RAISE EXCEPTION 'Nenhum chat autorizado encontrado entre % e %. A mensagem não foi enviada.', 
            NEW.chat_envia_username, NEW.chat_recebe_username;
        RETURN NULL;
    END IF;

    RAISE NOTICE '-------------------------------'; 
    NEW.remetente := envia;
    RAISE NOTICE 'Criando mensagem entre % e %', envia, recebe; 
    -- Padroniza a direção para (A, B) onde B envia para A
    -- Se o chat existente estiver na direção oposta (B → A), invertemos
    IF chat_na_direcao_oposta AND (NOT chat_na_direcao) THEN
        -- Inverte a direção da mensagem para manter o padrão (A, B)
        RAISE NOTICE 'TROCA % e %', envia, recebe; 
        temp_username := recebe;
        recebe := envia;
        envia := temp_username;
        RAISE NOTICE 'TROCA FEITA NOVOS ENVIA E RECEBE: % e %', envia, recebe; 
    END IF;
    RAISE NOTICE 'Criando mensagem entre % e %', envia, recebe; 
    
    -- Garante que o remetente seja sempre quem está enviando (B)

    NEW.chat_recebe_username = recebe;
    NEW.chat_envia_username = envia;

    RAISE NOTICE 'REMETENTE %', NEW.remetente; 
    RAISE NOTICE '-------------------------------'; 
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_preencher_mensagem
BEFORE INSERT ON mensagem
FOR EACH ROW
EXECUTE FUNCTION inserir_chat_mensagem();
