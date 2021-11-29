import java.util.Collections;
import java.util.Random;
import java.util.Arrays;

public class EdgeCases {
    /***********************************************************************
     *  main() function
     *  Place all of your unit tests here
     *  Hint: created additional functions to help organize your tests
     ***********************************************************************/
    public static Double [] randomArray(int N){ //creates array of random values in no specific order
        Random randNum = new Random();
        Double [] array = new Double [N];
        for(int i = 0; i < N; i++){
            array[i] = randNum.nextDouble();
        }
        return array;
    }

    public static Double [] sortedArray(Double [] array){ //creates array of sorted values from least to greatest
        Shell.sort(array);
        return array;
    }

    public static Double [] reverseSortedArray(Double [] array){ //creates array of sorted values from greatest to least
        Arrays.sort(array, Collections.reverseOrder());
        /*
        for(int i = 0; i< array.length; i++){
            StdOut.println(array[i]);
        }

         */
        return array;
    }

    public static Double [] distinctValueArray(int N){ //creates array of random (2) distinct values
        Random randNum = new Random();
        Double number;
        Double [] array = new Double [N];
        for(int i = 0; i < N; i++){
            if (randNum.nextBoolean()){
                array[i] = .01;
            }
            else{
                array[i] = .02;
            }
        }
        return array;
    }

    public static Double [] oneValueArray(int N){ //creates array of one distinct value that has that value in it N times
        Double number = .01;
        Double [] array = new Double [N];
        for(int i = 0; i < N; i++){
            array[i] = number;
        }
        return array;
    }

    public static void main(String[] args) {
        Double [] array = randomArray(10000); //creates an array of size N
        Double [] sortedArray = sortedArray(array); // sorts in acsending order
        Double [] reverseArray = reverseSortedArray(array); // sorts in descending order
        Double [] oneValueArray = oneValueArray(10000); // array of one value only of size N
        Double [] distinctValueArray = distinctValueArray(10000); // array of 2 distinct values..array is of size N



        Stopwatch stopwatch = new Stopwatch();
        //Bubble.sort(distinctValueArray);     // bubble sort
        //Selection.sort(oneValueArray);  // selection sort
        //Insertion.sort(distinctValueArray);  // insertion sort
        //Shell.sort(distinctValueArray);      // Shellsort
        Quick.sort(distinctValueArray);      // quicksort
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");
    }
}
