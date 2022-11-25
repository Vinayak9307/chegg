from Animal import Animal

class Feline(Animal):
    
    def __init__(self,picture,food,hunger) -> None:
        super().__init__(picture,food,hunger)
        

    def roam(self):
        print(type(self).__name__+' class : roam() method')
