import math

a = 42

class Point: #Criando uma classe
    def __init__(self, x, y):
        self.move(x, y)
    
    def move(self, x, y):
        self.x = x
        self.y = y
    
    def reset(self):
        self.x = 0
        self.y = 0

    def calculate_distance(self, other):
        return math.hypot(self.x - other.x, self.y - other.y)