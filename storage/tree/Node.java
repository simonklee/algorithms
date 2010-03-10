

public class Node
{
    private Node left;
    private Node right;
    private int key;
    
    public Node(int key) {
        this.key = key;
        left = null;
        right = null;
    }

    public Node(int key, Node left, Node right) {
        this.key = key;
        this.left = left;
        this.right = right;
    }
    
    // Set and get methods.
    public void setLeft(Node left) {this.left = left;}
    public void setRight(Node right) {this.right = right;}
    public void setKey(int key) {this.key = key;}
    public Node getLeft() {return left;}
    public Node getRight() {return right;}
    public int getKey() {return key;}
}

