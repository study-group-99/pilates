package internal

import (
	"os"
	"testing"
)

func TestNewExists(t *testing.T) {
	err := os.Chdir("../testdata/libft")
	if err != nil {
		t.Error(err)
	}

	exists, err := NewExists()
	if err != nil {
		t.Error(err)
	}

	if exists != false {
		t.Error("unexpected output")
	}
}

func TestNewExistsNot(t *testing.T) {
	err := os.Chdir("../xtra/libft")
	if err != nil {
		t.Error(err)
	}

	exists, err := NewExists()
	if err != nil {
		t.Error(err)
	}

	if exists != true {
		t.Error("unexpected output")
	}
}
