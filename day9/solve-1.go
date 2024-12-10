package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func solve1() {
	file, err := os.Open("in")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	var line string
	if scanner.Scan() {
		line = scanner.Text()
	}

	A := []int{}
	for i, j := range line {
		j = j - '0'
		if i%2 == 0 {
			val := i / 2
			for k := 0; k < int(j); k++ {
				A = append(A, val)
			}
		} else {
			for k := 0; k < int(j); k++ {
				A = append(A, 0)
			}
		}
	}

	N := len(A)

	sum := 0
	l := int(line[0] - '0')
	r := N - 1

	for l <= r {
		if A[l] == 0 {
			for A[r] == 0 && l <= r {
				r--
			}
			if l > r {
				break
			}
			sum += A[r] * l
			l++
			r--
		} else {
			sum += A[l] * l
			l++
		}
	}

	fmt.Println(sum)
}
