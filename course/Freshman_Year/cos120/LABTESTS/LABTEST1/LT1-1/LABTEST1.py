#LT01-1
def countEachCharInOther(aString,aString1):
    for i in aString:
        print(i,aString1.count(i))

#LT01-2
def characterizeRun(low,high):
    total=0
    length=0
    for i in range(low,high+1):
        total=total+i
        length=length+1
    print("Length of run is",length)
    print("Sum of run is",total)
    print("Average of run is",(total/length))

#LT01-3
def everyOther(aString):
    myString = ""
    i = True  
    for char in aString:
        if i:
            myString+=char.lower()
        else:
            myString+=char.upper()
        if char != ' ':
            i = not i
    print(myString)
#LT01-4
def thisIsFunction(aString,aString1):
    index = 0
    while index < len(aString1):
        index = aString1.find(aString, index)
        if index == -1:
            break
        print(aString,"found at index", index)
        index=index+1
#LT01-5
def enterWordsSumASCII(maxNumWords,maxSumASCIIPerWord,maxTotalASCIISum):
    x=input("Say something")
    if x>maxNumWords:
        print("You met the maximun amount of words")
    if x=="quit":
        print("You entered quit")
    
#LT01-6
def thisIsFunction2(a,b):
    if a[-1] in b[1]:
        return False
    elif a[-1:] in b[:1]:
        return True
    elif a[-2:] in b[:2]:
         return True
    elif a[-3:] in b[:3]:
        return True
    elif a[-4:] in b[:4]:
        return True
    elif a[-5:] in b[:5]:
        return True
    elif a[-6:] in b[:6]:
        return True
    elif a[-7:] in b[:7]:
        return True
    else:
        return False

#LT01-7
def commandTurtle(t,cmdString):
    import turtle
    wn=turtle.Screen()
    bob=turtle.Turtle()
    
#LT01-8
def turtleStop():
    import turtle
    import random
    wn=turtle.Screen()
    bob=turtle.Turtle()
    sara=turtle.Turtle()
    rick=turtle.Turtle()

    bob.penup()
    bob.goto(-250,250)
    bob.pendown()
    bob.forward(500)
    for i in range(3):
        bob.right(90)
        bob.forward(500)
    bob.penup()
    bob.goto(0,0)
    bob.color("blue")
    sara.color("red")
    rick.color("orange")
    bob.pendown()
    moves=0
    while moves<10:
        bob.right(random.randint(0,359))
        bob.forward(random.randint(30,70))
        sara.right(random.randint(0,359))
        sara.forward(random.randint(30,70))
        rick.right(random.randint(0,359))
        rick.forward(random.randint(30,70))
        moves=moves+1
    
    
                   
            


def main():
    #countEachCharInOther("ohyeah","ohnoooooo")
    #characterizeRun(4,9)
    #everyOther("There was a cow in my home town that came to eat me")
    #thisIsFunction("aa","aaaaaaa")
    #enterWordsSumASCII(10,500,500)
    #print(thisIsFunction2("defg","defg"))
    #commandTurtle(bob,F50R90F50R)
    turtleStop()
    




main()
