#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <string>

#include "Player.h"

class Myplayer : public Player {
    std::string real_name;

  public:
    Myplayer(std::string name, int start_row);

    void new_player(const std::string& name) override;
    void new_game() override;
    void new_round() override;

    Turn get_turn(const Table& table, int player_number,
		  const std::vector<Board>& boards) override;

    std::string name() const override;
};

#endif
