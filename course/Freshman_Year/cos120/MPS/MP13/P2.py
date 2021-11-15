import random
import copy


def listValidMoves(board,player):
    possibleMoves=[]
    validRange=[0,1,2,3,4,5,6,7] #list(range(8))
    if player=="b":
        playerTokens=["b","B"]
        moveRowInc=-1
    else:
        playerTokens=["r","R"]
        moveRowInc=1
    kingTokens=["B","R"]
    for row in range(8): #For every row
        for col in range(8):  #For every square in a row
            if board[row][col] in playerTokens: #If the board contains either a regular or king checker of the given player
                if board[row][col] not in kingTokens: #if checker is NOT a king
                    for colInc in [-1,1]: #for each diagonal square in the correct row direction
                        if row+moveRowInc in validRange and col+colInc in validRange and board[row+moveRowInc][col+colInc] =='e':
                            possibleMoves.append(chr(row+65)+str(col)+":"+chr(row+65+moveRowInc)+str(col+colInc))
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
                    for rowIncs in [-1,1]: #for each row direction (forward and backward)
                        for colInc in [-1,1]:
                            if row+rowIncs in validRange and col+colInc in validRange and board[row+rowIncs][col+colInc] in enemyTokens:                        
                                colJumpInc=2 * colInc
                                rowJumpInc=2 * rowIncs
                                if row+rowJumpInc in validRange and col + colJumpInc in validRange and board[row+rowJumpInc][col+colJumpInc]=="e":
                                    possibleSingleJumps.append(chr(row+65)+str(col)+":"+chr(row+65+rowJumpInc)+str(col+colJumpInc))
    return possibleSingleJumps

def listMultipleJumps(board,player,jumpsList):
    newJumps=expandJumps(board,player,jumpsList)
    while newJumps != jumpsList:
        jumpsList=newJumps[:]
        newJumps=expandJumps(board,player,jumpsList)
    return newJumps

def expandJumps(board,player,oldJumps):
    INCs=[1,-1]
    VALID_RANGE=[0,1,2,3,4,5,6,7]
    if player=="b":
        playerTokens=["b","B"]
        rowInc=-1
        opponentTokens=["r","R"]
    else:
        playerTokens=["r","R"]
        rowInc=1
        opponentTokens=["b","B"]
    newJumps=[]
    for oldJump in oldJumps:
        row=ord(oldJump[-2])-65
        col=int(oldJump[-1])
        newJumps.append(oldJump)
        startRow=ord(oldJump[0])-65
        startCol=int(oldJump[1])
        if board[startRow][startCol] not in ["R","B"]: #not a king
            for colInc in INCs:
                jumprow=row+rowInc
                jumpcol=col+colInc
                torow=row+2*rowInc
                tocol=col+2*colInc
                if jumprow in VALID_RANGE and jumpcol in VALID_RANGE and torow in VALID_RANGE and tocol in VALID_RANGE \
                and board[jumprow][jumpcol] in opponentTokens and board[torow][tocol]=='e':
                    newJumps.append(oldJump+":"+chr(torow+65)+str(tocol))
                    if oldJump in newJumps:
                        newJumps.remove(oldJump)
        else: #is a king
            for colInc in INCs:
                for newRowInc in INCs:
                    jumprow=row+newRowInc
                    jumpcol=col+colInc
                    torow=row+2*newRowInc
                    tocol=col+2*colInc
                    if jumprow in VALID_RANGE and jumpcol in VALID_RANGE and torow in VALID_RANGE and tocol in VALID_RANGE \
                    and board[jumprow][jumpcol] in opponentTokens and (board[torow][tocol]=='e' or oldJump[0:2]==chr(torow+65)+str(tocol)) \
                    and ((oldJump[-2:]+":"+chr(torow+65)+str(tocol)) not in oldJump) and ((chr(torow+65)+str(tocol)+':'+oldJump[-2:] not in oldJump)) and (chr(torow+65)+str(tocol)!=oldJump[-5:-3]):
                        newJumps.append(oldJump+":"+chr(torow+65)+str(tocol))
                        if oldJump in newJumps:
                            newJumps.remove(oldJump)
    return newJumps          

def findCrownRowMovesOrJumps(board,player,movesList):
    kingingList=[]
    for move in movesList:
        FROM=move[0:2]
        FROMRow=ord(FROM[0])-65
        FROMCol=int(FROM[1])
        TO=move[-2:]
        TORow=TO[0]
        if player=="r":
            kingRow="H"
        else:
            kingRow="A"
        if board[FROMRow][FROMCol]==player and TORow==kingRow:
            kingingList.append(move)
            movesList=movesList[:movesList.index(move)]+movesList[movesList.index(move)+1:]
    return kingingList

def findJumpBlockOpponent(playerJumps,opponentMoves):
    blockMovesList=[]
    for jump in playerJumps:
        for move in opponentMoves:
            if jump[-2:] in move:
                blockMovesList.append(jump)
    return blockMovesList


def getSafeMoves(movesList,opposingPlayer,board):
    safeList=[]
    for eachMove in movesList:
        myBoard=copy.deepcopy(board)
        FROM=eachMove[0:2]
        FROMRow=ord(FROM[0])-65
        FROMCol=int(FROM[1])
        TO=eachMove[3:5]
        TORow=ord(TO[0])-65
        TOCol=int(TO[1])
        myBoard[TORow][TOCol] = myBoard[FROMRow][FROMCol]
        myBoard[FROMRow][FROMCol] = "e"
        jumpsList=listSingleJumps(myBoard,opposingPlayer)
        jumpsList=listMultipleJumps(myBoard,opposingPlayer,jumpsList)
        for eachJump in jumpsList:
            FROMJump=eachJump[0:2]
            FROMJumpRow=ord(FROM[0])-65
            FROMJumpCol=int(FROM[1])
            TOJump=eachJump[3:5]
            TOJumpRow=ord(TO[0])-65
            TOJumpCol=int(TO[1])
            if not ((FROMJumpRow+TOJumpRow//2) == TORow and ((FROMJumpCol+TOJumpCol//2) == TOCol)):
                safeList.append(eachMove)

    return safeList

def getSafeJumps(movesList,opposingPlayer,board):
    safeList=[]
    for eachMove in movesList:
        myBoard=copy.deepcopy(board)
        FROM=eachMove[0:2]
        FROMRow=ord(FROM[0])-65
        FROMCol=int(FROM[1])
        TO=eachMove[-2:]
        TORow=ord(TO[0])-65
        TOCol=int(TO[1])
        myBoard[TORow][TOCol] = myBoard[FROMRow][FROMCol]
        myBoard[FROMRow][FROMCol] = "e"
        jumpsList=listSingleJumps(myBoard,opposingPlayer)
        jumpsList=listMultipleJumps(myBoard,opposingPlayer,jumpsList)
        for eachJump in jumpsList:
            FROMJump=eachJump[0:2]
            FROMJumpRow=ord(FROM[0])-65
            FROMJumpCol=int(FROM[1])
            TOJump=eachJump[-2:]
            TOJumpRow=ord(TO[0])-65
            TOJumpCol=int(TO[1])
            if not ((FROMJumpRow+TOJumpRow//2) == TORow and ((FROMJumpCol+TOJumpCol//2) == TOCol)):
                safeList.append(eachMove)
        
    return safeList

def maintainBackRow(movesList,jumpsList,board,player):
    newList=copy.deepcopy(movesList)
    if player == "r":
        homeRow=0
    else:
        homeRow=7
    for move in movesList:
        FROMRow=ord(move[0:1])-65
        FROMCol=int(move[1:2])
        TORow=ord(move[3:4])-65
        TOCol=int(move[4:5])
        if FROMRow==homeRow:
            newList.remove(move)
            return newList
    return newList

def maintainSecondToBackRow(movesList,jumpsList,board,player):
    newList=copy.deepcopy(movesList)
    if player == "r":
        homeRow=1
    else:
        homeRow=6
    for move in movesList:
        FROMRow=ord(move[0:1])-65
        FROMCol=int(move[1:2])
        TORow=ord(move[3:4])-65
        TOCol=int(move[4:5])
        if FROMRow==homeRow:
            newList.remove(move)
            return newList
    return newList

def maintainThirdToBackRow(movesList,jumpsList,board,player):
    newList=copy.deepcopy(movesList)
    if player == "r":
        homeRow=2
    else:
        homeRow=5
    for move in movesList:
        FROMRow=ord(move[0:1])-65
        FROMCol=int(move[1:2])
        TORow=ord(move[3:4])-65
        TOCol=int(move[4:5])
        if FROMRow==homeRow:
            newList.remove(move)
            return newList
    return newList
def throwOff(movesList,jumpsList,board,player):
    newList=copy.deepcopy(listValidMoves)
    aList=[]
    throwVariable=random.randint(0,29)
    if throwVariable==15:
        aList.append(newList[random.randint(0,len(listValidMoves)-1)])
        return aList
    return newList
        




def getValidMove(board,player):
    if player=="b":
        playerName="black"
        opponent="r"
    else:
        playerName="red"
        opponent="b"

    #Get player move options
    movesList=listValidMoves(board,player)
    jumpsList=listSingleJumps(board,player)
    jumpsList=listMultipleJumps(board,player,jumpsList)
    crowningJumps=findCrownRowMovesOrJumps(board,player,jumpsList)
    crowningMoves=findCrownRowMovesOrJumps(board,player,movesList)

    #Get opponent move options
    opponentMovesList=listValidMoves(board,opponent)
    opponentJumpsList=listSingleJumps(board,opponent)
    opponentJumpsList=listMultipleJumps(board,opponent,opponentJumpsList)
    opponentCrowningJumps=findCrownRowMovesOrJumps(board,opponent,opponentJumpsList)
    opponentCrowningMoves=findCrownRowMovesOrJumps(board,opponent,opponentMovesList)

    if crowningJumps !=[]: #Heuristic 3 (crowning jumps)
        return crowningJumps[random.randrange(0,len(crowningJumps))]
    if jumpsList != []: #Heuristic 1 (jumps)
        if opponentCrowningJumps !=[]: #Heuristic 5
            getSafeJumps(movesList,player,board) #Heuristic 9 (getSafeJumps)
            blocking = findJumpBlockOpponent(jumpsList,opponentCrowningJumps)
            if blocking != []:
                return blocking[random.randrange(0,len(blocking))]
        if opponentCrowningMoves != []: #Heuristic 6
            blocking = findJumpBlockOpponent(jumpsList,opponentCrowningMoves)
            if blocking != []:
                return blocking[random.randrange(0,len(blocking))]
        if opponentJumpsList != []: #Heuristic 7
            blocking = findJumpBlockOpponent(jumpsList,opponentJumpsList)
            if blocking != []:
                return blocking[random.randrange(0,len(blocking))]
        return jumpsList[random.randrange(0,len(jumpsList))] #OK, any old jump will do
    if crowningMoves != []: #Heuristic 4 (crowning move)
        safeKingMove=getSafeMoves(kingingList,player,board) #Heuristic 13 (It's getting safe moves for the king checkers now, and not normal checkers)
        return safeKingMove[random.randrange(0,len(safeKingMove))]
    else: #Heuristic 2 (moves)
        maintainBackRow(movesList,jumpsList,board,player) #Heuristic 10 (maintainBackRow)
        maintainSecondToBackRow(movesList,jumpsList,board,player) #Heuristic 11(maintainSecondToBackRow)
        maintainThirdToBackRow(movesList,jumpsList,board,player) #Heuristic 12(maintainThirdToBackRow)
        getSafeMoves(movesList,player,board) #Heuristic 8 (getSafeMoves)
        throwOff(movesList,jumpsList,board,player) #Heuristic #14 (throwOff) (Makes a moves without any heuristics attatched at all randomly)
        return movesList[random.randrange(0,len(movesList))]
