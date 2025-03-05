from invalid_square import InvalidSquareError
import math

class Square:
    def __init__(self, ul, dl, dr, ur):
        s1 = dr.distance(dl)
        s2 = dl.distance(ul)
        s3 = ul.distance(ur)
        s4 = ur.distance(dr)

        if not(s1 == s2 and s2 == s3 and s3 == s4):
            raise Exception

        self.ul = ul
        self.dl = dl
        self.dr = dr
        self.ur = ur
    
    def area(self):

        return (math.hypot(self.ul.x - self.dl.x, self.ul.y - self.dl.y) 
                * math.hypot(self.dr.x - self.dl.x, self.dr.y - self.dl.y))