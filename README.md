<p align="center">
  <img width="26%" src="https://user-images.githubusercontent.com/22690219/120901102-6aaf9d80-c641-11eb-9fe9-a5953f596bc9.png" />
</p>
 
# Ultimate Pilates Engine
A CLI (command line interface) common core tester.
```
$ pilates
pilates v0.2.1 - Ultimate Pilates Machine

pilates is an educational devops tool designed to help you along your curriculum.

Available commands:

   libft   Install and run unit tests, benchmarks, norm check, makefile check & memory leaks checks. 

Flags:

  -h, --help
    	Get help on the 'pilates' command.
  -u, --update
    	Update Pilates to the latest version.
  -v, --version
    	Pilates CLI version.

```

## Contents

- [Installation](#installation)
	- [Mac](#mac)
	  <!-- - [Homebrew](#homebrew) -->
	- [Linux (+wsl)](#linux)
	  <!-- - [Package](#package)
	    - [deb](#deb)
	    - [rpm](#rpm) -->
	- [Go](#go)
	  - [Install](#go-install)
	  - [Build Source](#build-source)
	<!-- - [Docker](#docker) -->
	- [Script](#script)
- [Usage](#usage)
	- [libft](#libft)
	  - [Init](#init)
	  - [Run](#run)
- [Development](#development)
	- [Contributing](#contributing)
- [Roadmap](#roadmap)
- [Credits](#credits)

# Installation

## Mac

**Manual**

* Download the latest stable (or beta) [release](https://github.com/study-group-99/pilates/releases).

* Move the binary in `/usr/local/bin` (or a custom location).

_If you opt for custom location you may need to include it in you [Path](https://www.architectryan.com/2012/10/02/add-to-the-path-on-mac-os-x-mountain-lion/#.Uydjga1dXDg)._

 _You may need to restart any open Terminal sessions for the change to take effect._

### Homebrew Tap

[Coming soon.](https://github.com/study-group-99/pilates/discussions/21)

## Linux

**Manual**

* Download the latest stable (or beta) [release](https://github.com/study-group-99/pilates/releases).

* Move the binary in `$HOME/.local/bin` (or a custom location).

**Path**

You may need to include the directory in your path.

Open you `~/.bashrc` or `~/.profile` etc amd add the line

```PATH="$HOME/.local/bin:$PATH"```

To load the changes run `source ~/.profile` or `source ~/.bashrc` etc.

### deb/rpm Packages

[Coming soon.](https://github.com/study-group-99/pilates/discussions/21)

<!-- #### deb -->

<!-- #### rpm -->

## Script

You can install `pilates` via an `install.sh` script.

`curl -sfL https://raw.githubusercontent.com/study-group-99/pilates/main/install.sh | sh`

This will download and install latest stable release. If you feel adventurous you can download the script and run locally pointing to latest beta ie. `sh install.sh pilates-v0.1.0-beta.1`. Please check [releases](https://github.com/study-group-99/pilates/releases) for latest beta version.

_Path_

_See relevant path instructions for your platform above._

<!-- ## Docker -->

## Go

_Note: minimum go version required is 1.6+._

### Go Install

`go install github.com/study-group-99/pilates/cmd/pilates`

_Remember that you need to have $GOPATH/bin in your path._

### Build Source

* Clone the repo `git clone https://github.com/study-group-99/pilates.git`

* Change in the `pilates` directory `cd pilates`

* Build the app `go build ./cmd/pilates`

# Usage

### Help

To print the help screen of root command run `pilates -h` or `pilates --help`.

In there you will find information about pilates available subcommands and options (flags).

Each sub command has a more thorough help section available under the `-h` of the subcommand. For example `pilates libft -h` will return the expanded relevant section of the `libft` subcommand and its options.

## libft

**Dependencies: Cmake, Gcovr, Norminette**

Pilates needs Cmake for building the unit tests. In addition Gcovr is needed if you you would like to use the -c, --coverage option. We assume Norminette is already installed but if not please do or option -n, --norm will return an err.

Linux:

* Debian/Ubuntu `sudo apt-get install cmake gcovr`
* RHEL/Fedora/CentOS/ `sudo yum install cmake gcovr`

Mac:

* Via brew `brew install cmake gcovr`
* Manually from https://cmake.org/download/
* `pip install gcovr`

Norminette:

* `python3 -m pip install norminette`

**`new`**

pilates is using the `google test` framework which is written in C++. Consequently `new` can not be used as argument in any of your C prototypes or tests wont even build.

To circumvent this issue rename all arguments named `new` to something different in both `libft.h` and the equivalent `ft_*.c` file.

pilates can do this for you automagically by running `pilates libft init --fix-new`. Behind the scenes pilates will edit your `libft.h` and all `ft_*.c` files necessary, replacing `new` with `neew`.

### Init

Open a terminal and `cd` in you `libft` directory. Run `pilates libft init`. pilates will create a `.gitignore` file if it does not exists, two `CMakeLists` files a pilates directory.

_If for any reason you would like to re-init you can use the -f, --force option `pilates libft init -f`._

All tests are `.cpp` files that live inside pilates directory. You are strongly advised to look inside! If you know what you are doing you of-course can edit/comment out/delete or add code.

Files and directories generated by pilates are all listed in the `.gitignore` so when you submit your project no artifacts will be present.

### Run

The `run` subcommand is intended to be used with one of the bellow options. Trying to run it without one will return an error. To print help run `pilates libft run -h`.

#### Unit

`pilates libft run --unit` or `pilates libft run -u` for short. 
The -u, --unit option will run unit tests against your libft files. There is no part one/two, bonus options etc. pilates will test against all `ft_*.c` found on top level directory.

_Building and running the unit tests will create a new directory `build`._

##### Coverage

You can optionally see the coverage of you code by passing the -c --coverage option.

#### Makefile

`pilates libft run -m` the `makefile` option will attempt to build your Makefile checking that all that should exist work.

#### Norm

`pilates libft run -n` runs linter checks. It is meant to be used along -r, --report option for wholesomeness.

#### Report

`pilates libft run -ur` generates a `report.txt` log file. Report option can not be used alone.

#### All

`pilates libft run -a` option -a, --all will turn all other options true. It is the equivalent of `pilates libft run -unmcr`.


# Development

`pilates` is written in `go 1.6+`. Older versions won't work because of the `embed` feature use.

Go unit tests use all the dependencies needed for end users so the same applies here as well.

_If the contribution is go code + new feature instead of bug fix, please include at least an example usage unit test._

### Branch workflow and commit messages

We use [gitflow workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow) so all development is happening in the `dev` branch.

All commit messages should adhere to [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/).

### Feature/bug cycles

1. Open/assign your self to a ticket in discussions/issues.

2. Fork/clone the repo, checkout `dev` branch and then branch off to a new branch named after the feature you are implementing/bug fixing, ie. `git checkout -b feat/libft_benchmarks` or `git checkout -b fix/libftmemeoryleaks`.

3. Push changes and open a pull request against `dev` branch.

4. The title of the pull requests should be in the form of `feat: feature name (#19)`. #19 is the number of the issue/discussion.

5. Wait for reviews to finish.

6. Once all `lgtm` **squash** merge. The message when squashing should look something like `feat: bug name (#19) (#25)` or `fix: feature name (#19) (#25)` with the second (#25) being the pull requests itself.

_note: org members do not need to fork but outside collaborators do._

#### Beta

On successful merge on `dev` branch automation fires a new `beta` release for testing purposes.

### Release

When a pull request against `main` branch is successfully merged automation will make a new release (see `/workflows/release.yml` & `./goreleaser.yml`). If commit messages contain `feat` a minor bump will run `v0.1.0` to `v0.2.0`, if commit messages contain `fix` a patch bump will run ie. `v0.1.0` to `v0.1.1`. If messages contain `breaking` a major bump will run `v0.1.0` to `v1.0.0`.

### Local Dev

When implementing a feature or patch for a bug the two ways to test what you did are 

1. `go install ./cmd/pilates` which will build a binary inside `go/bin`. You can you use this binary against some test directory.
2. `go test ./... -v` to run through all unit tests.

#### CI

##### Comments

Regardless the branch contributors can comment/trig certain actions (see `/workflows/comments.yml`).

`/libft-ci` : Triggers cpp unit tests for libft. Comments back the result once actions is done.

##### Pull requests defaults

* Go tests (see `/workflows/gotests.yml`) run on every pull request made on `dev` and `main` branches.

* Individual c/cpp tests (see `/workflows/main.yml`) run only on `main`.

## Contributing

All active students and alumni are welcome to contribute.

_We are especially interested in forming a small "core" team of maintainers._

* **Code** ~ A good place to start is to check for open [issues](https://github.com/study-group-99/pilates/issues) (bugs) or in [discussions](https://github.com/study-group-99/pilates/discussions/categories/feature-request) for  unassigned feature request tickets. Once you have identified what you would like to contribute to assign yourself and let others know.

* **Bug reports** ~ Bug reports are **very** welcome. If you spot `pilates` misbehaving do [open an issue](https://github.com/study-group-99/pilates/issues/new) describing the bug, your OS, and pilates version.

* **Feature requests** ~ If `pilates` does not have the functionality you wish, [open a ticket](https://github.com/study-group-99/pilates/discussions/new) in discussions under `feature request` describing the clearest you can how the new feature should behave and what it accomplishes.

* **Reviews** ~ If you would like to sharpen your code review skills contact someone that is already in org to send an invitation and start reviewing voluntarily any of the open pull requests.

# Roadmap

- [x] Libft
- [ ] ft_printf
- [ ] get_next_line
- [ ] minitalk (?)
- [ ] pipex (?)
- [ ] so_long (?)
- [ ] Fdf (?)
- [ ] fract-ol (?)
- [ ] push_swap (?)
- [ ] minishell (?)
- [ ] Philosophers (?)
- [ ] cub3d (?)
- [ ] miniRT (?)
- [ ] ft_containers (?)
- [ ] ft_services (?)
- [ ] Inception (?)
- [ ] ft_irc (?)
- [ ] webserv (?)
- [ ] cpp module (?)

# Credits

## [Contributors](https://github.com/study-group-99/pilates/graphs/contributors)

Reviewers/Testers: <a href="https://github.com/ignan1">@ignan1</a>, <a href="https://github.com/Zyanite7">@Zyanite7</a>, <a href="https://github.com/LePlaYa">@LePlaYa</a>, <a href="https://github.com/dejanzivanov">@dejanzivanov</a>, <a href="https://github.com/Madasanya">@Madasanya</a>, <a href="https://github.com/Lillzz">@Lillzz</a>, <a href="https://github.com/berlintrabby">@berlintrabby</a>.

## Shoulders of giants
Test cases for libft unit tests also came from: <a href="https://github.com/berlintrabby">@berlintrabby</a>, <a href="https://github.com/alelievr">@alelievr</a> & <a href="https://github.com/ska42">@ska42</a>.
