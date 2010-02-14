package main

import (
    "flag"
    "os"
    "fmt"
    "strconv"
)

var count int
var current int
var width int

func factorial(n int) (int){
    current := count - (n - 1)
    fmt.Printf("call nr. %d to fac\n", current)
    if n == 0 {
        fmt.Printf("BASE\n")
        fmt.Printf("n is 1 at call nr. %d \n", current)
        return 1
    }
    x := (n * factorial(n - 1))
    fmt.Printf("n is %d at call nr. %d\n", n, current)
    return x
}

func factorial2(n int) (int){
    d := false
    for i := 0; i < width; i++ {
        if i >= (width - count) {
            fmt.Printf("*")
        } else {
            fmt.Printf(" ")
        }
        if n == 0 && !d {
            s := "BASE"
            fmt.Printf(s)
            i += len(s)
            d = true
        }
        if i == width - 1 {
            fmt.Printf(" %d", count)
        }
    }
    if n == 0 {
        fmt.Printf("\n")
        return 1
    }

    fmt.Printf("\n")
    count -= 1

    x := (n * factorial2(n - 1))

    count += 1
    for i := 0; i < width; i++ {
        if i >= (width - count) {
            fmt.Printf("*")
        } else {
            fmt.Printf(" ")
        }
        if i == width - 1 { fmt.Printf(" %d", count) }
    }
    fmt.Printf("\n")
    return x
}

func main() {
	flag.Parse()
    if flag.NArg() != 1 {
        os.Stdout.WriteString("Missing arguments\n");
        os.Exit(1)
    }
    n, err := strconv.Atoi(flag.Arg(0))
    if err != nil {
        os.Stdout.WriteString("Conversion failed\n");
        os.Exit(1)
    }
    count = n +1
    width = n +1
    fmt.Printf("Result: %d\n", factorial2(n));
}
