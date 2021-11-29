import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Steque<Item> implements Iterable<Item> {
    private Node first = null;
    private Node last = null;
    private int size;
    private int opsCount;
    public Steque() {
    }

    private class Node {    // private inner class
        Item item;        // (access modifiers for instance
        Node next; // variables don't matter)
    }
    // returns the number of items stored
    public int size() {
        return size;
    }

    // returns true if steque is empty
    public boolean isEmpty() {
        if (first == null){
            return true;
        }
        else{
            return false;
        }
    }

    // enqueues item to bottom of steque
    public void enqueue(Item item) {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        size++;
        opsCount++;
        if(isEmpty()) first = last;     // handle special case
        else oldLast.next = last;       // for empty queue
    }

    // pushes item to top of steque
    public void push(Item item) {
        boolean wasEmpty = isEmpty();
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        size++;
        opsCount++;
        if(wasEmpty){
            last = first;
        }
    }

    // pops and returns top item
    public Item pop() throws NoSuchElementException {
        if (isEmpty()){
            throw new NoSuchElementException("Linked list is empty - can't pop");
        }
        Item item = first.item;
        first = first.next;
        if(isEmpty()){
            last = first;
        }
        size--;
        opsCount++;
        return item;

    }
    //public class Stack<Item> implements Iterable<Item> {
        @Override
        public Iterator<Item> iterator() {
            int opsNow = opsCount;
            return new Iterator<Item>() {
                private Node current = first;

                public boolean hasNext() {
                    if(opsNow!=opsCount){
                        throw new java.util.ConcurrentModificationException("Stack was modified");
                    }
                    return current != null;
                }

                public void remove() { /* not supported */ }

                public Item next() {
                    Item item = current.item;
                    current = current.next;
                    return item;
                }
            };
        }

    // perform unit testing here
    public static void main(String[] args) throws NoSuchElementException {
        Steque<Integer> steque = new Steque<Integer>();
        steque.push(5);
        steque.enqueue(6);
      //  StdOut.print(steque.pop() + "\n");
       // StdOut.print(steque.pop() + "\n");
        //StdOut.print(steque.isEmpty() + "\n");
        Iterator<Integer> i = steque.iterator();
        while(i.hasNext()) {
            Integer s = i.next();
            StdOut.println(s);
        }
    }

}