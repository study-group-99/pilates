package pilates

import (
	"embed"
	"fmt"
	"io/ioutil"
	"os"

	"github.com/leaanthony/clir"
)

const (
	libftDescription = "Install and run unit tests, benchmarks, linter check, makefile check.\n"

	libftInitDescription = "Generates the unit tests under default folder 'pilates' and two CMake files on root level. You can edit the tests but DO NOT rename or delete anything unless you know what you do. You can run 'pilates libft clean' to clean the generated files."
	libftInitForce       = "Forces files gerenation."
	libftInitDir         = "Custom directory name other than default 'pilates'."

	libftRunDescription = "Builds and runs unit tests.\n\nExamples:\n   # Run unit tests with benchmarks.\n   pilates libft -ub\n\n   # Run unit tests with linter and report.\n   pilates libft -ulr\n"
	libftRunUnit        = "Run unit tests. Cmake is necessary."
	libftRunCoverage    = "Print coverage for your library. Gcov is necessary."
	libftRunBenchmark   = "Run bernchamarks against your library. Cmake is necessary."
	libftRunMakefile    = "Checks 'Makefile' for compliance."
	libftRunLinter      = "Runs linter check. Norminette is necessary."
	libftRunReport      = "Generates a 'report.txt' with the results."
	libftRunBonus       = "Includes bonus functions in testing."

	libftCleanDescription = "Cleans your folder from 'pilates' generated files."
)

//go:embed libft/*
var libtTests embed.FS

func Cli() *clir.Cli {
	cli := clir.NewCli("pilates", "Ultimate Pilates Machine", "v0.0.1")
	libft(cli)
	// gnl(cli)
	return cli
}

func libft(cli *clir.Cli) {
	libft := cli.NewSubCommand("libft", libftDescription)
	libftInit(libft)
	libftRun(libft)
	libftClean(libft)
}

func libftInit(libft *clir.Command) {
	libftInit := libft.NewSubCommand("init", libftInitDescription)
	var forceInitFlag bool
	libftInit.BoolFlag("force", "f", libftInitForce, &forceInitFlag)
	var path string
	libftInit.StringFlag("dir", "d", libftInitDir, &path)
	libftInit.Action(func() error {

		if path == "" {
			path = "pilates"
		}
		_, err := os.Stat(path)
		if !os.IsNotExist(err) && !forceInitFlag {
			return fmt.Errorf("directory %s already exists. If know what you are doing try the -f, --force option", path)
		}

		os.Mkdir("./pilates", 0744)
		dir, err := libtTests.ReadDir("libft")
		if err != nil {
			return err
		}

		for _, file := range dir {
			data, err := libtTests.ReadFile(fmt.Sprintf("libft/%s", file.Name()))
			if err != nil {
				return err
			}

			if file.Name() == "CMakeLists.txt.test" {
				err = ioutil.WriteFile(fmt.Sprintf("%s", "CMakeLists.txt"), data, 0744)
				if err != nil {
					return err
				}
				continue
			}

			err = ioutil.WriteFile(fmt.Sprintf("%s/%s", path, file.Name()), data, 0744)
			if err != nil {
				return err
			}
		}
		return nil
	})
}

func libftRun(libft *clir.Command) {
	libftRun := libft.NewSubCommand("run", libftRunDescription)
	var unit bool
	libftRun.BoolFlag("unit", "u", libftRunUnit, &unit)
	var coverage bool
	libftRun.BoolFlag("coverage", "c", libftRunCoverage, &coverage)
	var bench bool
	libftRun.BoolFlag("benchmark", "b", libftRunBenchmark, &bench)
	var makefile bool
	libftRun.BoolFlag("makefile", "m", libftRunMakefile, &makefile)
	var linter bool
	libftRun.BoolFlag("linter", "l", libftRunLinter, &linter)
	var report bool
	libftRun.BoolFlag("report", "r", libftRunReport, &report)
	var bonus bool
	libftRun.BoolFlag("bonus", "", libftRunBonus, &bonus)
	libftRun.Action(func() error {
		if !unit && !coverage && !bench && !makefile && !linter && !report {
			return fmt.Errorf("error: must specify at least one flag\nrun 'pilates libft run -h' for help")
		}
		fmt.Println("Runinning tests")
		fmt.Println(unit)
		return nil
	})

}

func libftClean(libft *clir.Command) {
	libftClean := libft.NewSubCommand("clean", libftCleanDescription)
	libftClean.Action(func() error {
		fmt.Println("Clean folder")
		return nil
	})
}
