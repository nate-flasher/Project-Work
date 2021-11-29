import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class OnePointerQueue<Item> implements Iterable<Item> {
    private Node last = null;
    private int size;
    private int opsCount;
    public OnePointerQueue() {

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
        if (size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    // enqueue item to "back"
    public void enqueue(Item item) {
        Node oldLast = last;
        last = new Node();
        last.item = item;

        if(isEmpty()) {
            last.next = last;
        }
        else {
            last.next = oldLast.next;
            oldLast.next = last;
        }
        size++;
        opsCount++;
    }

    // dequeue item from "front"
    public Item dequeue() throws NoSuchElementException {
        if(isEmpty()){
            throw new NoSuchElementException("One Pointer Queue is empty");
        }

        Item item = last.next.item;
        if(size == 1){
            last = null;
        }
        else {
            last.next = last.next.next;
        }
        opsCount++;
        size--;
        return item;
    }

    // returns new Iterator<Item> that iterates over items
    @Override
    public Iterator<Item> iterator() {
        if(size == 0){
            throw new NoSuchElementException("Linked list is empty - can't iterate");
        }
        return new Iterator<Item>() {
            private Node current = last.next;
            int opsNow = opsCount;
            int hasIteratedAll = 0;

            public boolean hasNext() {
                if(opsNow!=opsCount){
                    throw new java.util.ConcurrentModificationException("Stack was modified");
                }
                if(hasIteratedAll == size){
                    return false;
                }
                else{
                    return true;
                }
            }

            public void remove() { /* not supported */ }

            public Item next() {
                Item item = current.item;
                current = current.next;
                hasIteratedAll++;
                return item;
            }
        };
    }

    // perform unit testing here
    public static void main(String[] args) {
        OnePointerQueue<Integer> opq = new OnePointerQueue<Integer>();
        opq.enqueue(6);
       // StdOut.println(opq.dequeue());
        opq.enqueue(5);
        //StdOut.println(opq.dequeue());
        //StdOut.println(opq.dequeue());
        //opq.enqueue(6);
        //opq.enqueue(7);
        //  StdOut.print(steque.pop() + "\n");
        // StdOut.print(steque.pop() + "\n");
        //StdOut.print(steque.isEmpty() + "\n");

        Iterator<Integer> i = opq.iterator();
        while(i.hasNext()) {
            Integer s = i.next();
            StdOut.println(s);
        }


    }
}
