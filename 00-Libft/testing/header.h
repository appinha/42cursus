/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:26:19 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/19 14:00:38 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <fcntl.h>

# define BLACK(string)		"\033[30m" string "\033[0m"
# define GRAY(string)		"\033[38;5;8m" string "\033[0m"
# define L_GRAY(string)		"\033[38;5;245m" string "\033[0m"
# define RED(string)		"\033[31m" string "\033[0m"
# define L_RED(string)		"\033[38;5;9m" string "\033[0m"
# define GREEN(string)		"\033[32m" string "\033[0m"
# define D_GREEN(string)	"\033[38;5;22m" string "\033[0m"
# define V_GREEN(string)	"\033[38;5;82m" string "\033[0m"
# define PETROL_G(string)	"\033[38;5;23m" string "\033[0m"
# define PETROL_B(string)	"\033[38;5;24m" string "\033[0m"
# define YELLOW(string)		"\033[38;5;11m" string "\033[0m"
# define V_YELLOW(string)	"\033[33m" string "\033[0m"
# define L_YELLOW(string)	"\033[38;5;191m" string "\033[0m"
# define BLUE(string)		"\033[34m" string "\033[0m"
# define V_BLUE(string)		"\033[38;5;27m" string "\033[0m"
# define VIOLET(string)		"\033[35m" string "\033[0m"
# define PINK(string)		"\033[38;5;199m" string "\033[0m"
# define LILAC(string)		"\033[38;5;13m" string "\033[0m"
# define PURPLE(string)		"\033[38;5;93m" string "\033[0m"
# define CYAN(string)		"\033[36m" string "\033[0m"
# define V_CYAN(string)		"\033[38;5;44m" string "\033[0m"
# define ORANGE(string)		"\033[38;5;166m" string "\033[0m"
# define V_ORANGE(string)	"\033[38;5;202m" string "\033[0m"

# define HEADER_T(string)	"\033[1m\033[38;5;199m" string "\033[0m"
# define HEADER_L(string)	"\033[38;5;43m" string "\033[0m"
# define HEADER_A(string)	"\033[1m\033[38;5;23m" string "\033[0m"
# define PARTS(string)		"\033[38;5;13m" string "\033[0m"
# define FUNCTION(string)	"\033[1m\033[38;5;75m" string "\033[0m"

enum		e_values {
	TEST_OK,
	TEST_KO,
	TEST_KO_11,
	TEST_KO_10,
	TEST_KO_6,
	TEST_KO_I,
	TEST_KO_I_11,
	TEST_KO_I_10,
	TEST_KO_I_6,
	TEST_ABORT
};

/***********************/
/* Auxiliary functions */
/***********************/

int		pid;
int		signal_code;

void	res_test(int n);
void	test_nbr(int nbr);
void	test_description(char *s);
void	test_type1(size_t (*p_ft)(const char *), size_t (*p_libc)(const char *), char *str);
void	test_type1_showres(size_t r1, size_t r2);
void	test_type2(int (*p_ft)(int), int (*p_libc)(int), int lower, int upper);

# define SANDBOX(x)	do { \
	if ((pid = fork()) < 0) \
	exit(EXIT_FAILURE); \
	if (pid == 0) { \
		do { x } while(0); \
		exit(EXIT_SUCCESS); \
	} else { \
		wait(&pid); \
		if (pid != 0) { \
			res_test(TEST_KO); \
			if ((signal_code = WTERMSIG(pid)) == 11) \
				printf(L_RED("function segfaulted\t(SIGSEGV)\n")); \
			if ((signal_code = WTERMSIG(pid)) == 10) \
				printf(L_RED("function got bus error\t(SIGBUS)\n")); \
			if ((signal_code = WTERMSIG(pid)) == 6) \
				printf(L_RED("function aborted\t(SIGABRT)\n")); \
		} \
	} \
} while(0);

# define SANDBOX_I(x)	do { \
	if ((pid = fork()) < 0) \
	exit(EXIT_FAILURE); \
	if (pid == 0) { \
		do { x } while(0); \
		exit(EXIT_SUCCESS); \
	} else { \
		wait(&pid); \
		if (pid != 0) { \
			res_test(TEST_OK); \
			if ((signal_code = WTERMSIG(pid)) == 11) \
				printf("function segfaulted\t"); \
			if ((signal_code = WTERMSIG(pid)) == 10) \
				printf("function got bus error\t"); \
			if ((signal_code = WTERMSIG(pid)) == 6) \
				printf("function sigaborted\t"); \
		} \
	} \
} while(0);

/******************/
/* Test functions */
/******************/

/* ft_strlen */

void	test_strlen_0(void);
void	test_strlen_1(void);
void	test_strlen_2(void);
void	test_strlen_3(void);
void	test_strlen_4(void);
void	test_strlen_5(void);

/* ft_isxxxxx */

void	test_isalnum(void);
void	test_isalpha(void);
void	test_isascii(void);
void	test_isdigit(void);
void	test_isprint(void);

#endif
