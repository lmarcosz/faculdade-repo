from point import Point
from square import Square
from invalid_square import InvalidSquareError
import pytest

def test_area():
    ul = Point(0,5)
    dl = Point(0,0)
    dr = Point(5,0)
    ur = Point(5,5)

    square = Square(ul, dl, dr, ur)
    a = square.area()
    assert a==25

def test_invalid_square():
    ul = Point(0,5)
    dl = Point(0,0)
    dr = Point(10,0)
    ur = Point(10,5)
    with pytest.raises(Exception):
        s1 = Square(ul, dl, dr, ur)