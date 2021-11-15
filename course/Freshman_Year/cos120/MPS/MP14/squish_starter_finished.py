import turtle
import random

def drawBoard(wn,t,cols,rows):
    wn.tracer(False)
    for row in range(rows+1):
        t.up()
        t.goto(0,row)
        t.down()
        t.goto(cols,row)
    for col in range(cols+1):
        t.up()
        t.goto(col,0)
        t.down()
        t.goto(col,rows)

def showBoard(board):
    for row in board[-1::-1]:
        print(row)
    print()
        
def drawMe(t,col,row,colr,marker,board):
    t.up()
    t.goto(col,row)
    t.down()
    t.color("black",colr)
    t.begin_fill()
    t.goto(col+1,row)
    t.goto(col+1,row+1)
    t.goto(col,row+1)
    t.goto(col,row)
    board[row][col]=marker
    t.end_fill()
    
def main():
    meMarker=1
    debug=False
    #Set up board
    cols=20
    rows=20
    wn=turtle.Screen()
    wn.setworldcoordinates(0-(cols*.1),0-(rows*.1),cols+(cols*.1),rows+(rows*.1))
    bob=turtle.Turtle()
    bob.hideturtle()
    drawBoard(wn,bob,cols,rows)
    row=[0]*cols
    board=[]
    for i in range(rows):
        board.append(row[:])
    bob.up()
    bob.ht()
    bob.color("black","blue")
    #Starting position
    global currentCol, currentRow
    currentCol=0
    currentRow=0
    drawMe(bob,currentCol,currentRow,"blue",1,board)
    def fwd():
        global currentRow
        if currentRow<=rows-2:
            drawMe(bob,currentCol,currentRow,"white",0,board)
            currentRow+=1
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
        #showBoard(board)
    def bkwd():
        global currentRow
        if currentRow>=1:
            drawMe(bob,currentCol,currentRow,"white",0,board)
            currentRow-=1
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
        else:
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
            currentRow=currentRow
    def lft():
        global currentCol
        if currentCol>=1:
            drawMe(bob,currentCol,currentRow,"white",0,board)
            currentCol-=1
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
    def rght():
        global currentCol
        if currentCol<=cols-2:
            drawMe(bob,currentCol,currentRow,"white",0,board)
            currentCol+=1
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
        else:
            drawMe(bob,currentCol,currentRow,"blue",meMarker,board)
            currentCol=currentCol
    #Declare event handlers for keyboard events
    wn.onkeypress(fwd,"Up")
    wn.onkeypress(bkwd,"Down")
    wn.onkeypress(lft,"Left")
    wn.onkeypress(rght,"Right")
    #Run turtle mainloop where it listens for events
    turtle.listen()
    turtle.mainloop()
    

main()
