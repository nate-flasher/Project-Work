public class Neo_Up extends Neo<Integer> {
    private int N;
    private int i1;

    public Neo_Up() {
        N = StdRandom.uniform(1, 1000000);
        i1 = StdRandom.uniform(N);
    }

    public int size() {
        return N;
    }

    public int get(Integer i) throws Exception {
        increaseCalls();
        if(i < 0 || i >= N) throw new IndexOutOfBoundsException();
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
