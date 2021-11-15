/**
 * Declaration of the Human class.
 *
 * @author Stefan Brandle
 * @date March 2012
 */

#include "Board.h"

#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

/**
 * @class Human
 * @brief The Human class declaration.
 */
class Human {
    friend class Board;
    public:
        Human(int initRow, int initCol, bool initInfected, Board* thisBoard, bool chasing, bool followed, int followNum, int chaseNum);
	virtual ~Human();
	virtual void move();
	virtual void draw();

	// "Setters" and "getters"
	virtual void getLocation(int& row, int& col);
	virtual void setLocation(int row, int col);
	virtual void setInfected();
	virtual bool isInfected();
    virtual void startChasing();
    virtual void startBeingChased();
    virtual void stopChasing();
    virtual void stopBeingChased();
    protected:
        bool infected;     // Track whether or not this human is infected.
	int row, col;    // The row and column where this human is on the board.
    bool isChasing;   // Tracks whether an infected is chasing a human.
    bool isBeingChased;  // Tracks if an uninfected human is being chased.
    int followerValue, chaseValue; // Numbers to keep track of who is chasing who.
	Board *board;      // Pointer to the board so the human can ask the board whether
	                   // the human can move to a given location on the board.
};

#endif // HUMAN_H
