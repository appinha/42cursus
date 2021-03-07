/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:03:08 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/31 12:37:44 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(int *len, t_flags fl)
{
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+') ||
		(fl.space == 1 && fl.plus == 0 && fl.sign == '+'))
		fl.width--;
	if (fl.precision <= (int)fl.strlen)
		fl.precision = (int)fl.strlen;
	if (fl.pad_c == '0' && (fl.minus == 1 || fl.point == 1) &&
		!(fl.spe_c == 'f' && fl.minus == 0))
		fl.pad_c = ' ';
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

static void	print_zeros(int *len, t_flags fl)
{
	int		j;

	if ((fl.spe_c == 'x' && fl.hash == 1) || fl.spe_c == 'p')
		ft_putcstr_len("0x", len, 2);
	if (fl.spe_c == 'X' && fl.hash == 1)
		ft_putcstr_len("0X", len, 2);
	if (fl.spe_c == 'o' && fl.hash == 1)
		ft_putchar_len('0', len);
	if (fl.minus == 0 && fl.pad_c == '0')
		print_width(len, fl);
	if (fl.point == 1)
	{
		j = fl.precision;
		while (j-- > (int)fl.strlen)
			ft_putchar_len('0', len);
	}
}

void		print_flags(int *len, t_flags fl)
{
	fl.strlen = ft_strlen(fl.a);
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0 && fl.print_n0 == 0)
		fl.width++;
	if (((fl.spe_c == 'x' || fl.spe_c == 'X') && fl.hash == 1) ||
			fl.spe_c == 'p')
		fl.width -= 2;
	if (fl.spe_c == 'o' && fl.hash == 1)
		fl.width -= 1;
	if (fl.spe_c == 'o' && fl.hash == 1 && fl.point == 1)
		fl.precision -= 1;
	if (fl.point == 1 && fl.spe_c != 'f')
		fl.pad_c = ' ';
	if (fl.minus == 0 && fl.pad_c == ' ')
		print_width(len, fl);
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	if (fl.space == 1 && fl.plus == 0 && fl.sign == '+')
		ft_putchar_len(' ', len);
	print_zeros(len, fl);
	if (!(fl.ulli == 0 && fl.point == 1 && fl.precision == 0) ||
		fl.print_n0 == 1)
		ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (fl.minus == 1)
		print_width(len, fl);
}
