#include "Actor.h"

class Hospital : public Actor {
  public:
    Hospital(const Location& initLocation, Board* thisBoard);
    void move() override;
    char getCharacter() const override;
    std::string getColor() const override;
    void interact(Actor *other) const override;
};
