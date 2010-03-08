/**
 * This list implementation is modelled after Google Go's container/list pkg.
 * http://golang.org/pkg/container/list/
 */

public class List  {
    private int len;
    private Node first;
    private Node last;

    /** Set len to zero */
    public List()
    {
        len = 0;
    }

    /** @return returns the first node in the list */
    public Node First() {
        return first;
    }

    /** @return returns the last node in the list */
    public Node Last() {
        return last;
    }

    /** @return returns true if list is empty  */
    public boolean IsEmpty() {
        if (len == 0)
            return true;
        return false;
    }

    /** @return returns the list's current lenght */
    public int Len() {
        return len;
    }

    /** Push adds a new node to the front of the list. */
    public void Push(int data) {
        Node node = newNode(null, null, data);
        if (IsEmpty()) {
            first = node;
            last = node;
            len++;
        } else {
            InsertBefore(node, first);
        }
    }

    /** Push adds a new node to the front of the list. */
    public void Push(Node node) {
        node.Next(null);
        node.Prev(null);
        if (IsEmpty()) {
            first = node;
            last = node;
            len++;
        } else {
            InsertBefore(node, first);
        }
    }

    public void PushLast(Node node) {
        node.Next(null);
        node.Prev(null);
        if (IsEmpty()) {
            first = node;
            last = node;
            len++;
        } else {
            InsertAfter(node, last);
        }
    }

    /** Retrieve the top node and remove it from the list */
    public Node Pop() {
        Node tmp = first;
        Remove(first);
        return tmp;
    }

    /** Remove a Node */
    public void Remove(Node node) {
        if (node.Prev() == null) {
            first = node.Next();
        } else {
            node.Prev().Next(node.Next());
        }
        if (node.Next() == null) {
            last = node.Prev();
        } else {
            node.Next().Prev(node.Prev());
        }
        //node.Next(null);
        //node.Prev(null);
        len--;
    }

    /** Move a node before the marker */
    public void Move(Node node, Node mark) {
        Remove(node);
        InsertBefore(node, mark);
    }

    /** Insert a new node after marked node in List. */
    public  void InsertAfter(int data, Node mark) {
        Node n = newNode(null, null, data);
        InsertAfter(n, mark);
    }

    /** Insert a new node before marked node in List. */
    public void InsertBefore(int data, Node mark) {
        Node n = newNode(null, null, data);
        InsertBefore(n, mark);
    }

    /** Insert the node after marked node. */
    public void InsertAfter(Node node, Node mark) {
        if (mark.Next() == null) {
            last = node;
        } else {
            mark.Next().Prev(node);
        }
        node.Next(mark.Next());
        node.Prev(mark);
        mark.Next(node);
        len++;
    }

    /** Insert the node before marked node. */
    public void InsertBefore(Node node, Node mark) {
        if (mark.Prev() == null) {
            first = node;
        } else {
            mark.Prev().Next(node);
        }
        node.Prev(mark.Prev());
        node.Next(mark);
        mark.Prev(node);
        len++;
    }

    public void Print() {
        Node head = first;
        System.out.print("NR:\t");
        for (int i = 1; i <= Len(); i++) {
            System.out.print("| " + i + " |\t");
        }
        System.out.println();
        for (int i = 1; i <= Len(); i++) {
            System.out.print("----------");
        }
        System.out.print("\nDATA:\t");
        while (head != null) {
            System.out.print("| "+ head.Data() + " |\t");
            head = head.Next();
        }
        System.out.println();
    }

    /** @return return a new node. */
    private Node newNode(Node next, Node prev, int data) {
        return new Node(next, prev, data);
    }
}
