CREATE SCHEMA facepage;
SET search_path to facepage;

create table usuario_conta (
		username varchar(30), 
		cpf varchar(11) UNIQUE NOT NULL,
		nome varchar(60) NOT NULL,
		data_nas date NOT NULL,
		email varchar(30) NOT NULL,
		senha varchar(30) NOT NULL,
		endereco varchar(100),
		tel_contato varchar(20) NOT NULL,
		CONSTRAINT usuario_conta_pk PRIMARY KEY(username) 
	);

create table pessoal (
	nro_amg int NOT NULL DEFAULT 0,
	CONSTRAINT pessoal_pk PRIMARY KEY(username)
) INHERITS (usuario_conta);

create table pacote (
	id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	nome varchar(30) UNIQUE NOT NULL,
	preco real NOT NULL,
	funcionalidades varchar(100) NOT NULL
);

create table empresarial (
	nome_fantasia varchar(60) NOT NULL,
	cnpj varchar(12) UNIQUE NOT NULL,
	id_pacote int,
	CONSTRAINT empresarial_pk PRIMARY KEY(username),
	CONSTRAINT empresarial_fk FOREIGN KEY(id_pacote)
	REFERENCES pacote(id)
) INHERITS (usuario_conta);

CREATE TABLE req_amizade (
    status VARCHAR(20) NOT NULL CHECK (status IN('Pendente', 'Aceita', 'Recusada')),
    recebe_username VARCHAR(30),
    envia_username VARCHAR(30),
    CONSTRAINT req_amizade_pk PRIMARY KEY (recebe_username, envia_username),
    CONSTRAINT req_amizade_fk_recebe FOREIGN KEY (recebe_username) REFERENCES pessoal(username),
    CONSTRAINT req_amizade_fk_envia FOREIGN KEY (envia_username) REFERENCES pessoal(username)
);

CREATE TABLE chat (
	nome varchar(50) NOT NULL,
	recebe_username varchar(30),
	envia_username varchar(30),
	CONSTRAINT chat_pk PRIMARY KEY (recebe_username, envia_username),
	CONSTRAINT chat_fk_recebe FOREIGN KEY (recebe_username) REFERENCES pessoal(username),
	CONSTRAINT chat_fk_envia FOREIGN KEY (envia_username) REFERENCES pessoal(username)
);

CREATE TABLE mensagem (
    id INT GENERATED ALWAYS AS IDENTITY,
    chat_recebe_username VARCHAR(30) NOT NULL,
    chat_envia_username VARCHAR(30) NOT NULL,
    remetente VARCHAR(30) NOT NULL,
    conteudo TEXT NOT NULL,
    data_envio TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    lida BOOLEAN DEFAULT FALSE,

	CONSTRAINT mensagem_pk PRIMARY KEY (chat_recebe_username, chat_envia_username, id),
    CONSTRAINT mensagem_fk_chat FOREIGN KEY (chat_recebe_username, chat_envia_username)
        REFERENCES chat(recebe_username, envia_username) ON DELETE CASCADE,
        
    CONSTRAINT mensagem_fk_remetente FOREIGN KEY (remetente)
        REFERENCES pessoal(username)
);



create table grupo_amigos (
	codigo int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	nome varchar(30) NOT NULL,
	descricao varchar(100),
	admin varchar(30),
	CONSTRAINT grupo_amigos_fk FOREIGN KEY (admin) REFERENCES pessoal(username)
);

create table participa (
	id_grupo int,
	amigo varchar(30),
	CONSTRAINT participa_pk PRIMARY KEY (id_grupo, amigo),
	CONSTRAINT participa_fk_pessoal FOREIGN KEY (amigo) REFERENCES pessoal(username),
	CONSTRAINT participa_fk_grupo_amigos FOREIGN KEY (id_grupo) REFERENCES grupo_amigos(codigo)
);

create table jogo (
	nome varchar(30) UNIQUE NOT NULL PRIMARY KEY,
	descricao varchar(100) NOT NULL,
	dificuldade smallint NOT NULL CHECK (dificuldade BETWEEN 1 AND 10)
);

create table joga (
	nome_jogo varchar(30),
	username varchar(30),
	pontuacao int NOT NULL,
	CONSTRAINT joga_pk PRIMARY KEY (nome_jogo, username),
	CONSTRAINT joga_fk_jogo FOREIGN KEY (nome_jogo) REFERENCES jogo(nome),
	CONSTRAINT joga_fk_usuario_conta FOREIGN KEY (username) REFERENCES usuario_conta(username)
);

create table comunidade (
	nome_comunidade varchar(30),
	descricao varchar(100),
	nro_membros int NOT NULL DEFAULT 0,
	admin varchar(30),
	CONSTRAINT comunidade_pk PRIMARY KEY (nome_comunidade),
	CONSTRAINT comunidade_fk FOREIGN KEY (admin) REFERENCES usuario_conta(username)
);

create table membros_comunidade (
	comunidade varchar(30),
	membro varchar(30),
	CONSTRAINT membros_comunidade_pk PRIMARY KEY (comunidade, membro),
	CONSTRAINT membros_comunidade_fk_usuario_conta FOREIGN KEY (membro) REFERENCES usuario_conta(username),
	CONSTRAINT membros_comunidade_fk_comunidade FOREIGN KEY (comunidade) REFERENCES comunidade(nome_comunidade)
);

create table topico (
	codigo int GENERATED ALWAYS AS IDENTITY,
	membro varchar(30),
	comunidade varchar(30),
	titulo varchar(60) NOT NULL,
	data date NOT NULL,
	descricao varchar(1000) NOT NULL,
	CONSTRAINT topico_pk PRIMARY KEY (codigo, membro, comunidade),
	CONSTRAINT topico_fk FOREIGN KEY (membro, comunidade) REFERENCES membros_comunidade(membro, comunidade)
);

create table comentam (
	id int GENERATED ALWAYS AS IDENTITY,
	comentario varchar(1000) NOT NULL,
	membro_postou VARCHAR(30),
	codigo_topico int,
	comunidade_topico varchar(30),
	comunidade_membro varchar(30),
	membro_comentou varchar(30),
	data date NOT NULL DEFAULT current_date,
	CONSTRAINT comentam_pk PRIMARY KEY (membro_postou, membro_comentou, codigo_topico, comunidade_topico, comunidade_membro, id),
	CONSTRAINT comentam_fk_topico FOREIGN KEY (codigo_topico, comunidade_topico, membro_postou) REFERENCES topico(codigo, comunidade, membro),
	CONSTRAINT comentam_fk_membros_comunidade FOREIGN KEY (comunidade_membro, membro_comentou) REFERENCES membros_comunidade(comunidade, membro)
);


create table pagina(
	nome varchar(60),
	nro_visitas int,
	criador varchar(30),
	CONSTRAINT pagina_pk PRIMARY KEY (nome, criador), 
	CONSTRAINT pagina_fk FOREIGN KEY (criador) REFERENCES usuario_conta(username)
);

create table propaganda(
	taxa_cliques double precision,
	taxa_rejeicao double precision,
	taxa_conversao double precision,
	admin varchar(30),
	CONSTRAINT propaganda_fk FOREIGN KEY (admin) REFERENCES empresarial(username)
) INHERITS (pagina); 

create table pode_ver (
	nome varchar(60),
	criador varchar(30),
	codigo_grupo int,
	CONSTRAINT pode_ver_pk PRIMARY KEY (nome, criador, codigo_grupo), 
	CONSTRAINT pode_ver_fk_pagina FOREIGN KEY (nome, criador) REFERENCES pagina(nome, criador),
	CONSTRAINT pode_ver_fk_grupo_amigos FOREIGN KEY (codigo_grupo) REFERENCES grupo_amigos(codigo) 
);

create table acao (
	codigo int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	descricao varchar(100)
);

create table privilegios (
	usuario varchar(30),
	nome varchar(60),
	criador varchar(30),
	codigo_acao int,
	CONSTRAINT privilegios_pk PRIMARY KEY(usuario, nome, criador, codigo_acao),
	CONSTRAINT privilegios_fk_pessoal FOREIGN KEY (usuario) REFERENCES pessoal(username),
	CONSTRAINT privilegios_fk_pagina FOREIGN KEY (nome, criador) REFERENCES pagina(nome, criador),
	CONSTRAINT privilegios_fk_acao FOREIGN KEY (codigo_acao) REFERENCES acao(codigo)
);
