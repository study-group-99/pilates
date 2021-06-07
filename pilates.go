package pilates

import (
	"fmt"

	"github.com/leaanthony/clir"
)

func RootCommand(cli *clir.Cli) {
	// cli.LongDescription("Examples:\n   # Update the CLI\n   pilates -u\n\n   # Pilates c++ new moulinette\n   pilates --fix-new")
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
			return fmt.Errorf("WIP")
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
