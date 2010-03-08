
public class SimpleList
{
    private class Node {
        public Node next;
        public int data;

        public Node(int data, Node next) {
            this.next = next;
            this.data = data;
        }
    }

    private Node head;

    public SimpleList() {

    }
}
