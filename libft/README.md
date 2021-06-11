# libft unit tests

While you could just run `pilates libft init` you might opt to manually install the unit test and reproduce what the CLI is doing behind the scenes.

#### Prerequisites 

_Cmake needs to be installed._

1. copy `CMakeLists.txt` and `CMakeLists.txt.in` inside the folder containing your libft.
```
.
├── CMakeLists.txt
├── CMakeLists.txt.in
├── ft_atoi.c
├── ft_bzero.c
├── ...
├── libft.h
├── Makefile
```
2. Inside your libft create a new folder named `pilates` and above `.cpp` files inside.

	You can use any other folder name but you have to also edit `CMakeLists.txt` line 63 `add_subdirectory(foldername)`.
3. Copy `CMakeLists.txt.test` inside the above created folder. Remember to remove the `.test` from the end of the file.
4. Run `cmake -S . -B build` ro generate the build.
5. Build the tests `cmake --build build`.
6. `cd` in the `build` folder and run the actual tests `ctest --output-on-failure`.

if `gcovr` is installed you can also cd to top folder and:

7. Run `gcovr --exclude '.*test.*' --root .` to get the coverage.
