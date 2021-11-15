#include "killer.h"
#include "conio.h"
#include "cstdlib"

Killer::Killer(const Location& initLocation, Board* theBoard)
    : Actor(initLocation, theBoard)
{
}

void Killer::move() {
    int rowDelta = random()%7 - 3;
    int colDelta = random()%7 - 3;

    Location possibleLocation;
    possibleLocation.row = possibleLocation.row + rowDelta;
    possibleLocation.col = possibleLocation.col + colDelta;

    if(board->tryMove(possibleLocation)) {
        location = possibleLocation;
    }
}

char Killer::getCharacter() const{
    return '~';
}

std::string Killer::getColor() const {
    return conio::bgColor(conio::LIGHT_BLUE);
}

void Killer::interact(Actor *other) const {
    if(other->isInfected() && other != this){
        other->setKilled();
    }
}


