use SistemaBancario

Obter o número de cada conta, assim como a quantidade de clientes, a quantidade de
contas corrente e a quantidade de contas poupança vinculada a cada conta.

SELECT CON_NUMERO,
(SELECT COUNT(*)
FROM tbCliente
WHERE C.CON_CODIGO = CON_CODIGO) AS QTDE_CLIENTE , 
(SELECT COUNT (*)
FROM tbContaCorrente
WHERE C.CON_CODIGO = CON_CODIGO) AS QTDE_CONTACORRENTE,
(SELECT COUNT (*)
FROM tbContaPoupanca
WHERE C.CON_CODIGO = CON_CODIGO) AS QTDE_CONTAPOUPANCA
FROM tbConta AS C

Obter o número da agência, o somatório da taxa de manutenção de cada conta corrente
vinculada à agência e o somatório da taxa de rendimento de cada conta poupança
vinculada à agência.

SELECT AGE_NUMERO,
(SELECT SUM(COC_TAXA_MANUTENCAO)
FROM tbContaCorrente CC JOIN tbConta AS C
ON CC.CON_CODIGO = C.CON_CODIGO
WHERE A.AGE_CODIGO = AGE_CODIGO) AS SOMATORIO_TAXA_DE_MANUTENCAO,
(SELECT SUM(COP_TAXA_RENDIMENTO)
FROM tbContaPoupanca AS CP JOIN tbConta AS C
ON CP.CON_CODIGO = C.CON_CODIGO
WHERE A.AGE_CODIGO = AGE_CODIGO) AS SOMATORIO_TAXA_DE_RENDIMENTO
FROM tbAgencia AS A

Obter o nome e o CPF dos clientes da cidade de Fortaleza, a quantidade de contas
corrente e a quantidade de contas poupanças que o cliente possui.

SELECT CLI_NOME, CLI_CPF,
(SELECT COUNT(*)
FROM tbContaCorrente AS CC JOIN tbConta AS CN
ON CC.CON_CODIGO = CN.CON_CODIGO
JOIN 
tbContaCliente AS CCL
ON CN.CON_CODIGO = CCL.CON_CODIGO
WHERE C.CLI_CODIGO = CLI_CODIGO) AS QTDE_CONTACORRENTE,
(SELECT COUNT(*)
FROM tbContaPoupanca AS CP JOIN tbConta AS CN
ON CP.CON_CODIGO = CN.CON_CODIGO
JOIN 
tbContaCliente AS CCL
ON CN.CON_CODIGO = CCL.CON_CODIGO
WHERE C.CLI_CODIGO = CLI_CODIGO) AS QTDE_CONTAPOUPANCA 
FROM tbCliente AS C
WHERE CLI_CIDADE = 'FORTALEZA'

Obter o número de cada agência, a quantidade de contas vinculada a agência e a
quantidade de clientes (distintos) vinculados à agência.

SELECT AGE_NUMERO,
(SELECT COUNT(*)
FROM tbConta
WHERE A.AGE_CODIGO = AGE_CODIGO) AS QTDE_CONTASVINCULADAS,
(SELECT COUNT(DISTINCT C.CLI_CODIGO)
FROM tbCliente AS C JOIN tbContaCliente AS CC
ON C.CLI_CODIGO = CC.CLI_CODIGO
JOIN 
tbConta AS CN
ON CC.CON_CODIGO = CN.CON_CODIGO
WHERE A.AGE_CODIGO = AGE_CODIGO) AS CLIENTESDISTINTOS
FROM tbAgencia AS A

Obter o número de cada agência, a quantidade de clientes (distintos) vinculados à
agência e o percentual de clientes da agência em relação a todos os clientes.

SELECT AGE_NUMERO, 
(SELECT  COUNT(DISTINCT CL.CLI_CODIGO)
FROM tbCliente AS CL JOIN tbContaCliente AS CC
ON CL.CLI_CODIGO = CC.CLI_CODIGO
JOIN
tbConta AS C
ON CC.CON_CODIGO = C.CON_CODIGO
WHERE A.AGE_CODIGO = AGE_CODIGO) AS CLIENTESDISTINTOS,
(SELECT  COUNT(DISTINCT CL.CLI_CODIGO)
FROM tbCliente AS CL JOIN tbContaCliente AS CC
ON CL.CLI_CODIGO = CC.CLI_CODIGO
JOIN
tbConta AS C
ON CC.CON_CODIGO = C.CON_CODIGO
WHERE A.AGE_CODIGO = AGE_CODIGO)/CONVERT (DECIMAL(10,2),(SELECT COUNT(*) 
FROM tbCliente)) * 100 AS PERCENTUALCLIENTES
FROM tbAgencia AS A  