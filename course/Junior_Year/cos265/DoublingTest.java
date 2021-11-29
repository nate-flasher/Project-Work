import java.util.Random;
import java.lang.Math;

public class DoublingTest<Item> {
    /***********************************************************************
     *  main() function
     *  Place all of your unit tests here
     *  Hint: created additional functions to help organize your tests
     ***********************************************************************/
    public static Double [] createArray(int N){
        Random randNum = new Random();
        Double [] array = new Double [N];
        for(int i = 0; i < N; i++){
            array[i] = randNum.nextDouble();
        }
        return array;
    }

    public static double bValue(double timePrev, double timeNow){

        double r = timeNow/timePrev;

        double b = Math.log(r)/Math.log(2);

        return b;
    }

    public static double aValue(double N, double timeNow, double b){
        double a = timeNow/Math.pow(N,b);
        return a;
    }

    public static void main(String[] args) {

        Double [] array = createArray(4096000);

        Stopwatch stopwatch = new Stopwatch();
        //Selection.sort(array);  // selection sort
        //Insertion.sort(array);  // insertion sort
        //Shell.sort(array);      // Shellsort
        //Bubble.sort(array);
        Quick.sort(array);
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");


        double s = bValue(2.834, 6.594);
        StdOut.println(aValue(2048000*2, 6.594, s) + "N^" + s);
    }
}
