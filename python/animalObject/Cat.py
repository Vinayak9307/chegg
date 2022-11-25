# Cat.py

from Feline import Feline

class Cat(Feline):
    
    def __init__(self,picture,food,hunger,name) -> None:
        super().__init__(picture,food,hunger)
        self.name = name

    def makeNoise(self):
        print(type(self).__name__+' class : makeNoise() method' + ' Cat makes mewing sound.')
    
    def eat(self):
        print(type(self).__name__+' class : eat() method' +  self.name + ' eats '+self.food)
