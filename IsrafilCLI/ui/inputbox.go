package ui

import (
	"bufio"
	"io"
	//	"fmt"
	"log"
	"os"
)

func GetInput() string {
	fi, err := os.Open("input.txt")
	if err != nil {
		log.Fatalf("Error: %s\n", err)
		return ""
	}
	defer fi.Close()

	br := bufio.NewReader(fi)
	a, _, c := br.ReadLine()
	if c == io.EOF {
		log.Fatal("Empty input.txt file!")
	}
	log.Printf("Input: %s", string(a))
	return string(a)
}
