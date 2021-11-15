#ifndef TURN_H
#define TURN_H

#include <iostream>

#include "Tile.h"

class Turn {
  public:
    Turn(int factory, const Tile& type, int row);

    int factory;
    Tile type;
    int row;
    int num_tiles;
    bool starting_player_token;

    bool operator<(const Turn& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Turn& turn);
};

#endif
