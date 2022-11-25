class Animal:
    def __init__(self,picture,food,hunger) -> None:
        self.picture = picture
        self.food = food
        self.hunger = hunger
        print(type(self).__name__+' class : __init__() method')

    
    def setPicture(self,picture):
        self.picture = picture
        print(type(self).__name__+' class : setPicture() method')


    def setFood(self,food):
        self.food = food
        print(type(self).__name__+' class : setFood() method')


    def setHunger(self,hunger):
        self.hunger = hunger
        print(type(self).__name__+' class : setHunger() method')


    def getPicture(self):
        print(type(self).__name__+' class : getPicture() method')
        return self.picture
        
    
    def getFood(self):
        print(type(self).__name__+' class : getFood() method')
        return self.food
    
    def getHunger(self):
        print(type(self).__name__+' class : getHunger() method')
        return self.hunger

    
    def makeNoise(self):
        print(type(self).__name__+' class : makeNoise() method')
    
    def eat(self):
        print(type(self).__name__+' class : eat() method')

    def sleep(self):
        print(type(self).__name__+' class : sleep() method')

    def roam(self):
        print(type(self).__name__+' class : roam() method')