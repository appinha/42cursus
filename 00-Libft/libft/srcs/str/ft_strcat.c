/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:21:00 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:57:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: concatenate strings (s2 into s1)
**
** DESCRIPTION:
** 		The strcat() and strncat() functions append a copy of the null-
**	terminated string s2 to the end of the null-terminated string s1, then
**	add a terminating `\0'.  The string s1 must have sufficient space to hold
**	the result.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;

	i = ft_strlen(s1);
	while (*s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}
