import turtle
bobo=turtle.Turtle()

def drawPolygon(t,length,numSides):
    angle=360/numSides
    for i in range(numSides):
        t.forward(length)
        t.right(angle)
drawPolygon(bobo,1,50)
