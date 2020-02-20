# Libft

"The aim of this project is to code a C library regrouping usual functions that you'll be allowed to use in all your other projects." - for further information, refer to the project's PDF on folder "../_PDFs".

## Contents

### From `<ctype.h>` library
* `ft_isascii`	- test for ASCII character
* `ft_isalnum`	- alphanumeric character test
* `ft_isalpha`	- alphabetic character test
* `ft_islower`	- lower-case character test
* `ft_isupper`	- upper-case character test
* `ft_isdigit`	- decimal-digit character test
* `ft_isxdigit`	- hexadecimal-digit character test
* `ft_isprint`	- printing character test (space character inclusive)
* `ft_isgraph`	- printing character test (space character exclusive)
* `ft_isspace`	- white-space character test
* `ft_isblank`	- space or tab character test
* `ft_ispunct`	- punctuation character test
* `ft_iscntrl`	- control character test
* `ft_tolower`	- upper case to lower case letter conversion
* `ft_toupper`	- lower case to upper case letter conversion

### From `<stdlib.h>` library
* `ft_atoi`		- convert ASCII string to integer
* `ft_calloc`	- memory allocation

### From `<strings.h>` library
* `ft_bzero`	- write zeroes to a byte string
* `ft_memset`	- write a byte to a byte string
* `ft_memchr`	- locate byte in byte string
* `ft_memcmp`	- compare byte string
* `ft_memmove`	- copy byte string
* `ft_memcpy`	- copy memory area
* `ft_memccpy`	- copy string until character found

### From `<string.h>` library
* `ft_strlen`	- find length of string
* `ft_strchr`	- locate character in string (first occurrence)
* `ft_strrchr`	- locate character in string (last occurence)
* `ft_strstr`	- locate a substring in a string
* `ft_strnstr`	- locate a substring in a string (size-bounded)
* `ft_strcmp`	- compare strings
* `ft_strncmp`	- compare strings (size-bounded)
* `ft_strcpy`	- copy strings
* `ft_strncpy`	- copy strings (size-bounded)
* `ft_strdup`	- save a copy of a string (with malloc)
* `ft_strndup`	- save a copy of a string (with malloc, size-bounded)
* `ft_strcat`	- concatenate strings (s2 into s1)
* `ft_strncat`	- concatenate strings (s2 into s1, size-bounded)
* `ft_strlcpy`	- size-bounded string copying
* `ft_strlcat`	- size-bounded string concatenation

### From `<math.h>` library
* `ft_sqrt`		- square root function

### Non standard functions
* `ft_swap`			- swap value of two integers
* `ft_putchar`		- output a character to stdout
* `ft_putchar_fd`	- output a character to given file
* `ft_putstr`		- output string to stdout
* `ft_putstr_fd`	- output string to given file
* `ft_putendl`		- output string to stdout with newline
* `ft_putendl_fd`	- output string to given file with newline
* `ft_putnbr`		- output integer to stdout
* `ft_putnbr_fd`	- output integer to given file
* `ft_itoa`			- convert integer to ASCII string
* `ft_substr`		- extract substring from string
* `ft_strtrim`		- trim beginning and end of string with the specified characters
* `ft_strjoin`		- concatenate two strings into a new string (with malloc)
* `ft_split`		- split string, with specified character as delimiter, into an array of strings
* `ft_strmapi`		- create new string from modifying string with specified function

### Linked list functions
* `ft_lstnew`		- create new list
* `ft_lstsize`		- count elements of a list
* `ft_lstlast`		- find last element of list
* `ft_lstadd_back`	- add new element at end of list
* `ft_lstadd_front`	- add new element at beginning of list
* `ft_lstdelone`	- delete element from list
* `ft_lstclear`		- delete sequence of elements of list from a starting point
* `ft_lstiter`		- apply function to content of all list's elements
* `ft_lstmap`		- apply function to content of all list's elements into new list
