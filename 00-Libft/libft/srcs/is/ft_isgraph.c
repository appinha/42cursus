/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:42:00 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:54:46 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: printing character test (space character exclusive)
**
** DESCRIPTION:
** 		 The isgraph() function tests for any printing character except space
**	(` ') and other locale-specific, space-like characters.
*/

int		ft_isgraph(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
