import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MinimumStack<Item extends Comparable> implements Iterable<Item> {
    private Node first = null;
    private int size;
    private int opsCount;
    Stack<Item> minStack = new Stack<>();
    public MinimumStack() {
    }


    private class Node {    // private inner class
        Item item;        // (access modifiers for instance
        Node next; // variables don't matter)
    }


    // returns the number of items stored
    public int size() {
        return size;
    }

    // returns true iff empty
    public boolean isEmpty() {
        if (first == null){
            return true;
        }
        else{
            return false;
        }
    }

    // push item onto stack
    public void push(Item item) {
        boolean wasEmpty = isEmpty();
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        size++;
        if(size == 1){
            minStack.push(first.item);
        }
        else{
            if (first.item.compareTo(minStack.peek()) <= 0){
                minStack.push(item);
            }
        }
        opsCount++;
    }

    // pop and return the top item
    public Item pop() throws NoSuchElementException {
        if (isEmpty()){
            throw new NoSuchElementException("Stack is empty - can't pop");
        }
        Item item = first.item;
        first = first.next;
        size--;
        opsCount++;
        if (item.compareTo(minStack.peek()) == 0){
            minStack.pop();
        }
        return item;
    }

    // returns the minimum item in constant time
    public Item minimum() throws NoSuchElementException {
        if(minStack.isEmpty()){
            throw new NoSuchElementException("Stack is empty - can't return minimum");
        }
        return minStack.peek();
    }

    // returns new Iterator<Item> that iterates over items
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

    public static void main(String[] args) {
        MinimumStack<Integer> steque = new MinimumStack<>();
        steque.push(5);
        steque.push(7);
        steque.push(5);
        steque.push(4);
        steque.push(3);
        steque.pop();
        steque.pop();
        steque.pop();
        steque.pop();
        steque.pop();

        StdOut.println("Minimum is: " + steque.minimum() + "\n");
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
