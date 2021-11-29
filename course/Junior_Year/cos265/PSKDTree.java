import java.util.Iterator;
import  java.lang.Math;

/**
 * PSKDTree is a Point collection that provides nearest neighbor searching using
 * 2d tree
 */
public class PSKDTree<Value> implements PointSearch<Value> {
    private Node root;
    private Point min;
    private Point max;
    private Point nearest;
    private MaxPQ<PointDist> nearestPQ = new MaxPQ<>();
    private class Node {
        Point p;
        Value v;
        Node left, right;
        Partition.Direction dir;
        int size = 1;
        public Node(Point key, Value val, int depth){
            if(depth % 2 == 0){ //depth is even number
                dir = Partition.Direction.LEFTRIGHT;
            }
            else{
                dir = Partition.Direction.DOWNUP;
            }
            this.p = key;
            this.v = val;
        }
    }

    // constructor makes empty kD-tree
    public PSKDTree() {
        root = null;
    }

    // add the given Point to kD-tree
    public void put(Point p, Value v) {
        //increment size
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(isEmpty()){
            min = p;
            max = p;
        }
        else{
            min = Point.min(min, p);
            max = Point.max(max, p);
        }
        root = put(root, p, v, 0);
    }


    private Node put(Node current, Point key, Value val, int depth) {
        if (current == null) return new Node(key, val, depth);

        if (key.equals(current.p)) {
            current.v = val;
        }
        else if (current.dir == Partition.Direction.LEFTRIGHT) { //even number
            if (current.p.x() > key.x()) current.left = put(current.left, key, val, depth + 1);
            else current.right = put(current.right, key, val, depth + 1);
            current.size = 1 + size(current.left) + size(current.right);
        }
        else{
            if (current.p.y() > key.y()) current.left = put(current.left, key, val, depth + 1);
            else current.right = put(current.right, key, val, depth + 1);
            current.size = 1 + size(current.left) + size(current.right);
        }

            return current;
        }


    public Value get(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        return get(root, p);
    }

    private Value get(Node current, Point key) {
        if (current == null) {
            return null;
        }
        if(key.equals(current.p)) {
            return current.v;
        }
        if(current.dir == Partition.Direction.LEFTRIGHT) {
            if (current.p.x() > key.x()) return get(current.left, key);
            else return get(current.right, key);
        }
        else {
            if (current.p.y() > key.y()) return get(current.left, key);
            else return get(current.right, key);
        }
    }


    public boolean contains(Point p) {
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        return get(p) != null;
    }

    public Value getNearest(Point p) { //do this
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(isEmpty()){
            return null;
        }

        //help
        Point q = nearest(p);
        return get(q);
    }

    // return an iterable of all points in collection
    public Iterable<Point> points() {
        Queue<Point> q = new Queue<Point>();
        inorder(root, q);
        return q;
    }

    private void inorder(Node x, Queue<Point> q){
        if (x == null) return;
        inorder(x.left, q);
        q.enqueue(x.p);
        inorder(x.right, q);
    }

    // return an iterable of all partitions that make up the kD-tree
    public Iterable<Partition> partitions() {
        return null;
    }

    // return the Point that is closest to the given Point
    public Point nearest(Point p) {  //do this
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(isEmpty()){
            return null;
        }

        //help
        nearest = root.p;
        nearest(root, p);
        return nearest;
    }

    private void nearest(Node current, Point p) {
        if(current == null){
            return;
        }

        if(p.dist(current.p) < p.dist(nearest)){ //check to see if we have a new nearest
            nearest = current.p;
        }

        if(current.dir == Partition.Direction.LEFTRIGHT) {
            double xDist = Math.abs(current.p.x() - p.x());
            if (current.p.x() <= p.x()) {
                nearest(current.right, p);
                if (xDist < p.dist(nearest)) {
                    nearest(current.left, p);
                }
            } else {
                nearest(current.left, p);
                if (xDist < p.dist(nearest)) {
                    nearest(current.right, p);
                }
            }
        }
        else {
            double yDist = Math.abs(current.p.y() - p.y());
            if (current.p.y() <= p.y()) {
                nearest(current.right, p);
                if (yDist < p.dist(nearest)) {
                    nearest(current.left, p);
                }
            } else {
                nearest(current.left, p);
                if (yDist < p.dist(nearest)) {
                    nearest(current.right, p);
                }
            }
        }

    }

    // return the k nearest Points to the given Point
    public Iterable<Point> nearest(Point p, int k) {  //do this
        Stack<Point> nearestPoints = new Stack<>();
        if(p == null){
            throw new java.lang.NullPointerException("No point");
        }
        if(k == 0){
            return nearestPoints;
        }
        if(isEmpty()){
            return nearestPoints;
        }

        //help
        nearestPQ = new MaxPQ<>();
        nearestK(root, p, k);

        for(PointDist currentpD : nearestPQ) {
            nearestPoints.push(currentpD.p());
        }
        //System.out.println(nearestPoints);
        return nearestPoints;


    }

    private void nearestK(Node current, Point p, int k) {
        if(current == null){
            return;
        }

        PointDist currentPD = new PointDist(current.p, p.dist(current.p));

        if(nearestPQ.isEmpty()){
            nearestPQ.insert(currentPD);
        }

        nearestPQ.insert(currentPD);

        if(nearestPQ.size() > k){
            nearestPQ.delMax();
        }

        if(current.dir == Partition.Direction.LEFTRIGHT) {
            double xDist = Math.abs(current.p.x() - p.x());
            if (current.p.x() <= p.x()) {
                nearestK(current.right, p, k);
                if (xDist < nearestPQ.max().d() || nearestPQ.size() < k) {
                    nearestK(current.left, p, k);
                }
            } else {
                nearestK(current.left, p, k);
                if (xDist < nearestPQ.max().d() || nearestPQ.size() < k) {
                    nearestK(current.right, p, k);
                }
            }
        }
        else {
            double yDist = Math.abs(current.p.y() - p.y());
            if (current.p.y() <= p.y()) {
                nearestK(current.right, p, k);
                if (yDist < nearestPQ.max().d() || nearestPQ.size() < k) {
                    nearestK(current.left, p, k);
                }
            } else {
                nearestK(current.left, p, k);
                if (yDist < nearestPQ.max().d() || nearestPQ.size() < k) {
                    nearestK(current.right, p, k);
                }
            }
        }

    }

    // return the min and max for all Points in collection.
    // The min-max pair will form a bounding box for all Points.
    // if kD-tree is empty, return null.
    public Point min() {
        if(isEmpty()){
            return null;
        }
        else{
            return min;
        }
    }
    public Point max() {
        if(isEmpty()){
            return null;
        }
        else{
            return max;
        }
    }

    // return the number of Points in kD-tree
    public int size() {
        if(root == null){
            return 0;
        }
        else{
            return root.size;
        }

    }
    private int size(Node x) {
        if (x == null) return 0;
        else return x.size;
    }

    // return whether the kD-tree is empty
    public boolean isEmpty() { return size() == 0; }

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
        /*
        PSKDTree<String> hello = new PSKDTree<>();
        Point hi = new Point(0.688888, 0.3);
        Point hiiii = new Point(0.688888, 0.388888);
        hello.put(hi, "hello");
        hello.put(hiiii, "hiiii");
        System.out.println(hello.getNearest(hi));
        System.out.println(hello.getNearest(hiiii));

         */
        PointSearch<String[]> psBurgerKings = new PSKDTree<>();

        insertCSV("input1M.txt", psBurgerKings);
        int count = 0;
        Stopwatch stopwatch = new Stopwatch();
        for(int i = 0; i < 415000; i++) {
            Point hi = Point.uniform();
            psBurgerKings.nearest(hi);
            count++;
        }
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");

    }

}
