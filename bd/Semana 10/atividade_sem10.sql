/*Nome: Marcos Lucas da Silva (RA:140782)
Banco de Dados 2021/2 - Profª Daniela Leal Musa*/
CREATE DATABASE Cinema;

CREATE TABLE Ator(
	coda integer,
    nomeart varchar(25),
    nomereal varchar(25),
    nacionalidade varchar(25),
    sexo char,
    indicacoesoscar integer,
    num_oscar integer,
    PRIMARY KEY(coda)
);

CREATE TABLE Filme(
	codf integer,
    nome varchar(20),
    ano date,
    orcamento float,
    tempo float,
    PRIMARY KEY(codf)
);

CREATE TABLE Personagem(
	coda integer,
    codf integer,
    personagem varchar(25),
    cache float,
    PRIMARY KEY(coda, codf),
    FOREIGN KEY(coda) REFERENCES Ator(coda),
    FOREIGN KEY(codf) REFERENCES Filme(codf)
);

INSERT INTO Ator(coda, nomeart, nomereal, nacionalidade, sexo, indicacoesoscar, num_oscar)
VALUES 	(1, "DemiMoore", "MariadaSilva", "USA", 'f', 0, 0),
		(2, "BradPitt", "JoaoPaulo", "USA", 'm', 1, 0),
        (3, "DustinHoffman", "DustinHoffman", "USA", 'm', 2, 0),
        (4, "JessicaLange", "JessicaLange", "USA", 'f', 4, 2),
        (5, "SoniaBraga", "SoniaBraga", "Brasil", 'f', 0, 0);
        
INSERT INTO Filme(codf, nome, ano, orcamento, tempo)
VALUES 	(1, "A Jurada", '1996-02-02', 1000000, 18),
		(2, "A Letra Escarlete", '1995-10-13', 10000000, 24),
        (3, "Seven", '1995-12-15', 1500000, 20),
        (4, "Tootsie", '1982-12-17', 50000, 16),
        (5, "Tieta", '1996-08-30', 200000, 18);
        
INSERT INTO Personagem(coda, codf, personagem, cache)
VALUES 	(1, 1,"Mary", 3000),
		(1, 2,"Sandy", 5000),
        (2, 3,"John", 5000),
        (3, 4,"Mary", 1000),
        (4, 4,"Tootsie", 2000),
        (5, 5,"Tieta", 500);

/*SEMANA 10*/

/*1. a soma das idades das atrizes (NÃO EXISTE O ATRIBUTO "IDADE"!)*/

/*2. o nome do artista e o número de filmes em que participou*/
SELECT nomeart, COUNT(*) 
FROM Ator a, Filme f, Personagem p
WHERE a.coda=f.coda AND f.codf=p.codf 
GROUP BY a.coda

/*3. para cada ator que não ganhou oscar, listar o seu nome, ano de seu filme mais antigo e do mais novo*/
SELECT nomeart, MIN(Filme.ano) , MAX(Filme.ano)
FROM Ator, Personagem, Filme
WHERE Ator.coda=Personagem.coda AND Personagem.codf=Filme.codf
GROUP BY Ator.coda

/*4. para cada filme listar: o nome do filme, média de cachês pagos por filme, cachê mais alto, cachê
mais baixo, e total dos cachês pagos*/
SELECT nome, AVG(Filme.orcamento), MAX(Filme.orcamento), MIN(Filme.orcamento), SUM(Filme.orcamento) 
FROM Filme 
GROUP BY Filme.codf

/*5. o nome do artista e o número de filmes em que participou, para todo artista que participou de
no mínimo 2 filmes*/
SELECT nomeart, COUNT(*) 
FROM Ator, Filme, Personagem 
WHERE Ator.coda=Personagem.coda AND Filme.codf=Personagem.codf 
GROUP BY Ator.coda
HAVING COUNT(*) >= 2

/*6. o número de caches distintos maiores do que 2000 pagos em cada filme, para todo filme onde
a soma dos cachês destes artistas foi inferior a 8000. ( use count (distinct cache) )*/
SELECT COUNT(DISTINCT cache)
FROM Personagem p, Filme f
WHERE f.codf=pcodf AND cache>2000
GROUP BY f.codf
HAVING SUM(cache) < 8000