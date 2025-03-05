from datetime import date
from carro import Car
from usuario import User

class Aluguel:
    def __init__(self, carr, data1, data2):
        self.carr = carr
        self.data1 = data1
        self.data3 = data2

    def alugar_carro(self):
        d1 = date.fromisoformatformat(self.data1)
        d2 = date.fromisoformatformat(self.data2)
        dias = (d2 - d1).days

        valor_alu = dias * self.carr.valor_diaria
        valor_total = valor_alu + (valor_alu*0.15)

        print(f'Valor do aluguel: R${valor_alu} para {dias}.\nValor total com a taxa: R${valor_total}')
    