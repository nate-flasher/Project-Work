import turtle

def drawSquare(t,length,color):
    t.fillcolor(color)
    t.begin_fill()
    for num in range(4):
        t.forward(length)
        t.right(90)
    t.end_fill()

def blackRedRow(t,length):
    for i in range(4):
        drawSquare(t,length,"black")
        t.forward(length)
        drawSquare(t,length,"red")
        t.forward(length)

def redBlackRow(t,length):
    for i in range(4):
        drawSquare(t,length,"red")
        t.forward(length)
        drawSquare(t,length,"black")
        t.forward(length)

def checkerboard(length):
    bob=turtle.Turtle()
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

checkerboard(50)
        
