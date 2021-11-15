#ifndef HUMAN_H
#define HUMAN_H

/**
 * Declaration of the Human class.
 *
 * @author Stefan Brandle
 * @date March 2012
 * @author Jonathan Geisler
 * @date November 2019
 */

#include <string>
#include "Board.h"
#include "Actor.h"

/**
 * @class Human
 * @brief The Human class declaration.
 */
class Human : public Actor {
    public:
        Human(const Location& initLocation, Board* thisBoard);
	virtual ~Human();
    void move() override;
    bool isKilled() const override;
    void setKilled() override;
	char getCharacter() const override;
	std::string getColor() const override;
	void interact(Actor *other) const override;
};

#endif // HUMAN_H
