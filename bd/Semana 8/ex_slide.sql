CREATE DATABASE Marcos;
/*
Fornecedor (fcod,fone,status,cidade)
Peça(pcod,pnome,cor,peso,cidade)
Projeto (prcod,prnome,cidade)
Fornecimento (#fcod,#pcod,#prcod,quantidade)
*/
CREATE TABLE Fornecedor(
	fcod integer,
    fone integer,
    status integer,
    cidade varchar(30),
    PRIMARY KEY(fcod)
);

CREATE TABLE Peca(
	pcod integer not null,
    pnome varchar(30) not null,
    cor varchar(20) not null,
    peso float not null,
    cidade varchar(30) not null,
    PRIMARY KEY(pcod)
);

CREATE TABLE Projeto(
	prcod integer,
    prnome varchar(30),
    cidade varchar(30),
    PRIMARY KEY(prcod)
);

CREATE TABLE Fornecimento(
	fcod integer,
    pcod integer,
    prcod integer,
    quantidade integer,
    PRIMARY KEY(fcod, pcod, prcod),
    FOREIGN KEY (fcod) REFERENCES Fornecedor(fcod),
    FOREIGN KEY (pcod) REFERENCES Peca(pcod),
    FOREIGN KEY (prcod) REFERENCES Projeto(prcod) ON DELETE CASCADE
);

ALTER TABLE Projeto ADD horas time;
ALTER TABLE Peca DROP cidade;

DROP TABLE Projeto;
