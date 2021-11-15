import turtle

startColor="lightgreen"
otherColor="black"

def drawSquare(t,length,color):
    t.fillcolor(color)
    t.begin_fill()
    for num in range(4):
        t.forward(length)
        t.right(90)
    t.end_fill()

def blackRedRow(t,length):
    for i in range(4):
        drawSquare(t,length,startColor)
        t.forward(length)
        drawSquare(t,length,otherColor)
        t.forward(length)

def redBlackRow(t,length):
    for i in range(4):
        drawSquare(t,length,otherColor)
        t.forward(length)
        drawSquare(t,length,startColor)
        t.forward(length)

def checkerboard(length,bob):
    bob.speed(0)
    for x in range(4):
        blackRedRow(bob,length)
        bob.backward(8*length)
        bob.right(90)
        bob.forward(length)
        bob.left(90)
        redBlackRow(bob,length)
        bob.backward(8*length)
        bob.right(90)
        bob.forward(length)
        bob.left(90)

def drawChecker(row,col,size):
    x=0
    y=0
    bob.fillcolor("red")
    bob.begin_fill()
    if(row==0):
        x=25
    else:
        x=25+row*50
    y=-(50*col+50)
    bob.penup()
    bob.goto(x,y)
    bob.pendown()
    bob.circle(25)
    bob.end_fill()
    
    



bob=turtle.Turtle()
checkerboard(50,bob)
drawChecker(1,1,50)

        
