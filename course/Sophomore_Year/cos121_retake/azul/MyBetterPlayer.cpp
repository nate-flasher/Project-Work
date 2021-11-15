#include <iostream>
#include <string>

#include "MyBetterPlayer.h"
#include "Tile.h"
#include "conio.h"
#include "stdlib.h"
#include <fstream>


using namespace std;
using namespace conio;

    vector<Tile> tileVector = {Tile::White,Tile::Blue,Tile::Orange,Tile::Red,Tile::Black};

MyBetterPlayer::MyBetterPlayer(string name, int start) : real_name(name), Player(start) {
    real_name = "MyBetterPlayer";
}

int MyBetterPlayer::factory_tile_number_return(Tile tile, vector<Tile> vectorOfTiles){
    int count = 0;
    for(auto currentTile: vectorOfTiles){
        if(tile == currentTile){
            count++;
        }
    }
    return count;
}

bool MyBetterPlayer::rowFull(int theRow, const Board board){
        for(auto thisTile: board.get_row(theRow) ){
            if(thisTile == Tile::Empty){
                return false;
            }
        }
        return true;

}

bool MyBetterPlayer::rowEmpty(int theRow, const Board board){
        for(auto thisTile: board.get_row(theRow) ){
            if(thisTile != Tile::Empty){
                return false;
            }
        }
        return true;
}
Turn MyBetterPlayer::get_turn(const Table& table, int player_number,
		     const vector<Board>& boards)
{
    const Board& board = boards[player_number];

    Turn result{-1, Tile::Empty, -1};
    int bestScore = -1;

    for(int factory = -1; factory < 5; factory++){
        for(auto tile: tileVector){
            for(int row = -1; row < 5; row++){
                int score = 0;
                //table.factory_contents(factory);
                if(row != -1 && rowEmpty(row, board)){
                        score += 1; 
                }
                else if(row != -1){
                    if(!rowFull(row, board)){
                        for(auto thisTile: board.get_row(row) ){
                            if(tile == thisTile){
                                score += 2;
                            }
                        }
                    }
                    else{
                    }
                }
               // int numOfTilesInFactory = factory_tile_number_return(tile, table.factory_contents(factory)); //tells me how many tiles are in the facotry im curently pulling from
               // int numOfTiles = factory_tile_number_return(tile, board.get_row(row)); //tells me how many are in the row i currently placed

                if(score >= bestScore){
                    Turn tempResult{factory, tile, row};
                    if(table.is_legal(board, tempResult)){
                        result = tempResult;
                        bestScore = score;
                    }
                    else{
                    }
                }
            }
        }
    }
    return result;
    
}

string MyBetterPlayer::name() const {
    return real_name;
}

void MyBetterPlayer::new_player(const string& other_name) {
}

void MyBetterPlayer::new_game() {
}

void MyBetterPlayer::new_round() {
}

extern "C" {
Player *make_player(const char *name, int start_row) {
    return new MyBetterPlayer(name, start_row);
}
}
