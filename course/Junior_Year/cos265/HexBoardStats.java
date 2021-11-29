/****************************************************************************
 *  Command: HexBoardStats N0 N1 T
 *
 *  This program takes the board sizes N0,N1 and game count T as a command-line
 *  arguments. Then, the program runs T games for each board size N where
 *  N0 <= N <= N1 and where each play randomly chooses an unset tile to set in
 *  order to estimate the probability that player 1 will win.
 ****************************************************************************/
import java.util.Random;
public class HexBoardStats {
    int N0; //min board size
    int N1; //max board size
    int T; //number of games played
    int [] p1winsForEachBoardSize;
    HexBoard HexBoard;
    public HexBoardStats(int N0, int N1, int T) {
        this.N0 = N0;
        this.N1 = N1;
        this.T = T;
        if (N0 <= 0 || N1 <= 0 || T <= 0){
            throw new java.lang.IllegalArgumentException("Either board size is 0 or less or game count is 0 or less");
        }
        p1winsForEachBoardSize = new int [N1+1];

        Stopwatch stopwatch = new Stopwatch();
        for(int i=N0; i <= N1; i++ ){ //for each board size
            for(int b=0; b < T; b++){ //for all games
                if(playGame(i) == 1){
                    p1winsForEachBoardSize[i]++;
                }
            }
        }
        double time = stopwatch.elapsedTime();
        StdOut.println("elapsed time = " + time + "\n");
    }

    public int playGame(int N) {
        HexBoard = new HexBoard(N);
        Random rand = new Random();
        int randInt1;
        int randInt2;
        while(!HexBoard.hasPlayer1Won() && !HexBoard.hasPlayer2Won()){
            randInt1 = rand.nextInt(N);
            randInt2 = rand.nextInt(N);
            while(HexBoard.isSet(randInt1, randInt2)){
                randInt1 = rand.nextInt(N);
                randInt2 = rand.nextInt(N);
            }
            HexBoard.setTile(randInt1, randInt2, 1);

            if (HexBoard.hasPlayer1Won()){
                return 1;
            }


            randInt1 = rand.nextInt(N);
            randInt2 = rand.nextInt(N);
            while(HexBoard.isSet(randInt1, randInt2)){
                randInt1 = rand.nextInt(N);
                randInt2 = rand.nextInt(N);
            }
            HexBoard.setTile(randInt1, randInt2, 2);
            if (HexBoard.hasPlayer2Won()){
                return 2;
            }
        }
        return 0; //why?
    }

    public int getN0() {
        return N0;
    }

    public int getN1() {
        return N1;
    }

    public int getT() {
        return T;
    }

    public double getP1WinProbabilityEstimate(int n) {
        if(n < N0 || n > N1){
            throw new java.lang.IndexOutOfBoundsException("Board size out of bounds");
        }
        return (double)p1winsForEachBoardSize[n]/T;
    }

    public double getP2WinProbabilityEstimate(int n) {
        return 1-(double)p1winsForEachBoardSize[n]/T;
    }

    public static void main(String[] args) {
        int N0 = Integer.parseInt(args[0]);
        int N1 = Integer.parseInt(args[1]);
        int T = Integer.parseInt(args[2]);
        HexBoardStats HBS = new HexBoardStats(N0, N1, T);
        System.out.print("T = " + T + "\n");

        for (int i = N0; i <= N1; i++) {
            System.out.print("N = " + i + "," + " P1 = " + HBS.getP1WinProbabilityEstimate(i) + "," + " P2 = " + HBS.getP2WinProbabilityEstimate(i) + "\n");
        }
    }
}
