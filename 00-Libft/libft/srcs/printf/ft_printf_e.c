/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/31 12:37:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*fill_nbr_0s(char *nbr, int precision)
{
	char	str[precision + 3];
	char	*a;
	size_t	strlen;
	int		i;

	strlen = ft_strlen(nbr);
	if (precision == 0)
		ft_strlcpy(str, nbr, 2);
	else
	{
		ft_strlcpy(str, nbr, strlen + 1);
		i = strlen;
		while (i <= precision + 1)
			str[i++] = '0';
		str[i] = '\0';
	}
	a = ft_strdup(str);
	return (a);
}

static t_flags	get_0nbr_e_verifs(t_flags fl, int *j)
{
	*j = 1;
	while (fl.d[++(*j)] != '\0')
	{
		if ((ft_strchr_01("123456789", fl.d[*j])) == 1)
			break ;
	}
	free(fl.d);
	fl.d = ft_ftoa_rnd(fl.f, (*j - 1) + fl.precision, 5);
	*j = 1;
	while (fl.d[++(*j)] != '\0')
	{
		if (fl.d[*j] == '0')
		{
			fl.d[*j] = '.';
			fl.d[(*j) - 1] = '0';
		}
		else if ((fl.d[*j - 1] = fl.d[*j]))
		{
			fl.d[*j] = '.';
			break ;
		}
	}
	fl.e_nbr = -((*j) - 1);
	fl.tmp = ft_substr(fl.d, (*j) - 1, ft_strlen(fl.d) - ((*j) - 1));
	return (fl);
}

static t_flags	get_0nbr_e(t_flags fl, int *j)
{
	ft_strlcpy(fl.e, "e-", 3);
	fl.size = 1;
	fl.d = ft_ftoa_rnd(fl.f, fl.size, 5);
	*j = 1;
	while (fl.d[++(*j)] != '\0' && *j <= 18)
	{
		if ((fl.size++) && (ft_strchr_01("123456789", fl.d[*j])) == 1)
			break ;
		free(fl.d);
		fl.d = ft_ftoa_rnd(fl.f, fl.size, 5);
	}
	if (*j > 18 && (fl.e[1] = '+'))
	{
		free(fl.d);
		fl.d = fill_nbr_0s("0.", fl.precision);
		return (fl);
	}
	fl = get_0nbr_e_verifs(fl, j);
	free(fl.d);
	if (ft_strlen(fl.tmp) >= fl.strlen)
		fl.d = ft_substr(fl.tmp, 0, fl.strlen);
	else
		fl.d = fill_nbr_0s(fl.tmp, fl.precision);
	free(fl.tmp);
	return (fl);
}

static t_flags	get_nbr_e(t_flags fl, unsigned long long int i_part, int *j)
{
	ft_strlcpy(fl.e, "e+", 3);
	while (i_part /= 10)
		fl.e_nbr++;
	fl.d = ft_ftoa_rnd((fl.f / ft_pow(10, fl.e_nbr)), fl.precision, 5);
	*j = ft_strlen(fl.d);
	while (--(*j) >= 0)
	{
		if (fl.d[*j] == '.' && *j >= 2)
		{
			fl.d[*j] = fl.d[(*j) - 1];
			fl.d[(*j) - 1] = '.';
		}
	}
	if (ft_strlen(fl.d) > fl.strlen)
	{
		fl.tmp = ft_substr(fl.d, 0, fl.strlen);
		fl.e_nbr += ft_strlen(fl.d) - fl.strlen;
		free(fl.d);
		fl.d = fl.tmp;
	}
	return (fl);
}

t_flags			print_spec_e(t_flags fl, double n)
{
	int		j;

	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.e_nbr = 0;
	fl.strlen = (fl.precision > 0) ? (size_t)fl.precision + 2 : 1;
	if (fl.ulli > 0)
		fl = get_nbr_e(fl, fl.ulli, &j);
	else
		fl = get_0nbr_e(fl, &j);
	fl.tmp = ft_ullitoa_base(((fl.e_nbr > 0) ? fl.e_nbr : -fl.e_nbr), DIGITS);
	if ((ft_strlen(fl.tmp)) == 1 && (ft_strlcat(fl.e, "0", 4)))
		ft_strlcat(fl.e, fl.tmp, 5);
	else
		ft_strlcat(fl.e, fl.tmp, 5);
	free(fl.tmp);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.d, ".");
		free(fl.d);
		fl.d = fl.tmp;
	}
	fl.a = ft_strjoin(fl.d, fl.e);
	return (fl);
}
