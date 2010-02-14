package main

import (
    "fmt"
)

func pow(x, y int) (int) {
    if y <= 1 {
        fmt.Printf("Base reached, returning x(%d)\n", x)
        return x
    }
    fmt.Printf("%d * %d == ", x, x)
    x *= x
    fmt.Printf("%d\n", x)
    return pow(x, y/2)
}

func main() {
    x := 2
    y := 4
    fmt.Printf("pow(%d, %d) == %d\n", x, y, pow(x, y))
}
