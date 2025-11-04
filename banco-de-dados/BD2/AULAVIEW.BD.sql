use SistemaAcademicoBCC

→ Crie uma visão vwCurso que exiba o código, o nome, o
nível do curso, assim como a quantidade de disciplinas e o
somatório de carga horária das disciplinas do curso.

CREATE VIEW VWCURSO
AS SELECT C.CUR_CODIGO, CUR_NOME, CUR_NIVEL,
COUNT (*) AS QTDEDISCIPLINAS ,
SUM (D.DIS_CARGA_HORARIA) AS SOMA
FROM tbCurso AS C JOIN TBDISCIPLINA AS D
ON C.CUR_CODIGO = D.CUR_CODIGO
GROUP BY C.CUR_CODIGO, CUR_NOME, CUR_NIVEL

SELECT * FROM VWCURSO

→ Crie uma visão vwAluno que exiba o código, o nome e o
nome e as disciplinas de cada aluno.

CREATE VIEW VWALUNO
AS 
SELECT A.ALU_CODIGO, ALU_NOME, DIS_NOME
FROM tbAluno AS A JOIN tbAlunoMatricula AS AM
ON A.ALU_CODIGO = AM.ALU_CODIGO
JOIN tbOfertaDisciplina AS OD
ON AM.ODI_CODIGO = OD.ODI_CODIGO
JOIN tbDisciplina AS D
ON OD.DIS_CODIGO = D.DIS_CODIGO

EXIBIR O NOME DOS ALUNOS QUE CURSA BANCO DE DADOS II

SELECT ALU_NOME
FROM VWALUNO
WHERE DIS_NOME = 'BANCO DE DADOS II'

→ Crie uma visão vwCursoDisciplina que exiba o código, o
nome e o nível dos cursos cuja carga horária do curso é
superior ao somatório da carga horária das suas disciplinas.

CREATE VIEW VWCursoDisciplina
AS 
SELECT CUR_CODIGO, CUR_NOME ,CUR_NIVEL
FROM tbCurso AS C
WHERE CUR_CARGA_HORARIA > (SELECT SOMA FROM VWCURSO WHERE C.CUR_CODIGO = CUR_CODIGO)


O NOME DO CURSO DE NIVEL TECNICO

SELECT CUR_NOME
FROM VWCursoDisciplina
WHERE CUR_NIVEL = 'TÉCNICO'













