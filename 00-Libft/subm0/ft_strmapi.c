/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:36:24 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/03 15:11:17 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s || !f || !(res = ft_strdup(s)))
		return (0);
	i = 0;
	while (res[i])
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
