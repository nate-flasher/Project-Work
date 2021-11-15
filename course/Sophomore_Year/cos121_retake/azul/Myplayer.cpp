#include <iostream>
#include <string>

#include "Myplayer.h"
#include "Tile.h"
#include "conio.h"
#include "stdlib.h"

using namespace std;
using namespace conio;

Myplayer::Myplayer(string name, int start) : real_name(name), Player(start) {
    /*
    cout << "What is your 'real' name? ";
    cin >> real_name;
    */
    real_name = "Myrandomplayer";
}

Turn Myplayer::get_turn(const Table& table, int player_number,
		     const vector<Board>& boards)
{
    const Board& board = boards[player_number];

    Turn result{-1, Tile::Empty, -1};
/*
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
*/

    srand (time(NULL));
    while(!table.is_legal(board, result)){
    int tileNumber = rand() % 6;
    int factoryNumber = rand() % 6;
    int rowNumber = rand() % 6;
                
        if(factoryNumber == 0){
            result.factory = 0; 
        }
        else if(factoryNumber == 1){
            result.factory = 1;
        }
        else if(factoryNumber == 2){
            result.factory = 2;
        }
        else if(factoryNumber == 3){
            result.factory = 3;
        }
        else if(factoryNumber == 4){
            result.factory = 4;
        }
        else {
            result.factory = -1;
        }





        if(tileNumber == 0){
            result.type = Tile::White; 
        }
        else if(tileNumber == 1){
            result.type = Tile::Blue;
        }
        else if(tileNumber == 2){
            result.type = Tile::Orange;
        }
        else if(tileNumber == 3){
            result.type = Tile::Red;
        }
        else if(tileNumber == 4){
            result.type = Tile::Black;
        }
        else {
            result.type = Tile::FirstPlayer;
        }





        if(rowNumber == 0){
            result.row = 0; 
        }
        else if(rowNumber == 1){
            result.row = 1;
        }
        else if(rowNumber == 2){
            result.row = 2;
        }
        else if(rowNumber == 3){
            result.row = 3;
        }
        else if(rowNumber == 4){
            result.row = 4;
        }
        else {
            result.row = -1;
        }
    }

    return result;
}

string Myplayer::name() const {
    return real_name;
}

void Myplayer::new_player(const string& other_name) {
}

void Myplayer::new_game() {
}

void Myplayer::new_round() {
}

extern "C" {
Player *make_player(const char *name, int start_row) {
    return new Myplayer(name, start_row);
}
}
