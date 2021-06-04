package main

import (
	"fmt"

	"github.com/leaanthony/clir"
	"github.com/study-group-99/pilates"
)

func cli() *clir.Cli {
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.1")
	cli.Action(func() error {
		w := cli.OtherArgs()
		if len(w) == 0 {
			cli.PrintHelp()
			return nil
		}
		return fmt.Errorf(`error: unknown command %#q for %#q
Run '%[2]s --help' for usage`, w[0], cli.Name())
	})

	pilates.LibftCommand(cli)
	return cli
}

func main() {
	if err := cli().Run(); err != nil {
		fmt.Println(err)
	}
}
