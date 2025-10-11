-- Resetar
DROP TABLE IF EXISTS Cargo, Partido, Zona_Secao, Candidato, Votacao;

-- a) Criação das tabelas Candidato, Votacao e Zona_Secao, 
-- especificando chave primária e chaves estrangeiras;

CREATE TABLE IF NOT EXISTS Cargo(
	cod_cargo INT PRIMARY KEY,
	nome_cargo VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Partido(
	cod_partido INT PRIMARY KEY,
	nome_partido VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Zona_Secao(
	num_zona INT,
	num_secao INT,
	nome_zona_secao VARCHAR(255) NOT NULL,
	qtd_eleitores INT,
	CONSTRAINT pk_zona_secao 
		PRIMARY KEY (num_zona, num_secao)
);

CREATE TABLE IF NOT EXISTS Candidato(
	num_candidato INT PRIMARY KEY,
	cod_cargo INT,
	cod_partido INT,
	nome_candidato VARCHAR(255) NOT NULL,
	CONSTRAINT fk_candidato_cargo 
		FOREIGN KEY (cod_cargo) REFERENCES Cargo(cod_cargo),
	CONSTRAINT fk_candidato_partido
		FOREIGN KEY (cod_partido) REFERENCES Partido(cod_partido)
);

CREATE TABLE IF NOT EXISTS Votacao(
	num_zona INT,
	num_secao INT,
	num_candidato INT,
	qtd_votos INT,
	CONSTRAINT pk_votacao
		PRIMARY KEY (num_zona, num_secao, num_candidato),
	CONSTRAINT fk_votacao_zona_secao
		FOREIGN KEY (num_zona, num_secao) REFERENCES Zona_Secao(num_zona, num_secao),
	CONSTRAINT fk_votacao_candidato
		FOREIGN KEY (num_candidato) REFERENCES Candidato(num_candidato)
);

-- b) Alteração da estrutura da tabela Votacao, adicionando um atributo data_votacao;

ALTER TABLE Votacao
ADD COLUMN data_votacao DATE;

-- c) Alteração da estrutura da tabela Candidato, 
-- removendo a chave estrangeira com a tabela Partido; 

ALTER TABLE Candidato
DROP CONSTRAINT fk_candidato_partido;

-- d) Criar um índice “não-clustered” na tabela Candidato, 
-- com os atributos cod_cargo e cod_partido;

CREATE INDEX idx_candidato_partido ON Candidato (cod_cargo, cod_partido);

-- e) Inserir um registro na tabela Votacao. 
-- (qtd_votos = 1000, num_secao = 10, num_zona = 5, num_candidato = 555);

INSERT INTO Zona_Secao (num_zona, num_secao, nome_zona_secao, qtd_eleitores)
VALUES (5, 10, 'Colégio Nossa Senhora', 128);

INSERT INTO Partido (cod_partido, nome_partido)
VALUES (10, 'Partido IFBA');

INSERT INTO Cargo (cod_cargo, nome_cargo)
VALUES (7, 'Tesoureiro');

INSERT INTO Candidato (num_candidato, cod_cargo, cod_partido, nome_candidato)
VALUES (555, 7, 10, 'João');

INSERT INTO Votacao (qtd_votos, num_secao, num_zona, num_candidato, data_votacao)
VALUES (1000, 10, 5, 555, '20250708');

SELECT * FROM Votacao;

-- f) Inserir um registro na tabela Zona_Secao 
-- (qtd_eleitores = 300, nome_zona_secao = “Zona Teste”, num_zona = 7, num_secao = 99).

INSERT INTO Zona_Secao (num_zona, num_secao, nome_zona_secao, qtd_eleitores)
VALUES (7, 99, 'Zona Teste', 300);

-- g) Alterar a quantidade de votos, multiplicando por 2, para os candidatos a governador
-- (código do cargo = 1) e do Partido Democrático (código de partido = 5);

UPDATE Votacao
SET qtd_votos = qtd_votos * 2
WHERE num_candidato IN (
	SELECT num_candidato
	FROM Candidato
	WHERE cod_cargo = 1 AND cod_partido = 5
);

--h) Alterar a quantidade de eleitores, somando 100, para as zonas/seções onde ocorreu
-- votação para candidatos ao Senado (código do cargo = 2);

UPDATE Zona_Secao
SET qtd_eleitores = qtd_eleitores + 100
WHERE (num_zona, num_secao) IN (
	SELECT v.num_zona, v.num_secao
	FROM Votacao v
	JOIN Candidato c ON v.num_candidato = c.num_candidato
	WHERE c.cod_cargo = 2
);

-- i) Apagar todos os cargos que não possuem candidatos;

DELETE FROM Cargo
WHERE cod_cargo NOT IN (
	SELECT DISTINCT cod_cargo 
	FROM Candidato
	WHERE cod_cargo IS NOT NULL
);

-- j) Apagar as zonas/seções que possuam menos de 1.000 eleitores 
-- e que o nome comecem com a letra “A”;

DELETE FROM Zona_Secao
WHERE qtd_eleitores < 1000 and nome_zona_secao ILIKE 'A%';

-- k) Selecionar nome do partido, nome do candidato e nome do cargo, 
-- em ordem alfabética do nome do partido;
SELECT
	p.nome_partido,
	c.nome_candidato,
	ca.nome_cargo
FROM Candidato c
JOIN Partido p ON c.cod_partido = p.cod_partido
JOIN Cargo ca ON c.cod_cargo = ca.cod_cargo
ORDER BY p.nome_partido;

-- l) Selecionar código e nome do partido, nome do cargo e a 
-- quantidade de candidatos por partido, para cada cargo;
SELECT
	p.cod_partido,
	p.nome_partido,
	ca.nome_cargo,
	COUNT(c.num_candidato) AS quantidade_de_candidatos
FROM Candidato c
JOIN Partido p ON c.cod_partido = p.cod_partido
JOIN Cargo ca ON c.cod_cargo = ca.cod_cargo
GROUP BY p.cod_partido, p.nome_partido, ca.nome_cargo
ORDER BY p.nome_partido, ca.nome_cargo;

-- m) Selecionar as zonas/seções onde não ocorreu votação;

SELECT zs.*
FROM Zona_Secao zs
LEFT JOIN Votacao v ON zs.num_zona = v.num_zona AND zs.num_secao = v.num_secao
WHERE v.num_candidato IS NULL;

-- n) Selecionar número do candidato, nome do candidato, nome do cargo, 
-- nome do partido e quantidade total de votos de cada candidato, apenas 
-- para os candidatos que tiveram uma votação superior 100.000 votos;
SELECT
	c.num_candidato,
	c.nome_candidato,
	ca.nome_cargo,
	p.nome_partido,
	SUM(v.qtd_votos) AS total_de_votos
FROM Votacao v
JOIN Candidato c ON v.num_candidato = c.num_candidato
JOIN Cargo ca ON c.cod_cargo = ca.cod_cargo
JOIN Partido p ON c.cod_partido = p.cod_partido
GROUP BY c.num_candidato, c.nome_candidato, ca.nome_cargo, p.nome_partido
HAVING SUM(v.qtd_votos) > 100000;

-- o) Selecionar o número do candidato, nome do candidato e a sua média 
-- de votos obtidos nas zonas/seções;
SELECT
	c.num_candidato,
	c.nome_candidato,
	AVG(v.qtd_votos) AS media_de_vodos
FROM Votacao v
JOIN Candidato c ON v.num_candidato = c.num_candidato
GROUP BY c.num_candidato, c.nome_candidato;

-- p) Selecionar o código do partido, nome do partido, nome do candidato 
-- e a média de votos obtidos, apenas para os candidatos que tiveram média
-- de votos superior à média de votos do seu partido.

WITH MediaVotosCandidato AS (
	SELECT
		num_candidato,
		AVG(qtd_votos) AS media_candidato
	FROM Votacao
	GROUP BY num_candidato
),
MediaVotosPartido AS (
	SELECT
		c.cod_partido,
		AVG(v.qtd_votos) AS media_partido
	FROM Votacao v
	JOIN Candidato c ON v.num_candidato = c.num_candidato
	GROUP BY c.cod_partido
)
SELECT
	p.cod_partido,
	p.nome_partido,
	c.nome_candidato,
	mvc.media_candidato
FROM Candidato c
JOIN Partido p ON c.cod_partido = p.cod_partido
JOIN MediaVotosCandidato mvc ON c.num_candidato = mvc.num_candidato
JOIN MediaVotosPartido mvp ON c.cod_partido = mvp.cod_partido
WHERE mvc.media_candidato > mvp.media_partido;

