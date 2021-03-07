/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:54:33 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:57:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <math.h>
** SYNOPSIS: square root function
**
** DESCRIPTION:
** 		The sqrt() function compute the non-negative square root of x.
*/

double	ft_sqrt(double x)
{
	double	n;

	n = 1;
	if (x > 0)
	{
		while (n * n <= x)
		{
			if (n * n == x)
				return (n);
			n++;
		}
	}
	return (0);
}
