import java.math.BigInteger;

public class Neo_Right extends Neo<BigInteger> {
    private static final double pStart = 0.9999;
    private static final double pDecay = 0.9999;
    private static final BigInteger [] singles = {
            new BigInteger("0"),
            new BigInteger("1"),
            new BigInteger("2"),
            new BigInteger("3"),
            new BigInteger("4"),
            new BigInteger("5"),
            new BigInteger("6"),
            new BigInteger("7"),
            new BigInteger("8"),
            new BigInteger("9"),
    };

    private BigInteger i1 = BigInteger.ZERO;

    public Neo_Right() {
        for(double p = pStart; StdRandom.uniform() < p; p *= pDecay) {
            i1 = i1.multiply(BigInteger.TEN).add(singles[StdRandom.uniform(10)]);
        }
        if(StdRandom.uniform() < 0.5) i1 = i1.negate();
    }

    public int get(BigInteger i) throws Exception {
        increaseCalls();
        if(i.compareTo(i1) < 0) return 0;
        return 1;
    }

    public void found1(BigInteger i) throws Exception {
        foundCalled();
        if(i.equals(i1)) {
            StdOut.println("Congratulations!");
        } else {
            StdOut.println("Too bad");
        }
        StdOut.println("You called get() " + this.callsCount() + " times");
    }
}
