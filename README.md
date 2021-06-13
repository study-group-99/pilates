<p align="center">
  <img width="26%" src="https://user-images.githubusercontent.com/22690219/120901102-6aaf9d80-c641-11eb-9fe9-a5953f596bc9.png" />
</p>
 
# Ultimate Pilates Engine
Common core tester.

## Contents

- [Installation](#installation)
	- [Script](#script)
	- [Manual](#manual)
	- [Build Source](#build-source)
- [Usage](#usage)
	- [libft](#libft)
- [Development](#development)
	- [Roadmap](#roadmap)
	- [Contributing](#contributing)
	- [Credits](#credits)

# Installation
## Script
## Manual
## Build Source
# Usage

general case, update, help etc

## libft

_note: new c++ google test (linked lists functions)_

### Dependencies: Cmake, Gcovr, Norminette

Pilates needs Cmake in roder to build and run the unit tests. In addition Gcovr is needed if you you would like to use the -c, --coverage option. We assume Norminette is already installed but if not please do or option -n, --norm will return an err.

# Development

### Feature cycle

### Bug cycle

### Release

#### Release Schedule 

#### CI

##### Main branch

When a pull request against `main` branch is successfully merged a CI gets triggered that leads to release (see `/workflows/release.yml`).

##### Comments

Regardless the branch users can comment/trig certain actions (see `/workflows/comments.yml`).

`/libft-ci` : Triggers cpp unit tests for libft. Comments back the result once actions is done.

##### Pull requests defaults

on all branches
1. Go tests (see `/workflows/gotests.yml`)

If branch is `main`

2. Runs all c/cpp tests (see `/workflows/main.yml`)

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

All students and alumni are very welcome to contribute.

* Code:

* Bug reports:

* Feature requests:

* Reviews:

## Credits

[Contributors](https://github.com/study-group-99/pilates/graphs/contributors)

<!-- Reviewers:  -->

### Shoulders of giants
Test cases for libft unit tests also came from: <a href="https://github.com/Ysoroko">@Ysoroko</a>, <a href="https://github.com/alelievr">@alelievr</a> & <a href="https://github.com/ska42">@ska42</a>.
