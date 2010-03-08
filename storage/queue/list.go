package queue

//import "fmt"

// A typical node in a list. Knowing about it's ancestors and siblings.
type Node struct {
    next  *Node
    prev  *Node
    value int
}

// Find the node after this. Next is set to null if it's the last.
func (n *Node) nextNode() *Node {
    return n.next
}

// Find the node previous to this. Prev is set to null, if it's the first.
func (n *Node) prevNode() *Node {
    return n.prev
}

// Used to retrieve the data from within one node in a list.
func (n *Node) nodeValue() int {
    return n.value;
}

func newNode(next *Node, prev *Node, value int) *Node {
//    n := new(Node)
    return &Node{next, prev, value}
}

// A list struct with total nr of items, as well as the first and last.
type List struct {
    first *Node
    last  *Node
    len   int
}

// Used to clear all elements in a list structure, usually at init.
func (l *List) InitList() *List {
    l.first = nil
    l.last = nil
    l.len = 0
    return l
}

// Used to create a new list and set it to zero.
func NewList() *List {
    return new(List).InitList()
}

// Return the first node in a list or nil.
func (l *List) First() *Node{
    return l.first
}

// Return the last node in a list or nil.
func (l *List) Last() *Node{
    return l.last
}

// Find out if the list is empty.
func (l *List) IsEmpty() bool {
    if l.Len() == 0 {
        return true
    }
    return false
}

// Return the number of list items.
func (l *List) Len() int {
    return l.len
}

// Insert a Node at the end of the List.
func (l *List) InsertLast(data int) *Node {
    newNode := newNode(nil, l.last, data)

    if l.IsEmpty() {
        l.first = newNode
    } else {
        l.last.next = newNode
    }
    l.last = newNode
    l.len += 1
    return newNode
}

// Delete first item in the list, return the data.
func (l *List) DeleteFirst() int {
    tmp := l.first.nodeValue()

    // we only have one item in the list
    if l.first.next == nil {
        l.last = nil
    }

    // set the first node in the list to the next.
    l.first = l.first.next
    l.len -= 1
    return tmp
}

/*
func main() {
    var list *List
    list = NewList()
    if list.IsEmpty() {
        fmt.Print("is empty\n")
    }

    list.InsertLast(2)
    fmt.Printf("Last value: %d, len: %d\n", list.first.nodeValue(), list.Len())

    val := list.DeleteFirst()
    fmt.Printf("Last value was: %d, len: %d\n", val, list.Len())

    list.InsertLast(5)
    list.InsertLast(4)
    list.InsertLast(3)
    list.InsertLast(2)
    list.InsertLast(1)
    fmt.Printf("Last value: %d, len: %d\n", list.last.nodeValue(), list.Len())
    fmt.Printf("First value: %d, len: %d\n", list.first.nodeValue(), list.Len())

    list.DeleteFirst()
    fmt.Printf("Last value: %d, len: %d\n", list.last.nodeValue(), list.Len())
    fmt.Printf("First value: %d, len: %d\n", list.first.nodeValue(), list.Len())
}*/
