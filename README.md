<p align="center">
  <img width="26%" src="https://user-images.githubusercontent.com/22690219/120901102-6aaf9d80-c641-11eb-9fe9-a5953f596bc9.png" />
</p>
 
# Ultimate Pilates Engine
Common core tester.

## Contents

- [Installation](#installation)
	- [Windows](#windows)
	- [Mac](#Mac)
	- [Linux](#linux)
- [Usage](#usage)
	- [libft](#libft)
- [Development](#development)
	- [Roadmap](#roadmap)
	- [Contributing](#contributing)
	- [Credits](#credits)

# Installation

## Windows

## Mac

## Linux

### Manual

### Script

`wget https://raw.githubusercontent.com/study-group-99/pilates/main/install.sh | sh`

### Go Install

`go install github.com/study-group-99/pilates/cmd/pilates@v0.0.10-pre`

### Build Source

git clone

cd

go build ./cmd/pilates

# Usage

### Help

To print the help screen of root command run `pilates -h` or `pilates --help`.

In there you will find information about pilates available subcommands and options (flags).

Each sub command has a more thorough help section available under the `-h` of the subcommand. For example `pilates libft -h` will return the expanded relevant section of the `libft` subcommand and its options.

## libft

**Dependencies: Cmake, Gcovr, Norminette**

Pilates needs Cmake in order to build the unit tests. In addition Gcovr is needed if you you would like to use the -c, --coverage option. We assume Norminette is already installed but if not please do or option -n, --norm will return an err.

**`new`**

Pilates is using `google test` which is written in C++. Consequently `new` can not be used as argument in C prototypes. 

To circumvent this issue just rename any argument named `new` to something different in both `libft.h` and the equivalent `ft_*.c` file.

pilates can do this for you automagically but running `libft init --fix-new`. Behind the scenes pilates will edit your `libft.h` and all `ft_*.c` files necessary by replacing `new` with `neww`.

### Init



### Run



# Development

`pilates` is written in `go 1.6+`. Older versions won't work because of the `embed` feature use.

Go unit tests use all the dependencies needed for end users so the same applies here as well.

_If the contribution is go code + new feature instead of bug fix, pull request without at least an example usage unit test will not get reviewed._

### Branch workflow and commit messages

We use [Gitflow Workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow) so all development is happening in the `dev` branch.

All commit messages should adhere to [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/).

### Feature/bug cycles

Open/assign your self to a ticket in discussions/issues.

Fork/clone the repo, checkout `dev` branch and create and new branch named after the feature you are implementing/bug fixing, ie. `git checkout -b feat/libft_benchmarks` or `git checkout -b fix/libftmemeoryleaks`.

Push changes and open a pull request against `dev` branch.

The title of the pull requests should be in the form of `feat: feature name (#19)`. #19 is the number of the issue/discussion.

Wait for reviews to finish.

Once all `lgtm` **squash** merge. The message when squashing should look something like `feat: bug name (#19) (#25)` or `fix: feature name (#19) (#25)` with the second (#25) being the pull requests itself.

_note: org members do not need to fork but outside collaborators do._

#### Beta

When a successful merge on `dev` is finished automation fires a new `beta` release.

### Release

When a pull request against `main` branch is successfully merged a CI gets triggered that leads to release (see `/workflows/release.yml`).

#### CI

##### Comments

Regardless the branch users can comment/trig certain actions (see `/workflows/comments.yml`).

`/libft-ci` : Triggers cpp unit tests for libft. Comments back the result once actions is done.

##### Pull requests defaults

* Go tests (see `/workflows/gotests.yml`) run on every pull request made on `dev` and `main` branches.

* Individual c/cpp tests (see `/workflows/main.yml`) run only on `main`.

## Roadmap

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

## Contributing

All active students and alumni are welcome to contribute.

_We are especially interested in forming a small "core" team of maintainers._

* **Code** ~ A good place to start is to check out for open issues (bugs) or in discussions for open feature request tickets. Once you have identified what you would like to contribute to assign yourself and let others now.

* **Bug reports** ~ Bug reports are **very** welcome. If you spot `pilates` misbehaving do open an issue describing the bug, your OS, and pilates version.

* **Feature requests** ~ If `pilates` does not have the functionality you wish, open a ticket in discussions under `feature request` describing the clearest you can how the new feature should behave and what it accomplishes.

* **Reviews** ~ If you would like to sharpen your code review skills contact someone that is already in org to send an invitation and start reviewing voluntarily any of the open pull requests.


## Credits

[Contributors](https://github.com/study-group-99/pilates/graphs/contributors)

<!-- Reviewers:  -->

### Shoulders of giants
Test cases for libft unit tests also came from: <a href="https://github.com/Ysoroko">@Ysoroko</a>, <a href="https://github.com/alelievr">@alelievr</a> & <a href="https://github.com/ska42">@ska42</a>.
