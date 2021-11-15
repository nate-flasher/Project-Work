#ifndef ACTOR_H
#define ACTOR_H

/**
 * Declaration of the Actor class.
 *
 * @author Jonathan Geisler
 * @date November 2019
 */

class Actor;

#include <string>

#include "Board.h"
#include "Location.h"

/**
 * @class Actor
 * @brief The Actor class declaration.
 */
class Actor {
    public:
        Actor(const Location& initLocation, Board* thisBoard);
	virtual ~Actor();

	virtual void move() = 0;
	void draw() const;

	Location getLocation() const;
	virtual void setInfected(bool infect);
	bool isInfected() const;
    virtual bool isKilled() const;
    virtual void setKilled() ;

	virtual char getCharacter() const = 0;
	virtual std::string getColor() const = 0;

	virtual void interact(Actor *other) const;

    protected:
    bool killed;
	bool infected;     // Track whether or not this actor is infected.
	Location location; // Where this actor is on the board.

	Board *board;      // Pointer to the board so the actor can ask the
			   // board whether the actor can move to a given
			   // location on the board.
};

#endif // HUMAN_H
