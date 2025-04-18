SET search_path TO facepage;

INSERT INTO pacote (nome, preco, funcionalidades) VALUES
('Plano Básico', 50.00, 'Perfil empresarial, 5 postagens/mês, suporte básico'),
('Plano Pro', 150.00, '10 postagens/mês, analytics simples, suporte prioritário'),
('Plano Premium', 300.00, 'Postagens ilimitadas, analytics avançados, SEO tools'),
('Business Plus', 450.00, 'Gestão de equipe, relatórios personalizados, integração API'),
('Social Starter', 75.00, '3 postagens/dia, métricas essenciais'),
('Enterprise Elite', 500.00, 'Consultoria personalizada, domínio customizado, CRM integrado'),
('Growth Guru', 200.00, 'Campanhas automatizadas, audience insights'),
('E-Commerce Pack', 350.00, 'Catálogo de produtos, checkout integrado'),
('Influencer Boost', 120.00, 'Ferramentas de engajamento, hashtag analytics'),
('Local Hero', 80.00, 'Geolocalização, promoções segmentadas'),
('Content Master', 250.00, 'Agendamento de posts, biblioteca de mídia'),
('Analytics Pro', 400.00, 'Heatmaps, funil de vendas, A/B testing'),
('Startup Special', 90.00, 'Mentoria, acesso a eventos exclusivos'),
('Nonprofit Bundle', 60.00, 'Doações integradas, storytelling tools'),
('Global Reach', 480.00, 'Tradução automática, multi-região'),
('Brand Guardian', 180.00, 'Monitoramento de marca, alertas de crise'),
('Ad Campaigner', 220.00, 'Gestão de anúncios, otimização em tempo real'),
('Data Driven', 380.00, 'Big data, machine learning insights'),
('Community Builder', 130.00, 'Fóruns moderados, gamificação'),
('VIP Experience', 499.00, 'Concierge 24/7, treinamentos exclusivos');

INSERT INTO pessoal (username, cpf, nome, data_nas, email, senha, endereco, tel_contato) VALUES
('ShadowHunter', '12345678901', 'Carlos Silva', '1995-03-15', 'carlos@gmail.com', 'carlos1234', 'Rua das Flores, 123', '+5511987654321'),
('DragonSlayer', '23456789012', 'Ana Souza', '2000-07-22', 'ana@outlook.com', 'dragonana22', 'Avenida Paulista, 456', '+5511912345678'),
('PixelWarrior', '34567890123', 'Pedro Rocha', '1988-11-05', 'pedro.pixel@gmail.com', 'pixel88rocha', NULL, '+5511123456789'),
('CyberNinja', '45678901234', 'Julia Lima', '1999-04-30', 'julia.ninja@outlook.com', 'ninja9999', 'Rua Tech, 789', '+5511987654321'),
('SteamLord', '56789012345', 'Lucas Oliveira', '2002-09-12', 'lucas.steam@gmail.com', 'steam2020', NULL, '+5511976543210'),
('MechaQueen', '67890123456', 'Fernanda Castro', '1993-12-25', 'fer.mecha@outlook.com', 'mechaXmas93', 'Alameda Santos, 101', '+5511988776655'),
('CodeSamurai', '78901234567', 'Ricardo Kim', '1985-06-18', 'ricardo.code@gmail.com', 'samurai85', NULL, '+5511933344556'),
('PhoenixRider', '89012345678', 'Mariana Costa', '2005-01-07', 'mariana.phoenix@outlook.com', 'phoenix2005', 'Rua Java, 202', '+5511966699887'),
('NeonGhost', '90123456789', 'Gabriel Alves', '1997-08-14', 'gabriel.neon@gmail.com', 'neon97gabs', 'Avenida Python, 303', '+5511955544332'),
('VortexMage', '01234567890', 'Isabela Santos', '2001-02-28', 'isa.vortex@outlook.com', 'vortexisa28', NULL, '+5511944433221'),
('BladeRunner', '11223344556', 'Rodrigo Pereira', '1990-05-20', 'rodrigo.blade@gmail.com', 'runner1990', 'Rua C++, 404', '+5511922233445'),
('Starlight', '22334455667', 'Camila Rios', '2003-10-10', 'camila.star@outlook.com', 'starlight10', NULL, '+5511999988776'),
('IronPilot', '33445566778', 'Thiago Nunes', '1987-04-03', 'thiago.iron@gmail.com', 'pilot1987', 'Alameda Ruby, 505', '+5511887766554'),
('SkyGuardian', '44556677889', 'Patricia Moraes', '1996-07-19', 'paty.sky@outlook.com', 'guardian96', NULL, '+5511876655443'),
('FrostWolf', '55667788990', 'Bruno Carvalho', '2004-12-01', 'bruno.frost@gmail.com', 'wolf2004br', 'Rua HTML, 606', '+5511866554332'),
('SolarFlare', '66778899001', 'Larissa Gomes', '1994-03-08', 'larissa.solar@outlook.com', 'flare1994', NULL, '+5511855443321'),
('ThunderBolt', '77889900112', 'Gustavo Henrique', '1989-09-23', 'gustavo.bolt@gmail.com', 'thunder89', 'Avenida CSS, 707', '+5511844332211'),
('MoonKnight', '88990011223', 'Amanda Freitas', '2006-06-15', 'amanda.moon@outlook.com', 'moon15night', NULL, '+5511833221100'),
('DarkKnight', '99001112234', 'Roberto Dias', '1998-11-11', 'roberto.dark@gmail.com', 'dark1998rob', 'Rua JavaScript, 808', '+5511822110099'),
('CyberPunk', '00112233445', 'Clara Ribeiro', '2007-04-04', 'clara.cyber@outlook.com', 'cyberclara04', NULL, '+5511811009988');

INSERT INTO empresarial (username, cpf, nome, data_nas, email, senha, endereco, tel_contato, nome_fantasia, cnpj, id_pacote) VALUES
('TechSolutions', '99988877766', 'Tech Solutions LTDA', '2010-05-20', 'contato@tech.com', 'tech12345', 'Avenida Inovação, 1000', '+551121234567', 'Tech Solutions', '123456789012', 4),
('InovaCorp', '88877766655', 'Inova Corp SA', '2015-08-12', 'inovacorp@outlook.com', 'inova2023', 'Rua Startup, 200', '+551131234567', 'Inova Corp', '234567890123', 1),
('DataDrivenCo', '77766655544', 'Data Driven Analytics', '2018-03-01', 'data@driven.com', 'data2024!', NULL, '+551141234567', 'Data Driven', '345678901234', 18),
('EcomMaster', '66655544411', 'E-Commerce Masters', '2020-11-15', 'ecom@master.com', 'ecom2020#', 'Alameda Digital, 300', '+551151234567', 'Ecom Master', '456789012345', 8),
('SocialBee', '55544433311', 'SocialBee Marketing', '2012-07-30', 'hello@socialbee.com', 'beemarketing', 'Rua das Redes, 400', '+551161234567', 'SocialBee', '567890123456', 7),
('BrandHub', '44433322255', 'Brand Hub Creative', '2019-04-25', 'brand@hub.com', 'brandhub99', NULL, '+551171234567', 'Brand Hub', '678901234567', 16),
('CloudNest', '33322211199', 'Cloud Nest Tech', '2016-09-10', 'cloud@nest.com', 'cloudnest16', 'Avenida Nuvem, 500', '+551181234567', 'Cloud Nest', '789012345678', 3),
('FutureLabs', '22211100088', 'Future Labs Inc', '2022-01-05', 'labs@future.com', 'future2025', 'Rua Futuro, 600', '+551191234567', 'Future Labs', '890123456789', 6),
('GreenTech', '11100099977', 'Green Tech SA', '2014-12-12', 'green@tech.com', 'greentech14', NULL, '+551101234567', 'Green Tech', '901234567890', 12),
('CodeCraft', '00099988866', 'CodeCraft Devs', '2017-06-18', 'code@craft.com', 'codecraft17', 'Alameda Dev, 700', '+551112345678', 'CodeCraft', '012345678901', 5),
('AdVision', '99988877744', 'AdVision Media', '2011-02-28', 'ads@vision.com', 'advision2024', 'Rua Publicidade, 800', '+551122345678', 'AdVision', '123450987654', 17),
('HealthPlus', '88877766622', 'Health Plus Clinic', '2013-10-07', 'health@plus.com', 'healthplus13', NULL, '+551132345678', 'Health Plus', '234561098765', 9),
('EduTech', '77766655511', 'EduTech Solutions', '2023-04-09', 'edu@tech.com', 'edutech2023', 'Avenida Educação, 900', '+551142345678', 'EduTech', '345672109876', 13),
('FoodieNet', '66655544433', 'Foodie Network', '2021-08-22', 'contact@foodie.com', 'foodie2021!', 'Rua Gastronomia, 1000', '+551152345678', 'FoodieNet', '456783210987', 10),
('TravelMasters', '55544433322', 'Travel Masters Co', '2019-05-14', 'travel@masters.com', 'travelmasters19', NULL, '+551162345678', 'Travel Masters', '567894321098', 14),
('FashionHub', '44433322211', 'Fashion Hub LTDA', '2015-03-03', 'fashion@hub.com', 'fashionhub15', 'Avenida Moda, 1100', '+551172345678', 'Fashion Hub', '678905432109', 2),
('FinTechX', '33322211100', 'FinTech X', '2020-07-19', 'fintechx@mail.com', 'fintechx2020', 'Rua Financeira, 1200', '+551182345678', 'FinTech X', '789016543210', 11),
('AutoDrive', '22211100099', 'AutoDrive Systems', '2024-01-01', 'auto@drive.com', 'autodrive24', NULL, '+551192345678', 'AutoDrive', '890127654321', 19),
('GameForge', '11100099988', 'GameForge Studios', '2018-11-11', 'game@forge.com', 'gameforge18', 'Rua dos Jogos, 1300', '+551102345678', 'GameForge', '901238765432', 20),
('BuildIt', '00099988877', 'Build It Construções', '2016-04-04', 'build@it.com', 'buildit2016', 'Avenida Obras, 1400', '+551112345679', 'Build It', '012349876543', 15);

-- Inserindo os dados na tabela pai, para garantir herança

INSERT INTO usuario_conta (username, cpf, nome, data_nas, email, senha, endereco, tel_contato)
SELECT username, cpf, nome, data_nas, email, senha, endereco, tel_contato
FROM pessoal; 

INSERT INTO usuario_conta (username, cpf, nome, data_nas, email, senha, endereco, tel_contato)
SELECT username, cpf, nome, data_nas, email, senha, endereco, tel_contato
FROM empresarial; 

-- 20 requisições com status variados
INSERT INTO req_amizade (status, recebe_username, envia_username) VALUES
-- Solicitações ACEITAS (10)
('Aceita', 'ShadowHunter', 'DragonSlayer'),
('Aceita', 'PixelWarrior', 'CyberNinja'),
('Aceita', 'SteamLord', 'MechaQueen'),
('Aceita', 'CodeSamurai', 'PhoenixRider'),
('Aceita', 'NeonGhost', 'VortexMage'),
('Aceita', 'BladeRunner', 'Starlight'),
('Aceita', 'IronPilot', 'SkyGuardian'),
('Aceita', 'FrostWolf', 'SolarFlare'),
('Aceita', 'ThunderBolt', 'MoonKnight'),
('Aceita', 'DarkKnight', 'CyberPunk'),
-- Solicitações PENDENTES (5)
('Pendente', 'ShadowHunter', 'PixelWarrior'),
('Pendente', 'DragonSlayer', 'SteamLord'),
('Pendente', 'MechaQueen', 'NeonGhost'),
('Pendente', 'PhoenixRider', 'BladeRunner'),
('Pendente', 'VortexMage', 'IronPilot'),
-- Solicitações RECUSADAS (5)
('Recusada', 'CyberNinja', 'ShadowHunter'),
('Recusada', 'Starlight', 'DragonSlayer'),
('Recusada', 'SolarFlare', 'MechaQueen'),
('Recusada', 'MoonKnight', 'PhoenixRider'),
('Recusada', 'CyberPunk', 'ThunderBolt');

-- Mensagens para o chat ShadowHunter & DragonSlayer
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('ShadowHunter', 'DragonSlayer', 'E aí, Carlos! Tudo bem?'),
('DragonSlayer', 'ShadowHunter', 'Oi Ana! Tudo ótimo, e com você?'),
('ShadowHunter', 'DragonSlayer', 'Tudo tranquilo! Vamos jogar hoje?');

-- Mensagens para o chat PixelWarrior & CyberNinja
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('PixelWarrior', 'CyberNinja', 'Julia, você viu o novo jogo que saiu?'),
('CyberNinja', 'PixelWarrior', 'Vi sim, Pedro! Parece incrível, quero testar'),
('PixelWarrior', 'CyberNinja', 'Bora jogar juntos amanhã?');

-- Mensagens para o chat SteamLord & MechaQueen
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('SteamLord', 'MechaQueen', 'Fernanda, conseguiu passar daquela fase difícil?'),
('MechaQueen', 'SteamLord', 'Ainda não, Lucas! Preciso de dicas'),
('SteamLord', 'MechaQueen', 'Te mando um tutorial que achei');

-- Mensagens para o chat CodeSamurai & PhoenixRider
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('CodeSamurai', 'PhoenixRider', 'Mariana, como está o projeto novo?'),
('PhoenixRider', 'CodeSamurai', 'Indo bem, Ricardo! Preciso de ajuda com o código'),
('CodeSamurai', 'PhoenixRider', 'Posso te ajudar depois das 18h');

-- Mensagens para o chat NeonGhost & VortexMage
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('NeonGhost', 'VortexMage', 'Isabela, marcamos de treinar hoje, lembra?'),
('VortexMage', 'NeonGhost', 'Sim, Gabriel! Às 20h no parque, certo?'),
('NeonGhost', 'VortexMage', 'Isso mesmo! Levo os equipamentos');

-- Mensagens para o chat BladeRunner & Starlight
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('BladeRunner', 'Starlight', 'Camila, já leu o livro que te indiquei?'),
('Starlight', 'BladeRunner', 'Ainda não, Rodrigo! Estou terminando outro'),
('BladeRunner', 'Starlight', 'Depois me diz o que achou quando ler');

-- Mensagens para o chat IronPilot & SkyGuardian
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('IronPilot', 'SkyGuardian', 'Patricia, viagem marcada para sexta!'),
('SkyGuardian', 'IronPilot', 'Que ótimo, Thiago! Já arrumei as malas'),
('IronPilot', 'SkyGuardian', 'Passo te buscar às 7h');

-- Mensagens para o chat FrostWolf & SolarFlare
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('FrostWolf', 'SolarFlare', 'Larissa, recebeu os documentos?'),
('SolarFlare', 'FrostWolf', 'Recebi sim, Bruno! Já enviei a revisão'),
('FrostWolf', 'SolarFlare', 'Perfeito, obrigado!');

-- Mensagens para o chat ThunderBolt & MoonKnight
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('ThunderBolt', 'MoonKnight', 'Amanda, vamos no show sábado?'),
('MoonKnight', 'ThunderBolt', 'Claro, Gustavo! Já comprei os ingressos'),
('ThunderBolt', 'MoonKnight', 'Show! Nos encontramos lá');

-- Mensagens para o chat DarkKnight & CyberPunk
INSERT INTO facepage.mensagem (chat_recebe_username, chat_envia_username, conteudo) VALUES
('DarkKnight', 'CyberPunk', 'Clara, como foi na prova hoje?'),
('CyberPunk', 'DarkKnight', 'Foi bem, Roberto! Acertei quase tudo'),
('DarkKnight', 'CyberPunk', 'Parabéns! Merece comemorar');

-- Grupos do ShadowHunter (Amigo: DragonSlayer)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Clã dos Caçadores', 'Grupo de jogadores hardcore', 'ShadowHunter'),
('Aliança Tech', 'Amantes de tecnologia', 'ShadowHunter');

INSERT INTO participa (id_grupo, amigo) VALUES
(1, 'DragonSlayer'), -- Grupo 1
(2, 'DragonSlayer'); -- Grupo 2

-- Grupos do DragonSlayer (Amigo: ShadowHunter)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Guilda das Feras', 'RPG e estratégia', 'DragonSlayer'),
('Equipe Pixel', 'Fãs de jogos retro', 'DragonSlayer');

INSERT INTO participa (id_grupo, amigo) VALUES
(3, 'ShadowHunter'), -- Grupo 3
(4, 'ShadowHunter'); -- Grupo 4

-- Grupos do PixelWarrior (Amigo: CyberNinja)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Mestres do Pixel', 'Jogos clássicos', 'PixelWarrior'),
('Cyber Squad', 'Competitivo online', 'PixelWarrior');

INSERT INTO participa (id_grupo, amigo) VALUES
(5, 'CyberNinja'), -- Grupo 5
(6, 'CyberNinja'); -- Grupo 6

-- Grupos do SteamLord (Amigo: MechaQueen)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Masters of Steam', 'Jogos de PC', 'SteamLord'),
('Indie Lovers', 'Jogos independentes', 'SteamLord');

INSERT INTO participa (id_grupo, amigo) VALUES
(7, 'MechaQueen'), -- Grupo 7
(8, 'MechaQueen'); -- Grupo 8

-- Grupos do CodeSamurai (Amigo: PhoenixRider)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Code Masters', 'Desenvolvedores de jogos', 'CodeSamurai'),
('Aventureiros Digitais', 'Exploradores de mundos virtuais', 'CodeSamurai');

INSERT INTO participa (id_grupo, amigo) VALUES
(9, 'PhoenixRider'), -- Grupo 9
(10, 'PhoenixRider'); -- Grupo 10

-- Grupos do NeonGhost (Amigo: VortexMage)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Neon Tribe', 'Jogos noturnos', 'NeonGhost'),
('Mago Guild', 'Magia e estratégia', 'NeonGhost');

INSERT INTO participa (id_grupo, amigo) VALUES
(11, 'VortexMage'), -- Grupo 11
(12, 'VortexMage'); -- Grupo 12

-- Grupos do BladeRunner (Amigo: Starlight)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Blade Alliance', 'Ação e aventura', 'BladeRunner'),
('Star Squad', 'Jogos espaciais', 'BladeRunner');

INSERT INTO participa (id_grupo, amigo) VALUES
(13, 'Starlight'), -- Grupo 13
(14, 'Starlight'); -- Grupo 14

-- Grupos do IronPilot (Amigo: SkyGuardian)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Iron Wings', 'Simuladores de voo', 'IronPilot'),
('Sky Guardians', 'Defensores do céu', 'IronPilot');

INSERT INTO participa (id_grupo, amigo) VALUES
(15, 'SkyGuardian'), -- Grupo 15
(16, 'SkyGuardian'); -- Grupo 16

-- Grupos do FrostWolf (Amigo: SolarFlare)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Frost Pack', 'Jogos de inverno', 'FrostWolf'),
('Solar Clan', 'Energia e estratégia', 'FrostWolf');

INSERT INTO participa (id_grupo, amigo) VALUES
(17, 'SolarFlare'), -- Grupo 17
(18, 'SolarFlare'); -- Grupo 18

-- Grupos do ThunderBolt (Amigo: MoonKnight)
INSERT INTO grupo_amigos (nome, descricao, admin) VALUES
('Thunder Force', 'Jogos de ação rápida', 'ThunderBolt'),
('Moon Knights', 'Aventuras noturnas', 'ThunderBolt');

INSERT INTO participa (id_grupo, amigo) VALUES
(19, 'MoonKnight'), -- Grupo 19
(20, 'MoonKnight'); -- Grupo 20

INSERT INTO facepage.jogo (nome, descricao, dificuldade) VALUES
('Space Warriors', 'Batalhas intergalácticas em tempo real', 7),
('Epic Quest', 'RPG de fantasia com mundos abertos', 6),
('Speed Racers', 'Corridas extremas em pistas futuristas', 5),
('Dragon Realm', 'Aventura épica para domar dragões', 8),
('Cyber Battle', 'FPS tático em cenários cyberpunk', 9),
('Farm Life Simulator', 'Gerencie sua fazenda e colheitas', 3),
('Puzzle Masters', 'Desafie sua lógica com quebra-cabeças complexos', 4),
('Soccer Stars', 'Simulador de futebol com ligas globais', 6),
('Zombie Survival', 'Sobreviva a hordas de zumbis pós-apocalípticos', 8),
('Candy Kingdom', 'Combine doces em puzzles coloridos', 2);

INSERT INTO facepage.joga (nome_jogo, username, pontuacao) VALUES
-- ShadowHunter (pessoal)
('Space Warriors', 'ShadowHunter', 1500),
('Epic Quest', 'ShadowHunter', 3000),

-- DragonSlayer (pessoal)
('Speed Racers', 'DragonSlayer', 2500),
('Dragon Realm', 'DragonSlayer', 4200),

-- TechSolutions (empresarial)
('Cyber Battle', 'TechSolutions', 9800),
('Farm Life Simulator', 'TechSolutions', 1200),

-- InovaCorp (empresarial)
('Puzzle Masters', 'InovaCorp', 6700),
('Soccer Stars', 'InovaCorp', 3300),

-- MechaQueen (pessoal)
('Zombie Survival', 'MechaQueen', 5500),
('Candy Kingdom', 'MechaQueen', 7800),

-- CloudNest (empresarial)
('Space Warriors', 'CloudNest', 2100),
('Speed Racers', 'CloudNest', 4500),

-- NeonGhost (pessoal)
('Epic Quest', 'NeonGhost', 8800),
('Dragon Realm', 'NeonGhost', 6100),

-- BrandHub (empresarial)
('Cyber Battle', 'BrandHub', 3200),
('Puzzle Masters', 'BrandHub', 7600),

-- ThunderBolt (pessoal)
('Farm Life Simulator', 'ThunderBolt', 2900),
('Soccer Stars', 'ThunderBolt', 5300),

-- EduTech (empresarial)
('Zombie Survival', 'EduTech', 6700),
('Candy Kingdom', 'EduTech', 8900);


-- Criando as comunidades

INSERT INTO facepage.comunidade (nome_comunidade, descricao, admin) VALUES
('Tech Innovators', 'Discussões sobre inovações tecnológicas', 'TechSolutions'),
('Gaming Legends', 'Comunidade para amantes de jogos clássicos e modernos', 'ShadowHunter'),
('Music Lovers', 'Compartilhamento de músicas e playlists', 'DragonSlayer'),
('E-Commerce Masters', 'Dicas e estratégias para negócios online', 'EcomMaster'),
('Fitness & Health', 'Dicas de exercícios, dieta e bem-estar', 'NeonGhost'),
('Startup Hub', 'Networking e mentoria para startups', 'InovaCorp'),
('Art & Design', 'Arte digital, design gráfico e ilustração', 'MechaQueen'),
('Travel Explorers', 'Relatos de viagens e dicas de destinos', 'ThunderBolt'),
('Book Club', 'Recomendações e discussões literárias', 'Starlight'),
('Foodie Paradise', 'Receitas, restaurantes e gastronomia', 'SolarFlare');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Tech Innovators', 'TechSolutions'), -- Admin
('Tech Innovators', 'CloudNest'),
('Tech Innovators', 'CodeCraft'),
('Tech Innovators', 'DataDrivenCo'),
('Tech Innovators', 'FutureLabs');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Gaming Legends', 'ShadowHunter'), -- Admin
('Gaming Legends', 'DragonSlayer'),
('Gaming Legends', 'PixelWarrior'),
('Gaming Legends', 'CyberNinja'),
('Gaming Legends', 'SteamLord');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Music Lovers', 'DragonSlayer'), -- Admin
('Music Lovers', 'VortexMage'),
('Music Lovers', 'BladeRunner'),
('Music Lovers', 'IronPilot'),
('Music Lovers', 'MoonKnight');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('E-Commerce Masters', 'EcomMaster'), -- Admin
('E-Commerce Masters', 'BrandHub'),
('E-Commerce Masters', 'SocialBee'),
('E-Commerce Masters', 'AdVision'),
('E-Commerce Masters', 'FinTechX');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Fitness & Health', 'NeonGhost'), -- Admin
('Fitness & Health', 'SkyGuardian'),
('Fitness & Health', 'SolarFlare'),
('Fitness & Health', 'FrostWolf'),
('Fitness & Health', 'PhoenixRider');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Startup Hub', 'InovaCorp'), -- Admin
('Startup Hub', 'GreenTech'),
('Startup Hub', 'EduTech'),
('Startup Hub', 'TravelMasters'),
('Startup Hub', 'BuildIt');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Art & Design', 'MechaQueen'), -- Admin
('Art & Design', 'Starlight'),
('Art & Design', 'CyberPunk'),
('Art & Design', 'DarkKnight'),
('Art & Design', 'CodeSamurai');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Travel Explorers', 'ThunderBolt'), -- Admin
('Travel Explorers', 'MoonKnight'),
('Travel Explorers', 'SkyGuardian'),
('Travel Explorers', 'IronPilot'),
('Travel Explorers', 'BladeRunner');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Book Club', 'Starlight'), -- Admin
('Book Club', 'VortexMage'),
('Book Club', 'NeonGhost'),
('Book Club', 'PhoenixRider'),
('Book Club', 'SolarFlare');

INSERT INTO facepage.membros_comunidade (comunidade, membro) VALUES
('Foodie Paradise', 'SolarFlare'), -- Admin
('Foodie Paradise', 'FoodieNet'),
('Foodie Paradise', 'HealthPlus'),
('Foodie Paradise', 'ThunderBolt'),
('Foodie Paradise', 'DragonSlayer');

-- Comunidade 1: Tech Innovators (Descrição: Discussões sobre inovações tecnológicas)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('TechSolutions', 'Tech Innovators', 'O Futuro da IA em 2024', '2023-11-01', 'Como a inteligência artificial está transformando indústrias em 2024?'),
('DataDrivenCo', 'Tech Innovators', 'Blockchain para Segurança Digital', '2023-11-05', 'Aplicações práticas de blockchain em proteção de dados.');

-- Comunidade 2: Gaming Legends (Descrição: Comunidade para amantes de jogos clássicos e modernos)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('ShadowHunter', 'Gaming Legends', 'Melhores Jogos Retro de 2023', '2023-10-15', 'Lista dos jogos retrô mais populares deste ano.'),
('CyberNinja', 'Gaming Legends', 'eSports: Cenário Competitivo Atual', '2023-10-20', 'Discussão sobre torneios e equipes dominantes.');

-- Comunidade 3: Music Lovers (Descrição: Compartilhamento de músicas e playlists)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('DragonSlayer', 'Music Lovers', 'Playlists para Estudo/Concentração', '2023-09-10', 'Indicações de músicas instrumentais e lo-fi.'),
('VortexMage', 'Music Lovers', 'Novos Lançamentos de Rock Alternativo', '2023-09-12', 'Bandas emergentes e álbuns do gênero.');

-- Comunidade 4: E-Commerce Masters (Descrição: Dicas e estratégias para negócios online)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('EcomMaster', 'E-Commerce Masters', 'SEO para Lojas Virtuais', '2023-08-01', 'Como otimizar seu e-commerce para buscadores.'),
('SocialBee', 'E-Commerce Masters', 'Marketing em Redes Sociais', '2023-08-05', 'Estratégias para impulsionar vendas no Instagram.');

-- Comunidade 5: Fitness & Health (Descrição: Dicas de exercícios, dieta e bem-estar)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('NeonGhost', 'Fitness & Health', 'Rotina de Exercícios em Casa', '2023-07-20', 'Treinos eficientes sem equipamentos.'),
('SkyGuardian', 'Fitness & Health', 'Dietas Plant-Based para Iniciantes', '2023-07-25', 'Guia prático para transição alimentar.');

-- Comunidade 6: Startup Hub (Descrição: Networking e mentoria para startups)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('InovaCorp', 'Startup Hub', 'Como Captar Investimento-Anjo', '2023-06-05', 'Passo a passo para pitchs convincentes.'),
('GreenTech', 'Startup Hub', 'Sustentabilidade em Startups Tech', '2023-06-10', 'Cases de sucesso e desafios.');

-- Comunidade 7: Art & Design (Descrição: Arte digital, design gráfico e ilustração)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('MechaQueen', 'Art & Design', 'Ferramentas para Designers em 2023', '2023-05-15', 'Comparativo entre Photoshop, Figma e Canva.'),
('CodeSamurai', 'Art & Design', 'Arte Generativa com IA', '2023-05-18', 'Como criar arte usando MidJourney e Stable Diffusion.');

-- Comunidade 8: Travel Explorers (Descrição: Relatos de viagens e dicas de destinos)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('ThunderBolt', 'Travel Explorers', 'Melhores Destinos para Mochilão', '2023-04-01', 'Roteiros econômicos na América do Sul.'),
('IronPilot', 'Travel Explorers', 'Viagens Sustentáveis: Como Reduzir Impacto', '2023-04-05', 'Dicas para turismo consciente.');

-- Comunidade 9: Book Club (Descrição: Recomendações e discussões literárias)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('Starlight', 'Book Club', 'Livros Distópicos para 2024', '2023-03-10', 'Indicações de ficção científica e distopias.'),
('PhoenixRider', 'Book Club', 'Clássicos da Literatura Brasileira', '2023-03-12', 'Releituras contemporâneas de Machado de Assis.');

-- Comunidade 10: Foodie Paradise (Descrição: Receitas, restaurantes e gastronomia)
INSERT INTO facepage.topico (membro, comunidade, titulo, data, descricao) VALUES
('SolarFlare', 'Foodie Paradise', 'Receitas com Ingredientes Locais', '2023-02-01', 'Como aproveitar produtos regionais.'),
('FoodieNet', 'Foodie Paradise', 'Top 10 Restaurantes Veganos no Brasil', '2023-02-05', 'Avaliação de estabelecimentos especializados.');

-----------------------------
-- Comunidade: Tech Innovators
-----------------------------
-- Tópico 1: O Futuro da IA em 2024 (codigo = 1)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('A IA está revolucionando até a medicina! Empresas como a DeepMind já fazem diagnósticos precisos.', 'TechSolutions', 1, 'Tech Innovators', 'Tech Innovators', 'CloudNest'),
('Precisamos debater ética no uso de IA. Alguém conhece frameworks para regulamentação?', 'TechSolutions', 1, 'Tech Innovators', 'Tech Innovators', 'CodeCraft');

-- Tópico 2: Blockchain para Segurança Digital (codigo = 2)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Blockchain é essencial para evitar fraudes em contratos inteligentes. Ótimo tópico!', 'DataDrivenCo', 2, 'Tech Innovators', 'Tech Innovators', 'FutureLabs'),
('Alguém já testou a plataforma Hyperledger para implementação? Recomendam?', 'DataDrivenCo', 2, 'Tech Innovators', 'Tech Innovators', 'TechSolutions');

-----------------------------
-- Comunidade: Gaming Legends
-----------------------------
-- Tópico 3: Melhores Jogos Retro de 2023 (codigo = 3)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Adoro jogos retrô! Recomendo "Celeste" para quem gosta de plataforma.', 'ShadowHunter', 3, 'Gaming Legends', 'Gaming Legends', 'DragonSlayer'),
('Alguém vai participar do campeonato de Street Fighter VI?', 'ShadowHunter', 3, 'Gaming Legends', 'Gaming Legends', 'CyberNinja');

-- Tópico 4: eSports: Cenário Competitivo Atual (codigo = 4)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('A equipe Furia está dominando o cenário brasileiro de CS:GO!', 'CyberNinja', 4, 'Gaming Legends', 'Gaming Legends', 'SteamLord'),
('Precisamos de mais investimento em equipes femininas de eSports.', 'CyberNinja', 4, 'Gaming Legends', 'Gaming Legends', 'PixelWarrior');

-----------------------------
-- Comunidade: Music Lovers
-----------------------------
-- Tópico 5: Playlists para Estudo/Concentração (codigo = 5)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Playlist "Lo-Fi Beats" no Spotify é minha favorita!', 'DragonSlayer', 5, 'Music Lovers', 'Music Lovers', 'BladeRunner'),
('Música clássica também ajuda muito. Recomendo Bach.', 'DragonSlayer', 5, 'Music Lovers', 'Music Lovers', 'IronPilot');

-- Tópico 6: Novos Lançamentos de Rock Alternativo (codigo = 6)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('A banda "Arctic Monkeys" lançou algo novo?', 'VortexMage', 6, 'Music Lovers', 'Music Lovers', 'MoonKnight'),
('Confira o álbum "The Now Now" do Gorillaz!', 'VortexMage', 6, 'Music Lovers', 'Music Lovers', 'VortexMage');

-----------------------------
-- Comunidade: E-Commerce Masters
-----------------------------
-- Tópico 7: SEO para Lojas Virtuais (codigo = 7)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Ferramentas como SEMrush são ótimas para keywords.', 'EcomMaster', 7, 'E-Commerce Masters', 'E-Commerce Masters', 'SocialBee'),
('Conteúdo relevante ainda é o rei do SEO!', 'EcomMaster', 7, 'E-Commerce Masters', 'E-Commerce Masters', 'AdVision');

-- Tópico 8: Marketing em Redes Sociais (codigo = 8)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Instagram Stories aumenta o engajamento em 40%.', 'SocialBee', 8, 'E-Commerce Masters', 'E-Commerce Masters', 'FinTechX'),
('TikTok para negócios está subestimado!', 'SocialBee', 8, 'E-Commerce Masters', 'E-Commerce Masters', 'EcomMaster');

-----------------------------
-- Comunidade: Fitness & Health
-----------------------------
-- Tópico 9: Rotina de Exercícios em Casa (codigo = 9)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Treino com elásticos é ótimo para iniciantes.', 'NeonGhost', 9, 'Fitness & Health', 'Fitness & Health', 'PhoenixRider'),
('Yoga também conta como exercício?', 'NeonGhost', 9, 'Fitness & Health', 'Fitness & Health', 'SolarFlare');

-- Tópico 10: Dietas Plant-Based para Iniciantes (codigo = 10)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Comecei com a Segunda Sem Carne e estou amando!', 'SkyGuardian', 10, 'Fitness & Health', 'Fitness & Health', 'FrostWolf'),
('Onde encontrar proteína vegetal barata?', 'SkyGuardian', 10, 'Fitness & Health', 'Fitness & Health', 'NeonGhost');

-----------------------------
-- Comunidade: Startup Hub
-----------------------------
-- Tópico 11: Como Captar Investimento-Anjo (codigo = 11)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('O pitch precisa ser claro em 3 minutos!', 'InovaCorp', 11, 'Startup Hub', 'Startup Hub', 'GreenTech'),
('Busquem aceleradoras como Y Combinator.', 'InovaCorp', 11, 'Startup Hub', 'Startup Hub', 'EduTech');

-- Tópico 12: Sustentabilidade em Startups Tech (codigo = 12)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Energia solar reduziu nossos custos em 30%.', 'GreenTech', 12, 'Startup Hub', 'Startup Hub', 'TravelMasters'),
('Como medir o impacto ambiental da startup?', 'GreenTech', 12, 'Startup Hub', 'Startup Hub', 'BuildIt');

-----------------------------
-- Comunidade: Art & Design
-----------------------------
-- Tópico 13: Ferramentas para Designers em 2023 (codigo = 13)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Figma é insubstituível para colaboração em tempo real.', 'MechaQueen', 13, 'Art & Design', 'Art & Design', 'DarkKnight'),
('Alguém usa Affinity Designer aqui?', 'MechaQueen', 13, 'Art & Design', 'Art & Design', 'CodeSamurai');

-- Tópico 14: Arte Generativa com IA (codigo = 14)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('MidJourney cria artes incríveis para capas de livros.', 'CodeSamurai', 14, 'Art & Design', 'Art & Design', 'Starlight'),
('Como evitar violação de direitos autorais?', 'CodeSamurai', 14, 'Art & Design', 'Art & Design', 'CyberPunk');

-----------------------------
-- Comunidade: Travel Explorers
-----------------------------
-- Tópico 15: Melhores Destinos para Mochilão (codigo = 15)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Patagônia é imperdível para aventuras radicais!', 'ThunderBolt', 15, 'Travel Explorers', 'Travel Explorers', 'MoonKnight'),
('Alguém já fez mochilão na Europa Oriental?', 'ThunderBolt', 15, 'Travel Explorers', 'Travel Explorers', 'IronPilot');

-- Tópico 16: Viagens Sustentáveis: Como Reduzir Impacto (codigo = 16)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Hotéis eco-friendly são a melhor opção.', 'IronPilot', 16, 'Travel Explorers', 'Travel Explorers', 'BladeRunner'),
('Evitem plástico descartável durante as viagens!', 'IronPilot', 16, 'Travel Explorers', 'Travel Explorers', 'SkyGuardian');

-----------------------------
-- Comunidade: Book Club
-----------------------------
-- Tópico 17: Livros Distópicos para 2024 (codigo = 17)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('"1984" do Orwell continua atualíssimo.', 'Starlight', 17, 'Book Club', 'Book Club', 'PhoenixRider'),
('Leiam "The Handmaid''s Tale"!', 'Starlight', 17, 'Book Club', 'Book Club', 'NeonGhost');

-- Tópico 18: Clássicos da Literatura Brasileira (codigo = 18)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Machado de Assis é genial em "Dom Casmurro".', 'PhoenixRider', 18, 'Book Club', 'Book Club', 'SolarFlare'),
('Alguém já leu "Grande Sertão: Veredas"?', 'PhoenixRider', 18, 'Book Club', 'Book Club', 'VortexMage');

-----------------------------
-- Comunidade: Foodie Paradise
-----------------------------
-- Tópico 19: Receitas com Ingredientes Locais (codigo = 19)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('Açaí com peixe frito é uma delícia no Pará!', 'SolarFlare', 19, 'Foodie Paradise', 'Foodie Paradise', 'FoodieNet'),
('Como usar mandioca em pratos sofisticados?', 'SolarFlare', 19, 'Foodie Paradise', 'Foodie Paradise', 'HealthPlus');

-- Tópico 20: Top 10 Restaurantes Veganos no Brasil (codigo = 20)
INSERT INTO facepage.comentam (comentario, membro_postou, codigo_topico, comunidade_topico, comunidade_membro, membro_comentou) VALUES
('O "Pop Vegan" em SP é incrível!', 'FoodieNet', 20, 'Foodie Paradise', 'Foodie Paradise', 'ThunderBolt'),
('Falta mais opções veganas no Nordeste.', 'FoodieNet', 20, 'Foodie Paradise', 'Foodie Paradise', 'DragonSlayer');

-- Inserções para páginas pessoais
INSERT INTO facepage.pagina (nome, nro_visitas, criador) VALUES
('Caçadores de Sombras', 0, 'ShadowHunter'),
('Domadores de Dragões', 0, 'DragonSlayer'),
('Guerreiros do Pixel', 0, 'PixelWarrior'),
('Dojo CyberNinja', 0, 'CyberNinja'),
('Reino do Steam', 0, 'SteamLord');

-- Inserções para páginas empresariais
INSERT INTO facepage.pagina (nome, nro_visitas, criador) VALUES
('Tech Solutions Oficial', 0, 'TechSolutions'),
('Inova Corp Hub', 0, 'InovaCorp'),
('Ecom Master Digital', 0, 'EcomMaster'),
('SocialBee Marketing', 0, 'SocialBee'),
('Cloud Nest Tech', 0, 'CloudNest');

-- Inserções para propagandas (herda de página)
INSERT INTO facepage.propaganda (nome, nro_visitas, criador, taxa_cliques, taxa_rejeicao, taxa_conversao, admin) VALUES
('Anúncios Tech Solutions', 0, 'TechSolutions', 0.25, 0.15, 0.20, 'TechSolutions'),
('Promo Inova Corp', 0, 'InovaCorp', 0.18, 0.12, 0.28, 'InovaCorp'),
('Ofertas Ecom Master', 0, 'EcomMaster', 0.22, 0.10, 0.25, 'EcomMaster'),
('Campanhas SocialBee', 0, 'SocialBee', 0.30, 0.20, 0.15, 'SocialBee'),
('Cloud Nest Ads', 0, 'CloudNest', 0.27, 0.18, 0.22, 'CloudNest');

-- Inserindo ações genéricas para interação com páginas
INSERT INTO facepage.acao (descricao) VALUES
('Criar postagens na página'),
('Editar postagens existentes'),
('Excluir postagens da página'),
('Gerenciar membros da página'),
('Alterar configurações de visibilidade'),
('Publicar anúncios patrocinados'),
('Visualizar métricas de engajamento'),
('Responder a comentários'),
('Moderar conteúdo ofensivo'),
('Atualizar informações da página');

-- Atribuir privilégios apenas aos amigos que participam dos grupos vinculados às páginas
INSERT INTO privilegios (usuario, nome, criador, codigo_acao) VALUES
-------------------------------
-- Página: Caçadores de Sombras (Criador: ShadowHunter)
-------------------------------
-- Grupo 1: Clã dos Caçadores (Membros: DragonSlayer)
('DragonSlayer', 'Caçadores de Sombras', 'ShadowHunter', 1),  -- Ação 1: Criar postagens
-- Grupo 2: Aliança Tech (Membros: DragonSlayer)
('DragonSlayer', 'Caçadores de Sombras', 'ShadowHunter', 2),  -- Ação 2: Editar postagens

-------------------------------
-- Página: Domadores de Dragões (Criador: DragonSlayer)
-------------------------------
-- Grupo 3: Guilda das Feras (Membros: ShadowHunter)
('ShadowHunter', 'Domadores de Dragões', 'DragonSlayer', 3),  -- Ação 3: Excluir postagens
-- Grupo 4: Equipe Pixel (Membros: ShadowHunter)
('ShadowHunter', 'Domadores de Dragões', 'DragonSlayer', 4),  -- Ação 4: Gerenciar membros

-------------------------------
-- Página: Guerreiros do Pixel (Criador: PixelWarrior)
-------------------------------
-- Grupo 5: Mestres do Pixel (Membros: CyberNinja)
('CyberNinja', 'Guerreiros do Pixel', 'PixelWarrior', 5),     -- Ação 5: Publicar anúncios
-- Grupo 6: Cyber Squad (Membros: CyberNinja)
('CyberNinja', 'Guerreiros do Pixel', 'PixelWarrior', 6),     -- Ação 6: Visualizar métricas

-------------------------------
-- Página: Reino do Steam (Criador: SteamLord)
-------------------------------
-- Grupo 7: Masters of Steam (Membros: MechaQueen)
('MechaQueen', 'Reino do Steam', 'SteamLord', 7),            -- Ação 7: Responder a comentários
-- Grupo 8: Indie Lovers (Membros: MechaQueen)
('MechaQueen', 'Reino do Steam', 'SteamLord', 8);            -- Ação 8: Moderar conteúdo

INSERT INTO pode_ver (nome, criador, codigo_grupo) VALUES
-- Página: Caçadores de Sombras (Criador: ShadowHunter)
('Caçadores de Sombras', 'ShadowHunter', 1),  -- Grupo 1: Clã dos Caçadores (admin: ShadowHunter)
('Caçadores de Sombras', 'ShadowHunter', 2),  -- Grupo 2: Aliança Tech (admin: ShadowHunter)

-- Página: Domadores de Dragões (Criador: DragonSlayer)
('Domadores de Dragões', 'DragonSlayer', 3),  -- Grupo 3: Guilda das Feras (admin: DragonSlayer)
('Domadores de Dragões', 'DragonSlayer', 4),  -- Grupo 4: Equipe Pixel (admin: DragonSlayer)

-- Página: Guerreiros do Pixel (Criador: PixelWarrior)
('Guerreiros do Pixel', 'PixelWarrior', 5),   -- Grupo 5: Mestres do Pixel (admin: PixelWarrior)
('Guerreiros do Pixel', 'PixelWarrior', 6),   -- Grupo 6: Cyber Squad (admin: PixelWarrior)

-- Página: Reino do Steam (Criador: SteamLord)
('Reino do Steam', 'SteamLord', 7),           -- Grupo 7: Masters of Steam (admin: SteamLord)
('Reino do Steam', 'SteamLord', 8);           -- Grupo 8: Indie Lovers (admin: SteamLord)