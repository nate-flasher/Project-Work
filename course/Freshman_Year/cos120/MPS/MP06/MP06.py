import turtle

def drawSquare(t,color):
    t.color("black")
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

def drawChecker(t,row,col,color,kingFlag):
    y=row-1
    x=col+.5
    t.color("dimgray",color)
    t.up()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    t.circle(.5)
    t.end_fill()
    #draw the concentric circles in the checker
    for i in range(1,5):
        t.up()
        t.goto(x,y+(i*.1))
        t.down()
        if i==4 and kingFlag:
            t.begin_fill()
            t.color("yellow")
        t.circle(.5-(i*.1))
        if i==4 and kingFlag:
            t.end_fill()
            t.color("dimgray")

    if kingFlag:
        #draw a star
        pass

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

def drawLabel(t,row,col):
    t.color("white")
    t.up()
    t.goto(col+.82,row+.02)
    t.down()
    t.write(chr(row+65)+str(col))
    t.color("black")

def printBoard(board):
    for row in range(8):
        for col in range(8):
            print("",board[row][col],end="")
        print()
    print()

def populateBoardsWithCheckers(t,board):
##    offset=0
##    t.color("red")
##    for row in range(0,3):
##        for col  in range(0,8,2):
##            drawChecker(t,row,col+offset,"red",False)
##            board[row][col+offset]="r"
##        if offset==0:
##            offset=1
##        else:
##            offset=0
##    offset=1
##    t.color("black")
##    for row in range(5,8):
##        for col in range(0,8,2):
##            drawChecker(t,row,col+offset,"black",False)
##            board[row][col+offset]="b"
##        if offset==1:
##            offset=0
##        else:
##            offset=1
    drawChecker(t,4,4,"black",True)
    board[4][4]="B"
    drawChecker(t,6,0,"red",False)
    board[6][0]="r"


def listValidMoves(board,player):
    possibleMoves=[]
    validRange=[0,1,2,3,4,5,6,7] #list(range(8))
    if player=="b":
        playerTokens=["b","B"]
        rowInc=-1
    else:
        playerTokens=["r","R"]
        rowInc=1
    kingTokens=["B","R"]
    for row in range(8): #For every row
        for col in range(8):  #For every square in a row
            if board[row][col] in playerTokens: #If the board contains either a regular or king checker of the given player
                if board[row][col] not in kingTokens: #if checker is NOT a king
                    for colInc in [-1,1]: #for each diagonal square in the correct row direction
                        if row+rowInc in validRange and col+colInc in validRange and board[row+rowInc][col+colInc] =='e':
                            possibleMoves.append(chr(row+65)+str(col)+":"+chr(row+65+rowInc)+str(col+colInc))
                else:  #checker is a king
                    for rowInc in [-1,1]: #for each row direction (forward and backward)
                        for colInc in [-1,1]: #for each diagonal square in each row direction
                            if row+rowInc in validRange and col+colInc in validRange and board[row+rowInc][col+colInc] =='e':
                                possibleMoves.append(chr(row+65)+str(col)+":"+chr(row+65+rowInc)+str(col+colInc))                                      
    return possibleMoves

def listSingleJumps(board,player):
    possibleSingleJumps=[]
    validRange=[0,1,2,3,4,5,6,7] #list(range(8))
    if player=="b":
        playerTokens=["b","B"]
        rowInc=-1
        enemyTokens=["r","R"]
    else:
        playerTokens=["r","R"]
        rowInc=1
        enemyTokens=["b","B"]
    kingTokens=["B","R"]
    for row in range(8):
        for col in range(8):
            if board[row][col] in playerTokens:
                if board[row][col] not in kingTokens:  #if checker is NOT a king
                    for colInc in [-1,1]:
                        if row+rowInc in validRange and col+colInc in validRange and board[row+rowInc][col+colInc] in enemyTokens:                        
                            colJumpInc=2 * colInc
                            rowJumpInc=2 * rowInc
                            if row+rowJumpInc in validRange and col + colJumpInc in validRange and board[row+rowJumpInc][col+colJumpInc]=="e":
                                possibleSingleJumps.append(chr(row+65)+str(col)+":"+chr(row+65+rowJumpInc)+str(col+colJumpInc))
                else: #checker is a king
                    for rowInc in [-1,1]: #for each row direction (forward and backward)
                        for colInc in [-1,1]:
                            if row+rowInc in validRange and col+colInc in validRange and board[row+rowInc][col+colInc] in enemyTokens:                        
                                colJumpInc=2 * colInc
                                rowJumpInc=2 * rowInc
                                if row+rowJumpInc in validRange and col + colJumpInc in validRange and board[row+rowJumpInc][col+colJumpInc]=="e":
                                    possibleSingleJumps.append(chr(row+65)+str(col)+":"+chr(row+65+rowJumpInc)+str(col+colJumpInc))
    return possibleSingleJumps

def getValidMove(board,player):
    if player=="b":
        playerName="black"
    else:
        playerName="red"
    movesList=listValidMoves(board,player)
    singleJumpsList=listSingleJumps(board,player)
    print(listValidMoves(board,player))
    print(listSingleJumps(board,player))
    while True:
        move=input("Player "+playerName+" enter a move.  If there is a jump, you must take it => ")
        move=move.upper()
        if move.lower()=="quit":
            return move
        if singleJumpsList!=[]:
            if move in singleJumpsList:
                return move
            else:
                print("You must specify a valid jump!")
        else:
            if move in movesList:
                return move
            else:
                print("You must specify a valid move!")
                
def swapPlayer(player):
    if player=="b":
        player="r"
        playerColor="red"
    else:
        player="b"
        playerColor="black"
    return player,playerColor

def setupGame():
    #Set up graphics for game
    wn=turtle.Screen()
    wn.setworldcoordinates(-2,9,10,-2)
    bob=turtle.Turtle()
    bob.hideturtle()
    wn.tracer(False)
    drawBoard(bob)
    #Set up logical and graphical checkers
    row=["e","e","e","e","e","e","e","e"]
    board=[]
    for i in range(8):
        board.append(row[:])
    populateBoardsWithCheckers(bob,board)
    printBoard(board)
    wn.tracer(True)
    return wn,bob,board
    
def parseMove(move):
    FROM=move[:2]
    FROMRow=ord(FROM[0])-65
    FROMCol=int(FROM[1])
    TO=move[3:]
    TORow=ord(TO[0])-65
    TOCol=int(TO[1])
    return FROMRow,FROMCol,TORow,TOCol

def removeCheckerGraphicalAndLogical(bob,FROMCol,FROMRow,board):
    bob.up()
    bob.goto(FROMCol,FROMRow)
    bob.down()
    drawSquare(bob,"gray")
    drawLabel(bob,FROMRow,FROMCol)
    playerBoardToken=board[FROMRow][FROMCol] #could be "b" or "B" or "r" or "R"
    board[FROMRow][FROMCol]='e'
    return playerBoardToken

def placeCheckerGraphicalAndLogical(bob,TOCol,TORow,board,playerToken):
    if playerToken == "r" and TORow==7:
        board[TORow][TOCol]=playerToken.upper()
    elif playerToken == "b" and TORow==0:
        board[TORow][TOCol]=playerToken.upper()
    else:
        board[TORow][TOCol]=playerToken
    if board[TORow][TOCol] =="b":
        drawChecker(bob,TORow,TOCol,"black",False)
    elif board[TORow][TOCol] =="B":
        drawChecker(bob,TORow,TOCol,"black",True)
    elif board[TORow][TOCol] =="r":
        drawChecker(bob,TORow,TOCol,"red",False)
    else:
        drawChecker(bob,TORow,TOCol,"red",True)

def win(board):
    rmove=listValidMoves(board,"r")
    rjump=listSingleJumps(board,"r")
    bmove=listValidMoves(board,"b")
    bjump=listSingleJumps(board,"b")
    if len(rmove)==0 and len(rjump)==0:
        return [True,"black"]
    if len(bmove)==0 and len(bjump)==0:
        return [True,"red"]
    return [False,""]
    
def checkersMain():
    wn,bob,board=setupGame() 
    player="b"
    playerColor="black"
    gameOver=False
    move = getValidMove(board,player) #get the first move
    while move.lower() != "quit" and not gameOver:   #Start black and red alternate play
        wn.tracer(False)
        FROMRow,FROMCol,TORow,TOCol=parseMove(move) #parse move into locations
        if abs(FROMRow-TORow)==1: #move, not a jump
            playerToken=board[FROMRow][FROMCol] #save the player form current location (regular checker or king)
            removeCheckerGraphicalAndLogical(bob,FROMCol,FROMRow,board) #remove the checker to be moved
            placeCheckerGraphicalAndLogical(bob,TOCol,TORow,board,playerToken) #place the moved checker in its new location
        else: #jump, not a move
            playerToken=board[FROMRow][FROMCol] #save the player form current location (regular checker or king)
            removeCheckerGraphicalAndLogical(bob,FROMCol,FROMRow,board) #remove the checker to be moved
            removeCheckerGraphicalAndLogical(bob,(FROMCol+TOCol)//2,(FROMRow+TORow)//2,board) #remove the jumped checker
            placeCheckerGraphicalAndLogical(bob,TOCol,TORow,board,playerToken) #place the jumping checker in its new location
        wn.tracer(True)
        printBoard(board)
        player,playerColor=swapPlayer(player)
        gameOver,winningPlayer=win(board)
        if not gameOver:
            move = getValidMove(board,player)
    print("Game over, man!!!")
    if move.lower() != "quit":
        print(winningPlayer +" won the game in a smashing victory!")

checkersMain()
        
