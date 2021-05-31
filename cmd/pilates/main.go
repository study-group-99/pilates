package main

import (
	"fmt"

	"github.com/study-group-99/pilates"
)

func main() {
	if err := pilates.Cli().Run(); err != nil {
		fmt.Println(err)
	}
}
