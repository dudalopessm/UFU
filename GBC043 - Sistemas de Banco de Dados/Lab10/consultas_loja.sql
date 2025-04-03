SET search_path TO loja;

-- 1. Quais são os Nomes e Telefones de clientes que compram na loja 2;
SELECT c.nome, c.telefone
FROM notafiscal nf
INNER JOIN cliente c ON nf.codcliente = c.codcliente
INNER JOIN loja l ON nf.codloja = l.codloja
WHERE l.codloja = '2';

-- 2. Qual o Nome da Loja que mais vendeu no período de 20/05/1999 à 30/05/1999;
SELECT l.codloja, COUNT(nf.codloja) AS quantidade_vendida
FROM notafiscal nf
INNER JOIN loja l ON nf.codloja = l.codloja
WHERE nf.data BETWEEN '1999/05/20' AND '1999/05/30'
GROUP BY l.codloja
ORDER BY COUNT(l.codloja) DESC
LIMIT 1;

-- 3. valor total de notas fiscais de um mesmo cliente por loja, valor total de notas fiscais (total) por cliente, total dos valores de notas fiscais (resolver em uma mesma consulta);
SELECT c.codcliente AS cliente, l.codloja AS loja, SUM(nf.valortotal) AS total
FROM notafiscal nf
INNER JOIN loja l ON nf.codloja = l.codloja
INNER JOIN cliente c ON c.codcliente = nf.codcliente
GROUP BY ROLLUP(c.codcliente, l.codloja)
ORDER BY c.codcliente ASC;

-- 4. valor total de notas fiscais de um mesmo cliente por loja, valor total de notas fiscais (total) por cliente, valor total de notas fiscais (total) por loja, total dos valores de notas fiscais (resolver em uma mesma consulta);
SELECT c.codcliente AS cliente, l.codloja AS loja, SUM(nf.valortotal) AS total
FROM notafiscal nf
INNER JOIN loja l ON nf.codloja = l.codloja
INNER JOIN cliente c ON c.codcliente = nf.codcliente
GROUP BY CUBE(c.codcliente, l.codloja)
ORDER BY c.codcliente ASC;

-- 5. quantidade de atendimentos de um mesmo cliente por loja, quantidade de atendimentos de clientes (total) por loja, total da quantidade de atendimentos de clientes (considerando todas as lojas) (resolver em uma mesma consulta);
SELECT c.codcliente AS cliente, l.codloja AS loja, COUNT(nf.numnfiscal) AS total_atendimentos
FROM notafiscal nf
INNER JOIN loja l ON nf.codloja = l.codloja
INNER JOIN cliente c ON c.codcliente = nf.codcliente
GROUP BY ROLLUP(c.codcliente, l.codloja)
ORDER BY l.codloja, c.codcliente ASC;

-- 6. quantidade de atendimentos de um mesmo cliente por loja, quantidade de atendimentos de clientes (total) por loja, quantidade de atendimentos de clientes (total) independente da loja, total da quantidade de atendimentos de clientes (considerando todas as lojas) (resolver em uma mesma consulta).
SELECT c.codcliente AS cliente, l.codloja AS loja, COUNT(nf.numnfiscal) AS total_atendimentos
FROM notafiscal nf
INNER JOIN loja l ON nf.codloja = l.codloja
INNER JOIN cliente c ON c.codcliente = nf.codcliente
GROUP BY CUBE(c.codcliente, l.codloja)
ORDER BY l.codloja, c.codcliente ASC;

-- c) Criar visões que permitam mostrar

-- 1. As faturas, indicadas por seu numfatura, com as suas respectivas notas fiscais, também indicadas por seu numnfiscal além de valor total das notas fiscais. Fazer uma consulta na visão que contenha um agrupamento;
CREATE VIEW faturas AS
SELECT f.numfatura, nf.numnfiscal, nf.valortotal AS total_nfs
FROM notafiscal nf
INNER JOIN fatura f ON nf.numfatura = f.numfatura
GROUP BY f.numfatura, nf.numnfiscal
ORDER BY f.numfatura, nf.numnfiscal ASC;

SELECT numfatura, COUNT(DISTINCT numnfiscal) AS qtde_nf_por_faturas
FROM faturas
GROUP BY numfatura;

-- 2. Criar uma visão materializada com a opção WITH NO DATA para recuperar os nomes dos clientes juntamente com o número de lojas que eles efetuaram compras. Mostrar uma consulta à visão;
CREATE MATERIALIZED VIEW clientes_e_lojas AS
SELECT c.codcliente, c.nome, COUNT(l.codloja) AS quantidade_comprada_em
FROM notafiscal nf
INNER JOIN cliente c ON nf.codcliente = c.codcliente
INNER JOIN loja l ON l.codloja = nf.codloja
GROUP BY c.codcliente, c.nome
ORDER BY c.codcliente, c.nome ASC
WITH NO DATA;

REFRESH MATERIALIZED VIEW clientes_e_lojas;

SELECT cl.codcliente, quantidade_lojas_compradas, l.nome AS nome_loja
FROM clientes_e_lojas cl
INNER JOIN notafiscal nf ON nf.codcliente = cl.codcliente
INNER JOIN loja l ON l.codloja = nf.codloja
GROUP BY cl.codcliente, quantidade_lojas_compradas, l.nome
ORDER BY cl.codcliente, l.nome ASC;

-- 3. Criar uma visão para recuperar os nomes dos clientes juntamente com os nomes das lojas que eles efetuaram compras. Mostrar uma consulta à visão que contenha um agrupamento;
CREATE VIEW compradores_de_lojas AS
SELECT c.nome AS cliente, l.nome AS loja
FROM notafiscal nf
INNER JOIN cliente c ON nf.codcliente = c.codcliente
INNER JOIN loja l ON nf.codloja = l.codloja
GROUP BY c.nome, l.nome
ORDER BY c.nome, l.nome ASC;

SELECT cl.cliente, cl.loja, SUM(nf.valortotal) AS quantidade_gasta
FROM compradores_de_lojas cl
INNER JOIN cliente c ON c.nome = cl.cliente
INNER JOIN loja l ON l.nome = cl.loja
INNER JOIN notafiscal nf ON nf.codcliente = c.codcliente AND nf.codloja = l.codloja
GROUP BY cl.cliente, cl.loja
ORDER BY SUM(nf.valortotal) DESC;

-- 4. Criar a visão 'produtosmaisvendidos' contendo a descrição dos três produtos mais vendidos. Mostrar uma consulta à visão;
CREATE VIEW top_tres_produtos AS
SELECT p.descricao AS descricao_produto
FROM itemnotafiscal it
INNER JOIN notafiscal nf ON nf.numnfiscal = it.numnfiscal
INNER JOIN produto p ON p.codproduto = it.codproduto
GROUP BY p.descricao
ORDER BY SUM(it.quantidade) DESC
LIMIT 3;

SELECT p.codproduto AS produto, top.descricao_produto, SUM(quantidade) AS vendas
FROM top_tres_produtos top
INNER JOIN produto p ON p.descricao = top.descricao_produto
INNER JOIN itemnotafiscal it ON it.codproduto = p.codproduto
GROUP BY p.codproduto, top.descricao_produto
ORDER BY SUM(quantidade) DESC;

-- 5. Criar a visão 'notafiscaldetalhada' contendo para cada nota fiscal seu número, data, código do cliente, código da loja, valor total e a descrição dos produtos contidos nela. Mostrar uma consulta à visão;
CREATE VIEW notafiscaldetalhada AS
SELECT nf.numnfiscal AS numero, nf.data, nf.codcliente AS cliente, nf.codloja AS loja, nf.valortotal AS valor, p.descricao AS desc_produto
FROM notafiscal nf
INNER JOIN itemnotafiscal it ON nf.numnfiscal = it.numnfiscal
INNER JOIN produto p ON it.codproduto = p.codproduto
GROUP BY nf.numnfiscal, nf.data, nf.codcliente, nf.codloja, nf.valortotal, p.descricao;

SELECT cliente, loja, desc_produto, valor
FROM notafiscaldetalhada
GROUP BY cliente, loja, desc_produto, valor
ORDER BY valor DESC
LIMIT 3;

-- 6. Criar a visão 'clientesimportantes' contendo para cada cliente que gastou mais do que R$100,00, o nome do cliente, o contato do cliente, o telefone do cliente e o valor total gasto. Mostrar uma consulta à visão.
CREATE VIEW clientesimportantes AS
SELECT c.nome AS nome_cliente, c.contato AS contato_cliente, c.telefone AS telefone_cliente, SUM(nf.valortotal) AS gastos
FROM notafiscal nf
INNER JOIN cliente c ON nf.codcliente = c.codcliente
GROUP BY c.nome, c.contato, c.telefone
HAVING SUM(nf.valortotal) > 100;

SELECT ci.nome_cliente, ci.contato_cliente, ci.telefone_cliente, ci.gastos AS total_gasto, COUNT(nf.numnfiscal) AS quantidade_compras
FROM clientesimportantes ci
INNER JOIN notafiscal nf ON nf.codcliente = (SELECT codcliente FROM cliente WHERE nome = ci.nome_cliente)
GROUP BY ci.nome_cliente, ci.contato_cliente, ci.telefone_cliente, ci.gastos
ORDER BY ci.gastos DESC;
