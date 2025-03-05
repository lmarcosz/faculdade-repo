-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 04-Fev-2022 às 00:11
-- Versão do servidor: 10.1.19-MariaDB
-- PHP Version: 5.6.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `trabalhofinalbd2021`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `categoria`
--

CREATE TABLE `categoria` (
  `idCategoria` int(11) NOT NULL,
  `nome_categoria` varchar(45) NOT NULL,
  `horario_beneficio` time NOT NULL,
  `valor_passagem` double NOT NULL,
  `linhas_liberadas` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `categoria`
--

INSERT INTO `categoria` (`idCategoria`, `nome_categoria`, `horario_beneficio`, `valor_passagem`, `linhas_liberadas`) VALUES
(1, 'CATEGORIA_01', '12:00:00', 5, 101),
(2, 'CATEGORIA_02', '14:00:00', 5, 102),
(3, 'CATEGORIA_03', '13:00:00', 2.5, 101),
(4, 'CATEGORIA_04', '19:00:00', 5, 104),
(5, 'CATEGORIA_05', '06:00:00', 2.5, 102),
(6, 'CATEGORIA_06', '12:00:00', 3, 103);

-- --------------------------------------------------------

--
-- Estrutura da tabela `empresa`
--

CREATE TABLE `empresa` (
  `idEmpresa` int(11) NOT NULL,
  `CNPJ` int(11) NOT NULL,
  `nome` varchar(45) NOT NULL,
  `endereco_empresa` varchar(45) NOT NULL,
  `telefone` int(11) NOT NULL,
  `email` varchar(45) NOT NULL,
  `Prefeitura_idPrefeitura` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `empresa`
--

INSERT INTO `empresa` (`idEmpresa`, `CNPJ`, `nome`, `endereco_empresa`, `telefone`, `email`, `Prefeitura_idPrefeitura`) VALUES
(1, 1, 'EMPRESA_01', 'ENDEREÇO_EMPRESA_01', 10101010, 'EMPRESA@01.COM', 1),
(2, 2, 'EMPRESA_02', 'ENDEREÇO_EMPRESA_0', 20202020, 'EMPRESA@02.COM', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `funcionario`
--

CREATE TABLE `funcionario` (
  `salario` double NOT NULL,
  `cargo` varchar(45) NOT NULL,
  `tempo_empresa` date NOT NULL,
  `horario_trabalho` time NOT NULL,
  `Pessoa_idPessoa` int(11) NOT NULL,
  `Empresa_idEmpresa` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `funcionario`
--

INSERT INTO `funcionario` (`salario`, `cargo`, `tempo_empresa`, `horario_trabalho`, `Pessoa_idPessoa`, `Empresa_idEmpresa`) VALUES
(1000.99, 'CARGO_01', '2022-02-01', '12:00:00', 1, 1),
(1200.99, 'CARGO_02', '2012-12-21', '11:00:00', 2, 1),
(2000.99, 'CARGO_03', '2021-01-01', '13:00:00', 3, 1),
(1000.99, 'CARGO_01', '2012-02-01', '12:00:00', 4, 1),
(1200.99, 'CARGO_02', '2019-02-01', '11:00:00', 5, 1),
(1000.99, 'CARGO_01', '2022-02-01', '12:00:00', 6, 2),
(1200.99, 'CARGO_02', '2012-12-21', '11:00:00', 7, 2),
(2000.99, 'CARGO_03', '2021-01-01', '13:00:00', 8, 2),
(1000.99, 'CARGO_01', '2012-02-01', '12:00:00', 9, 2),
(1200.99, 'CARGO_02', '2019-02-01', '11:00:00', 10, 2);

-- --------------------------------------------------------

--
-- Estrutura da tabela `garagem`
--

CREATE TABLE `garagem` (
  `idGaragem` int(11) NOT NULL,
  `endereco_garagem` varchar(45) NOT NULL,
  `capac_veiculos` int(11) NOT NULL,
  `Empresa_idEmpresa` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `garagem`
--

INSERT INTO `garagem` (`idGaragem`, `endereco_garagem`, `capac_veiculos`, `Empresa_idEmpresa`) VALUES
(1, 'ENDEREÇO_01', 101, 1),
(2, 'ENDEREÇO_02', 102, 1),
(3, 'ENDEREÇO_06', 111, 2),
(4, 'ENDEREÇO_07', 112, 2);

-- --------------------------------------------------------

--
-- Estrutura da tabela `linha`
--

CREATE TABLE `linha` (
  `idLinha` int(11) NOT NULL,
  `origem` varchar(45) NOT NULL,
  `destino` varchar(45) NOT NULL,
  `num_linha` int(11) NOT NULL,
  `Garagem_idGaragem` int(11) NOT NULL,
  `Terminal_idTerminal` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `linha`
--

INSERT INTO `linha` (`idLinha`, `origem`, `destino`, `num_linha`, `Garagem_idGaragem`, `Terminal_idTerminal`) VALUES
(1, 'ORIGEM_01', 'DESTINO_02', 101, 1, 1),
(2, 'ORIGEM_02', 'DESTINO_03', 102, 2, 2),
(3, 'ORIGEM_03', 'DESTINO_04', 103, 3, 3),
(4, 'ORIGEM_04', 'DESTINO_05', 104, 4, 2),
(5, 'ORIGEM_01', 'DESTINO_03', 105, 2, 2);

-- --------------------------------------------------------

--
-- Estrutura da tabela `pessoa`
--

CREATE TABLE `pessoa` (
  `idPessoa` int(11) NOT NULL,
  `nome_pessoa` varchar(45) NOT NULL,
  `CPF` int(11) NOT NULL,
  `data_nasc` date NOT NULL,
  `Prefeitura_idPrefeitura` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `pessoa`
--

INSERT INTO `pessoa` (`idPessoa`, `nome_pessoa`, `CPF`, `data_nasc`, `Prefeitura_idPrefeitura`) VALUES
(1, 'PESSOA_01', 1000000001, '2000-01-01', 1),
(2, 'PESSOA_02', 1000000002, '2000-01-02', 1),
(3, 'PESSOA_03', 1000000003, '2000-01-03', 1),
(4, 'PESSOA_04', 1000000004, '2000-01-03', 1),
(5, 'PESSOA_05', 1000000005, '2000-06-25', 1),
(6, 'PESSOA_06', 1000000006, '2000-04-13', 1),
(7, 'PESSOA_07', 1000000007, '2000-08-22', 1),
(8, 'PESSOA_08', 1000000008, '2000-11-05', 1),
(9, 'PESSOA_09', 1000000009, '2000-01-15', 1),
(10, 'PESSOA_10', 1000000010, '2001-12-17', 1),
(11, 'PESSOA_11', 1000000011, '2000-09-22', 1),
(12, 'PESSOA_12', 1000000012, '2000-11-03', 1),
(13, 'PESSOA_13', 1000000013, '2001-01-26', 1),
(14, 'PESSOA_14', 1000000014, '2000-11-23', 1),
(15, 'PESSOA_15', 1000000015, '2000-12-12', 1),
(16, 'PESSOA_16', 1000000016, '2002-05-03', 1),
(17, 'PESSOA_17', 1000000017, '2000-11-24', 1),
(18, 'PESSOA_18', 1000000018, '2001-03-24', 1),
(19, 'PESSOA_19', 1000000019, '2000-12-22', 1),
(20, 'PESSOA_20', 1000000020, '2000-04-27', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `prefeitura`
--

CREATE TABLE `prefeitura` (
  `idPrefeitura` int(11) NOT NULL,
  `municipio` varchar(45) NOT NULL,
  `UF` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `prefeitura`
--

INSERT INTO `prefeitura` (`idPrefeitura`, `municipio`, `UF`) VALUES
(1, 'Ubiratã ', 'RS');

-- --------------------------------------------------------

--
-- Estrutura da tabela `terminal`
--

CREATE TABLE `terminal` (
  `idTerminal` int(11) NOT NULL,
  `endereco_terminal` varchar(45) NOT NULL,
  `capac_pessoas_terminal` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `terminal`
--

INSERT INTO `terminal` (`idTerminal`, `endereco_terminal`, `capac_pessoas_terminal`) VALUES
(1, 'ENDEREÇO_01', 101),
(2, 'ENDEREÇO_02', 102),
(3, 'ENDEREÇO_03', 100),
(4, 'ENDEREÇO_04', 141),
(5, 'ENDEREÇO_05', 155);

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuario`
--

CREATE TABLE `usuario` (
  `saldo_cartao` double NOT NULL,
  `Categoria_idCategoria` int(11) NOT NULL,
  `Pessoa_idPessoa` int(11) NOT NULL,
  `Prefeitura_idPrefeitura` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `usuario`
--

INSERT INTO `usuario` (`saldo_cartao`, `Categoria_idCategoria`, `Pessoa_idPessoa`, `Prefeitura_idPrefeitura`) VALUES
(0, 1, 11, 1),
(10, 1, 12, 1),
(20, 2, 13, 1),
(10, 3, 14, 1),
(50, 4, 15, 1),
(25, 5, 16, 1),
(30, 6, 17, 1),
(40, 1, 18, 1),
(3, 3, 19, 1),
(100, 4, 20, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `veiculo`
--

CREATE TABLE `veiculo` (
  `idVeiculo` int(11) NOT NULL,
  `tipo` varchar(45) NOT NULL,
  `marca` varchar(45) NOT NULL,
  `placa` varchar(45) NOT NULL,
  `quilometragem` int(11) NOT NULL,
  `capac_pessoas_veiculo` int(11) NOT NULL,
  `num_assentos` int(11) NOT NULL,
  `ano` year(4) NOT NULL,
  `chassi` varchar(45) NOT NULL,
  `Linha_idLinha` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `veiculo`
--

INSERT INTO `veiculo` (`idVeiculo`, `tipo`, `marca`, `placa`, `quilometragem`, `capac_pessoas_veiculo`, `num_assentos`, `ano`, `chassi`, `Linha_idLinha`) VALUES
(1, 'TIPO_01', 'MARCA_01', 'ABC-001', 10, 45, 30, 2021, 'VOLVO', 4),
(2, 'TIPO_02', 'MARCA_01', 'ABC-002', 11, 45, 40, 2011, 'VOLVO', 1),
(3, 'TIPO_03', 'MARCA_02', 'ABC-003', 12, 50, 40, 2020, 'MERCEDES', 2),
(4, 'TIPO_01', 'MARCA_02', 'ABC-004', 13, 50, 40, 2019, 'MERCEDES', 2),
(5, 'TIPO_01', 'MARCA_01', 'ABC-005', 20, 60, 20, 2021, 'VOLVO', 3),
(6, 'TIPO_01', 'MARCA_02', 'ABC-006', 21, 45, 30, 2021, 'BMW', 3),
(7, 'TIPO_01', 'MARCA_02', 'ABC-007', 22, 50, 20, 2021, 'MARCOPOLO', 5),
(8, 'TIPO_01', 'MARCA_01', 'ABC-008', 23, 45, 30, 2021, 'BMW', 5);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `categoria`
--
ALTER TABLE `categoria`
  ADD PRIMARY KEY (`idCategoria`);

--
-- Indexes for table `empresa`
--
ALTER TABLE `empresa`
  ADD PRIMARY KEY (`idEmpresa`),
  ADD KEY `fk_Empresa_Prefeitura1_idx` (`Prefeitura_idPrefeitura`);

--
-- Indexes for table `funcionario`
--
ALTER TABLE `funcionario`
  ADD PRIMARY KEY (`Pessoa_idPessoa`),
  ADD KEY `fk_Funcionario_Empresa1_idx` (`Empresa_idEmpresa`);

--
-- Indexes for table `garagem`
--
ALTER TABLE `garagem`
  ADD PRIMARY KEY (`idGaragem`),
  ADD KEY `fk_Garagem_Empresa1_idx` (`Empresa_idEmpresa`);

--
-- Indexes for table `linha`
--
ALTER TABLE `linha`
  ADD PRIMARY KEY (`idLinha`),
  ADD KEY `fk_Linha_Garagem1_idx` (`Garagem_idGaragem`),
  ADD KEY `fk_Linha_Terminal1_idx` (`Terminal_idTerminal`);

--
-- Indexes for table `pessoa`
--
ALTER TABLE `pessoa`
  ADD PRIMARY KEY (`idPessoa`),
  ADD KEY `fk_Pessoa_Prefeitura1_idx` (`Prefeitura_idPrefeitura`);

--
-- Indexes for table `prefeitura`
--
ALTER TABLE `prefeitura`
  ADD PRIMARY KEY (`idPrefeitura`);

--
-- Indexes for table `terminal`
--
ALTER TABLE `terminal`
  ADD PRIMARY KEY (`idTerminal`);

--
-- Indexes for table `usuario`
--
ALTER TABLE `usuario`
  ADD PRIMARY KEY (`Pessoa_idPessoa`),
  ADD KEY `fk_Usuario_Categoria1_idx` (`Categoria_idCategoria`),
  ADD KEY `fk_Usuario_Prefeitura1_idx` (`Prefeitura_idPrefeitura`);

--
-- Indexes for table `veiculo`
--
ALTER TABLE `veiculo`
  ADD PRIMARY KEY (`idVeiculo`),
  ADD KEY `fk_Veiculo_Linha_idx` (`Linha_idLinha`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `categoria`
--
ALTER TABLE `categoria`
  MODIFY `idCategoria` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT for table `empresa`
--
ALTER TABLE `empresa`
  MODIFY `idEmpresa` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `garagem`
--
ALTER TABLE `garagem`
  MODIFY `idGaragem` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `linha`
--
ALTER TABLE `linha`
  MODIFY `idLinha` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `pessoa`
--
ALTER TABLE `pessoa`
  MODIFY `idPessoa` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
--
-- AUTO_INCREMENT for table `prefeitura`
--
ALTER TABLE `prefeitura`
  MODIFY `idPrefeitura` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `terminal`
--
ALTER TABLE `terminal`
  MODIFY `idTerminal` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `veiculo`
--
ALTER TABLE `veiculo`
  MODIFY `idVeiculo` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- Constraints for dumped tables
--

--
-- Limitadores para a tabela `empresa`
--
ALTER TABLE `empresa`
  ADD CONSTRAINT `fk_Empresa_Prefeitura1` FOREIGN KEY (`Prefeitura_idPrefeitura`) REFERENCES `prefeitura` (`idPrefeitura`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `funcionario`
--
ALTER TABLE `funcionario`
  ADD CONSTRAINT `fk_Funcionario_Empresa1` FOREIGN KEY (`Empresa_idEmpresa`) REFERENCES `empresa` (`idEmpresa`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_Funcionario_Pessoa1` FOREIGN KEY (`Pessoa_idPessoa`) REFERENCES `pessoa` (`idPessoa`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `garagem`
--
ALTER TABLE `garagem`
  ADD CONSTRAINT `fk_Garagem_Empresa1` FOREIGN KEY (`Empresa_idEmpresa`) REFERENCES `empresa` (`idEmpresa`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `linha`
--
ALTER TABLE `linha`
  ADD CONSTRAINT `fk_Linha_Garagem1` FOREIGN KEY (`Garagem_idGaragem`) REFERENCES `garagem` (`idGaragem`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_Linha_Terminal1` FOREIGN KEY (`Terminal_idTerminal`) REFERENCES `terminal` (`idTerminal`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `pessoa`
--
ALTER TABLE `pessoa`
  ADD CONSTRAINT `fk_Pessoa_Prefeitura1` FOREIGN KEY (`Prefeitura_idPrefeitura`) REFERENCES `prefeitura` (`idPrefeitura`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `usuario`
--
ALTER TABLE `usuario`
  ADD CONSTRAINT `fk_Usuario_Categoria1` FOREIGN KEY (`Categoria_idCategoria`) REFERENCES `categoria` (`idCategoria`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_Usuario_Pessoa1` FOREIGN KEY (`Pessoa_idPessoa`) REFERENCES `pessoa` (`idPessoa`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_Usuario_Prefeitura1` FOREIGN KEY (`Prefeitura_idPrefeitura`) REFERENCES `prefeitura` (`idPrefeitura`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Limitadores para a tabela `veiculo`
--
ALTER TABLE `veiculo`
  ADD CONSTRAINT `fk_Veiculo_Linha` FOREIGN KEY (`Linha_idLinha`) REFERENCES `linha` (`idLinha`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
