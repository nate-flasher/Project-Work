import java.util.Iterator;
import java.util.Random;

public class LinkedList<Item extends Comparable<Item>> implements Iterable<Item> {
    private Node first = null;
    private int count = 0;

    private class Node {
        final Item item;    // cannot change item once it is set in constructor
        Node next;          // can change next, though

        public Node(Item i, Node n) {
            item = i;
            next = n;
        }
    }

    public LinkedList() { }

    public LinkedList(Item[] fromList) {
        for(Item item : fromList) insert(item);
    }

    public void insert(Item item) {
        first = new Node(item, first);
        count++;
    }

    public Item remove() {
        Item item = first.item;
        first = first.next;
        count--;
        return item;
    }

    public boolean isEmpty() { return count == 0; }

    public Iterator<Item> iterator() {
        return new Iterator<Item>() {
            Node current = first;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public Item next() {
                Item item = current.item;
                current = current.next;
                return item;
            }
        };
    }

    public Node merge(Node run1first, Node run1end, Node run2first, Node run2end){
        Node last = null;
        Node newFirst = null;
        while (run1first != null && run2first != null) {
            if (run1first.item.compareTo(run2first.item) > 0) {
                if(newFirst == null && last == null){
                    newFirst = run2first;
                    last = run2first;
                    run2first = run2first.next;
                    last.next = null;
                }
                else {
                    last.next = run2first;
                    last = run2first;
                    run2first = run2first.next;
                    last.next = null;
                }
            } else {
                if(newFirst == null && last == null){
                    newFirst = run1first;
                    last = run1first;
                    run1first = run1first.next;
                    last.next = null;
                }
                else{
                    last.next = run1first;
                    last = run1first;
                    run1first = run1first.next;
                    last.next = null;
                }

            }

        }
        if(run1first == null){
            last.next = run2first;
        }
        if(run2first == null){
            last.next = run1first;
        }
        return newFirst;
    }
    /***********************************************************************
     * Rearranges the linked list in ascending order, using the natural order
     * and mergesort.
     ***********************************************************************/
    
    public void sort() {
        Node current = first;
        Node run1first = current;
        Node run1end = current;
        Node run2first = current;
        Node run2end = current;
        Node newRun1first;
        Node mergedEnd = null;
        if (first == null){
            return;
        }
        int count = 0;
        while(first != null) {
            if(count == 0 && current == null) {
                return;
            }
            if(current == null){
                current = first;
                count = 0;
            }
            run1first = current;
            run1end = current;
            while (current.next != null && current.item.compareTo(current.next.item) <= 0) {
                current = current.next;
                run1end = current;
            }
            newRun1first = current.next;
            current = newRun1first;
            run2first = current;
            run2end = current;
            if(current == null){
                continue;
            }
            while (current.next != null && current.item.compareTo(current.next.item) <= 0) {
                current = current.next;
                run2end = current;
            }
            current = current.next;
            run1end.next = null;
            run2end.next = null;

            Node mergedStart = merge(run1first, run1end, run2first, run2end);

            if (count == 0) { //our first time merging
                first = mergedStart;

                mergedEnd = mergedStart;
                while (mergedEnd.next != null) {
                    mergedEnd = mergedEnd.next;
                }
                mergedEnd.next = current; //link post unMerged list with new merged list end
                count++;
            } else {
                mergedEnd.next = mergedStart;
                mergedEnd = mergedStart;
                while (mergedEnd.next != null) {
                    mergedEnd = mergedEnd.next;
                }

                //mergedEnd.next = mergedStart; //link preMerged list with new merged list beginning


                mergedEnd.next = current; //link post unMerged list with new merged list end

                count++;
            }
        }
    }

    /***********************************************************************
     *  main() function
     *  Place all of your unit tests here
     *  Hint: created additional functions to help organize your tests
     ***********************************************************************/

    public static void main(String[] args) {
        //Double[] a = {1.2, 2.0, 4.8, 7.9, 7.4};
        LinkedList<Double> linkedlist = new LinkedList<>();
        Random randNum = new Random();
        for (int i=0; i < 2048000; i++){
            linkedlist.insert(randNum.nextDouble());
        }
        /*
        linkedlist.insert(6.0);
        linkedlist.insert(10.0);
        linkedlist.insert(7.0);
        linkedlist.insert(12.0);
        linkedlist.insert(8.0);

         */

/*
        linkedlist.insert(12.0);
        linkedlist.insert(10.0);
        linkedlist.insert(8.0);
        linkedlist.insert(7.0);
        linkedlist.insert(6.0);

 */

        Stopwatch stopwatch = new Stopwatch();
        linkedlist.sort();
        double time = stopwatch.elapsedTime();
        StdOut.println("Elapsed time = " + time + "\n");


/*
        for(Double d: linkedlist){
            StdOut.print(d + " ");
        }

 */
    }
}
