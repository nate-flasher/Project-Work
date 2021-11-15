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
    print("Use arrow keys to move, s to see logical board, q to quit (focus must be on the screen)")
    #set up board parameters
    cols=15
    rows=15
    wn=turtle.Screen()
    bob=turtle.Turtle()
    wn.setworldcoordinates(0-(cols*.1),0-(rows*.1),cols+(cols*.1),rows+(rows*.1))
    bob.color("black","blue")
    bob.hideturtle()
    
    #set up logical board and draw graphical board
    row=[0]*cols
    board=[]
    for i in range(rows):
        board.append(row[:])
    drawBoard(wn,bob,cols,rows)
    
    #position the player randomly
    global myRow
    global myCol
    myRow=random.randint(0,rows-1)
    myCol=random.randint(0,cols-1)
    myMarker=1
    myColor="blue"
    drawMe(bob,myCol,myRow,myColor,myMarker,board)

    def drawBlackSquares(numSquares):
        for i in range(numSquares):
            myRow=random.randint(0,rows-1)
            myCol=random.randint(0,cols-1)
            myMarker=2
            myColor="black"
            drawMe(bob,myCol,myRow,myColor,myMarker,board)

        

    def fwd():
        global myRow
        if myRow<rows-1:
            if board[myRow+1][myCol]==2:
                firstWhiteRow=myRow+1
                while board[firstWhiteRow][myCol]!=0:
                    edge=False
                    if firstWhiteRow+1<rows:
                        firstWhiteRow+=1
                    else:
                        edge=True
                        break
                if edge==False:
                    drawMe(bob,myCol,myRow,"white",0,board)
                    drawMe(bob,myCol,myRow+1,myColor,myMarker,board)
                    myRow+=1 
                    drawMe(bob,myCol,firstWhiteRow,"black",2,board)
            else:
                drawMe(bob,myCol,myRow,"white",0,board)
                myRow+=1
                drawMe(bob,myCol,myRow,myColor,myMarker,board)
                
    def bkwd():
        global myRow
        if myRow>0:
            if board[myRow-1][myCol]==2:
                firstWhiteRow=myRow-1
                while board[firstWhiteRow][myCol]!=0:
                    edge=False
                    if firstWhiteRow-1>=0:
                        firstWhiteRow-=1
                    else:
                        edge=True
                        break
                if edge==False:
                    drawMe(bob,myCol,myRow,"white",0,board)
                    drawMe(bob,myCol,myRow-1,myColor,myMarker,board)
                    myRow-=1 
                    drawMe(bob,myCol,firstWhiteRow,"black",2,board)
            else:
                drawMe(bob,myCol,myRow,"white",0,board)
                myRow-=1
                drawMe(bob,myCol,myRow,myColor,myMarker,board)

    def lft():
        global myCol
        if myCol>0:
            if board[myRow][myCol-1]==2:
                firstWhiteCol=myCol-1
                while board[myRow][firstWhiteCol]!=0:
                    edge=False
                    if firstWhiteCol-1>=0:
                        firstWhiteCol-=1
                    else:
                        edge=True
                        break
                if edge==False:
                    drawMe(bob,myCol,myRow,"white",0,board)
                    drawMe(bob,myCol-1,myRow,myColor,myMarker,board)
                    myCol-=1 
                    drawMe(bob,firstWhiteCol,myRow,"black",2,board)
            else:
                drawMe(bob,myCol,myRow,"white",0,board)
                myCol-=1
                drawMe(bob,myCol,myRow,myColor,myMarker,board)

    def rght():
        global myCol
        global myRow
        if myCol<cols-1:
            if board[myRow][myCol+1]==2:
                firstWhiteCol=myCol+1
                while board[myRow][firstWhiteCol]!=0:
                    edge=False
                    if firstWhiteCol+1<cols:
                        firstWhiteCol+=1
                    else:
                        edge=True
                        break
                if edge==False:
                    drawMe(bob,myCol,myRow,"white",0,board)
                    drawMe(bob,myCol+1,myRow,myColor,myMarker,board)
                    myCol+=1 
                    drawMe(bob,firstWhiteCol,myRow,"black",2,board)
            else:
                drawMe(bob,myCol,myRow,"white",0,board)
                myCol+=1
                drawMe(bob,myCol,myRow,myColor,myMarker,board)

    def quitProg():
        wn.bye()

    def showBoard():
        for row in board[-1::-1]:
            print(row)
        print()


    drawBlackSquares(50)
        
    #Declare event handlers for keyboard events (i.e. what function to run for given keyboard event)
    wn.onkeypress(fwd,"Up")
    wn.onkeypress(bkwd,"Down")
    wn.onkeypress(lft,"Left")
    wn.onkeypress(rght,"Right")
    wn.onkeypress(showBoard,"s")
    wn.onkeypress(quitProg,"q")
    
    #Run turtle mainloop where it listens for events
    turtle.listen()
    turtle.mainloop()
    
main()
