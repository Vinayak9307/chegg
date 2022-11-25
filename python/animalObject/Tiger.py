# Tiger.py

from Feline import Feline

class Tiger(Feline):
    
    def __init__(self,picture,food,hunger) -> None:
        super().__init__(picture,food,hunger)

    def makeNoise(self):
        print(type(self).__name__+' class : makeNoise() method' + ' Tiger makes roaring sound.')
    
    def eat(self):
        print(type(self).__name__+' class : eat() method' +  type(self).__name__ + ' eats '+self.food)
