#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Player.h"

class Human : public Player {
    std::string real_name;

  public:
    Human(std::string name, int start_row);

    void new_player(const std::string& name) override;
    void new_game() override;
    void new_round() override;

    Turn get_turn(const Table& table, int player_number,
		  const std::vector<Board>& boards) override;

    std::string name() const override;
};

#endif
