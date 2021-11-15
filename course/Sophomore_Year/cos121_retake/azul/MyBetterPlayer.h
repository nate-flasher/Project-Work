#ifndef MYBETTERPLAYER_H
#define MYBETTERPLAYER_H

#include <string>
#include "Player.h"

class MyBetterPlayer : public Player {
    std::string real_name;

  public:
    bool rowEmpty(int theRow, const Board board);
    bool rowFull(int theRow, const Board board);
    int factory_tile_number_return(Tile tile, std::vector<Tile> vectorOfTiles);

    MyBetterPlayer(std::string name, int start_row);

    void new_player(const std::string& name) override;
    void new_game() override;
    void new_round() override;

    Turn get_turn(const Table& table, int player_number,
		  const std::vector<Board>& boards) override;

    std::string name() const override;
};

#endif
