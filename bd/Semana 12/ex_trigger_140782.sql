/*Nome: Marcos Lucas da Silva (RA:140782)
Banco de Dados 2021/2 - Profª Daniela Leal Musa*/
CREATE DATABASE ex_trigger;

CREATE TABLE departamento(
	dnum int,
    nome varchar(10),
    TotalSal float,
    PRIMARY KEY(dnum)
);

CREATE TABLE empregado(
	id int,
    nome varchar(10),
    salario float,
    dnum int,
    PRIMARY KEY(id),
    FOREIGN KEY(dnum) REFERENCES departamento(dnum)
);

INSERT INTO departamento values (1, 'computação', 0);
INSERT INTO departamento values (2, 'matemática', 0);

/*Ex3*/
INSERT INTO empregado values (1, 'José', 3500, 1);
INSERT INTO empregado values (2, 'Marcela', 6500, 2);
INSERT INTO empregado values (3, 'Fernanda', 1000, 1);

CREATE TRIGGER tgr_totalsal_insert AFTER INSERT
ON empregado
FOR EACH ROW
UPDATE departamento SET TotalSal = TotalSal + NEW.salario
WHERE departamento.dnum = NEW.empregado.dnum;


/*Ex4*/
CREATE TRIGGER tgr_totalsal_update AFTER UPDATE
ON empregado
FOR EACH ROW
UPDATE departamento SET TotalSal = TotalSal - OLD.salario
WHERE dnum = OLD.dnum;
UPDATE departamento SET TotalSal = TotalSal + NEW.salario
WHERE dnum = new.dnum

/*Ex5*/
CREATE TABLE FolhaPagamento(
	id int auto_increment,
    salario float,
    codemp int,
    PRIMARY KEY (id)
    FOREIGN KEY (codemp) REFERENCES empregado(id)
);

DROP TRIGGER tgr_totalsal_insert;

CREATE TRIGGER tgr_folhapagamento_insert AFTER INSERT
ON empregado
FOR EACH ROW
INSERT INTO FolhaPagamento(salario, codemp) VALUES (1200, 1);