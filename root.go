package pilates

import (
	"fmt"

	"github.com/bh90210/clir"
)

func RootCommand(cli *clir.Cli) {
	cli.LongDescription("pilates is an educational devops tool designed to help you along you curriculum.")
	var version bool
	cli.BoolFlag("version", "v", "Pilates CLI version.", &version)
	var update bool
	cli.BoolFlag("update", "u", "Update Pilates to the latest version.", &update)
	cli.Action(func() error {
		switch {
		case version && update:
			return fmt.Errorf("select only one option. Either -u, --update or -v, --version")
		case version:
			fmt.Println(cli.Name(), "version", cli.Version())
			return nil
		case update:
			return fmt.Errorf("WIP. We need your help implementing the update function! go to https://github.com/study-group-99/pilates/discussions for more information.")
		}

		w := cli.OtherArgs()
		if len(w) == 0 {
			cli.PrintHelp()
			return nil
		}
		return fmt.Errorf(`error: unknown command %#q for %#q
Run '%[2]s --help' for usage`, w[0], cli.Name())
	})
}
