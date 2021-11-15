/**
 * @file Human.cpp
 * @brief The Human class implementation file.
 *
 * -- Enter the correct information below, then remove this line.
 * @author Ryan Costello
 * @author Wyatt Deno
 * @author Nate Flasher
 * @date May 4 2019
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
 * @param initRow the initial human row location.
 * @param initCol the initial human column location.
 * @param initInfected whether the human is initially infected.
 * @param theBoard a pointer to the board (used to ask board whether a proposed move is ok).
 */
Human::Human(int initRow, int initCol, bool initInfected, Board* theBoard, bool chasing, bool followed, int followNum, int chaseNum) {
    row = initRow;
    col = initCol;
    infected = initInfected;
    board = theBoard;
    isChasing = chasing;
    isBeingChased = followed;
    followerValue = followNum;
    chaseValue = chaseNum;
}

/**
  werValue
 * @brief The Human class destructor.
 * The Human class destructor does nothing (so far), but is here as a placeholder to remind
 * you that it is a good idea for classes to have destructors, even if you can't think of 
 * work for destructor at this point.
 */
Human::~Human() {
    // Nothing to do
}

/**
 * @brief Have the human try to move.
 * To know whether it is ok to move to some position (r,c), ask the board
 * whether the position is ok. E.g., "if( board->tryMove(r,c) ) ..."
 * If the move is ok, then update the human's row and column to reflect the move.
 */

void Human::startChasing() {
    isChasing = true;

}

void Human::startBeingChased() {
    isBeingChased = true;

}

void Human::stopChasing() {
    isChasing = false;
    chaseValue=-1;
}

void Human::stopBeingChased(){
    isBeingChased = false;
    followerValue=-1;
}

void Human::move() {
   int rowDelta=0, colDelta=0;
    if(isBeingChased){
        //if a human is being chased, they will run away from the infected that is chasing them.
        if(row < board->humans[followerValue]->row){
            rowDelta=-1, colDelta=0;
        }
        else if(row > board->humans[followerValue]->row){
            rowDelta=1, colDelta=0;
        }
        else if(col < board->humans[followerValue]->col){
            rowDelta=0, colDelta=-1;
        }
        else if(col > board->humans[followerValue]->col){
            rowDelta=0, colDelta=1;
        }        
   }
   if(! isBeingChased){
    // Generate a +/- 2 row and column delta.
    rowDelta=rand()%5-2, colDelta=rand()%5-2;
   }
   // check to see if this human is infected
   if (isInfected()) {
       // check to see if they are currently not chasing anyone
       if(! isChasing){
           // check all humans to see if there are any within a 3 "space" radius
           for(int pos=0; pos<board->numHumans; ++pos){
               if(board->humans[pos]->isInfected()==false && abs(row-board->humans[pos]->row)<=4 && 
                  abs(col-board->humans[pos]->col)<=4)
               {
                    // if so, start chasing them, and set that uninfected human to being chased
                    startChasing();
                    chaseValue=pos;
                    board->humans[pos]->startBeingChased();
                    for(int pos1=0; pos1<board->numHumans; ++pos1){
                        if(row==board->humans[pos1]->row && col==board->humans[pos1]->col){
                            board->humans[pos]->followerValue=pos1;
                        }
                    }
                    break;
               }
           }
       }
        if (isChasing){
        // if this infected human is chasing a human, move towards them
            if(row>board->humans[chaseValue]->row){
                 rowDelta=-1, colDelta=0;
                 cout<<"chasing";
            }
            else if(row<board->humans[chaseValue]->row){
                 rowDelta=1, colDelta=0;
                 cout<<"chasing";
            }
            else if(col<board->humans[chaseValue]->col){
                rowDelta=0, colDelta=1;
                cout<<"chasing";
            }
            else if(col>board->humans[chaseValue]->col){
                rowDelta=0, colDelta=-1;
                cout<<"chasing";
            }
        }
   }
    // Ask the board whether you can make that move, if so, do it
    if(board->tryMove(row+rowDelta, col+colDelta)) {
	row+=rowDelta;
	col+=colDelta;
    }
}

/**
 * @brief Get the human's current row/col location.
 * Returns the human's current row/column location via the reference parameters.
 * @param[out] currentRow the human's current row  
 * @param[out] currentCol the human's current column
 */
void Human::getLocation(int& currentRow, int& currentCol) {
    currentRow = row;
    currentCol = col;
}

/**
 * @brief Set the human's row/col location.
 * Sets the human's current row/column location to the parameter values.
 * @param[in] newRow the human's new row location
 * @param[in] newCol the human's new column location
 */
void Human::setLocation(int newRow, int newCol) {
    row=newRow;
    col=newCol;
}

/**
 * @brief Sets this human to be infected.
 * Sets this human object's state to infected.
 */
void Human::setInfected() {
    infected = true;
    stopBeingChased();
}

/**
 * @brief reports whether this human is infected.
 * @return whether this human object is infected.
 */
bool Human::isInfected() {
    return infected;
}

/**
 * @brief Draws the human.
 * Draws the human at the current row/col location on the screen.
 * Remember that the first conio row=1, and first conio col=1.
 */
void Human::draw() {
    cout << conio::gotoRowCol(row+1,col+1);
    if( infected ) {
        if(isChasing){
            cout<< conio::bgColor(conio::MAGENTA);
        } else{
        cout << conio::bgColor(conio::LIGHT_RED);
        }
    } else {
        if(isBeingChased){
            cout << conio::bgColor(conio::YELLOW);
        } else{
        cout << conio::bgColor(conio::LIGHT_GREEN);
        }
    }

    cout << '@' << conio::resetAll() << flush;
}

