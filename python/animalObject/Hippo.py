# Hippo.py

from Animal import Animal

class Hippo(Animal):
    
    def __init__(self,picture,food,hunger) -> None:
        super().__init__(picture,food,hunger)
    
    def makeNoise(self):
        print(type(self).__name__+' class : makeNoise() method' + ' hippo makes honking sound.')
    
    def eat(self):
        print(type(self).__name__+' class : eat() method' +  type(self).__name__ + ' eats '+self.food)
