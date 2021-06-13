package pilates

import (
	"os"
	"testing"

	"github.com/bh90210/clir"
)

func TestLibftCommandInit(t *testing.T) {
	os.Chdir("testdata/libft")
	cli := clir.NewCli("test", "long test", "v0.0.0")
	LibftCommand(cli)
	err := cli.Run("libft", "init", "-f")
	if err != nil {
		t.Error(err)
	}
}

func TestLibftCommandRun(t *testing.T) {
	cli := clir.NewCli("test", "long test", "v0.0.0")
	LibftCommand(cli)
	err := cli.Run("libft", "run", "-ar")
	if err != nil {
		t.Error(err)
	}
}
