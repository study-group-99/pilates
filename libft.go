package pilates

import (
	"embed"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"

	"github.com/leaanthony/clir"
)

const (
	libftDescription = "Install and run unit tests, benchmarks, linter check, makefile check.\n"

	libftFiles = "ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c"

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
var libftTests embed.FS

type libft struct {
	c     *clir.Command
	tests *embed.FS
}

func LibftCommand(cli *clir.Cli) {
	libft := new(libft)
	libft.c = cli.NewSubCommand("libft", libftDescription)
	libft.tests = &libftTests
	libft.libftInit()
	libft.libftRun()
	libft.libftClean()
}

// func libftInit(libft *clir.Command) {
func (libft *libft) libftInit() {
	libftInit := libft.c.NewSubCommand("init", libftInitDescription)
	var forceInitFlag bool
	libftInit.BoolFlag("force", "f", libftInitForce, &forceInitFlag)
	libftInit.Action(func() error {
		var path string = "pilates"
		_, err := os.Stat(path)
		if !os.IsNotExist(err) && !forceInitFlag {
			return fmt.Errorf("directory %s already exists. If know what you are doing try the -f, --force option", path)
		}

		os.Mkdir(path, 0744)
		// dir, err := libftTests.ReadDir("libft")
		dir, err := libft.tests.ReadDir("libft")
		if err != nil {
			return err
		}

		for _, file := range dir {
			data, err := libft.tests.ReadFile(fmt.Sprintf("libft/%s", file.Name()))
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

			err = ioutil.WriteFile(fmt.Sprintf("%s/%s", path, file.Name()), data, 0755)
			if err != nil {
				return err
			}
		}

		cmd := exec.Command("cmake", "-S", ".", "-B", "build")
		// cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		cmd.Env = os.Environ()
		if err := cmd.Run(); err != nil {
			fmt.Println("failed to run cmake: ", err)
		}

		return nil
	})
}

func (libft *libft) libftRun() {
	libftRun := libft.c.NewSubCommand("run", libftRunDescription)
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
	// var bonus bool
	// libftRun.BoolFlag("bonus", "", libftRunBonus, &bonus)
	libftRun.Action(func() error {
		if !unit && !coverage && !bench && !makefile && !linter && !report {
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
		}

		if unit {
			cmd := exec.Command("cmake", "-S", ".", "-B", "build")
			fmt.Println("Generating build")
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run cmake: ", err)
			}

			cmd = exec.Command("cmake", "--build", "build")
			fmt.Println("Building C++ files")
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run cmake: ", err)
			}

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
				fmt.Println("failed to run ctest: ", err)
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
				fmt.Println("failed to run gcovr: ", err)
			}
		}

		if makefile {
			fmt.Println("make checks")
			makeVariations := []string{"all", "clean", "libft.a", "re", "fclean", "bonus", "rebonus"}
			for _, val := range makeVariations {
				cmd := exec.Command("make", val)
				fmt.Printf("make %s\n", val)
				cmd.Env = os.Environ()
				if report {
					file.WriteString(fmt.Sprintf("make %s\n", val))
					cmd.Stderr = io.MultiWriter(os.Stderr, file)
				} else {
					cmd.Stderr = os.Stderr
				}
				if err := cmd.Run(); err != nil {
					fmt.Printf("failed to run make %s: %s\n", val, err)
				} else {
					fmt.Printf("make %s - Pass\n", val)
					file.WriteString("make all - Pass\n")
				}
			}

			// clean everything in the end
			cmd := exec.Command("make", "fclean")
			cmd.Env = os.Environ()
			cmd.Run()
		}

		if linter {
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
				fmt.Println("failed to run norminette: ", err)
			}
		}

		return nil
	})
}

func (libft *libft) libftClean() {
	libftClean := libft.c.NewSubCommand("clean", libftCleanDescription)
	libftClean.Action(func() error {

		files := []string{"CMakeLists.txt", "CMakeLists.txt.in", "report.txt", "build", "pilates", "Testing"}
		for i, file := range files {
			if i < 3 {
				i++
				fmt.Printf("deleting file %s\n", file)
				err := os.Remove(file)
				if err != nil {
					if !strings.Contains(err.Error(), "no such file or directory") {
						fmt.Println(err)
					}
				}
			} else {
				fmt.Printf("deleting folder %s\n", file)
				err := os.RemoveAll(file)
				if err != nil {
					fmt.Println(err)
				}
			}
		}

		return nil
	})
}
