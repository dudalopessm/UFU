CREATE SCHEMA LOJA;

SET SEARCH_PATH TO LOJA;

CREATE TABLE CLIENTE (
  codcliente SMALLINT PRIMARY KEY,
  nome VARCHAR(50),
  endereco VARCHAR(100),
  cidade VARCHAR(20),
  telefone VARCHAR(15),
  cgccliente VARCHAR(20),
  contato VARCHAR(50));

CREATE TABLE LOJA (
  codloja SMALLINT PRIMARY KEY,
  nome VARCHAR(50),
  endereco VARCHAR(100),
  cidade VARCHAR(20),
  cgccliente VARCHAR(20));

CREATE TABLE FATURA (
  numfatura INT PRIMARY KEY,
  datavenc DATE,
  datapg DATE,
  codcliente SMALLINT,
  valortotal NUMERIC(9,2),
  CONSTRAINT faturafk FOREIGN KEY (codcliente) REFERENCES CLIENTE);

CREATE TABLE NOTAFISCAL (    
  numnfiscal SMALLINT PRIMARY KEY,
  data DATE,
  codcliente SMALLINT,
  codloja SMALLINT,
  numfatura INT,
  valortotal NUMERIC(9,2),
  CONSTRAINT faturafk1 FOREIGN KEY (codcliente) REFERENCES CLIENTE,
  CONSTRAINT faturafk2 FOREIGN KEY (codloja) REFERENCES LOJA,
  CONSTRAINT faturafk3 FOREIGN KEY (numfatura) REFERENCES FATURA);

CREATE TABLE PRODUTO (    
  codproduto INT PRIMARY KEY,
  descricao VARCHAR(100),
  valorvenda NUMERIC(9,2),
  valorcompra NUMERIC(9,2),
  unidade VARCHAR(10),
  qtdestoque SMALLINT);

CREATE TABLE ITEMNOTAFISCAL (
  numnfiscal SMALLINT,
  codproduto INT,
  quantidade SMALLINT,
  valorunidcusto NUMERIC(9,2),
  valorunidvenda NUMERIC (9,2),
  CONSTRAINT faturaPK PRIMARY KEY (numnfiscal,codproduto),
  CONSTRAINT inffk1 FOREIGN KEY (numnfiscal) REFERENCES NOTAFISCAL,
  CONSTRAINT inffk2 FOREIGN KEY (codproduto) REFERENCES PRODUTO);

  INSERT INTO CLIENTE VALUES (111,'Computec Ltda', 'Av.São Carlos, 186', 'São Carlos - SP', '(017) 276-9999', '123.689.157/0001-89', 'José da Silva'),
(112, 'MicroMédia SA', 'R.José Bonifácio, 70', 'São Carlos - SP', '(017) 273-8974', '154.586.524/0001-55', 'João da Silva'),
(113, 'TecnoCom Ltda', 'R.Luiz Camões, 120', 'Ibaté - SP', '(017) 278-8568', '875.684.458/0001-99', 'Antonio Benedito'),
(114, 'C&P', 'Av. São Carlos, 176', 'São Carlos - SP', '(017) 274-9874', '352.476.777/0001-43', 'Lucas Jorge'),
(115, 'ProvTecno', 'R.Raul Junior, 180', 'São Carlos - SP', '(017) 273-9865', '278.852.468/0001-58', 'Carlos Antonio');

INSERT INTO LOJA  VALUES (1, 'Papelândia 1', 'Av.São Carlos, 870', 'São Carlos - SP', '232.456.666/0001-89'),
(2, 'Papelândia 2', 'R. XV Novembro, 121', 'São Carlos - SP', '232.456.666/0002-34'),
(3, 'Papelândia 3', 'R. 7 Setembro, 1823', 'São Carlos - SP', '232.456.666/0003-92'),
(4, 'Papelândia 4', 'Av. Independência, 567', 'São Carlos - SP', '232.456.666/0004-22'),
(5, 'Papelândia 5', 'R. Tiradentes 432', 'São Carlos - SP', '232.456.666/0005-19');


INSERT INTO FATURA (numfatura, datavenc, codcliente, valortotal) VALUES 
(045675, '10/04/1999', 111, 101.50),
(045690,'10/05/1999', 111, 108.90),
(045691, '10/05/1999', 112, 120.50),
(045692, '10/05/1999', 113, 14.90),
(045693, '10/05/1999', 115, 31.50);

INSERT INTO NOTAFISCAL VALUES 
(2142, '01/04/1999', 111, 1, 045675, 17.50),
(2143, '10/04/1999', 111, 2, 045675, 84.00),
(2144, '17/05/1999', 111, 1, 045675, 13.00),
(2145, '05/05/1999', 111, 1, 045690, 36.00),
(2146, '22/05/1999', 111, 2, 045690, 59.90),
(2147, '18/05/1999', 112, 2, 045691, 66.00),
(2148, '27/05/1999', 112, 5, 045691, 54.50),
(2149, '01/05/1999', 113, 4, 045692, 14.10),
(2150, '30/05/1999', 113, 4, 045692, 0.80),
(2151, '26/05/1999', 115, 5, 045693, 31.50);

INSERT INTO PRODUTO VALUES 
(86477, 'Resma papel sufite', 8.00, 4.55, 'pacote', 571),
(86478, 'Clips nº 5', 3.00, 1.76, 'caixa', 424),
(86479, 'Clips nº 10', 5.00, 2.52, 'caixa', 454),
(86480, 'Grampo para Grampeador', 4.00, 1.43, 'caixa', 357),
(86481, 'Grampeador', 18.00, 10.50, 'unidade', 54),
(86482, 'Lapis preto nº 5', 0.20, 0.05, 'unidade', 86),
(86483, 'Caderno 10 matérias 150 fls', 5.50, 2.30, 'unidade', 98),
(86484, 'Caderno 12 matérias 150 fls', 7.00, 3.81, 'unidade', 75),
(86485, 'Caneta azul bic', 0.50, 0.20, 'unidade', 86),
(86486, 'Caneta vermelha bic', 0.50, 0.20, 'unidade', 67);

INSERT INTO ITEMNOTAFISCAL VALUES
(2142, 86477, 2, 4.55, 8.00),
(2142, 86486, 3, 0.20, 0.50),
(2143, 86479, 12, 2.52, 5.00),
(2143, 86480, 6, 1.43, 4.00),
(2144, 86484, 1, 3.81, 7.00),
(2144, 86478, 2, 1.76, 3.00),
(2145, 86480, 9, 1.43, 4.00),
(2146, 86483, 1, 2.30, 5.50),
(2146, 86481, 3, 10.50, 18.00),
(2146, 86482, 2, 0.05, 0.20),
(2147, 86485, 4, 0.20, 0.50),
(2147, 86477, 8, 4.55, 8.00),
(2148, 86483, 9, 2.30, 5.50),
(2148, 86479, 1, 2.52, 5.00),
(2149, 86480, 2, 1.43, 4.00),
(2149, 86482, 3, 0.05, 0.20),
(2149, 86483, 1, 2.30, 5.50),
(2150, 86482, 4, 0.05, 0.20),
(2151, 86480, 7, 1.43, 4.00),
(2151, 86486, 7, 0.20, 0.50);

