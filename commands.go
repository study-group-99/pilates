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

	libftFiles = "ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c"

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
	libftInit.Action(func() error {
		var path string = "pilates"
		_, err := os.Stat(path)
		if !os.IsNotExist(err) && !forceInitFlag {
			return fmt.Errorf("directory %s already exists. If know what you are doing try the -f, --force option", path)
		}

		os.Mkdir(path, 0744)
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
			// cmd.Stdout = os.Stdout
			fmt.Println("Rebuilding C++ files")
			cmd.Stderr = os.Stderr
			cmd.Env = os.Environ()
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run cmake: ", err)
			}

			cmd = exec.Command("cmake", "--build", "build")
			// cmd.Stdout = os.Stdout
			fmt.Println("Rebuilding C files")
			cmd.Stderr = os.Stderr
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
			cmd := exec.Command("make", "all")
			fmt.Println("make all")
			cmd.Env = os.Environ()
			if report {
				cmd.Stderr = io.MultiWriter(os.Stderr, file)
				file.WriteString("Makefile checks\nmake all\n")
			} else {
				cmd.Stderr = os.Stderr
			}
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run make all: ", err)
			} else {
				fmt.Println("make all - Pass")
				file.WriteString("make all - Pass\n")
			}

			cmd = exec.Command("make", "clean")
			fmt.Println("make clean")
			cmd.Env = os.Environ()
			if report {
				cmd.Stderr = io.MultiWriter(os.Stderr, file)
				file.WriteString("make clean\n")
			} else {
				cmd.Stderr = os.Stderr
			}
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run make clean: ", err)
			} else {
				fmt.Println("make clean - Pass")
				file.WriteString("make clean - Pass\n")
			}

			cmd = exec.Command("make", "libft.a")
			fmt.Println("make libft.a")
			cmd.Env = os.Environ()
			if report {
				cmd.Stderr = io.MultiWriter(os.Stderr, file)
				file.WriteString("make libft.a\n")
			} else {
				cmd.Stderr = os.Stderr
			}
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run make libft.a: ", err)
			} else {
				fmt.Println("make libft.a - Pass")
				file.WriteString("make libft.a - Pass\n")
			}

			cmd = exec.Command("make", "re")
			fmt.Println("make re")
			cmd.Env = os.Environ()
			if report {
				cmd.Stderr = io.MultiWriter(os.Stderr, file)
				file.WriteString("make re\n")
			} else {
				cmd.Stderr = os.Stderr
			}
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run make re: ", err)
			} else {
				fmt.Println("make re - Pass")
				file.WriteString("make re - Pass\n")
			}

			cmd = exec.Command("make", "fclean")
			fmt.Println("make fclean")
			cmd.Env = os.Environ()
			if report {
				cmd.Stderr = io.MultiWriter(os.Stderr, file)
				file.WriteString("make fclean\n")
			} else {
				cmd.Stderr = os.Stderr
			}
			if err := cmd.Run(); err != nil {
				fmt.Println("failed to run make fclean: ", err)
			} else {
				fmt.Println("make fclean - Pass")
				file.WriteString("make fclean - Pass\n")
			}
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

func libftClean(libft *clir.Command) {
	libftClean := libft.NewSubCommand("clean", libftCleanDescription)
	libftClean.Action(func() error {
		fmt.Println("Clean folder")
		return nil
	})
}
