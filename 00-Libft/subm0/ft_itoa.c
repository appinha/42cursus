/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:23:36 by exam              #+#    #+#             */
/*   Updated: 2020/02/08 14:42:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	qty_dig(long int n)
{
	long int dig;

	dig = 1;
	while (n >= 10)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

char			*ft_itoa(int n)
{
	long int	n_aux;
	int			len;
	char		*res;
	int			i;

	n_aux = n;
	n_aux = (n_aux < 0 ? -n_aux : n_aux);
	len = qty_dig(n_aux) + (n < 0 ? 1 : 0);
	res = 0;
	if (!(res = malloc(len + 1)))
		return (0);
	res[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		res[i] = (n_aux % 10) + '0';
		n_aux /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
