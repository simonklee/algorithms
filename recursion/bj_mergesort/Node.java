public class Node {
    private Node prev;
    private Node next;
    private int data;
    
    public Node(Node next, Node prev, int data) {
        this.next = next;
        this.prev = prev;
        this.data = data;
    }
    
    public Node Next() {
        return next;
    }
    
    public Node Prev() {
        return prev;
    }
    
    public void Next(Node node) {
        next = node;
    }
    
    public void Prev(Node node) {
        prev = node;
    }
    
    public int Data() {
        return data;
    }
}
