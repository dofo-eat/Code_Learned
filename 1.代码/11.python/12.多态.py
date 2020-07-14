#!/usr/bin/env python
# coding=utf-8

#多态

class animal(object):
    def __init__ (self, name):
        self.name = name

    def say(self):
        print("{} is an animal, i can say".format(self.name))
        
#子类

class  Cat(animal):
    def say(self):
        print("{} is a cat, say 'miao~'".format(self.name))

class Dog(animal):
    def say(self):
        print("{} is a dog, say 'wang~'".format(self.name))

#动物叫
def animal_say(animal):
    animal.say()

#传人animal实例

animal_say(animal('a'))

#串入DOG的实例
animal_say(Dog('b'))

#猫的实例
animal_say(Cat('c'))
