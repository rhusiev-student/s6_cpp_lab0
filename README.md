# Lab 0: Prints the Incomprehensible

Authors (team):

- Husiev Radomyr: https://github.com/rhusiev

## Prerequisites

- C++
- cmake
- make
- linux

### Compilation

```bash
./compile.sh -d # or -o for optimized (release) build
```

### Installation

```bash
./compile.sh -d
```

### Usage

The library is installed into `bin/libmy_prints.a` (is on Linux -- on other OSes it might have a slightly different name), and the binary to test the prints is installed into `bin/prints_the_incomprehensible`.

Run the binary:

```bash
./bin/prints_the_incomprehensible
```

to see test output.

To use the library yourself, include the `include` directory in cmake, the corresponding files in your program: `my_print.hpp` for a more safe print that uses variadic templates and `my_printf.hpp` for an implementation that is similar to printf from the standard library.

#### String formatting

For `my_printf`, similar to C style:
- `%s` for string
- `%d` or `%i` for integer
- `%f` for double

Add the necessary values after the format string:

```cpp
my_printf("%s %d %f", "Hello", 42, 3.14);
```

For `my_print`, you just need to specify that a value is to be placed, without explicitly stating the type. Use `{}` for this purpose:

```cpp
my_print("{} {} {}", "Hello", 42, 3.14);
```
