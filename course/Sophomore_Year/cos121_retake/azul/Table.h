#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "Board.h"
#include "Tile.h"
#include "Turn.h"

class Table {
    std::vector<Tile> tiles;
    std::vector<Tile> dead_tiles;
    std::vector<std::vector<Tile>> factories;
    std::vector<Tile> center;
    bool starting_player_taken;

  public:
    Table(int num_players);

    bool is_legal(const Board& board, const Turn& turn) const;
    bool apply(Turn turn, Board& board);

    int num_factories() const;
    const std::vector<Tile>& factory_contents(int factory) const;
    const std::vector<Tile>& center_contents() const;

    void return_tiles(std::vector<Tile>& returned_tiles);
    void reset();

    void display() const;
};

#endif
