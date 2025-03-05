#Marcos Lucas da Silva (140782)
#POO 2022/2 - Exercicio 1
# Arquivo de TESTE

from point import Point
from square import Square

def test_area():
    ul = Point(0,5)
    dl = Point(0,0)
    dr = Point(5,0)
    ur = Point(5,5)

    square = Square(ul, dl, dr, ur)
    a = square.area()
    assert a==25