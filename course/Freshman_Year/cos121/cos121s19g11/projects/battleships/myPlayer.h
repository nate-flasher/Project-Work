/**
 * @author Stefan Brandle, Jonathan Geisler
 * @date September, 2004
 *
 * Please type in your name[s] here:
 *
 */

#ifndef myPlayer_H		// Double inclusion protection
#define myPlayer_H

using namespace std;

#include "PlayerV2.h"
#include "Message.h"
#include "defines.h"

// myPlayer herits from/extends PlayerV2

class myPlayer: public PlayerV2 {
    public:
	myPlayer( int boardSize );
	~myPlayer();
	void newRound();
	Message placeShip(int length);
	Message getMove();
	void update(Message msg);
    bool isLegal(int length, int row, int col, Direction dir);
    void putShip(int length, int row, int col, Direction dir);
    void getScanShot(int& scanRow, int& scanCol);
    void getFollowupShot(int scanRow, int scanCol, int& shotRow, int& shotCol);
    private:
	void initializeBoard();
        int scanRow;
        int scanCol;
	int numShipsPlaced;
        char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
        char shipBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
        int probability[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
        bool noProb;
};

#endif
