import java.math.BigInteger;

public class FindTheOne {
    private static void neo_up_naive() {
        StdRandom.setSeed(42);
        Neo_Up neo = new Neo_Up();
        try {
            int i = 0;
            while(neo.get(i) == 0) i++; // keep incrementing until
                                        // we find the first 1!
            neo.found1(i);
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    private static void neo_up_bad() {
        StdRandom.setSeed(42);
        Neo_Up neo = new Neo_Up();
        try {
            neo.found1(0);  // this is not the correct position!
            neo.found1(0);  // this is will throw an exception!
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    private static void neo_up() {
        StdRandom.setSeed(42);
        Neo_Up neo = new Neo_Up();
        try {
            int low = 0;
            int high = neo.size()-1;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if(neo.get(mid) == 0){
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
            neo.found1(low);
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    private static void neo_down() {
        StdRandom.setSeed(42);
        Neo_Down neo = new Neo_Down();
        try {
            int low = 0;
            int high = Integer.MAX_VALUE;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if(neo.get(mid) == 0){
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
            neo.found1(low);
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    private static void neo_left() {
        StdRandom.setSeed(42);
        Neo_Left neo = new Neo_Left();
        try {
            // do the tests here!
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    private static void neo_right() {
        StdRandom.setSeed(42);
        Neo_Right neo = new Neo_Right();
        try {
            // do the tests here!
        } catch(Exception e) {
            StdOut.println("Caught exception: " + e);
        }
    }

    public static void main(String[] args) {
        //neo_up_naive();
        //neo_up_bad();
        neo_up();
        neo_down();
        neo_left();
        neo_right();
    }
}
