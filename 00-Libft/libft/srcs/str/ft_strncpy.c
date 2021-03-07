/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:01:11 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:57:49 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: copy strings (size-bounded)
**
** DESCRIPTION:
** 		The stpcpy() and strcpy() functions copy the string s2 to s1 (including
**	the terminating `\0' character).
** 		The strncpy() function copies at most n characters from s2 into s1.  If
**	s2 is less than n characters long, the remainder of s1 is filled with
**	`\0' characters.  Otherwise, s1 is not terminated.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((src[i] != '\0') && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
