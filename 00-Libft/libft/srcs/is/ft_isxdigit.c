/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:20:55 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:56:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: hexadecimal-digit character test
**
** DESCRIPTION:
** 		The isxdigit() function tests for any hexadecimal-digit character.
*/

int		ft_isxdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
	(c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}
