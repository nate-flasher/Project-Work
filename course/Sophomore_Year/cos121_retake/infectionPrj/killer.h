#include "Actor.h"


class Killer : public Actor{

    public:
        Killer(const Location& initLocation, Board* thisBoard);
        void move() override;
//        void setInfected(bool infect) override;
        char getCharacter() const;
        std::string getColor() const;
        void interact(Actor *other) const override;

};
