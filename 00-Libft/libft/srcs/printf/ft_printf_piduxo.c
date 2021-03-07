/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_piduxo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/31 12:37:48 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_p(int *len, t_flags fl, unsigned long int p)
{
	fl.sign = 'u';
	fl.print_n0 = 0;
	fl.a = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_i_d_u(int *len, t_flags fl, va_list args)
{
	if (fl.spe_c == 'i' || fl.spe_c == 'd')
	{
		if (fl.length <= 0)
			fl.lli = va_arg(args, int);
		if (fl.length == 1)
			fl.lli = va_arg(args, long int);
		if (fl.length >= 2)
			fl.lli = va_arg(args, long long int);
		fl.sign = (fl.lli >= 0) ? '+' : '-';
		fl.ulli = (fl.lli >= 0) ? fl.lli : -fl.lli;
	}
	if (fl.spe_c == 'u')
	{
		if (fl.length <= 0)
			fl.ulli = va_arg(args, unsigned int);
		if (fl.length == 1)
			fl.ulli = va_arg(args, unsigned long int);
		if (fl.length >= 2)
			fl.ulli = va_arg(args, unsigned long long int);
		fl.sign = 'u';
	}
	fl.print_n0 = 0;
	fl.a = ft_ullitoa_base(fl.ulli, DIGITS);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_x(int *len, t_flags fl, va_list args)
{
	if (fl.length <= 0)
		fl.ulli = va_arg(args, unsigned int);
	if (fl.length == 1)
		fl.ulli = va_arg(args, unsigned long int);
	if (fl.length >= 2)
		fl.ulli = va_arg(args, unsigned long long int);
	fl.sign = 'u';
	fl.print_n0 = 0;
	if (fl.ulli == 0)
		fl.hash = 0;
	if (fl.spe_c == 'x')
		fl.a = ft_ullitoa_base(fl.ulli, HEXALOW);
	if (fl.spe_c == 'X')
		fl.a = ft_ullitoa_base(fl.ulli, HEXAUPP);
	print_flags(len, fl);
	free(fl.a);
}

void	print_spec_o(int *len, t_flags fl, va_list args)
{
	if (fl.length <= 0)
		fl.ulli = va_arg(args, unsigned int);
	if (fl.length == 1)
		fl.ulli = va_arg(args, unsigned long int);
	if (fl.length >= 2)
		fl.ulli = va_arg(args, unsigned long long int);
	fl.sign = 'u';
	fl.print_n0 = 1;
	if (fl.point == 1 && fl.precision == 0 && fl.hash == 0)
		fl.print_n0 = 0;
	if (fl.ulli == 0)
		fl.hash = 0;
	fl.a = ft_ullitoa_base(fl.ulli, OCTAL);
	print_flags(len, fl);
	free(fl.a);
}
