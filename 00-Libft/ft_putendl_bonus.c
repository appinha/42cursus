/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:54:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/19 14:05:08 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: output string to stdout with newline
**
** DESCRIPTION:
** 		Outputs the string ’s’ to stdout, followed by a newline.
*/

#include "libft.h"

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
