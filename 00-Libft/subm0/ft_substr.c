/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:24:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/07 23:13:32 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!s || !(str = (char *)malloc(len + 1)))
		return (0);
	size = len;
	if (len > ft_strlen(s) && start < ft_strlen(s))
		size = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		if (!(str = (char *)malloc(1)))
			return (0);
		str[0] = '\0';
		return (str);
	}
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
