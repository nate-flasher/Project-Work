public class Neo_Down extends Neo<Integer> {
    private int i1;

    public Neo_Down() {
        i1 = StdRandom.uniform(Integer.MAX_VALUE);
    }

    public int get(Integer i) throws Exception {
        increaseCalls();
        if(i < 0) throw new IndexOutOfBoundsException();
        if(i < i1) return 0;
        return 1;
    }

    public void found1(Integer i) throws Exception {
        foundCalled();
        if(i == i1) {
            StdOut.println("Congratulations!");
        } else {
            StdOut.println("Too bad");
        }
        StdOut.println("You called get() " + this.callsCount() + " times");
    }
}
