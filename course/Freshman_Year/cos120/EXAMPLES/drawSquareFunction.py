import turtle
bob=turtle.Turtle()

def drawSquare(t,numSides,length):
    angle=360/numSides
    for i in range(numSides):
        t.forward(length)
        t.right(angle)

def main():
    bob=turtle.Turtle()
    bob.up()
    bob.goto(-50,250)
    bob.down()
    for sides in range(3,13):
        bob.clear()
        drawSquare(bob,sides,100)
        
main()
        
