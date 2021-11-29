import java.util.Iterator;

/**
 * Walker takes an Iterable of Coords and simulates an individual
 * walking along the path over the given Terrain
 */
public class Walker {

    private Terrain terrain;
    private Iterator<Coord> path;
    private Coord pathNext;
    private Coord current;
    private float travelCost;
    private float totalTime;
    // terrain: the Terrain the Walker traverses
    // path: the sequence of Coords the Walker follows
    public Walker(Terrain terrain, Iterable<Coord> path) {
        this.terrain = terrain;
        this.path = path.iterator();
        this.current = this.path.next();
        this.pathNext = this.path.next();
        this.travelCost = terrain.computeTravelCost(current, pathNext);

    }

    // returns the Walker's current location
    public Coord getLocation() {
        return this.current;
    }

    // returns true if Walker has reached the end Coord (last in path)
    public boolean doneWalking() {
        return !path.hasNext();
    }

    // advances the Walker along path
    // byTime: how long the Walker should traverse (may be any non-negative value)
    public void advance(float byTime) {
        totalTime = totalTime + byTime;
        while((totalTime >= travelCost) && !doneWalking()){
            totalTime = totalTime - travelCost;
            current = pathNext;
            pathNext = path.next();
            travelCost = terrain.computeTravelCost(current, pathNext);
        }
    }

}
