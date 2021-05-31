package pilates

import (
	"fmt"

	"github.com/leaanthony/clir"
)

func customBanner(cli *clir.Cli) string {

	return ` ██████╗ ██╗██╗      █████╗ ████████╗███████╗███████╗
 ██╔══██╗██║██║     ██╔══██╗╚══██╔══╝██╔════╝██╔════╝
 ██████╔╝██║██║     ███████║   ██║   █████╗  ███████╗
 ██║     ██║███████╗██║  ██║   ██║   ███████╗███████║
     ` + cli.Version() + " - " + cli.ShortDescription()
}

func R() *clir.Cli {
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.1")
	cli.SetBannerFunction(customBanner)
	// Define action
	cli.Action(func() error {
		w := cli.OtherArgs()
		if len(w) != 0 {
			return fmt.Errorf("unknown command %q for %s\nRun '%[2]s --help' for usage", w[0], cli.Name())
		}
		return nil
	})

	libft := cli.NewSubCommand("libft", "Suspendisse fringilla diam vitae erat ultricies, eget accumsan arcu tempor. In turpis dolor, venenatis non enim ut, molestie ullamcorper nibh.\n")

	libftInit := libft.NewSubCommand("init", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent vestibulum dictum nisl a condimentum. Aenean consectetur metus id commodo vestibulum.\n")
	var forceInitFlag bool
	libftInit.BoolFlag("force", "f", "Force project blah blah sdfgiosgm sdfioiosd sdfiosad gt eqw uidsf dsf ewi.", &forceInitFlag)
	var lol bool
	libftInit.BoolFlag("lol", "l", "lololololololololololol.\n", &lol)
	libftInit.Action(func() error {
		fmt.Println("libft init")
		fmt.Println(forceInitFlag)
		fmt.Println(lol)
		return nil
	})

	libftRun := libft.NewSubCommand("run", "Praesent maximus ullamcorper justo ac euismod. Vestibulum vitae placerat diam. Nulla vehicula orci eu porta eleifend. Sed blandit purus ligula. Nunc arcu metus, vehicula sit amet finibus vitae, faucibus ac nisi.\n")
	libftRun.Action(func() error {
		fmt.Println("libft test")
		return nil
	})

	return cli
}
