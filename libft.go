package pilates

import (
	"bufio"
	"embed"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"os/exec"
	"regexp"
	"strings"

	"github.com/leaanthony/clir"
	"github.com/leaanthony/spinner"
)

const (
	libftDescription     = "Install and run unit tests, benchmarks, norm check, makefile check & memory leaks checks."
	libftLongDescription = "\nExamples:\n   # Init pilates for your libft.\n   pilates libft init\n\n   # Run unit tests and generate a report.\n   pilates libft run --unit --report"

	libftInitDescription     = "Generates the unit tests under default folder 'pilates', two CMake files on root level and a .gitignore. You can edit the tests but DO NOT rename or delete anything unless you know what you are doing."
	libftInitLongDescription = "\nExamples:\n   # Run init\n   pilates libft init\n\n   # Run init with -f, --force option\n   pilates libft init -f"
	libftInitForce           = "Forces files gerenation."
	libftInitError           = `initialization is not complete!

pilates detected the usage of parameter name 'new' in the above functions.
Our unit testing is written in C++ thus keyword 'new' can not be be used as argument name.
Changing the above lines and equivalent functions is OK with Moulinette.

If you try to run the tests anyway you will get an error. Please change 'new' to 'n' or anything else.
pilates can do this for you automagically by passing the '--fix-new' option like so 'pilates libft init --fix-new'
	
https://stackoverflow.com/questions/20653245/error-in-compiling-c-code-with-variable-name-new-with-g
`

	libftRunDescription     = "Runs tests with the options provided via flags. You need to include at least one (-r, --report flag not included)."
	libftRunLongDescription = "\nExamples:\n   # Run unit tests with benchmarks.\n   pilates libft run -ub\n\n   # Run unit tests with linter test and generates a report.\n   pilates libft run -ulr\n\n   # Pass verbose options.\n   pilates libft run --unit --norm"
	libftRunAll             = "Runs all tests."
	libftRunUnit            = "Runs unit tests. Cmake is necessary."
	libftRunCoverage        = "Prints coverage for your library. Gcov is necessary."
	libftRunBenchmark       = "Runs bernchamarks against your library. Cmake is necessary."
	libftRunMakefile        = "Checks 'Makefile' for compliance."
	libftRunNorm            = "Runs linter checks. Norminette is necessary."
	libftRunLeaks           = "Runs memory leaks tests. Valgrind is necessary."
	libftRunReport          = "Generates a 'report.txt' with the results."
)

//go:embed libft/*
var libftTests embed.FS

type libft struct {
	*clir.Command
}

// LibftCommand takes a *clir.Cli argument and setsup 'libft' subcommand.
func LibftCommand(cli *clir.Cli) {
	libft := &libft{cli.NewSubCommand("libft", libftDescription)}
	libft.LongDescription(libftLongDescription)

	// pilates libft subcommands
	libft.init()
	libft.run()
}

func (l *libft) init() {
	init := l.NewSubCommand("init", libftInitDescription)
	init.LongDescription(libftInitLongDescription)

	// pilates libft init --flags
	var forceInit bool
	init.BoolFlag("force", "f", libftInitForce, &forceInit)
	var fixNew bool
	init.BoolFlag("fix-new", "", "If your 'libft.h' contains any parameter named 'new' this option will change it to 'n' along with the corresponding 'ft_*.c' file.", &fixNew)

	init.Action(func() error {
		var path string = "pilates"
		switch {
		case forceInit && fixNew:
			return fmt.Errorf("the --fix-new option is indented to be used alone")
		case fixNew:
			fmt.Println("checking your libft.h")
			header, err := os.OpenFile("libft.h", os.O_APPEND, os.ModeAppend)
			if err != nil {
				return err
			}

			changeLines := make([]string, 0)
			scanner := bufio.NewScanner(header)
			for scanner.Scan() {
				if strings.Contains(scanner.Text(), " new") || strings.Contains(scanner.Text(), "*new") ||
					strings.Contains(scanner.Text(), "\tnew") {
					fmt.Println("found function", scanner.Text())
					changeLines = append(changeLines, scanner.Text())
				}
			}

			header.Close()

			if len(changeLines) == 0 {
				return fmt.Errorf("found no 'new' use. nothing to be done all clean")
			}

			changeLines = append(changeLines, "libft.h")

			fmt.Println("\"cleaning\" your files")
			for _, v := range changeLines {
				var name string
				// extract function's name
				if v == "libft.h" {
					name = "libft.h"
				} else {
					// create a regular expresion to retrieve the name of the function
					// in the form 'ft_some_function('
					r := regexp.MustCompile(`([a-zA-Z]+(_[a-zA-Z]+)+)\(`)
					// actually run the regex query then trim the '(' on the right and append a '.c' to the name
					name = fmt.Sprintf("%s.c", strings.TrimRight(r.FindAllString(v, -1)[0], "("))
				}
				// open file
				ft, err := ioutil.ReadFile(name)
				if err != nil {
					return err
				}
				// replace 'new'
				new := strings.ReplaceAll(string(ft), " new", " n")
				new = strings.ReplaceAll(new, "*new", "*n")
				new = strings.ReplaceAll(new, "\tnew", "\tn")
				// write it
				err = ioutil.WriteFile(name, []byte(new), 0)
				if err != nil {
					return err
				}
				fmt.Println(name, "done.")
			}

			fmt.Println("All done! Now you can run 'pilates libft run -u'")
			return nil
		}

		// check if folder pilates exists
		_, err := os.Stat(path)
		if !os.IsNotExist(err) && !forceInit {
			return fmt.Errorf("directory %s already exists. If know what you are doing try the -f, --force option", path)
		}

		fmt.Println("pilates initialization")

		// if not, or if -f option is used create it
		os.Mkdir(path, 0744)
		dir, err := libftTests.ReadDir("libft")
		if err != nil {
			return err
		}

		for _, file := range dir {
			data, err := libftTests.ReadFile(fmt.Sprintf("libft/%s", file.Name()))
			if err != nil {
				return err
			}

			if file.Name() == "CMakeLists.txt.test" {
				err = ioutil.WriteFile(fmt.Sprintf("%s/%s", path, "CMakeLists.txt"), data, 0755)
				if err != nil {
					return err
				}
				continue
			}

			if file.Name() == "CMakeLists.txt" || file.Name() == "CMakeLists.txt.in" {
				err = ioutil.WriteFile(file.Name(), data, 0755)
				if err != nil {
					return err
				}
				continue
			}

			if file.Name() == "gitignore" {
				// check if .gitignore is already present
				_, err := os.Stat(".gitignore")
				// if not create one
				if os.IsNotExist(err) {
					err = ioutil.WriteFile(".gitignore", data, 0755)
					if err != nil {
						return err
					}
					continue
				}

				// if it exists open it check if what we want to exclude is already present
				// if not append it.
				gitignore, err := os.OpenFile(".gitignore", os.O_APPEND|os.O_RDWR, os.ModeAppend)
				if err != nil {
					return err
				}
				ignoreList := []string{"build", "pilates", "*.txt", "*.in", "*.cpp"}
			appendNext:
				for _, key := range ignoreList {

					scanner := bufio.NewScanner(gitignore)
					// check in existing .gitignore if key exists
					for !scanner.Scan() || strings.Contains(scanner.Text(), key) {
						// if yes continue to next key
						continue appendNext
					}

					// if not append it
					if _, err := gitignore.WriteString(fmt.Sprintf("%s\n", key)); err != nil {
						return err
					}
				}

				if err := gitignore.Close(); err != nil {
					return err
				}

				continue
			}

			err = ioutil.WriteFile(fmt.Sprintf("%s/%s", path, file.Name()), data, 0755)
			if err != nil {
				return err
			}
		}

		// check for 'new' in header
		newPresense, err := newExists()
		if err != nil {
			return err
		}
		if newPresense {
			return fmt.Errorf(libftInitError)
		}

		fmt.Println("Ready!")
		return nil
	})
}

func (l *libft) run() {
	run := l.NewSubCommand("run", libftRunDescription)
	run.LongDescription(libftRunLongDescription)

	// pilates libft run --flags
	var all bool
	run.BoolFlag("all", "a", libftRunAll, &all)
	var unit bool
	run.BoolFlag("unit", "u", libftRunUnit, &unit)
	var coverage bool
	run.BoolFlag("coverage", "c", libftRunCoverage, &coverage)
	var bench bool
	run.BoolFlag("benchmark", "b", libftRunBenchmark, &bench)
	var makefile bool
	run.BoolFlag("makefile", "m", libftRunMakefile, &makefile)
	var norm bool
	run.BoolFlag("norm", "n", libftRunNorm, &norm)
	var leaks bool
	run.BoolFlag("leaks", "l", libftRunLeaks, &leaks)
	var report bool
	run.BoolFlag("report", "r", libftRunReport, &report)

	run.Action(func() error {

		// check for 'new' in header
		newPresense, err := newExists()
		if err != nil {
			return err
		}

		if newPresense {
			return fmt.Errorf(libftInitError)
		}

		// if --all flag is used set true every other var/flag
		switch {
		case all:
			unit = true
			coverage = true
			bench = true
			leaks = true
			makefile = true
			norm = true
		// if no flags are used return error
		case !unit && !coverage && !bench && !leaks && !makefile && !norm:
			return fmt.Errorf("error: must specify at least one flag\nrun 'pilates libft run -h' for help")
		}

		var file *os.File
		if report {
			file, err = os.Create("report.txt")
			if err != nil {
				fmt.Printf("error: %s\n", err)
			}

			defer file.Close()
			defer fmt.Println("generated report file 'report.txt' successfully.")
		}

		if unit {
			cmd := exec.Command("cmake", "-S", ".", "-B", "build", "--", "-j", "20")
			genSpinner := spinner.New("Generating build")
			genSpinner.Start()
			cmd.Env = os.Environ()
			cmd.Stderr = os.Stderr
			if err := cmd.Run(); err != nil {
				fmt.Printf("error: %s\n", err)
			}
			genSpinner.Success()

			cmd = exec.Command("cmake", "--build", "build", "--", "-j", "20")
			buildSpinner := spinner.New("Building C++ files")
			buildSpinner.Start()
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				fmt.Printf("error: %s\n", err)
			}
			buildSpinner.Success()

			os.Chdir("build")
			cmd = exec.Command("ctest", "--output-on-failure")
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if report {
				cmd.Stdout = io.MultiWriter(os.Stdout, file)
			} else {
				cmd.Stdout = os.Stdout
			}
			if err := cmd.Run(); err != nil {
				fmt.Printf("error: %s\n", err)
			}
			os.Chdir("..")
		}

		if norm {
			cmd := exec.Command("norminette")
			cmd.Args = append(cmd.Args, "libft.h")
			dir, err := os.ReadDir("./")
			if err != nil {
				return err
			}

			for _, file := range dir {
				if strings.Contains(file.Name(), "ft_") {
					cmd.Args = append(cmd.Args, file.Name())
				}
			}
			cmd.Stdout = os.Stdout
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if report {
				cmd.Stdout = io.MultiWriter(os.Stdout, file)
			} else {
				cmd.Stdout = os.Stdout
			}
			if err := cmd.Run(); err != nil {
				fmt.Printf("error: %s\n", err)
			}
		}

		if makefile {
			fmt.Println("makefile checks")
			makeVariations := []string{"all", "clean", "libft.a", "re", "fclean", "bonus"}
			for _, val := range makeVariations {
				cmd := exec.Command("make", val)
				fmt.Printf("make: %s\n", val)
				cmd.Env = os.Environ()
				if report {
					file.WriteString(fmt.Sprintf("make: %s\n", val))
					cmd.Stderr = io.MultiWriter(os.Stderr, file)
				} else {
					cmd.Stderr = os.Stderr
				}
				if err := cmd.Run(); err != nil {
					fmt.Printf("error: %s\n", err)
				} else {
					fmt.Printf("make: %s - Passed\n", val)
					file.WriteString(fmt.Sprintf("make: %s - Passed\n", val))
				}
			}

			// clean everything in the end
			cmd := exec.Command("make", "fclean")
			cmd.Run()
		}

		if leaks || bench {
			fmt.Println("WIP. We need your help implementing memory leaks and benchmarks! go to https://github.com/study-group-99/pilates/discussions for more information.")
		}

		if coverage {
			cmd := exec.Command("gcovr", "--exclude", "'.*test.*'", "--root", ".")
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if report {
				cmd.Stdout = io.MultiWriter(os.Stdout, file)
			} else {
				cmd.Stdout = os.Stdout
			}
			if err := cmd.Run(); err != nil {
				fmt.Printf("error: %s\n", err)
			}
		}

		return nil
	})
}

// check for 'new' in ft_*.c + header
func newExists() (bool, error) {
	var newPresense bool
	header, err := os.Open("libft.h")
	if err != nil {
		return false, err
	}

	defer header.Close()

	scanner := bufio.NewScanner(header)
	for scanner.Scan() {
		if strings.Contains(scanner.Text(), "*new") || strings.Contains(scanner.Text(), " new") ||
			strings.Contains(scanner.Text(), "\tnew") {
			fmt.Println("problem with init: function contaning 'new':", scanner.Text())
			newPresense = true
		}
	}

	return newPresense, nil
}
