from abc import ABC, abstractmethod
#A biblioteca ABC é usada para definir uma classe abstrata
#Classe abstrata (interface genérica)
class Bakable(ABC):
    @abstractmethod
    def bake(self):
        pass

class Bread(Bakable):
    def bake(self):
        print("Baking bread")

class Cookie(Bakable):
    def bake(self):
        print("Baking cookie")

#Bread e Cookie dependem da interface abstrata Bakable!
def cook(bakable: Bakable):
    bakable.bake()

cookie = Cookie()
bread = Bread()
cook(cookie)
cook(bread)

