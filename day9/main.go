package main

import (
    "fmt"
    "os"
)

func main() {
    if len(os.Args) < 2 {
        fmt.Println("Please specify '1' or '2' as a command-line argument.")
        os.Exit(1)
    }

    switch os.Args[1] {
    case "1":
        solve1()
    case "2":
        solve2()
    default:
        fmt.Println("Invalid argument. Please specify '1' or '2'.")
        os.Exit(1)
    }
}

