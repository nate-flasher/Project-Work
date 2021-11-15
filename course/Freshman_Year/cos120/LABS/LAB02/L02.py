def L02_0():
    for i in range (10,21):
        print(i)

def L02_1():
    for i in range (6):
        print(i)

def L02_2():
    for i in range (1,6):
        print(i)

def L02_3():
    for i in range (1,101):
        print(i)

def L02_4():
    for i in range (101,0,-1):
        print(i)

def L02_5():
    for i in range (3,34,3):
        print(i)

def L02_6():
    for i in range (33,2,-3):
        print(i)

def L02_7():
    total=0
    for num in range(1,11):
        total=total+num
    print(total)

def L02_8():
    total=1
    for i in range(1,11):
        total=total*i
    print(total)


def L02_9():
    for name in ["Mary","Joe","Adam"]:
        for i in range(1,4):
            print(i, name)
            
def L02_10():
    startNumber=int(input("Enter starting number"))
    endNumber=int(input("Enter ending number"))
    for name in ["Mary","Joe","Adam"]:
        for i in range(startNumber,endNumber+1):
            print(i, name)


def L02_11():
    for row in range(5):
        for col in range(5-row):
            print("*",end="")
        print()

def L02_12():
    for row in range(5):
        for col in range((row-4)+5):
            print("*",end="")
        print()

def L02_13():
    for i in range(1,4):
        for x in range(1,4):
            print(i,"x",x,"=",i*x)

def L02_14(m1start,m1stop,m2start,m2stop):
    for i in range(m1start,m1stop+1):
        for x in range(m2start,m2stop+1):
            print(i,"x",x,"=",i*x)

import turtle

def drawSquare(t,length):
    for num in range(4):
        t.forward(length)
        t.right(90)

def blackRedRow(t,length):
    for i in range(4):
        drawSquare(t,length)
        t.forward(length)
        drawSquare(t,length)
        t.forward(length)

def main():
    bob=turtle.Turtle()
    bob.speed(0)
    blackRedRow(bob,10)
    
    

main()
        
        
L02_0()
#L02_1()
#L02_2()
#L02_3()
#L02_4()
#L02_5()
#L02_6()
L02_7()
#L02_8()
#L02_9()
#L02_10()
#L02_11()
#L02_12()
#L02_13()
#L02_14(1,3,1,3)








