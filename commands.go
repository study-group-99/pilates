package pilates

import (
	"embed"
	"fmt"

	"github.com/leaanthony/clir"
)

func customBanner(cli *clir.Cli) string {
	return fmt.Sprintf(`%s %s - %s`, cli.Name(), cli.Version(), cli.ShortDescription())
}

//go:embed libft/*
var libtFiles embed.FS

func Cli() *clir.Cli {
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.1")
	cli.SetBannerFunction(customBanner)

	libft := cli.NewSubCommand("libft", "Install and run unit tests, benchmarks, linter check, makefile check.\n")

	libftInit := libft.NewSubCommand("init", "Generates the unit tests under default folder 'pilates'.")
	var forceInitFlag bool
	libft.BoolFlag("force", "f", "Forces files gerenation.", &forceInitFlag)
	var path string
	libftInit.StringFlag("dir", "d", "Custom directory name for generation of tests.", &path)
	libftInit.Action(func() error {
		fmt.Println("Creating folder")
		fmt.Println("Generating tests")
		file, _ := libtFiles.ReadFile("libft/CMakeLists.txt")
		print(string(file))
		return nil
	})

	libftRun := libft.NewSubCommand("run", "Builds and runs unit tests.\n\nExamples:\n   # Run unit tests with benchmarks.\n   pilates libft -ub\n\n   # Run unit with linter and report.\n   pilates libft -ulr\n")
	var unit bool
	libftRun.BoolFlag("unit", "u", "Run unit tests. Cmake is necessary.", &unit)
	var coverage bool
	libftRun.BoolFlag("coverage", "c", "Print coverage for your library. Gcov is necessary.", &coverage)
	var bench bool
	libftRun.BoolFlag("benchmark", "b", "Run bernchamarks against your library. Cmake is necessary.", &bench)
	var makefile bool
	libftRun.BoolFlag("makefile", "m", "Checks 'Makefile' for compliance.", &makefile)
	var linter bool
	libftRun.BoolFlag("linter", "l", "Runs linter check. Norminette is necessary.", &linter)
	var report bool
	libftRun.BoolFlag("report", "r", "Generates a 'report.txt' with the results.", &report)
	var bonus bool
	libftRun.BoolFlag("bonus", "", "Includes bonus functions in testing.", &bonus)
	libftRun.Action(func() error {
		if !unit && !coverage && !bench && !makefile && !linter && !report {
			return fmt.Errorf("error: must specify at least one flag\nrun 'pilates libft run -h' for help")
		}
		fmt.Println("Runinning tests")
		fmt.Println(unit)
		return nil
	})

	libftClean := libft.NewSubCommand("clean", "Cleans your folder from 'pilates' generated files.")
	libftClean.Action(func() error {
		fmt.Println("Clean folder")
		return nil
	})

	return cli
}
