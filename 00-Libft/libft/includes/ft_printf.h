/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/05 16:18:14 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define FLAGS		"-+#0 "
# define ALL_FL		"-+#0 *.0123456789lh"
# define FSPECS		"cspdiuxX%onfge"

# define DIGITS		"0123456789"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define OCTAL		"01234567"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
/*
** FORMAT SPECIFIER STRUCT
**
** .set:	stores all collected format specifiers.
** .spe_c:	specifier character - i.e. variable type (ex.: %c %s %p %d %i).
** .pad_c:	padding character - could be eiter ' ' (default) or '0' ('0' flag).
** .minus:	'-' flag - left-justifies within the given field width; right
**			justification is the default.
** .plus:	'+' flag - preceeds positive numbers with the plus sign; by default,
**			only negative numbers are preceeded with a '-' sign.
** .space:	' ' flag - a blank space is inserted before unsigned values.
** .hash:	'#' flag - for %o %x %X, preceeds not null values with 0, 0x or 0X
**			respectively; for %a %A %e %E %f %F %g %G, prints decimal point
**			even if no more digits follow. By default, if no digits follow, no
**			decimal point is printed.
** .width:	min number of characters to be printed, with blank space padding if
**			value is shorter than width.
** .point: '1' if precision is given, '0' if not.
** .precision: for %d %i %o %u %x %X, min number of digits to be printed, with
**			with 0 padding if value is shorter than precision; for %a %A %e %E
**			%f %F, number of digits to be printed after the decimal point (by
**			default, this is 6); for %g %G, max number of significants digits
**			to be printed; for %s, max number of characters to be printed (by
**			default, all characters are printed until '\0'); note: '.' = '.0'.
** .length:	modifies the length of the data type as follows:
**				| %d %i (int)	| %u %o %x %X (unsigned int)| %n (int*)		|
**			'l'	| long int		| unsigned long int			| long int*		|
**			'll'| long long int	| unsigned long long int	| long long int*|
**			'h'	| short int		| unsigned short int		| short int*	|
**			'hh	| signed char	| unsigned char				| signed char*	|
** Reference: http://www.cplusplus.com/reference/cstdio/printf/
*/
typedef struct	s_flags
{
	char					set[20];
	char					spe_c;
	char					pad_c;
	char					minus;
	char					plus;
	char					space;
	char					hash;
	int						width;
	char					point;
	int						precision;
	char					length;
	char					print_n0;
	char					sign;
	unsigned long long int	ulli;
	long long int			lli;
	long double				f;
	int						e_nbr;
	char					*a;
	char					*d;
	char					e[5];
	char					*tmp;
	int						size;
	size_t					strlen;
}				t_flags;

/*
** ft_ftoa_rnd STRUCT & UNION
*/
typedef struct	s_ftoa
{
	long double				n;
	short int				dec_len;
	short int				rnd;
	unsigned long long int	int_part;
	long double				dec_part;
	unsigned long long int	dec_int;
	int						dec_int_size;
	char					*a;
	char					*d;
	char					*tmp;
	char					z0[20];
}				t_ftoa;

typedef struct	s_dbl
{
	uint64_t	mantisa		:52;
	uint64_t	exponent	:11;
	uint64_t	sign		:1;

}				t_dbl;

union			u_dbl
{
	double	f;
	t_dbl	bits;
}				u_double_bit;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
/*
** FILE: ft_printf.c
** Initialization function: start/end variadic arguments functions <stdarg.h>;
** in between that, goes through the input string printing plain characters or
** collecting + treating format specifiers to the FORMAT SPECIFIER STRUCT thus
** printing each occurrance with the corresponding function.
*/
int				ft_printf(const char *str, ...);
/*
** FILE: ft_printf_csp_pct.c
** Outputs the input variable (collected by 'va_arg' function) as a pointer to a
** string to be printed by the 'print_flags' function.
*/
void			print_spec_c(int *len, t_flags fl, char c);
void			print_spec_s(int *len, t_flags fl, char *s);
void			print_spec_pct(int *len, t_flags fl);
/*
** FILE: ft_printf_iduxo.c
** Outputs the input variable (collected by 'va_arg' function) as a pointer to a
** string to be printed by the 'print_flags' function.
*/
void			print_spec_i_d_u(int *len, t_flags fl, va_list args);
void			print_spec_x(int *len, t_flags fl, va_list args);
void			print_spec_o(int *len, t_flags fl, va_list args);
void			print_spec_p(int *len, t_flags fl, unsigned long int p);
/*
** FILE: ft_printf_f_g.c
** Outputs the input variable (collected by 'va_arg' function) as a pointer to a
** string to be printed by the 'print_flags' function.
*/
void			print_spec_f_e_g(int *len, t_flags fl, double n);
t_flags			print_spec_f(t_flags fl, double n);
t_flags			print_spec_g(t_flags fl, double n, int p);
/*
** FILE: ft_printf_e.c
** Outputs the input variable (collected by 'va_arg' function) as a pointer to a
** string to be printed by the 'print_flags' function.
*/
t_flags			print_spec_e(t_flags fl, double n);
/*
** FILE: ft_printf_flags.c
** Prints each format specifier function's outputted string with formatting in
** accordance with the collected format specifiers.
*/
void			print_flags(int *len, t_flags fl);
/*
** FILE: ft_printf_utils.c
** Basic Libc functions - note: some were adapted and thus named with a suffix
** to indicate the nature of the customization.
*/
int				ft_strchr_01(char *s, char c);
void			ft_putchar_len(char c, int *len);
void			ft_putcstr_len(char *s, int *len, int size);
char			*ft_ullitoa_base(unsigned long long int n, char *base);
long double		ft_fmod(long double n, long double mod);
/*
** FILE: ft_ftoa_rnd.c
*/
char			*ft_ftoa_rnd(long double n, short int dec_len, short int rnd);

#endif
