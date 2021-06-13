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

	got, err := NewExists()
	if err != nil {
		t.Error(err)
	}

	if got {
		t.Error("unexpected output")
	}
}

func TestNewExistsNot(t *testing.T) {
	err := os.Chdir("../xtra/libft")
	if err != nil {
		t.Error(err)
	}

	got, err := NewExists()
	if err != nil {
		t.Error(err)
	}

	if !got {
		t.Error("unexpected output")
	}
}
