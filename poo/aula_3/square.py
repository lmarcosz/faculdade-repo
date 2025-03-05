#Marcos Lucas da Silva (140782)
#POO 2022/2 - Exercicio 1
# Classe Square (quadrado)

import math

class Square:
    def __init__(self, ul, dl, dr, ur):
        self.ul = ul
        self.dl = dl
        self.dr = dr
        self.ur = ur
    
    def area(self):
        return (math.hypot(self.ul.x - self.dl.x, self.ul.y - self.dl.y) 
                * math.hypot(self.dr.x - self.dl.x, self.dr.y - self.dl.y))