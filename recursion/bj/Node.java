public class Node<T> {
    private Node prev;
    private Node next;
    private T data;
    
    public Node(Node next, Node prev, T data) {
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
    
    public T Data() {
        return data;
    }
}
