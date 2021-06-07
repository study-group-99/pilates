package main

import (
	"fmt"

	"github.com/leaanthony/clir"
	"github.com/study-group-99/pilates"
)

func cli() *clir.Cli {
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.2")
	pilates.RootCommand(cli)
	pilates.LibftCommand(cli)
	return cli
}

func main() {
	if err := cli().Run(); err != nil {
		fmt.Println(err)
	}
}
