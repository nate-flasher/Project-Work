import java.util.Arrays;

/****************************************************************************
 *  This class manages an N-by-N hex game board .
 ****************************************************************************/

public class HexBoard {
    int [][] board;
    int numberOfUnsetTiles;
    int N;
   WeightedQuickUnionUF QF;
    int [] array;
    int redBot;
    int redTop;
    int blueBot;
    int blueTop;
    public HexBoard(int N) {
        if (N <= 0){
            throw new java.lang.IllegalArgumentException("N needs to be greater than 0");
        }
        board = new int[N][N]; //creates board of 0s, 1s, and 2s
        numberOfUnsetTiles = N*N;
        this.N = N;
        array = new int[N*N];
        QF = new WeightedQuickUnionUF(N*N +4); //N^2, N^2+1 etc..
        redBot = (N*N) + 2;
        redTop = (N*N) + 3;
        blueBot = (N*N);
        blueTop = (N*N) + 1;

    }

    public int getPlayer(int row, int col) {
        return board[row][col];
    }
    
    public boolean isSet(int row, int col)

    {
        if (board[row][col] != 0)
       return true;
        else {
            return false;
        }
    }

    public boolean isOnWinningPath(int row, int col) {
        if(row < 0 || row > N || col < 0 || col > N){
            throw new java.lang.IllegalArgumentException("row or col is out of bounds");
        }
        int index = (row*N + col);
        if (QF.connected(index, redBot) && QF.connected(index, redTop) || QF.connected(index, blueBot) && QF.connected(index, blueTop)){
            return true;
        }
        return false;
    }

    public void setTile(int row, int col, int player) {



        if (row < 0 || row > N-1){
            throw new java.lang.IndexOutOfBoundsException("Row out of bounds");
        }
        if (col < 0 || col > N-1){
            throw new java.lang.IndexOutOfBoundsException("Col out of bounds");
        }
        if (player != 1 && player != 2){
            throw new java.lang.IndexOutOfBoundsException("Player invalid");
        }
        if(board[row][col] == 1 || board[row][col] == 2){
            throw new java.lang.IllegalArgumentException("Tile is already set");
        }
        else{
            board[row][col] = player;
            numberOfUnsetTiles--;
        }


        int index = (row*N + col);

        if (((row+1) < N) && board[row+1][col] == player){
            QF.union(index, ((row+1)*N + col));
        }
        if (((row-1) >= 0) && board[row-1][col] == player){
            QF.union(index, ((row-1)*N + col));
        }
        if (((col+1) < N) && board[row][col+1] == player){
            QF.union(index, ((row)*N + (col+1)));
        }
        if (((col-1) >= 0) && board[row][col-1] == player){
            QF.union(index, ((row)*N + (col-1)));
        }
        if (((row+1) < N) && ((col-1) >= 0) && (board[row+1][col-1]) == player){
            QF.union(index, ((row+1)*N + (col-1)));
        }
        if (((row-1) >= 0) && ((col+1) < N) && (board[row-1][col+1]) == player){
            QF.union(index, ((row-1)*N + (col+1)));
        }

        if(col == 0 && player == 1){
            QF.union(index, redBot);
        }
        if(col == (N-1) && player == 1){
            QF.union(index, redTop);
        }
        if(row == 0 && player == 2){
            QF.union(index, blueBot);
        }
        if(row == (N-1) && player == 2){
            QF.union(index, blueTop);
        }


    }

    public boolean hasPlayer1Won() {
        if (QF.connected(redBot, redTop)){
            return true;
        }
        else{
            return false;
        }

    }

    public boolean hasPlayer2Won() {
        if(QF.connected(blueBot, blueTop)){
            return true;
        }
        else{
            return false;
        }
    }

    public int numberOfUnsetTiles() {
        return numberOfUnsetTiles;
    }
}
