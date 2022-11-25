
from Canine import Canine

class Wolf(Canine):
    
    def __init__(self,picture,food,hunger,name) -> None:
        super().__init__(picture,food,hunger)
    
    def makeNoise(self):
        print(type(self).__name__+' class : makeNoise() method' + ' Wolf makes howling sound.')
    
    def eat(self):
        print(type(self).__name__+' class : eat() method' +  type(self).__name__ + ' eats '+self.food)
