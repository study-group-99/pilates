package internal

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// NewExists checks for 'new' in ft_*.c + header
func NewExists() (bool, error) {
	var newPresense bool
	header, err := os.Open("libft.h")
	if err != nil {
		return false, err
	}

	defer header.Close()

	scanner := bufio.NewScanner(header)
	for scanner.Scan() {
		if strings.Contains(scanner.Text(), "*new") || strings.Contains(scanner.Text(), " new") ||
			strings.Contains(scanner.Text(), "\tnew") || strings.Contains(scanner.Text(), "!new") {
			fmt.Println("problem with init: function contaning 'new':", scanner.Text())
			newPresense = true
		}
	}

	return newPresense, nil
}
