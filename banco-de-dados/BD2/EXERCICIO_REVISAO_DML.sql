use empresa

1- Crie uma tabela de nome tbPedido preenchida com os dados NumPed, Nome do
funcionário, Nome do cliente, Total do pedido e Frete. Preencha apenas com os
pedidos cujo valor do frete é superior a média de fretes.

SELECT P.NUMPED, F.NOME AS NOME_FUNCIONARIO, C.NOME AS NOME_CLIENTE,
SUM(PRECO * QTDE - DESCONTO) AS TOTAL_PEDIDO, FRETE 
INTO TBPEDIDO
FROM PEDIDOS P JOIN Funcionarios F 
ON P.CodFun = F.CodFun
JOIN
CLIENTES C
ON C.CodCli = P.CodCli
JOIN
DetalhesPed DP
ON DP.NumPed = P.NumPed
WHERE FRETE > (SELECT AVG (FRETE) FROM Pedidos)
GROUP BY P.NumPed, F.NOME, C.NOME, FRETE

2- Insira o produto com os seguintes valores: Desc = Chees, Fornecedor = Leka
Trading, CodCategoria = Laticínios, Preço = 18.50, Unidades = 10,
Descontinuado = False.

INSERT INTO PRODUTOS
VALUES
('CHEES',(SELECT CODFOR FROM Fornecedores WHERE EMPRESA = 'Leka Trading'),
 (SELECT CODCATEGORIA FROM CATEGORIAS WHERE DESCR = 'Latic’nios'), 18.50, 10, 0)

 SELECT * FROM PRODUTOS

 3- Aumente o preço dos produtos para um acréscimo de 5% da média de preço.

 UPDATE PRODUTOS
SET PRECO = PRECO + (SELECT AVG(PRECO) FROM Produtos) * 0.05

4- Altere o desconto dos produtos que estão abaixo da média de desconto das
vendas para o valor médio.

UPDATE DETALHESPED
SET DESCONTO = (SELECT AVG(DESCONTO) FROM DETALHESPED)
WHERE DESCONTO < (SELECT AVG(DESCONTO) FROM DETALHESPED)

5- Remova o produto cujo preço é inferior a todos os produtos da Categoria Frutos
do Mar.

DELETE FROM PRODUTOS
WHERE PRECO < ALL(SELECT PRECO FROM PRODUTOS AS P JOIN CATEGORIAS AS C 
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR ='Frutos do Mar') 