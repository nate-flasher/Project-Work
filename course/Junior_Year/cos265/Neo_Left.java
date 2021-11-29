public class Neo_Left extends Neo<Double> {
    private double d1;

    public Neo_Left() {
        d1 = StdRandom.uniform(0.0, Double.MAX_VALUE);
    }

    public int get(Double d) throws Exception {
        increaseCalls();
        if(d < d1) return 0;
        return 1;
    }

    public void found1(Double d) throws Exception {
        this.foundCalled();
        double diff = Math.floor(d - d1);
        if(Double.compare(diff, 0.0) == 0) {
            StdOut.println("Perfect!");
        } else {
            StdOut.println("You are off by " + Math.abs(diff));
        }
        StdOut.println("You called get() " + this.callsCount() + " times");
    }
}
