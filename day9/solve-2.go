package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func moveBlock(i int, blocks_index []int, block_size []int, spaces map[int]int) {
	is_movable := false
	old_i := -1
	old_s := 1000
	for i_s, s_s := range spaces {
		if i_s < blocks_index[i] {
			if s_s >= block_size[i] {
				blocks_index[i] = i_s
				is_movable = true
				old_i = i_s
				old_s = s_s
				break
			}
		}
	}
	if is_movable {
		spaces[old_i+block_size[i]] = old_s - block_size[i]
		spaces[old_i] = -1
	}
}

func solve2() {
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

	block_size := []int{}
	blocks_index := []int{}
	spaces := make(map[int]int)
	index := 0
	for i, s := range line {
		s = s - '0'
		if i%2 == 0 {
			block_size = append(block_size, int(s))
			blocks_index = append(blocks_index, index)
			for k := 0; k < int(s); k++ {
				index++
			}
		} else {
			spaces[index] = int(s)
			for k := 0; k < int(s); k++ {
				index++
			}
		}
	}

	for i := len(block_size) - 1; i >= 0; i-- {
		moveBlock(i, blocks_index, block_size, spaces)
	}

	sum := 0
	for b := 1; b < len(block_size); b++ {
		for b_i := blocks_index[b]; b_i < blocks_index[b]+block_size[b]; b_i++ {
			sum += b * b_i
		}
	}
	fmt.Println(sum)
}
