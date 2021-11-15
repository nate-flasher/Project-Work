#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <array>

#include "Tile.h"
#include "Turn.h"

class Board {
    std::array<std::vector<Tile>, 5> rows;
    std::vector<Tile> broken_tiles;
    std::array<std::vector<Tile>, 5> placed_tiles;

    int start_row;

    bool starting_player;
    int points;

    void place_tile(const Tile& tile, int row, int col);
    int vert_contig(int row, int col);
    int horiz_contig(int row, int col);

    int count_placed(const Tile& tile) const;

  public:
    Board(int start_row);

    bool is_legal(const Turn& turn) const;
    const std::vector<Tile>& get_row(int row) const;
    const std::vector<Tile>& placed_row(int row) const;
    bool game_over() const;
    int current_score() const;

    void apply(const Turn& turn);
    void spill(const Turn& turn);
    bool score_round(std::vector<Tile>& returned_tiles);
    void final_scoring();

    void display(int id) const;
    int last_display_line() const;
};

#endif
