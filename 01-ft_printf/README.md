# ft_printf

>"This project is pretty straight forward. You will recode printf. Hopefully you
will be able to reuse it in future project without the fear of being flagged as a cheater.
You will mainly learn how to use variadic arguments."

For further information, refer to the [project's PDF](../_PDFs/01-ft_printf-en.pdf).

For **testing programs** developed for this project, refer to the
[project's development repo](https://github.com/appinha/42cursus-01-ft_printf).

This folder contains solely the files required for submission.

## Contents

Note: files contain both mandatory and (all) bonus requirements.

### Functions in `ft_printf.c`

* `ft_printf` (and auxiliary static functions) -
Initialization function: start/end variadic arguments functions `<stdarg.h>`;
in between that, goes through the input string printing plain characters or
collecting + treating format specifiers to the FORMAT SPECIFIER STRUCT thus
printing each occurrance with the corresponding function.

### Functions in `ft_printf_flags.c`

* `print_flags` (and auxiliary static functions) -
Prints each format specifier function's outputted string with formatting in
accordance with the collected format specifiers.

### Functions in `ft_printf_csp_pct.c`

The following functions
output the input variable (collected by `va_arg` function) as a pointer to a
string to be printed by the `print_flags` function.

* `print_spec_c`	- **character** (`%c`) type input variable;
* `print_spec_s`	- **string** (`%s`) type input variable;
* `print_spec_pct`	- **percent** (`%%`) character.

### Functions in `ft_printf_iduxo.c`

The following functions
output the input variable (collected by `va_arg` function) as a pointer to a
string to be printed by the `print_flags` function.

* `print_spec_i_d_u`	- **int** (`%i` and `%d`) and **unsigned int** (`%u`)type input variables;
* `print_spec_x`		- **lower** (`%x`) and **upper hexadecimal** (`%X`) type input variables;
* `print_spec_o`		- **octal** (`%o`) type input variable;
* `print_spec_p`		- **pointer** (`%p`) type input variable.

### Functions in `ft_printf_f_g.c`

The following functions
output the input variable (collected by `va_arg` function) as a pointer to a
string to be printed by the `print_flags` function.

* `print_spec_f_e_g`	- triage for **float** (`%f`), **scientific notation** (`%e`) and **general format** (`%g`) type input variables;
* `print_spec_f`		- **float** (`%f`) type input variable;
* `print_spec_g`		- **general format** (`%g`) type input variable.

### Functions in `ft_printf_f_g.c`

The following functions
output the input variable (collected by `va_arg` function) as a pointer to a
string to be printed by the `print_flags` function.

* `print_spec_e` - **scientific notation** (`%e`) type input variable.

### Functions in `ft_printf_utils.c`

Basic Libc functions - note: some were adapted and thus named with a suffix
to indicate the nature of the customization.

* `ft_strlen`		- find length of string;
* `ft_strchr_01`	- check the occurence of a character in a string;
* `ft_putchar_len`	- writes the input character to the output stream of stdout;
* `ft_putcstr_len`	- writes the input string to the output stream of stdout;

### Functions in `ft_printf_utils_2.c`

Basic Libc functions - note: some were adapted and thus named with a suffix
to indicate the nature of the customization.

* `ft_strlcpy`	- copy string to another location;
* `ft_strlcat`	- concatenate strings;
* `ft_strdup`	- save a copy of a string (with malloc);
* `ft_strjoin`	- join two strings (with malloc);
* `ft_substr`	- extract a substring (with malloc).

### Functions in `ft_printf_utils_3.c`

Basic Libc functions - note: some were adapted and thus named with a suffix
to indicate the nature of the customization.

* `ft_pow`			- returns the value of first argument raised to the power of second argument.
* `ft_ullitoa_base`	- allocates (with malloc) and returns a string representing the integer received as an argument according to the given base.
* `ft_fmod`			- returns the modulo of the float received as an argument.

### Functions in `ft_ftoa_rnd.c`

* `ft_ftoa_rnd` - allocates (with malloc) and returns a string representing the float received as an argument.
