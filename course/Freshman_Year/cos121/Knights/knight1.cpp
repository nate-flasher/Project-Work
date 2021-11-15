//Nate Flasher
//March 25, 2019

#include <iostream>
using namespace std;

void visitBoard(int row,int col,int drow,int dcol,int board[8][8],int jumps);

int main(){
    int srow;
    int scol;
    int drow;
    int dcol;
    int board[8][8];

    while(cin>>srow>>scol>>drow>>dcol){
        for(int row=0; row<8; row++){
            for(int col=0; col<8; col++){
                board[row][col]=-1;
            }

        }

        visitBoard(srow,scol,drow,dcol,board,0);
        
        cout<<board[drow][dcol]<<endl;
    }

    return 0;
}

void visitBoard(int row,int col,int drow,int dcol,int board[8][8],int jumps){
    if(row<0 || row>7 || col<0 || col>7) {
        return;
    }
    if(board[row][col]==-1){
        board[row][col]=jumps;
    } 
    else if(board[row][col]<=jumps){
        return;
    }
    else{
        board[row][col]=jumps;
    }

    visitBoard(row-2,col-1,drow,dcol,board,jumps+1);
    visitBoard(row-1,col-2,drow,dcol,board,jumps+1);
    visitBoard(row+1,col-2,drow,dcol,board,jumps+1);
    visitBoard(row+2,col-1,drow,dcol,board,jumps+1);
    visitBoard(row+2,col+1,drow,dcol,board,jumps+1);
    visitBoard(row+1,col+2,drow,dcol,board,jumps+1);
    visitBoard(row-1,col+2,drow,dcol,board,jumps+1);
    visitBoard(row-2,col+1,drow,dcol,board,jumps+1);
}
