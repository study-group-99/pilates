package pilates

import (
	"bufio"
	"embed"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"

	"github.com/leaanthony/clir"
	"github.com/leaanthony/spinner"
)

const (
	libftDescription = "Install and run unit tests, benchmarks, norm check, makefile check, memory leaks checks.\n\nExamples:\n   # Init pilates for your libft.\n   pilates libft init\n\n   # Run unit tests and generate a report.\n   pilates libft run --unit --report\n"

	libftInitDescription     = "Generates the unit tests under default folder 'pilates' and two CMake files on root level. You can edit the tests but DO NOT rename or delete anything unless you know what you are doing."
	libftInitLongDescription = "\nExamples:\n   # Run init\n   pilates libft init\n\n   # Run init with -f, --force option\n   pilates libft init -f"
	libftInitForce           = "Forces files gerenation."

	libftRunDescription     = "Runs tests with the options provided via flags."
	libftRunLongDescription = "\nExamples:\n   # Run unit tests with benchmarks.\n   pilates libft -ub\n\n   # Run unit tests with linter and report.\n   pilates libft -ulr`"
	libftRunAll             = "Runs all tests."
	libftRunUnit            = "Runs unit tests. Cmake is necessary."
	libftRunCoverage        = "Prints coverage for your library. Gcov is necessary."
	libftRunBenchmark       = "Runs bernchamarks against your library. Cmake is necessary."
	libftRunMakefile        = "Checks 'Makefile' for compliance."
	libftRunNorm            = "Runs linter checks. Norminette is necessary."
	libftRunLeaks           = "Runs memory leaks tests. Valgrind is necessary."
	libftRunReport          = "Generates a 'report.txt' with the results."
	libftRunBonus           = "Includes bonus functions in testing."

	libftFiles = "ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c"
)

//go:embed libft/*
var libftTests embed.FS

type libft struct {
	*clir.Command
}

// LibftCommand takes a *clir.Cli argument and setsup 'libft' subcommand.
func LibftCommand(cli *clir.Cli) {
	libft := &libft{cli.NewSubCommand("libft", libftDescription)}
	libft.libftInit()
	libft.libftRun()
}

func (libft *libft) libftInit() {
	libftInit := libft.NewSubCommand("init", libftInitDescription)
	libftInit.LongDescription(libftInitLongDescription)
	var forceInitFlag bool
	libftInit.BoolFlag("force", "f", libftInitForce, &forceInitFlag)
	libftInit.Action(func() error {
		var path string = "pilates"

		// check if folder pilates exists
		_, err := os.Stat(path)
		if !os.IsNotExist(err) && !forceInitFlag {
			return fmt.Errorf("directory %s already exists. If know what you are doing try the -f, --force option", path)
		}

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

			if file.Name() == ".gitignore" {
				// check if .gitignore is already present
				_, err := os.Stat(file.Name())
				// if not create one
				if os.IsNotExist(err) {
					err = ioutil.WriteFile(file.Name(), data, 0755)
					if err != nil {
						return err
					}
					continue
				}

				// if it exists open it check if what we want to exclude is already present
				// if not append it.
				gitignore, err := os.OpenFile(file.Name(), os.O_APPEND|os.O_RDWR, os.ModeAppend)
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

		// generate build files
		cmd := exec.Command("cmake", "-S", ".", "-B", "build")
		cmd.Stderr = os.Stderr
		cmd.Env = os.Environ()
		if err := cmd.Run(); err != nil {
			return err
		}

		return nil
	})
}

func (libft *libft) libftRun() {
	libftRun := libft.NewSubCommand("run", libftRunDescription)
	libftRun.LongDescription(libftRunLongDescription)
	var all bool
	libftRun.BoolFlag("all", "a", libftRunAll, &all)
	var unit bool
	libftRun.BoolFlag("unit", "u", libftRunUnit, &unit)
	var coverage bool
	libftRun.BoolFlag("coverage", "c", libftRunCoverage, &coverage)
	var bench bool
	libftRun.BoolFlag("benchmark", "b", libftRunBenchmark, &bench)
	var makefile bool
	libftRun.BoolFlag("makefile", "m", libftRunMakefile, &makefile)
	var norm bool
	libftRun.BoolFlag("norm", "n", libftRunNorm, &norm)
	var leaks bool
	libftRun.BoolFlag("leaks", "l", libftRunLeaks, &leaks)
	var report bool
	libftRun.BoolFlag("report", "r", libftRunReport, &report)
	libftRun.Action(func() error {
		switch {
		case all:
			unit = true
			coverage = true
			bench = true
			makefile = true
			norm = true
			leaks = true
		case !unit && !coverage && !bench && !makefile && !norm && !leaks && !report:
			return fmt.Errorf("error: must specify at least one flag\nrun 'pilates libft run -h' for help")
		}

		var file *os.File
		var err error
		if report {
			file, err = os.Create("report.txt")
			if err != nil {
				return err
			}

			defer file.Close()
			defer fmt.Println("Report 'report.txt' generated.")
		}

		if unit {
			cmd := exec.Command("cmake", "-S", ".", "-B", "build")
			genSpinner := spinner.New("Generating build")
			genSpinner.Start()
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				return err
			}
			genSpinner.Success()

			cmd = exec.Command("cmake", "--build", "build", "--", "-j", "20")
			buildSpinner := spinner.New("Building C++ files")
			buildSpinner.Start()
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				return err
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
				return err
			}
			os.Chdir("..")
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
				return err
			}
		}

		if makefile {
			fmt.Println("makefile checks")
			makeVariations := []string{"all", "clean", "libft.a", "re", "fclean", "bonus", "rebonus"}
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

		if norm {
			cmd := exec.Command("norminette")
			cmd.Args = strings.Split(libftFiles, " ")
			cmd.Args = append(cmd.Args, "libft.h")
			cmd.Stdout = os.Stdout
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if report {
				cmd.Stdout = io.MultiWriter(os.Stdout, file)
			} else {
				cmd.Stdout = os.Stdout
			}
			if err := cmd.Run(); err != nil {
				return err
			}
		}

		if leaks {
		}

		return nil
	})
}
