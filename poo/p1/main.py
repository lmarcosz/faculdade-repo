from datetime import date
from usuario import User
from carro import Car
from aluguel import Aluguel

u1 = User('Marcos Lucas da Silva', 'marcos@lucas.br','luc432')
u2 = User('Liliana Sousa da Silva', 'liliana@sousa.br','lili256312442')
u3 = User('Jose Marcos da Silva', 'jose@silva.br','JoSe2042')

c1 = Car('Honda', 'Civic', '2010', '70.00')
c2 = Car('Honda', 'Fit', '2014', '47.50')
c3 = Car('Hyundai', 'HB20S', '2019', '63.30')
c4 = Car('Chevrolet', 'Onix', '2015', '56.00')
c5 = Car('Renault', 'Kwid', '2017', '49.85')

al1 = Aluguel(c3, '2022-11-07', '2022-11-07')
al2 = Aluguel(c2, '2022-11-07', '2023-01-15')
al3 = Aluguel(c5, '2022-11-07', '2023-03-08')

al1.alugar_carro()
al2.alugar_carro()
al3.alugar_carro()
