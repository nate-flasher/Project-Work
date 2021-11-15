#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<bool>>;

const int boardSize = 8;

void displayBoard(const matrix& board){ //board is a reference to a const matrix
    for (auto row : board) {
        for (auto col : row){
            cout << col;
        }
        cout << "\n";
    }
}
bool check_columns(const matrix& board){
        int count = 0;
        for(int row = 0; row < boardSize; ++row){
            if(board[row][col]){ //==true;
                ++count;
            }
        }
    if(count > 1){
        return false;
    }
    }
    return true;
}
bool check_diagonals(int row, int col, const matrix& board){
    return true;
}
bool isValid(int row, int col, const matrix& board){
    if(!check_columns(col, board)){
        return false;
    }
    if (!check_diagonals(row, col, board)){
        return false;
    }
}

bool placeQueen(int queenNum, matrix& board){
   if(queenNum >= boardSize){ //if we are at exit, return true
        return true;
   }

    for(int col =  0; col < boardSize; ++col){
        board[queenNum][col] = true;
        if(isValid(board) && placeQueen(queenNum +1, board)){
            return true; //if we can place this queen then we can place the next queen
        }
        else{
            board[queenNum][col] = false; //if we cant place this queen 
        }
    }

    return false; //backtracking

}

int main(int argc, char **argv){
    matrix board(boardSize, vector<bool>(8, false)); //creates an 8x8 board of false element

    displayBoard(board);


    if(placeQueen(0, board)){
        cout << "Works!\n";
    }
    else{
        cout << "Not possible\n";
    }

    return 0;

}
