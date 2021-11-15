/**
 * @file Actor.cpp
 * @brief The Actor class implementation file.
 * @author Jonathan Geisler
 * @date November 2019
 */

#include <cstdlib>
#include <iostream>

#include "Actor.h"
#include "conio.h"

using namespace std;

/**
 * @brief The Actor class constructor.
 * This function initializes the row, col, infected, and board variables.
 *
 * @param initLocation the initial actor location (row & col)
 * @param theBoard a pointer to the board (used to ask board whether a
 *            proposed move is ok).
 */
Actor::Actor(const Location& initLocation, Board* theBoard)
    : infected(false), location(initLocation), board(theBoard)
{
}

/**
 * @brief The Actor class destructor.
 * The Actor class destructor does nothing (so far), but is here as a
 * placeholder to remind you that it is a good idea for classes to have
 * destructors, even if you can't think of work for destructor at this
 * point.
 */
Actor::~Actor() {
    // Nothing to do
}


bool Actor::isKilled() const {
    return killed;

}

void Actor::setKilled() {
    killed = true;    

}


/**
 * @brief Get the actor's current row/col location.
 * Returns the actor's current row/column location
 */


Location Actor::getLocation() const {
    return location;
}

/**
 * @brief Sets this actor's infection state
 * Sets this actor object's infection state to the value passed in
 */
void Actor::setInfected(bool infect) {
    infected = infect;
}

/**
 * @brief reports whether this actor is infected.
 * @return whether this actor object is infected.
 */
bool Actor::isInfected() const {
    return infected;
}

void Actor::interact(Actor *other) const {
}

/**
 * @brief Draws the actor.
 * Draws the actor at the current location on the screen.
 * Remember that the first conio row=1, and first conio col=1.
 */
void Actor::draw() const {
    if(isKilled()){
    cout << conio::gotoRowCol(location.row+1,location.col+1);
    cout << conio::bgColor(conio::BLACK) << getCharacter() << conio::resetAll() << flush;
    }
    else{
    cout << conio::gotoRowCol(location.row+1,location.col+1);
    cout << getColor() << getCharacter() << conio::resetAll() << flush;
    }
}
