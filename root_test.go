package pilates

import (
	"io/ioutil"
	"os"
	"strings"
	"testing"

	"github.com/bh90210/clir"
)

func TestRootCommandEmpty(t *testing.T) {
	cli := clir.NewCli("test", "long test", "v0.0.0")
	RootCommand(cli)
	err := cli.Run()
	// it should return help
	if err == nil {
		t.Error(err)
	}
}

func TestRootCommandVersion(t *testing.T) {
	rescueStdout := os.Stdout
	r, w, _ := os.Pipe()
	os.Stdout = w
	cli := clir.NewCli("test", "long test", "v0.0.0")
	RootCommand(cli)
	err := cli.Run("-v")
	if err != nil {
		t.Error(err)
	}

	w.Close()

	got, _ := ioutil.ReadAll(r)
	os.Stdout = rescueStdout
	want := "test version v0.0.0"

	if !strings.Contains(string(got), want) {
		t.Errorf("want %s, got %s", want, got)
	}
}

func TestRootCommandNon(t *testing.T) {
	cli := clir.NewCli("test", "long test", "v0.0.0")
	RootCommand(cli)
	err := cli.Run("non")
	if err == nil {
		t.Error(err)
	}

	want := "error: unknown command `non` for `test`\nRun 'test --help' for usage"
	got := err.Error()

	if want != got {
		t.Errorf("want %s, got %s", want, got)
	}
}
