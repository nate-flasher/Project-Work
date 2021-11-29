/**
 * The following code is *mostly* a copy of Quick class (quick sort) from algs4.jar
 */
import java.util.Random;
public class QuickSortMedian5 extends QuickSortMedian {

    public static class MedianOf5 extends MedianOfN {
        public MedianOf5() {
            // tell QuickSortMedian.MedianOfN we will find the median of 5 items
            super(5);
        }

        /***********************************************************
         * Determines which index in parameter indices points to
         * the median value in parameter a
         * @param a the array containing values
         * @param indices the array containing indices into a
         * @return the index of median value
         ***********************************************************/
        public int median(Comparable[] a, int[] indices) {
            // get values at specified indices

            //Comparable [] values = new Comparable[5];

            int i0 = indices[0];
            int i1 = indices[1];
            int i2 = indices[2];
            int i3 = indices[3];
            int i4 = indices[4];
            Comparable a0 = a[i0];
            Comparable a1 = a[i1];
            Comparable a2 = a[i2];
            Comparable a3 = a[i3];
            Comparable a4 = a[i4];

            Comparable [] values = new Comparable[] {a0, a1, a2, a3, a4};

            Shell.sort(values);
            //StdOut.println("i0: " + i0 + "\n" + "i1: " + i1 + "\n" + "i2: " + i2 + "\n" + "i3: " + i3 + "\n" + "i4: " + i4 + "\n");
            //StdOut.println("a0: " + a0 + "\n" + "a1: " + a1 + "\n" + "a2: " + a2 + "\n" + "a3: " + a3 + "\n" + "a4: " + a4 + "\n");
            for(int i=0; i < 5; i++){
                if(values[2] == a[indices[i]]){
                    return indices[i];
                }
            }

            return 0;
            /*
            for(int i=0; i<values.length; i++){
                StdOut.println(values[i]);
            }
             */


            // find median in a0,a1,a2,a3,a4, and return respective index
            // if a0 is median, return i0
            // if a1 is median, return i1
            // etc.

        }
    }

    /***********************************************************************
     * Rearranges the array in ascending order, using the natural order.
     * @param a the array to be sorted
     ***********************************************************************/
    public static void sort(Comparable[] a) {
        MedianOf5 median = new MedianOf5();
        QuickSortMedian.sort(a, median);
    }


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

    public static void main(String[] args) {
        //Double[] a = {0.0};
        Double [] array = createArray(4096000*2);
        Stopwatch stopwatch = new Stopwatch();
        QuickSortMedian5.sort(array);
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");
        //MedianOf5 medianof5 = new MedianOf5();
        //medianof5.median();
    }
}
