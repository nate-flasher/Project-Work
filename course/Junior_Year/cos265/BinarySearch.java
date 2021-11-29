import java.util.Arrays;
import java.util.Timer;

public class BinarySearch {
    public static int rank(int key, int[] a) {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi)
        {
           int mid = lo + (hi - lo) / 2;
           if (key < a[mid])
               hi = mid - 1;
           else if (key > a[mid])
               lo = mid +1;
           else
               return mid;
        }
        // returns the index position of key in a if it exists
        // else, returns -1
        return -1;
    }

    public static void main(String[] args) {

        int[] whitelist = In.readInts(args[0]);

        int[] checklist = In.readInts(args[1]);

        Arrays.sort(whitelist);
        long startTime = System.currentTimeMillis();
            for (int b = 0; b < checklist.length; b++)
        {
            int key = checklist[b];
            if (rank(key, whitelist) < 0)
                StdOut.println(key);
        }
        long endTime = System.currentTimeMillis();
        System.out.println("That took " + (endTime - startTime) + " milliseconds");
        // read ints from args[0] and store in whitelist
        // read ints from args[1] and store in checklist
        // print each int that is in checklist but is not in whitelist
    }

}
