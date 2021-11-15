import turtle

def drawSquare(t,color):
    t.fillcolor(color)
    t.begin_fill()
    for num in range(4):
        t.forward(1)
        t.right(90)
    t.end_fill()

def drawRow(t,color1,color2):
    for i in range(4):
        drawSquare(t,color1)
        t.forward(1)
        drawSquare(t,color2)
        t.forward(1)

def drawChecker(t,row,col,color):
    y=row-1
    x=col+.5
    t.color("grey",color)
    t.up()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    t.circle(.5)
    t.end_fill()
    #draw the concentric circles in the checker
    for i in range(1,5):
        t.color("grey")
        t.up()
        t.goto(x,y+(i*.1))
        t.down()
        t.circle(.5-(i*.1))

def drawBoard(bob):
    c1="gray"
    c2="red"
    for x in range(8):
        drawRow(bob,c1,c2)
        bob.up()
        bob.goto(0,x+1)
        bob.down()
        #switch c1 and c2 colors
        temp=c1
        c1=c2
        c2=temp
    drawLabels(bob)    

def drawLabels(t):
    offset=0
    t.color("white")
    for line in "ABCDEFGH":
        for cell in range(0,8,2):
            t.up()
            t.goto(offset+cell+.82,ord(line)-65+.02)
            t.down()
            t.write(line+str(cell+offset))
        if offset==0:
            offset=1
        else:
            offset=0
    t.color("black")

def printBoard(board):
    for row in range(8):
        for col in range(8):
            print("",board[row][col],end="")
        print()
    print()

def populateBoardWithCheckers(t,board):
    offset=0
    t.color("red")
    for row in range(0,3):
        for col  in range(0,8,2):
            drawChecker(t,row,col+offset,"red")
            board[row][col+offset]="r"
        if offset==0:
            offset=1
        else:
            offset=0
    t.color("black")
    for row in range(5,8):
        for col  in range(0,8,2):
            drawChecker(t,row,col+offset,"black")
            board[row][col+offset]="b"
        if offset==0:
            offset=1
        else:
            offset=0
            
def checkerboard():
    #Set up graphics for game
    wn=turtle.Screen()
    wn.setworldcoordinates(-2,9,10,-2)
    wn.tracer(False)
    bob=turtle.Turtle()
    bob.hideturtle()
    drawBoard(bob)
    #Set up logical board
    row=["e","e","e","e","e","e","e","e"]
    board=[]
    for i in range(8):
        board.append(row[:])
    #Draw one checker in upper left corner
    #drawChecker(bob,0,0)
    #board[0][0]="r"
    populateBoardWithCheckers(bob,board)
    printBoard(board) #OK - now the board contains a symbol representing the checker we drew
    wn.tracer(True) #Display all at once
    move=""
    player="b"
    color="black"
    while move != "quit":  #Until the user enters quit
        #Ask for a move
        move = input("Enter a From:To move (e.g. A0:B1) (Or enter 'quit') => ")
        FROM=move[0:2]
        TO=move[3:]
        letterToNum1=[ord(FROM[0])-65,FROM[1]]
        letterToNum2=[ord(TO[0])-65,TO[1]]
        if board[int(letterToNum2[0])][int(letterToNum2[1])]=="e" and board[int(letterToNum1[0])][int(letterToNum1[1])]==player:
            turtle.Screen().tracer(False)                                                               
            drawChecker(bob,int(letterToNum1[0]),int(letterToNum1[1]),"grey")
            drawChecker(bob,int(letterToNum2[0]),int(letterToNum2[1]),color)
            turtle.Screen().tracer(True)  
            board[int(letterToNum2[0])][int(letterToNum2[1])]=player
            board[int(letterToN
                      num1[0])][int(letterToNum1[1])]="e"
            printBoard(board)
        else:
            print("Invalid Mode")
        
        #If valid move
        if FROM in ["A0","A2","A4","A6","B1","B3","B5","B7","C0","C2","C4","C6","D1","D3","D5","D7","E0","E2","E4","E6","F1","F3","F5","F7","G0","G2","G4","G6","H1","H3","H5","H7"] and TO in ["A0","A2","A4","A6","B1","B3","B5","B7","C0","C2","C4","C6","D1","D3","D5","D7","E0","E2","E4","E6","F1","F3","F5","F7","G0","G2","G4","G6","H1","H3","H5","H7"]:  #also check right color and empty to
            wn.tracer(False) #Don't want to watch all of the individual graphical moves
            # drawSquare to undraw the FROM location
            # put an e in place of FROM in board
            # drawChecker in the TO location
            # put player in the TO location in board
            drawLabels(bob)
            wn.tracer(True) #Show all the changed graphics at once
            #switch players
            if player=="b":
                player="r"
                color="red"
            else:
                player="b"
                color="black"
        else:
            if move !="quit":
                print("Invalid move . . . Try again!")

        
checkerboard()
        
