import java.lang.IndexOutOfBoundsException;
import java.lang.IllegalArgumentException;

/**
 * Pathfinder uses A* search to find a near optimal path
 * between to locations with given terrain.
 */
// basic getters and setters
    //then implement the reset path (maybe revisit)
    //then implement the compute path

public class Pathfinder {

    private Coord pathStart = new Coord (0,0);
    private Coord pathEnd = new Coord (100,100);
    private MinPQ<PFNode> minPQ = new MinPQ<>();
    private Terrain terrain;
    private int boardSize;
    private PFNode [][] breadCrumbArray;
    private PFNode pointer;
    private Stack<Coord> stack = new Stack<>();
    private int count;
    private float heuristic;
    private PFNode current;

    /**
     * PFNode will be the key for MinPQ (used in computePath())
     */
    private class PFNode implements Comparable<PFNode> {
        private Coord coordinate;
        private PFNode fromNode;

        float travelCost;
        // loc: the location of the PFNode
        // fromNode: how did we get here? (linked list back to start)
        public PFNode(Coord loc, PFNode fromNode) {
            coordinate = loc;
            this.fromNode = fromNode;
            if(fromNode == null){
                travelCost = 0;
            }
            else {
                travelCost = terrain.computeTravelCost(coordinate, this.fromNode.coordinate) + this.fromNode.getCost(heuristic);
            }
        }

        // compares this with that, used to find minimum cost PFNode
        public int compareTo(PFNode that) {
            if(this.getCost(heuristic) < that.getCost(heuristic)){
                return -1;
            }
            else if(this.getCost(heuristic) > that.getCost(heuristic)){
                return 1;
            }
            else {
                return 0;
            }
        }

        // returns the cost to travel from starting point to this
        // via the fromNode chain
        public float getCost(float heuristic) {
                return travelCost + (heuristic * (terrain.computeDistance(current.coordinate.getI(), current.coordinate.getJ(), pathEnd.getI(), pathEnd.getJ())));
        }

        // returns if this PFNode is still valid
        public boolean isValid() {
            return false;
        }

        // invalidates the PFNode
        public void invalidate() {
        }

        // returns if the PFNode has been used
        public boolean isUsed() {
            return true;
        }

        // uses the PFNode
        public void use() { }

        // returns an Iterable of PFNodes that surround this
        public Iterable<PFNode> neighbors() {
            Stack<PFNode> s = new Stack<>();
            s.push(new PFNode(null, null));
            return s;
        }
    }

    public Pathfinder(Terrain terrain) {
        this.terrain = terrain;
    }

    public void setPathStart(Coord loc) {
        if(loc == null){
            throw new IllegalArgumentException("Path starting coordinate is null");
        }
        this.pathStart = loc;
    }

    public Coord getPathStart() {
        return this.pathStart;
    }

    public void setPathEnd(Coord loc) {
        if (loc == null) {
            throw new IllegalArgumentException("Path ending coordinate is null");
        }
        this.pathEnd = loc;
    }

    public Coord getPathEnd() {
        return this.pathEnd;
    }

    public void setHeuristic(float v) {
        heuristic = v;
    }

    public float getHeuristic() {
        return heuristic;
    }

    public void resetPath() {
        stack = new Stack<>();
        minPQ = new MinPQ<>();
    }

    public void computePath() {
        //throw Illegal Arugment Exception if computePath is called before path start and end are set
        if (this.pathStart == null || this.pathEnd == null) {
            throw new IllegalArgumentException("Either or both starting position or ending position is/are not set");
        }
        //getting N from terrain class which is the 1d board size
        boardSize = terrain.getN();

        //creating an array of size boardsize*boardsize to store the PFNode positions to see if we have been there
        breadCrumbArray = new PFNode[boardSize][boardSize];

        //starting position on board
        PFNode start = new PFNode(this.pathStart, null);

        //putting starting position in my breadcrumbarray
        breadCrumbArray[start.coordinate.getI()][start.coordinate.getJ()] = start;

        //putting the PFNode starting position in my minPQ
        minPQ.insert(start);

        count = 0;

        //do this while we have not found the end point on the board
        while (!minPQ.isEmpty()) {
            //delete value off of end of minPQ and set it equal to current
            current = minPQ.delMin();

            //once our current value is equal to the path ending position, create a pointer to the end of linked list and break
            if(current.coordinate.equals(this.pathEnd)){
                this.pointer = current;
                break;
            }

            //create directions north, east, south, west to check eventually
            Coord neighborNorth = new Coord(current.coordinate.getI(), current.coordinate.getJ() + 1);
            Coord neighborEast = new Coord(current.coordinate.getI() + 1, current.coordinate.getJ());
            Coord neighborSouth = new Coord(current.coordinate.getI(), current.coordinate.getJ() - 1);
            Coord neighborWest = new Coord(current.coordinate.getI() - 1, current.coordinate.getJ());

            //check if each neighbor is in bounds and we have not been there
            //if it is in bounds and we have not been there then add the position to the breadcrumbarray and the minPQ
            if ((neighborNorth.isInBounds(0, 0, boardSize -1, boardSize - 1)) && (breadCrumbArray[neighborNorth.getI()][neighborNorth.getJ()] == null)) {
                PFNode thisPosition = new PFNode(neighborNorth, current);
                breadCrumbArray[neighborNorth.getI()][neighborNorth.getJ()] = thisPosition;
                minPQ.insert(thisPosition);
                count++;
            }

            if ((neighborEast.isInBounds(0, 0, boardSize -1, boardSize - 1)) && (breadCrumbArray[neighborEast.getI()][neighborEast.getJ()] == null)) {
                PFNode thisPosition = new PFNode(neighborEast, current);
                breadCrumbArray[neighborEast.getI()][neighborEast.getJ()] = thisPosition;
                minPQ.insert(thisPosition);
                count++;
            }

            if ((neighborSouth.isInBounds(0, 0, boardSize -1, boardSize - 1)) && (breadCrumbArray[neighborSouth.getI()][neighborSouth.getJ()] == null)) {
                PFNode thisPosition = new PFNode(neighborSouth, current);
                breadCrumbArray[neighborSouth.getI()][neighborSouth.getJ()] = thisPosition;
                minPQ.insert(thisPosition);
                count++;
            }

            if ((neighborWest.isInBounds(0, 0, boardSize -1, boardSize - 1)) && (breadCrumbArray[neighborWest.getI()][neighborWest.getJ()] == null)) {
                PFNode thisPosition = new PFNode(neighborWest, current);
                breadCrumbArray[neighborWest.getI()][neighborWest.getJ()] = thisPosition;
                minPQ.insert(thisPosition);
                count++;
            }

            // loop
            //dequeue in PQ
            //look at all directions
            //check to see if we have already been there and if it is in bounds
            //if the direction is possible, add it to the PQ
            //record the way back
            //look at minPQ and choose choice that costs the less (or choose one at random)
        }
        PFNode current = this.pointer;
        while(current != null){
            stack.push(current.coordinate);
            current = current.fromNode;
        }
    }

    public boolean foundPath() {
        // if our pointer has anything it's looking at then there is a path and we return true
        if(this.pointer != null){
            return true;
        }
        else{
            return false;
        }
    }

    public float getPathCost() {
        //whatever path we found(the cost of it), store in a variable and return that here
        return pointer.travelCost;
    }

    public int getSearchSize() {
        //this is a number that represents how many coordinates that i put on minPQ
        //use a count variable to keep track of all things ive put on minPQ
        return count;
    }

    public Iterable<Coord> getPathSolution() {
        return stack;
    }

    public boolean wasSearched(Coord loc) {
        //returns true if the coordinate specified was ever put on minPQ, if this works we will see in purple what all we searched and not just the pink path
        return breadCrumbArray[loc.getI()][loc.getJ()] != null;
        }
}
