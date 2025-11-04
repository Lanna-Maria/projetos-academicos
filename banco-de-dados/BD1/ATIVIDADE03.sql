USE Empresa

1) Obter o nome dos produtos que possuem o maior preço. Ordene o resultado pelo nome do
produto.

SELECT DESCR 
FROM PRODUTOS
WHERE PRECO =ALL
(SELECT MAX(PRECO) AS MAIOR
FROM PRODUTOS)
ORDER BY DESCR

2) O número do pedido realizado no ano de 1996 que possui o maior valor de frete.

SELECT NUMPED
FROM PEDIDOS
WHERE YEAR (DataPed)= 1996 AND FRETE = 
(SELECT MAX(FRETE) AS MAIOR
FROM PEDIDOS
WHERE YEAR (DataPed)= 1996 )



3) Obter o nome dos funcionários do Brasil que possuem o salário superior à média de salário da
empresa.

SELECT NOME
FROM Funcionarios
WHERE PAIS = 'BRASIL' AND SALARIO > ALL
(SELECT AVG(SALARIO) AS MEDIA
FROM FUNCIONARIOS)

4) O nome dos produtos da categoria Bebidas que possuem o menor preço.

SELECT P.DESCR
FROM PRODUTOS AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  = 'BEBIDAS'  AND PRECO =ALL 
(SELECT MIN(PRECO) AS MENOR 
FROM PRODUTOS AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  = 'BEBIDAS')

5) O nome dos produtos da categoria Bebidas que também estão em outra categoria.

SELECT P.DESCR
FROM PRODUTOS AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  = 'BEBIDAS' 
 AND P.DESCR = ANY 
(SELECT P.DESCR
FROM PRODUTOS AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  != 'BEBIDAS' )

6) O nome dos produtos fornecidos pela Empresa Refrescos Americanas LTDA que possuem
preço superior a algum produto fornecido pela Empresa Ma Maison.

SELECT DESCR
FROM PRODUTOS AS P JOIN Fornecedores AS F
ON P.CodFor = F.CodFor
WHERE EMPRESA = 'Refrescos Americanas LTDA' AND PRECO > ANY
(SELECT PRECO
FROM PRODUTOS AS P JOIN Fornecedores AS F
ON P.CodFor = F.CodFor
WHERE EMPRESA = 'Ma Maison')


7) O nome dos funcionários que não realizaram nenhum pedido no ano de 1999.

SELECT NOME
FROM FUNCIONARIOS
WHERE NOME NOT IN
(SELECT NOME
FROM FUNCIONARIOS AS F JOIN Pedidos AS P
ON F.CodFun = P.CodFun
WHERE YEAR (DataPed)= 1999)

8) O nome dos produtos da categoria Confeitos que possuem preço superior que todos os preços
dos produtos da categoria Condimentos.

SELECT P.DESCR 
FROM Produtos AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  = 'CONFEITOS' 
AND PRECO > ALL
(SELECT PRECO
FROM Produtos AS P JOIN Categorias AS C
ON P.CodCategoria = C.CodCategoria
WHERE C.DESCR  = 'CONDIMENTOS' )



