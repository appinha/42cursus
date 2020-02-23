/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:34:35 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/19 14:05:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: output string to stdout
**
** DESCRIPTION:
** 		Outputs the string ’s’ to stdout.
*/

#include "libft.h"

void	ft_putstr(char *s)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
