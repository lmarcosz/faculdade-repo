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

SELECT * FROM Ator WHERE sexo='f'; /*1. dados de todas as atrizes*/
SELECT nomeart, sexo FROM Ator; /*2. o nome e sexo dos artistas*/
SELECT nomeart, indicacoesoscar, num_oscar FROM Ator; /*3. o nome e o número de oscars indicados e recebidos*/
SELECT codf FROM Personagem WHERE cache<1000; /*4. o código dos filmes onde houve  artista com cachê menor que 1000*/
SELECT personagem FROM Personagem, Ator WHERE nomeart='DemiMoore' AND Ator.coda=Personagem.coda; /*5. o nome dos personagens desempenhados por Demi Moore*/
SELECT nome FROM Filme, Ator, Personagem WHERE nomeart='DemiMoore' AND Ator.coda=Personagem.coda AND Filme.codf=Personagem.codf; /*6. o nome dos filmes desempenhados por Demi Moore*/
SELECT nomeart FROM Ator WHERE nomereal LIKE '%Jessica%'; /*7. o nome artístico completo de todas as atrizes chamadas Jessica*/
SELECT nomeart FROM Ator WHERE indicacoesoscar=num_oscar+2; /*8. o nome dos artistas que tem duas indicações a mais que oscar ganhos*/
SELECT nomeart FROM Ator ORDER BY nomeart; /*9. o nome de todos os artistas em ordem alfabética*/
SELECT personagem, nomeart FROM Personagem, Ator WHERE sexo='f' AND Ator.coda=Personagem.coda; /*10. O nome dos personagens desempenhados por cada atriz*/
SELECT COUNT(*) FROM Ator WHERE sexo='f'; /*11. o número de atrizes*/
SELECT SUM(orcamento) FROM Filme; /*12. a soma dos orçamentos dos filmes*/