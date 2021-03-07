/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:11:53 by apuchill          #+#    #+#             */
/*   Updated: 2020/11/04 16:14:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: find length of two dimensional array
**
** DESCRIPTION:
** 		The strlen_2() function computes the length of the two dimensional
**		array s.
*/

#include "libft.h"

size_t	ft_strlen_2(char **s)
{
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}
