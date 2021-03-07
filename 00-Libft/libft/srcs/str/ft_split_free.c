/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:15:44 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/07 09:27:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: free ft_split() return pointer
**
** DESCRIPTION:
** 		The ft_split_free() function frees the memory space pointed to by s,
**		which must have been returned by a previous call to malloc() by the
**		ft_split() function.
*/

#include "libft.h"

void	ft_split_free(char **s)
{
	size_t	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (i < ft_strlen_2(s))
		free(s[i++]);
	free(s);
	*s = NULL;
}
