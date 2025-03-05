-- Consultas basicas
-- 1.Endereço das garagens junto com a origem e destino de suas linhas

SELECT gar.endereco_garagem, lin.origem, lin.destino
FROM garagem gar, linha lin
WHERE gar.idGaragem = lin.Garagem_idGaragem;

-- 2.Empresas que operam em Ubiratã junto com seu CNPJ

SELECT emp.nome, emp.CNPJ
FROM empresa emp
WHERE emp.Prefeitura_idPrefeitura = (SELECT idPrefeitura FROM prefeitura WHERE municipio = "ubiratã");

-- 3.Nome da categoria de cada usuário.

SELECT pes.nome_pessoa, cat.nome_categoria
FROM pessoa pes, categoria cat, usuario usr
WHERE pes.idPessoa = usr.Pessoa_idPessoa
AND usr.Categoria_idCategoria = cat.idCategoria;

-- 4.Origem e o destino de cada veículo.

SELECT vei.idVeiculo, lin.origem, lin.destino
FROM veiculo vei, linha lin
WHERE vei.Linha_idLinha = lin.idLinha;

-- 5.Nome e o CNPJ das empresas donas das garagens, bem como o endereço delas.

SELECT emp.nome, emp.CNPJ, gar.endereco_garagem
FROM empresa emp, garagem gar
WHERE emp.idEmpresa = gar.Empresa_idEmpresa;

-- LEFT JOIN
-- 1.Salários que cada CPF recebe

SELECT pes.CPF, fun.salario
FROM pessoa pes
LEFT JOIN funcionario fun
	ON pes.idPessoa = fun.Pessoa_idPessoa;
    
-- 2.Categoria de benefício, e seu horário para cada linha

SELECT linha.num_linha, categoria.horario_beneficio
FROM linha
LEFT JOIN categoria
	ON linha.num_linha = categoria.linhas_liberadas;
    
-- Consultas com operadores
-- 1.Capacidade máxima de passageiros em cada chassi.

SELECT chassi, ano, MAX(capac_pessoas_veiculo)
FROM veiculo
GROUP BY chassi;
 
-- 2.Capacidade mínima de passageiros sentados cada chassi.

SELECT chassi, ano, MIN(num_assentos)
FROM veiculo
GROUP BY chassi;

-- 3.Veículos por ordem de quilometragem.

SELECT quilometragem, tipo, marca, placa, ano, chassi
FROM veiculo
ORDER BY quilometragem DESC;

-- 4.Empresas onde a soma da capacidade total de veículos de suas garagens seja maior ou igual a 210.

SELECT empresa.nome AS 'empresa', Empresa_idEmpresa AS 'id_empresa', SUM(capac_veiculos) AS 'capacidade total de veículos'
FROM garagem, empresa
WHERE garagem.Empresa_idEmpresa = empresa.idEmpresa
GROUP BY Empresa_idEmpresa
HAVING SUM(capac_veiculos) > 210;

-- 5.Média salarial dos funcionários de todas as empresas.

SELECT AVG(salario)
FROM funcionario;
