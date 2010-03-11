
public class Tree {   
    private Node tree;
    
    public Tree() {
        
        
        // insert some testdata.
        insert(10);
        insert(5);
        insert(15);
        insert(2);
        insert(3);
        insert(7);
        insert(8);
        insert(20);
        insert(30);
        insert(11);
        insert(16);
        insert(13);
        insert(4);
        insert(1);
    }
    
    /**
     * @param Integer value searched for.
     * @return The node with the key searched for or null.
     */
    public Node find(int key) {
        return findKey(key, tree);
    }
    
    /**
     * @param Integer value searched for.
     * @param The parent Node to search within. 
     * @return The node with the key searched for or null.
     */
    private Node findKey (int key, Node root) {
        
        if (root == null)
            return null; // Not Found.
        
        else if (key < root.getKey()) // Go left.
            return findKey(key, root.getLeft());
        
        else if (key > root.getKey()) // Go right.
            return findKey(key, root.getRight());
        
        return root; // success
    }
    
    /**
     * Display the tree in ascending order.
     */
    public void displayAsc() {
        inOrder(tree);
    }

    /**
    * Recursivly traverse the tree in ascending order.
    */
    private void inOrder(Node root) {
        if (root != null) {
            inOrder(root.getLeft());
            System.out.println(root.getKey() + "\\");
            inOrder(root.getRight());
        }
    }
    
    /**
     * @param Insert a key value into the tree.
     */
    public void insert(int key) {
        if (tree == null) 
            tree = newNode(key);
        else {
            Node current = tree;
            Node root = current;
            insertKey(key, root, current);
        }
    }
    
    /**
     * Will traverse a root tree untill it finds the correct null-value,
     * in which case it will connect the new node to the null-value's 
     * parent. 
     *
     * @param key Integer value to insert.
     * @param root The parent Node to insert in.
     * @param current The current position of our insertion routine.
     * @return when the correct location is fund, it will return null. 
     */
    private Node insertKey(int key, Node root, Node current) {
        if (current == null) {
            return null;
        }
        root = current;        
        if (key < current.getKey()) {
            if (insertKey(key, root, current.getLeft()) == null)
                root.setLeft(newNode(key));
        } else {
            if (insertKey(key, root, current.getRight()) == null)
                root.setRight(newNode(key));        
        }
        return root;
    }
    
    /**
     * Create a new node.
     * @return Node newly created node.
     */
    private Node newNode(int key) {
        return new Node(key);
    }
    
    /**
     * Not implemented yet.
     */
    public void delete(int key) {}
    
    private Node successor(Node root) {
        Node succ = findMin(root.getRight());
        return succ;
    }
    
    /**
     * Find the minimum value in a binary tree. 
     * @return Node Minium valued note on the left flank.
     */
    public Node min() {
        return findMin(tree);
    }
        
    /**
     * Traverse the left-most sided nodes until null is reached, then 
     * return the root of that null value.
     * @return Node Minium valued note on the left flank.
     */
    private Node findMin(Node root) {
        if (root.getLeft() == null)    
            return root;
        return findMin(root.getLeft()); 
    }
    
     /**
     * Find the maxium value in a binary tree. 
     * @return Node Maxium valued note on the right flank.
     */
    public Node max() {
        return findMax(tree);
    }
        
    /**
     * Traverse the right-most sided nodes until null is reached, then 
     * return the root of that null value.
     * @return Node Maxium valued note on the right flank.
     */
    private Node findMax(Node root) {
        if (root.getRight() == null)    
            return root;
        return findMax(root.getRight()); 
    }    
}
