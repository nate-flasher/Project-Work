#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>

class Tile {
  public:
    enum Value { White, Blue, Orange, Red, Black, Empty, FirstPlayer };

    Tile() = default;
    Tile(Value tile);
    Tile(std::string name);

    bool operator==(const Tile& other) const;
    bool operator!=(const Tile& other) const;
    bool operator<(const Tile& other) const;

    void display() const;

    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

  private:
    Value value;
};

#endif
