//Nate Flasher
//March 25, 2019

#include <iostream>
using namespace std;

void visitBoard(int row,int col,int board[20][20],int jumps,int bSize);

int main(){
    int srow;
    int scol;
    int board[20][20];
    int count;
    int bSize;
    int jumps;

    while(cin>>bSize>>srow>>scol>>jumps){
        for(int row=0; row<bSize; row++){
            for(int col=0; col<bSize; col++){
                board[row][col]=-1;
            }
        }

        visitBoard(srow,scol,board,jumps,bSize);

        count = 0;
        for(int row=0; row<bSize; row++){
            for(int col=0; col<bSize; col++){
                if(board[row][col]!=-1){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }

    return 0;
}


void visitBoard(int row,int col,int board[20][20],int jumps,int bSize){
    if(row<0 || row>=bSize || col<0 || col>=bSize) {
        return;
    }
    
    if(board[row][col]>=jumps){
        return;
    } else{
        board[row][col]=jumps;
    }

    if(jumps==0){
        return;
    }

    visitBoard(row-2,col-1,board,jumps-1,bSize);
    visitBoard(row-1,col-2,board,jumps-1,bSize);
    visitBoard(row+1,col-2,board,jumps-1,bSize);
    visitBoard(row+2,col-1,board,jumps-1,bSize);
    visitBoard(row+2,col+1,board,jumps-1,bSize);
    visitBoard(row+1,col+2,board,jumps-1,bSize);
    visitBoard(row-1,col+2,board,jumps-1,bSize);
    visitBoard(row-2,col+1,board,jumps-1,bSize);
}

