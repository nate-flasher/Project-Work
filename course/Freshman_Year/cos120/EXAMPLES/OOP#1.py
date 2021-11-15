import math
class Planet:
    def   __init__(self, iname, iradius, imass, idistance): 
        self.name = iname
        self.radius = iradius
        self.mass = imass
        self.distance = idistance
        self.numMoons = 0
        self.moonList = []
        
    def addMoon(self, moonName):
        self.moonList.append(moonName)
        self.numMoons = len(self.moonList)

    def getName(self):
        return self.name

    def getRadius(self):
        return self.radius

    def getMass(self):
        return self.mass

    def getDistance(self):
        return self.distance
    
    def getNumberOfMoves(self):
        return self.numMoons
    
    def getCircumference(self):
        return 2*math.pi*self.radius

        
class Sentence:
    def __init__(self, isentence):
        self.sentence = isentence

    def getSentence(self):
        return self.sentence
    def getWords(self):
        wordList = self.sentence.split()
        return wordList
    def getLength(self):
        return len(self.sentence)
    def getnumWords(self):
        return len(self.getWords())
    def setCAPS(self):
        self.sentence = self.sentence.upper()
    def setPunctuation(self, punc):
        self.sentence = self.sentence+punc
        

class Sentence2:
    def __init__(self, isentence):
        self.sentence = isentence.split()

    def getSentence(self):
        s=""
        for word in self.sentence:
            s+=word+" "
        s=s[0:-1]
        return s
    def getWords(self):
        return self.sentence
    def getLength(self):
        return len(self.getSentence())
    def getNumWords(self):
        return len(self.sentence)

s1=Sentence("This is a sentence")
s2=Sentence2("This is a sentence")
print(s2.getSentence())
print(s2.getWords())
print(s2.getLength())
print(s2.getNumWords())
##print(s1.getSentence())
##print(s1.getWords())
##print(s1.getLength())
##print(s1.getnumWords())
