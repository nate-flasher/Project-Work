/**
 * @brief myPlayerI for battleships
 * @file myPlayer.cpp
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004 Updated 2015 for multi-round play.
 *
 * This Battleships AI is very simple and does nothing beyond playing
 * a legal game. However, that makes it a good starting point for writing
 * a more sophisticated AI.
 *
 * The constructor
 */

#include <iostream>
#include <cstdio>

#include "myPlayer.h"


/**
 * @brief Constructor that initializes any inter-round data structures.
 * @param boardSize Indication of the size of the board that is in use.
 *
 * The constructor runs when the AI is instantiated (the object gets created)
 * and is responsible for initializing everything that needs to be initialized
 * before any of the rounds happen. The constructor does not get called 
 * before rounds; newRound() gets called before every round.
 */
myPlayer::myPlayer( int boardSize )
    :PlayerV2(boardSize)
{     
bool noProb=true;    // Could do any initialization of inter-round data structures here.
}

/**
 * @brief Destructor placeholder.
 * If your code does anything that requires cleanup when the object is
 * destroyed, do it here in the destructor.
 */
myPlayer::~myPlayer( ) {}

/*
 * Private internal function that initializes a MAX_BOARD_SIZE 2D array of char to water.
 */
void myPlayer::initializeBoard() {
    for(int row=0; row<boardSize; row++) {
	for(int col=0; col<boardSize; col++) {
	    this->board[row][col] = WATER;
	}
    }
}


/**
 * @brief Specifies the AI's shot choice and returns the information to the caller.
 * @return Message The most important parts of the returned message are 
 * the row and column values. 
 *
 * See the Message class documentation for more information on the 
 * Message constructor.
 */
Message myPlayer::getMove() {
    int shotRow = -1;
    int shotCol = -1;
    if(scanRow == -1 || board[scanRow][scanCol]!=HIT){
        getScanShot(scanRow, scanCol);
        shotRow = scanRow;
        shotCol = scanCol;
    }

    else{
        getFollowupShot(scanRow, scanCol, shotRow, shotCol);
    }

    Message result( SHOT, shotRow, shotCol, "Bang", None, 1 );
    return result;
}




void myPlayer::getScanShot(int& scanRow, int& scanCol) {
    int shot1Row = rand() % boardSize;
    int shot1Col = rand() % boardSize;
    int shot2Row = rand() % boardSize;
    int shot2Col = rand() % boardSize;
    while(board[shot1Row][shot1Col]!=WATER || board[shot2Row][shot2Col]!=WATER){
    shot1Row = rand() % boardSize;
    shot1Col = rand() % boardSize;
    shot2Row = rand() % boardSize;
    shot2Col = rand() % boardSize;
    }
    if(probability[shot1Row][shot1Col]>probability[shot2Row][shot2Col]){
        scanRow=shot1Row;
        scanCol=shot1Col;
    }
    else{
        scanRow=shot2Row;
        scanCol=shot2Col;
    }

}

void myPlayer::getFollowupShot(int scanRow, int scanCol, int& shotRow, int& shotCol) {
   // cout<<scanRow<<" "<<scanCol<<" "<<shotRow<<" "<<shotCol;
    if(scanRow-1>=0){
    for (int r = scanRow-1; r>=0; r--){
        
        
            if (board[r][scanCol]==MISS || board[r][scanCol] == KILL){
                break;
            }
            if (board[r][scanCol]==WATER){
                shotRow=r;
                shotCol=scanCol;
                cout<<shotRow;
                return;
            }
        
    }
    }
    if(scanRow+1<boardSize){
    for (int r = scanRow+1; r<boardSize; r++){
            if (board[r][scanCol]==MISS || board[r][scanCol] == KILL){
                break;
            }
            if (board[r][scanCol]==WATER){
                shotRow=r;
                shotCol=scanCol;
                return;
            }
    }
    }
    if(scanCol+1<boardSize){
    for (int c = scanCol+1; c<boardSize; c++){
            if (board[scanRow][c]==MISS || board[scanRow][c] == KILL){
                break;
            }
            if (board[scanRow][c]==WATER){
                shotRow=scanRow;
                shotCol=c;
                return;
            }
    }
    }
    if(scanCol-1>=0){
    for (int c = scanCol-1; c>=0; c--){
            if (board[scanRow][c]==MISS || board[scanRow][c] == KILL){
                break;
            }
            if (board[scanRow][c]==WATER){
                shotRow=scanRow;
                shotCol=c;
                return;
            }
    }
    }
}




/**
 * @brief Tells the AI that a new round is beginning.
 * The AI show reinitialize any intra-round data structures.
 */
void myPlayer::newRound() {
    /* myPlayers too simple to do any inter-round learning. Smarter players 
     * reinitialize any round-specific data structures here.
     */
    for(int i = 0; i<boardSize;i++){
        for(int g = 0; g<boardSize; g++){
            this->shipBoard[i][g]='~';
        }
    }
    if(noProb){
        for(int i = 0; i<boardSize; i++){
            for(int g = 0; g<boardSize; g++){
                if(i==0 && g==0||i==0 && g==9||i==9 && g==9||i==9 && g==0){
                    this->probability[i][g]=2;
                }
                if(i==0 && g==1||i==0 && g==8||i==1 && g==9||i==8 && g==9||i==9 && g==8||i==9 && g==1||i==8 && g==0||i==1 && g==0){
                    this->probability[i][g]=3;
                }
                if(i==0 && g>1 && g<8||i>1 && i<8 && g==9||i==9 && g>1 && g<8||i>1 && i<8 && g==0||i==1 && g==1||i==1 && g==8||i==8 && g==8||i==8 && g==1){
                    this->probability[i][g]=4;
                }
                if(i==1 && g>1 && g<8||i>1 && i<8 && g==8||i==8 && g>1 && g<8||i>2 && i<8 && g==1){
                    this->probability[i][g]=5;
                }
                if(i>1 && i<8 && g>1 && g<8){
                    this->probability[i][g]=6;
                }
            }
        }
        
    }

    this->scanRow = -1;
    this->scanCol = -1;
    this->numShipsPlaced = 0;

    this->initializeBoard();
}

/**
 * @brief Gets the AI's ship placement choice. This is then returned to the caller.
 * @param length The length of the ship to be placed.
 * @return Message The most important parts of the returned message are 
 * the direction, row, and column values. 
 *
 * The parameters returned via the message are:
 * 1. the operation: must be PLACE_SHIP 
 * 2. ship top row value
 * 3. ship top col value
 * 4. a string for the ship name
 * 5. direction Horizontal/Vertical (see defines.h)
 * 6. ship length (should match the length passed to placeShip)
 */


bool myPlayer::isLegal(int length,int row,int col, Direction dir) {
    for(int i=0;i<=length;i++){
        if(row<0 || row>=boardSize || col<0 || col>=boardSize){
            return false;
        }
        if(dir==Horizontal){
           if(shipBoard[row][col]=='S'){
                return false;
           }
        col++;
        }
        if(dir==Vertical){
            if(shipBoard[row][col]=='S'){
                return false;
            }
         row++;
        }
    }
}

void myPlayer::putShip(int length, int row, int col, Direction dir){
    for(int i = 0; i<=length; i++){
        if (dir == Horizontal){
            shipBoard[row][col]='S';
            col++;
        }
        if (dir == Vertical){
            shipBoard[row][col]='S';
            row++;
        }
    }
}

Message myPlayer::placeShip(int length) {
    char shipName[10];
    // Create ship names each time called: Ship0, Ship1, Ship2, ...
    snprintf(shipName, sizeof shipName, "Ship%d", numShipsPlaced);

    // parameters = mesg type (PLACE_SHIP), row, col, a string, direction (Horizontal/Vertical)
    numShipsPlaced++;


    while(true){
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        int direction = rand() % 2;
        Direction dir;
        if(direction == 0) {
            dir = Horizontal;
        }
        else{
            dir = Vertical;
        }
        
        if(isLegal(length,row, col, dir)){
            putShip(length, row, col, dir);          
            Message shipLoc(PLACE_SHIP, row, col, shipName, dir, length);
            return shipLoc;
        }
    }
}
/**
 * @brief Updates the AI with the results of its shots and where the opponent is shooting.
 * @param msg Message specifying what happened + row/col as appropriate.
 */
void myPlayer::update(Message msg) {
    switch(msg.getMessageType()) {
	case HIT:
	case KILL:
	case MISS:
	    board[msg.getRow()][msg.getCol()] = msg.getMessageType();
	    break;
	case WIN:
	    break;
	case LOSE:
	    break;
	case TIE:
	    break;
	case OPPONENT_SHOT:
	    // TODO: get rid of the cout, but replace in your AI with code that does something
	    // useful with the information about where the opponent is shooting.
	    //cout << gotoRowCol(20, 30) << "myPlayernent shot at "<< msg.getRow() << ", " << msg.getCol() << flush;
	    break;
    }
}

