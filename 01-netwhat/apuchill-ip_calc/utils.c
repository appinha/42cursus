/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:46:35 by apuchill          #+#    #+#             */
/*   Updated: 2020/03/09 15:46:35 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			byte2binary(unsigned int n)
{
	int	i;
	int b;

	i = 7;
	while (i >= 0)
	{
		b = n >> i;
		if (b & 1)
			printf(GRAY("%c"), '1');
		else
			printf(GRAY("%c"), '0');
		i--;
	}
}

void			print_binary_IP(unsigned int IP[4])
{
	byte2binary(IP[0]);
	printf(GRAY("."));
	byte2binary(IP[1]);
	printf(GRAY("."));
	byte2binary(IP[2]);
	printf(GRAY("."));
	byte2binary(IP[3]);
}

void			get_IP(char const *argv, unsigned int IP[4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			IP[j] = (IP[j] * 10) + (argv[i] - '0');
		else
			j++;
		i++;
	}
}

/*
** If decimal subnet mask is provided, get CIDR
*/
unsigned int	get_CIDR(char const *argv, unsigned int *mask)
{
	unsigned int	CIDR;
	unsigned int	t;
	int				i;

	CIDR = 0;
	i = 0;
	get_IP(argv, mask);
	while (i < 4) {
		t = mask[i];
		while (t & 0b10000000)
		{
			CIDR++;
			t = t << 1;
		}
		if (t == 0)
			i = 4;
		i++;
	}
	return (CIDR);
}

/*
** If CIDR is provided, get decimal subnet mask
*/
unsigned int	get_mask(char const *argv, unsigned int *mask)
{
	unsigned int	CIDR;
	int				i;
	int				j;
	int				k;

	CIDR = atoi(argv);
	i = CIDR;
	j = 0;
	k = 0;
	while (i > 0)
	{
		mask[j] = (0b10000000 | (mask[j] >> 1));
		if (++k == 8)
		{
			k = 0;
			j++;
		}
		i--;
	}
	return (CIDR);
}
