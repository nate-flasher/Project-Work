/**
 * @file Human.cpp
 * @brief The Human class implementation file.
 * @author Stefan Brandle
 * @date March 2012
 * @author Jonathan Geisler
 * @date November 2019
 */

#include <cstdlib>
#include <iostream>

#include "Human.h"
#include "conio.h"

using namespace std;

/**
 * @brief The Human class constructor.
 * This function initializes the row, col, infected, and board variables.
 *
 * @param initLocation the initial human location (row & col)
 * @param theBoard a pointer to the board (used to ask board whether a
 *        proposed move is ok).
 */
Human::Human(const Location& initLocation, Board* theBoard)
    : Actor(initLocation, theBoard)
{
}

/**
 * @brief The Human class destructor.
 * The Human class destructor does nothing (so far), but is here as a
 * placeholder to remind you that it is a good idea for classes to have
 * destructors, even if you can't think of work for destructor at this
 * point.
 */
Human::~Human() {
    // Nothing to do
}

/**
 * @brief Have the human try to move.
 * To know whether it is ok to move to some location (l), ask the board
 * whether the position is ok. E.g., "if( board->tryMove(l) ) ..."
 * If the move is ok, then update the human's location to reflect the move.
 */


bool Human::isKilled() const {
    return killed;
}

void Human::setKilled() {
    killed = true;
}

void Human::move() {
    // Generate a +/- 2 row and column delta.
    if(isKilled()){
        
    }
    else{
    int rowDelta=random()%5-2, colDelta=random()%5-2;

    // Ask the board whether you
    Location tryLocation;
    tryLocation.row = location.row + rowDelta;
    tryLocation.col = location.col + colDelta;

        if(board->tryMove(tryLocation)) {
	        location = tryLocation;
        }
    }
}

void Human::interact(Actor *other) const {
    if (isInfected() && typeid(*other) == typeid(Human)) {
	other->setInfected(true);
    }
}

char Human::getCharacter() const {
    return '@';
}

string Human::getColor() const {
    if (infected) {
        return conio::bgColor(conio::RED);
    } else {
        return conio::bgColor(conio::LIGHT_GREEN);
    }
}
