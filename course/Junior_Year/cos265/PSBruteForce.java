import java.util.Iterator;

/**
 * PSBruteForce is a Point collection that provides brute force
 * nearest neighbor searching using red-black tree.
 */

public class PSBruteForce<Value> implements PointSearch<Value> {

    private RedBlackBST<Point, Value> pointCollection;
    private Point nearest;
    private Point min;
    private Point max;
    // constructor makes empty collection
    public PSBruteForce() {
        pointCollection = new RedBlackBST<Point, Value>();
    }


    // add the given Point to KDTree
    public void put(Point p, Value v) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        //p and v is first item getting put on
        if(isEmpty()){
            min = p;
            max = p;
        }
        else{
            min = Point.min(min, p);
            max = Point.max(max, p);
        }
        pointCollection.put(p, v);
    }


    public Value get(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(pointCollection.isEmpty()){
            return null;
        }
        return pointCollection.get(p);
    }

    public boolean contains(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        return pointCollection.contains(p);
    }

    // return an iterable of all points in collection
    public Iterable<Point> points() {
        if(pointCollection.isEmpty()){
            return null;
        }
       return pointCollection.keys();
    }

    // return the Point that is closest to the given Point
    public Point nearest(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(pointCollection.isEmpty()){
            return null;
        }
        nearest = null;
        for(Point q: pointCollection.keys()){
            if(nearest == null){
                nearest = q;
            }
            else if(p.dist(q) < p.dist(nearest)){
                nearest = q;
            }
        }
        return nearest;
    }

    // return the Value associated to the Point that is closest to the given Point
    public Value getNearest(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(pointCollection.isEmpty()){
            return null;
        }
        return pointCollection.get(nearest);
    }

    // return the min and max for all Points in collection.
    // The min-max pair will form a bounding box for all Points.
    // if KDTree is empty, return null.
    public Point min() {
        if(pointCollection.isEmpty()){
            return null;
        }
        else{
            return min;
        }
    }
    public Point max() {
        if(pointCollection.isEmpty()){
            return null;
        }
        else{
            return max;
        }
    }

    // return the k nearest Points to the given Point
    public Iterable<Point> nearest(Point p, int k) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(pointCollection.isEmpty()){
            return null;
        }
        MaxPQ<PointDist> nearest = new MaxPQ<>();
        for(Point current : points()){
            PointDist currentPD = new PointDist(current, p.dist(current));
            nearest.insert(currentPD);
            if(nearest.size() > k){
                nearest.delMax();
            }
        }
        Stack<Point> nearestPoints = new Stack<>();
        for(PointDist currentPD : nearest){
            nearestPoints.push(currentPD.p());
        }
        return nearestPoints;
    }

    public Iterable<Partition> partitions() { return null; }

    // return the number of Points in KDTree
    public int size() {
        return pointCollection.size();
    }

    // return whether the KDTree is empty
    public boolean isEmpty() {
        return pointCollection.isEmpty();
    }

    private static void parseCSVLine(String line, String[] data) {
        boolean inQuote = false;
        int s = -1;
        int j = 0;
        for(int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if(c == ' ' && !inQuote) {
                if(line.charAt(s+1) == '"' && line.charAt(i-1) == '"') {
                    data[j] = line.substring(s+2,i-1);
                } else {
                    data[j] = line.substring(s + 1, i);
                }
                j++;
                s = i;
                continue;
            }
            if(c=='"') {
                inQuote = !inQuote;
            }
        }
        int i = line.length();
        if(s < i) {
            if(line.charAt(s+1) == '"' && line.charAt(i-1) == '"') {
                data[j] = line.substring(s+2,i-1);
            } else {
                data[j] = line.substring(s + 1, i);
            }
        }
    }

    private static String[][] readCSV(String filename, int m) {
        String[] lines = (new In(filename)).readAllLines();
        int n = lines.length;
        String[][] a = new String[n][m];
        for(int i = 0; i < n; i++) parseCSVLine(lines[i], a[i]);
        return a;
    }

    private static void insertCSV(String filename, PointSearch<String[]> ps) {
        String[][] data = readCSV(filename, 4);
        for(int i = 0; i < data.length; i++) {
            double longitude = Double.parseDouble(data[i][0]);
            double latitude = Double.parseDouble(data[i][1]);
            String[] loc = {data[i][2], data[i][3]};
            ps.put(new Point(longitude, latitude), loc);
        }
    }
    // place your timing code or unit testing here
    public static void main(String[] args) {
        PointSearch<String[]> psBurgerKings = new PSBruteForce<>();

        insertCSV("input1M.txt", psBurgerKings);
        int count = 0;
        Stopwatch stopwatch = new Stopwatch();
        for(int i = 0; i < 9; i++) {
            Point hi = Point.uniform();
            psBurgerKings.nearest(hi);
            count++;
        }
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");

    }
}
