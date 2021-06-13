package pilates

import (
	"os"
	"testing"

	"github.com/bh90210/clir"
)

var cli = clir.NewCli("test", "long test", "v0.0.0")

func TestLibftCommandInit(t *testing.T) {
	os.Chdir("testdata/libft")
	LibftCommand(cli)
	err := cli.Run("libft", "init", "-f")
	if err != nil {
		t.Error(err)
	}
}

func TestLibftCommandRun(t *testing.T) {
	LibftCommand(cli)
	err := cli.Run("libft", "run", "-ar")
	if err != nil {
		t.Error(err)
	}
}
