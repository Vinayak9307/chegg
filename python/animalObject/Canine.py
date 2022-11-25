# Canine.py

from Animal import Animal

class Canine(Animal):
    
    def __init__(self,picture,food,hunger) -> None:
        super().__init__(picture,food,hunger)

    def roam(self):
        print(type(self).__name__+' class : roam() method')
