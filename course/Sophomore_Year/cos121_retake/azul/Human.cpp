#include <iostream>
#include <string>

#include "Human.h"
#include "Tile.h"
#include "conio.h"

using namespace std;
using namespace conio;

Human::Human(string name, int start) : real_name(name), Player(start) {
    cout << "What is your 'real' name? ";
    cin >> real_name;
}

Turn Human::get_turn(const Table& table, int player_number,
		     const vector<Board>& boards)
{
    const Board& board = boards[player_number];

    Turn result{-1, Tile::Empty, -1};

    cout << gotoRowCol(board.last_display_line() + 1, 1);
    cout << real_name << ": Which factory? ";
    cin >> result.factory;
    cout << gotoRowCol(board.last_display_line() + 1, 1);
    cout << real_name << ": Which tile? ";
    string tile;
    cin >> tile;
    result.type = tile;
    do {
	cout << gotoRowCol(board.last_display_line() + 1, 1);
	cout << real_name << ": Which row? ";
	cin >> result.row;
    } while (!table.is_legal(board, result));

    return result;
}

string Human::name() const {
    return real_name;
}

void Human::new_player(const string& other_name) {
}

void Human::new_game() {
}

void Human::new_round() {
}

extern "C" {
Player *make_player(const char *name, int start_row) {
    return new Human(name, start_row);
}
}
