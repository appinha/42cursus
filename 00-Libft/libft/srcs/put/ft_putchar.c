/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:36:12 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:56:26 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdio.h>
** SYNOPSIS: output a character to stdout
**
** DESCRIPTION:
** 		The putchar() function writes the character c (converted to an
**	``unsigned char'') to the output stream of stdout.
** 		[42 PDF] Outputs the character ’c’ to stdout.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
