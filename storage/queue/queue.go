package queue

// Queue structure.
type Q struct {
    queue *List
}

func NewQueue() *Q {
    q := new(Q)
    q.queue = NewList()
    return q
}

func (q *Q) IsEmpty() bool {
    return q.queue.IsEmpty()
}

func (q *Q) Insert(data int) {
    q.queue.InsertLast(data)
}

func (q *Q) Remove() int {
    return q.queue.DeleteFirst()
}

func (q *Q) Len() int {
    return q.queue.Len()
}


/*func (q *Queue) NewQueue() {
    q
}

type Queue interface {
    NewQueue() *Q
    IsEmpty() bool
    Insert(data int)
    Remove() int
    Len() int
}*/
