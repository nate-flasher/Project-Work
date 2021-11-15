//----------------------------------------------------
// The "#ifndef ..." and "#define ..." lines are used to prevent the
// compiler from accidentally processing the contents of Board.h more than
// once, thus causing "Board redefined" errors.  At the end of the file is
// a "#endif" which marks the end of the "#ifndef" section.
//----------------------------------------------------
#ifndef BOARD_H
#define BOARD_H

/**
 * @file Board.h
 * @brief the Board class declaration file
 *
 * @author Stefan Brandle
 * @date March 2012
 * @author Jonathan Geisler
 * @date November 2019
 */

//----------------------------------------------------
// "forward" declaration of Board. Tell the compiler that this will be
// defined properly further "forward" in the program. This is needed because
// both classes reference each other. Otherwise, when include "Human.h" and
// the compiler finds a reference to Board, it will complain.
//----------------------------------------------------
class Board;

#include <vector>

#include "Actor.h"
#include "Location.h"

/**
 * @class Board
 * @brief The Board class declaration.
 */
class Board {
  public:
    Board(int numRows, int numCols, int numHumans);
    ~Board();

    void run();
    // Function that lets human know whether move is ok
    bool tryMove(const Location& location) const;

  private:
    void processInfection();  // Go through and process infection status
    bool allInfected() const; // Tells whether all humans are infected
    // Tells whether one human is next to another
    bool isNextTo(Actor* h1, Actor* h2) const;

    std::vector<Actor *> actors;
    int numHumans;            // Num humans
    int numInfected;          // Num humans infected
    int numRows;              // Number of rows in board
    int numCols;              // Number of cols in board
    int uSleepTime;           // Num microseconds to sleep between updates
};

#endif //#ifndef BOARD_H
