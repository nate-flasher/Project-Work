/**
 * @file Board.cpp
 * @brief Board class implementation (also called 'definition') file.
 * @author Stefan Brandle
 * @date March 2012
 * @author Jonathan Geisler
 * @date November 2019
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "Board.h"
#include "Human.h"
#include "Hospital.h"
#include "conio.h"
#include "killer.h"

using namespace std;

/**
 * @brief The Board class constructor, responsible for initializing a Board
 * object.  The Board constructor is responsible for initializing all the
 * Board object variables.
 *
 * @param rows The number of rows to make the board.
 * @param cols The number of columns to make the board.
 * @param numberOfHumans The number of humans to place on the board.
 */
Board::Board(int rows, int cols, int numberOfHumans)
    : numHumans(numberOfHumans), numInfected(0),
      numRows(rows), numCols(cols), uSleepTime(250000)
{
    // Creates 'Human' objects and sets the actors vector to point at them.
    for(int pos=0; pos<numHumans; ++pos) {

	int row = random()%numRows;  // row will be in range(0, numRows-1)
	int col = random()%numCols;  // col will be in range(0, numCols-1)
	// Create and initialize another Human with location on the board
	// and a pointer to this board object ('this').
	actors.push_back(new Human{Location{row, col}, this});
    }
    // Infect a random human in the range 0 to numHumans-1
    actors[random()%numHumans]->setInfected(true);

    // add a hospital in the middle of the board
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
    actors.push_back(new Killer{Location{numRows/2, numCols/2}, this});
}

/**
 * @brief The Board class destructor.
 * The Board destructor is responsible for any last-minute cleaning
 * up that a Board object needs to do before being destroyed. In this case,
 * it needs to return all the memory borrowed for creating the Human
 * objects.
 */
Board::~Board() {
    for (auto actor : actors) {
	delete actor;
    }
}

/**
 * @brief function that runs the simulation
 * runs simulation until all humans are infected.
 */
void Board::run() {
    for(int currentTime=0; allInfected() == false; ++currentTime) {
	// Clear screen before every new time unit
	cout << conio::clrscr() << flush;

	for (auto actor : actors) {
	    actor->move();
	}

	// Deal with infection propagation.
	processInfection();

	for (auto actor : actors) {
	    actor->draw();
	}

	// Print statistics.
	cout << conio::gotoRowCol(numRows+3, 1)
	     << "Time=" << currentTime
	     << " Total humans=" << numHumans
	     << " Total infected=" << numInfected << flush;

	// Sleep specified microseconds
	usleep(uSleepTime);
    }

    // Position the cursor so prompt shows up on its own line
    cout << "\n";
}

/**
 * @brief Determines whether or not all humans are infected.
 * @return If even one human is uninfected, returns false. Otherwise,
 *         returns true.
 */
bool Board::allInfected() const {
    return numInfected == numHumans;
}

/**
 * @brief The function that handles one infection cycle to determine what
 * new infections are present.
 * For each pair of adjacent humans in the simulation, processInfection()
 * makes sure that if one is infected, the other becomes infected as well.
 */
void Board::processInfection() {
    for (auto actor : actors) {
	for (auto actor2 : actors) {
	    if (isNextTo(actor, actor2)) {
		actor->interact(actor2);
	    }
	}
    }

    // Reset the board 'numInfected' count and recount how many are
    // infected.  We have to do this after the other loops because one
    // actor could be changed by another actor in the simulation.
    numInfected = 0;
    for (auto actor : actors) {
	if (actor->isInfected()) {
	    ++numInfected;
	}
    }

}

/**
 * @brief The function that determines whether a particular move can happen.
 *        If the move would go off the board, or land on the same position
 *        as another human, the function returns false (do not move).
 *        Otherwise, it returns true (ok to proceed).
 * @param[in] row the row the human wishes to move to.
 * @param[in] col the col the human wishes to move to.
 * @return Whether the human calling this function may move to the
 *         specified row and column.
 */
bool Board::tryMove(const Location& location) const {
    // If off board, the move is not permitted
    if(   location.row<0 || location.row>=numRows
       || location.col<0 || location.col>=numCols)
    {
	return false;
    }

    // if another human is on the same location, the move is not permitted
    for (auto actor : actors) {
	if(location == actor->getLocation() && !actor->isKilled()  ) {
	    return false;
	}
    }

    // No problems, so the move is permitted
    return true;
}

/**
 * @brief The function that determines whether two humans are on adjacent
 *        squares.
 * @param h1 pointer to first human object.
 * @param h2 pointer to second human object.
 * @return Whether or not h1 and h2 are on adjacent squares.
 */
bool Board::isNextTo(Actor *h1, Actor* h2) const {
    // Get human location information
    Location h1Location = h1->getLocation();
    Location h2Location = h2->getLocation();

    // Return whether h1 and h2 are on adjacent squares in any direction
    // (horizontally, vertically, diagonally).
    return    abs(h1Location.row - h2Location.row) <= 1
	   && abs(h1Location.col - h2Location.col) <= 1;
}
