USE Empresa

Aumentar o salário de todos os funcionários em 5% do valor
médio de salário da empresa.

UPDATE Funcionarios
SET SALARIO = SALARIO + (SELECT AVG(SALARIO) MEDIADESALARIO
FROM Funcionarios) * 0.05

SELECT * FROM Funcionarios

Alterar o salário do funcionário de maior salário para o maior
salário do funcionário de cargo Gerente.

UPDATE Funcionarios
SET SALARIO = (SELECT MAX (SALARIO) MAIORSALARIO FROM Funcionarios WHERE CARGO LIKE 'GERENTE%')
WHERE 
SALARIO = (SELECT MAX (SALARIO) MAIORSALARIO FROM Funcionarios)

→ Remova os funcionários cujo salário é maior que o maior
salário do funcionário de cargo ‘Gerente’.

DELETE FUNCIONARIOS
WHERE SALARIO > (SELECT MAX(SALARIO) FROM Funcionarios WHERE CARGO LIKE 'GERENTE%')

→ Remova os funcionários cujo salário é maior que qualquer
funcionário de cargo Coordenador.

DELETE Funcionarios
WHERE SALARIO > ANY (SELECT SALARIO FROM Funcionarios WHERE CARGO LIKE 'COORDENADOR%')
