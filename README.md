# ft_printf

> A custom implementation of the C `printf` function, supporting various format specifiers.

## About

`ft_printf` is a project from Hive Helsinki. The goal is to recreate the behavior of the standard C `printf` function, handling various format specifiers and edge cases, all while managing memory safely and writing to the standard output without using the standard C library (except `write()`).

## Features

- Reimplementation of `printf` using only allowed functions (`write`, etc.)
- Supports format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Custom output for `NULL` pointers and strings
- Returns the number of characters printed
- Handles edge cases and write errors

## Project Structure

```
ft_printf/
├── ft_printf.c        # Main printf logic and 
├── ft_printf.h        # Header file with 
├── ft_put.c           # Output functions for 
├── ft_basenbr.c       # Base conversion for 
├── Makefile           # For compiling the 
├── test.c             # Test file comparing ft_printf and standard printf
└── libft/             # My custom libft
```

## Installation & Usage

```bash
# Clone the repository
git clone https://github.com/Justyuanz/ft_printf.git
cd ft_printf
make
```

### Compile with a test file

```bash
cc test.c libftprintf.a -o ft_printf_test
./ft_printf_test
```

## Example Output

```c
ft_printf("Char: %c\n", 'A');
ft_printf("String: %s\n", NULL);
ft_printf("Decimal: %d\n", 42);
ft_printf("Unsigned: %u\n", 3000000000U);
ft_printf("Hex: %x\n", 255);
ft_printf("Pointer: %p\n", &ft_printf);
ft_printf("Percent: %%\n");
```

```bash
Char: A
String: (null)
Decimal: 42
Unsigned: 3000000000
Hex: ff
Pointer: 0x...
Percent: %
```

## Skills Learned

- Working with variadic arguments using `stdarg.h`
- Handling format parsing and custom specifiers
- Implementing base conversions (decimal, hex, pointer)
- Using only allowed system calls (`write`)
- Safely handling `NULL` and invalid formats
- Debugging output with `valgrind` and simulating write errors

## Advanced Testing

- Compared return values of `ft_printf` and standard `printf`
- Tested edge cases: lone `%`, null format strings, invalid specifiers
- Closed `stdout` to simulate write errors and confirmed correct behavior

## Future Improvements

I passed this project using **recursion** for number and base printing (e.g. `ft_putnbr`, `ft_putbase`). While it works and keeps the code simple, it relies on **stack memory**, which might be limited in real-world applications.

To make the implementation more scalable, I plan to **rewrite these functions using buffers**, where all the output is constructed dynamically in memory and written once. This would allow better control over memory usage and avoid deep recursion for large values.
