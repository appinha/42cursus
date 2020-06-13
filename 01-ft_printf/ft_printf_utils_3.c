/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 02:05:16 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/28 01:45:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_pow(long double n, unsigned int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

char		*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	while (n /= b_len)
		size++;
	if (!(a = (char *)malloc(size + 1)))
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}

long double	ft_fmod(long double n, long double mod)
{
	while (n >= mod)
		n -= mod;
	return (n);
}
