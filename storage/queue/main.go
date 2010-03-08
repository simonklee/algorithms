package main

import (
    q "queue"
    "fmt"
)

func main() {
    //var tmp q.Queue
    this := q.NewQueue()

/*    queue.q.Insert(2)*/
    fmt.Printf("%d\n", this.Len())

    this.Insert(2)
    fmt.Printf("%d\n", this.Len())

    fmt.Printf("data: %d\n", this.Remove())
    fmt.Printf("%d\n", this.Len())
}
