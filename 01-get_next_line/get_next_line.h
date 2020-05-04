/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 20:31:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/04/27 17:27:14 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define READL_OK 1
# define EOF_RCHD 0
# define ERR_HPND -1

int		get_next_line(int fd, char **line);

/*
** Utils
*/

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
