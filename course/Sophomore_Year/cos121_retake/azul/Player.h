#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Board.h"
#include "Table.h"
#include "Turn.h"

class Player {
    int start_row;
    int seat;

  public:
    Player(int start_row);
    virtual void new_player(const std::string& name) = 0;
    virtual void new_game() = 0;
    virtual void new_round() = 0;

    virtual Turn get_turn(const Table& table, int player_number,
			  const std::vector<Board>& boards) = 0;

    virtual std::string name() const = 0;
    void set_seat(int seat);
    void display() const;
};

Player *player_factory(std::string name, int start_row);

#endif
