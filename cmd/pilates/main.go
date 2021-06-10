package main

import (
	"fmt"

	"github.com/bh90210/clir"
	"github.com/study-group-99/pilates"
)

func main() {
	// start a new cli
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.9")
	// register subcommands
	pilates.RootCommand(cli)
	pilates.LibftCommand(cli)
	// run the app
	if err := cli.Run(); err != nil {
		fmt.Println(err)
	}
}
