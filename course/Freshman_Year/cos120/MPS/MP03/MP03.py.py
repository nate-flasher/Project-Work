import turtle
g=0
row=0
col=0
def drawSquare(t,length,color):
    t.fillcolor(color)
    t.begin_fill()
    for num in range(4):
        t.forward(length)
        t.right(90)
    t.end_fill()

def drawRow(t,length,color1,color2):
    for i in range(4):
        drawSquare(t,length,color1)
        t.forward(length)
        drawSquare(t,length,color2)
        t.forward(length)

def drawCircleFilled(t,size,color):
    t.fillcolor(color)
    t.begin_fill()
    t.circle(size*.5)
    t.end_fill()

def drawChecker(t,row,col,size):
    t.up()
    t.goto(0,0)
    t.down()
    y=(row-1)*size
    x=0+(col*size)+(.5*size)
    t.color("black","green")
    t.fillcolor("green")
    t.up()
    t.goto(x,y)
    t.down()
    drawCircleFilled(t,size,"green")
    t.up()
    t.goto(x,y+.1*size)
    t.down()
    t.circle(.8*size*.5)
    t.up()
    t.goto(x,y+.2*size)
    t.down()
    t.circle(.6*size*.5)
    t.up()
    t.goto(x,y+.3*size)
    t.down()
    t.circle(.4*size*.5)
    t.up()
    t.goto(x,y+.4*size)
    t.down()
    t.circle(.2*size*.5)

def drawLabels(t):
    col=0
    row=0
    increaseA=0
    increaseB=1
    letter=""
    for i in range(8):
        increaseA=0
        increaseB=1
        if row==0:
            letter="A"
        elif row==1:
            letter="B"
        elif row==2:
            letter="C"
        elif row==3:
            letter="D"
        elif row==4:
            letter="E"
        elif row==5:
            letter="F"
        elif row==6:
            letter="G"
        elif row==7:
            letter="H"
        for cell in range(col,8,2):
            t.up()
            if row%2==1:
                t.goto(cell+(1.83),row)
                t.down()
                t.write(letter+str(increaseB))
                increaseB=increaseB+2
            else:    
                t.goto(cell+.8,row)
                t.down()
                t.write(letter+str(increaseA))
                increaseA=increaseA+2
        row=row+1

def askChecker():
    userInput=input("Row? (e.g. A, B...) (type 'quit' to leave) ")
    if userInput=="A":
        userInput=0
    elif userInput=="B":
        userInput=1
    elif userInput=="C":
        userInput=2
    elif userInput=="D":
        userInput=3
    elif userInput=="E":
        userInput=4
    elif userInput=="F":
        userInput=5
    elif userInput=="G":
        userInput=6
    elif userInput=="H":
        userInput=7
    elif userInput =="quit":
        exit()
    else:
        print("Invalid Row")
    userInput2= int(input("Column Number? "))
##    if userInput2!=0 or userInput2!=1 or userInput2!=2 or userInput2!=3 or userInput2!=4 or userInput2!=5 or userInput2!=6 or userInput2!=7:
##        print("Invalid Column")
    return int(userInput),userInput2


def checkerboard(length):
    wn=turtle.Screen()
    wn.setworldcoordinates(-2,9,10,-2)
    wn.tracer(False)
    bob=turtle.Turtle()
    bob.hideturtle()    
    c1="gray"
    c2="red"
    for x in range(8):
        drawRow(bob,length,c1,c2)
        bob.up()
        bob.goto(0,x+1)
        bob.down()
        #switch c1 and c2 contents
        temp=c1
        c1=c2
        c2=temp
    drawLabels(bob)
    drawChecker(bob,row,col,length)
    wn.tracer(True)
        
while g==0:       
    checkerboard(1)
    row,col= askChecker()

        
