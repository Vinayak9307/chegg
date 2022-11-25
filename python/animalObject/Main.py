from Animal import Animal
from Feline import Feline
from Canine import Canine
from Hippo import Hippo
from Lion import Lion
from Cat import Cat
from Tiger import Tiger
from Wolf import Wolf
from Dog import Dog

def main():

    animal = Animal('Animals picture','Food','1kg of food per day')
    animal.makeNoise()
    animal.eat()
    animal.sleep()
    animal.roam()

    print()

    feline = Feline('Feline picture','meat','1kg of meat per day')
    feline.makeNoise()
    feline.eat()
    feline.sleep()
    feline.roam()

    print()

    canine = Canine('Canine picture','meat','1kg of meat per day')
    canine.makeNoise()
    canine.eat()
    canine.sleep()
    canine.roam()
    
    print()

    hippo = Hippo('Hippo picture','grass','40kg of grass per day')
    hippo.makeNoise()
    hippo.eat()
    hippo.sleep()
    hippo.roam()

    print()

    lion = Lion('Lion picture','meat','5kg of meat per day')
    lion.makeNoise()
    lion.eat()
    lion.sleep()
    lion.roam()
    
    print()

    tiger = Tiger('Tiger picture','meat','5kg of meat per day')
    tiger.makeNoise()
    tiger.eat()
    tiger.sleep()
    tiger.roam()
    
    print()

    cat = Cat('Cat picture','cat food','500g of cat food per day','SnowBell')
    cat.makeNoise()
    cat.eat()
    cat.sleep()
    cat.roam()

    print()

    dog = Dog('Dog picture','dog food','1kg of dog food per day','Rufus')
    dog.makeNoise()
    dog.eat()
    dog.sleep()
    dog.roam()

    print()

    wolf = Wolf('Wolf picture','meat','3kg of meat per day','Rufus')
    wolf.makeNoise()
    wolf.eat()
    wolf.sleep()
    wolf.roam()


main()