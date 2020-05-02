/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:30:50 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/19 14:08:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

/***********************/
/* Auxiliary functions */
/***********************/

void	res_test(int n)
{
	if (n == TEST_OK)
		printf(GREEN("[OK]\t"));
	if (n == TEST_KO)
		printf(RED("[KO]\t"));
	if (n == TEST_KO_I_11)
		printf(RED("[KO]\t") L_RED("ft didn't segfault\t"));
	if (n == TEST_ABORT)
		printf(YELLOW("[??]\t") L_YELLOW("the test has aborted for unknown reason\n"));
}

void	test_nbr(int nbr)
{
	printf(BLUE("  #%02d  "), nbr);
	fflush(stdout);
}

void	test_description(char *s)
{
	printf(L_GRAY("(%s)\n"), s);
}

void	test_type1_showres(size_t r1, size_t r2)
{
	printf("ft = %3zu | libc = %3zu\t", r1, r2);
}

void	test_type1(size_t (*p_ft)(const char *), size_t (*p_libc)(const char *), char *str)
{
	if (p_ft(str) == p_libc(str))
		res_test(TEST_OK);
	else
		res_test(TEST_KO);
	test_type1_showres(p_ft(str), p_libc(str));
}

void	test_type2(int (*p_ft)(int), int (*p_libc)(int), int lower, int upper)
{
	int i;

	i = lower;
	while (i < upper)
	{
		if (!!p_ft(i) != !!p_libc(i))
		{
			res_test(TEST_KO);
			printf(L_RED("ft doesn't handle basic input\t"));
			exit(0);
		}
		i++;
	}
	res_test(TEST_OK);
}


/******************/
/* Test functions */
/******************/

/* ft_strlen */

void	test_strlen_0(void)
{
	test_nbr(0);
	SANDBOX(
		size_t	(*p_ft)(const char *) = &ft_strlen;
		size_t	(*p_libc)(const char *) = &strlen;
		char	*str = "";
		test_type1(p_ft, p_libc, str);
	);
	test_description("empty string");
}

void	test_strlen_1(void)
{
	test_nbr(1);
	SANDBOX(
		size_t	(*p_ft)(const char *) = &ft_strlen;
		size_t	(*p_libc)(const char *) = &strlen;
		char	*str = "sais-tu compter ?";
		test_type1(p_ft, p_libc, str);
	);
	test_description("basic test");
}

void	test_strlen_2(void)
{
	test_nbr(2);
	SANDBOX(
		size_t	r1;
		size_t	r2;
		char	buff[0x100];
		int		offset;
		int		rnd_fd = open("/dev/urandom", O_RDONLY);
		const int test_count = 9001;

		if (rnd_fd < 0)
			res_test(TEST_ABORT);

		for (int i = 0; i < test_count; i++)
		{
			if (read(rnd_fd, buff, sizeof(buff)) > 0)
			{
				offset = rand() % sizeof(buff);
				buff[sizeof(buff) - 1] = 0;
				if ((r1 = ft_strlen(buff + offset)) != (r2 = strlen(buff + offset))) {
					res_test(TEST_KO);
					printf(L_RED("your function doesn't handle basic input\n"));
					break ;
				}
				else if (i == test_count - 1)
				{
					res_test(TEST_OK);
					printf("ft = %3s | libc = %3s\t", "-", "-");
				}
			}
			else
			{
				res_test(TEST_OK);
				printf("ft = %3s | libc = %3s\t", "-", "-");
			}
		}
	);
	test_description("numerous inputs");
}

void	test_strlen_3(void)
{
	test_nbr(3);
	SANDBOX(
		size_t	(*p_ft)(const char *) = &ft_strlen;
		size_t	(*p_libc)(const char *) = &strlen;
		char	*str = "01234567, AAAAAA, abc\xba e, ......, end of string !";
		test_type1(p_ft, p_libc, str);
	);
	test_description("string with \\xba");
}

void	test_strlen_4(void)
{
	test_nbr(4);
	SANDBOX(
		size_t	(*p_ft)(const char *) = &ft_strlen;
		size_t	(*p_libc)(const char *) = &strlen;
		char	*str = "♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪";
		test_type1(p_ft, p_libc, str);
	);
	test_description("unicode string");
}

void	test_strlen_5(void)
{
	test_nbr(5);
	SANDBOX_I(
		ft_strlen(NULL);
		res_test(TEST_KO_I_11);
	);
	test_description("function segfaults at NULL input");
}

/* ft_isalnum */

void	test_isalnum(void)
{
	SANDBOX(
		int		(*p_ft)(int) = &ft_isalnum;
		int		(*p_libc)(int) = &isalnum;
		test_type2(p_ft, p_libc, -1, 530);
	);
	test_description("numerous inputs: -1 < i < 530");
}

void	test_isalpha(void)
{
	SANDBOX(
		int		(*p_ft)(int) = &ft_isalpha;
		int		(*p_libc)(int) = &isalpha;
		test_type2(p_ft, p_libc, -1, 530);
	);
	test_description("numerous inputs: -1 < i < 530");
}

void	test_isascii(void)
{
	SANDBOX(
		int		(*p_ft)(int) = &ft_isascii;
		int		(*p_libc)(int) = &isascii;
		test_type2(p_ft, p_libc, -1, 530);
	);
	test_description("numerous inputs: -1 < i < 530");
}

void	test_isdigit(void)
{
	SANDBOX(
		int		(*p_ft)(int) = &ft_isdigit;
		int		(*p_libc)(int) = &isdigit;
		test_type2(p_ft, p_libc, -1, 530);
	);
	test_description("numerous inputs: -1 < i < 530");
}

void	test_isprint(void)
{
	SANDBOX(
		int		(*p_ft)(int) = &ft_isprint;
		int		(*p_libc)(int) = &isprint;
		test_type2(p_ft, p_libc, -1, 530);
	);
	test_description("numerous inputs: -1 < i < 530");
}
