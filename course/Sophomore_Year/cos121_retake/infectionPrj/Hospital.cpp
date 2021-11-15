#include "Hospital.h"
#include "conio.h"

Hospital::Hospital(const Location& initLocation, Board* thisBoard)
    : Actor(initLocation, thisBoard)
{
}

void Hospital::move() {
}

char Hospital::getCharacter() const {
//    return '+';
}

std::string Hospital::getColor() const {
  //  return conio::bgColor(conio::LIGHT_BLUE);
}

void Hospital::interact(Actor *other) const {
    //other->setInfected(false);
}
