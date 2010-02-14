package main

import (
    "fmt"
)

func pow2(x, y int) (int) {
    if y == 0 {
        fmt.Printf("Base reached, returning x(%d)\n", x)
        return 1
    }
//  fmt.Printf("%d * %d == ", x, x)
//  fmt.Printf("%d\n", x)
    return (pow(x, y - 1) * x)
}

func pow(x, y int) (int) {
    if y == 1 {
//      fmt.Printf("Base reached, returning x(%d)\n", x)
        return x 
    }
//  fmt.Printf("%d * %d == ", x, x)
    x *= x
//  fmt.Printf("%d\n", x)
    return pow(x, y/2)
}

func main() {
    x := 2
    y := 8
    fmt.Printf("pow2(%d, %x) == %d\n", x, y, pow2(x, y))
    fmt.Printf("pow(%d, %x) == %d\n", x, y, pow(x, y))
 
}
