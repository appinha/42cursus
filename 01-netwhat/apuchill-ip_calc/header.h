/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:50:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/17 22:50:43 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define BLACK(string)		"\033[30m" string "\033[0m"
# define GRAY(string)		"\033[38;5;8m" string "\033[0m"
# define L_GRAY(string)		"\033[38;5;245m" string "\033[0m"
# define RED(string)		"\033[31m" string "\033[0m"
# define L_RED(string)		"\033[38;5;9m" string "\033[0m"
# define GREEN(string)		"\033[32m" string "\033[0m"
# define D_GREEN(string)	"\033[38;5;22m" string "\033[0m"
# define V_GREEN(string)	"\033[38;5;82m" string "\033[0m"
# define PETROL_G(string)	"\033[38;5;23m" string "\033[0m"
# define PETROL_B(string)	"\033[38;5;24m" string "\033[0m"
# define YELLOW(string)		"\033[38;5;11m" string "\033[0m"
# define V_YELLOW(string)	"\033[33m" string "\033[0m"
# define L_YELLOW(string)	"\033[38;5;191m" string "\033[0m"
# define BLUE(string)		"\033[34m" string "\033[0m"
# define V_BLUE(string)		"\033[38;5;27m" string "\033[0m"
# define VIOLET(string)		"\033[35m" string "\033[0m"
# define PINK(string)		"\033[38;5;199m" string "\033[0m"
# define LILAC(string)		"\033[38;5;13m" string "\033[0m"
# define PURPLE(string)		"\033[38;5;93m" string "\033[0m"
# define CYAN(string)		"\033[36m" string "\033[0m"
# define V_CYAN(string)		"\033[38;5;44m" string "\033[0m"
# define ORANGE(string)		"\033[38;5;166m" string "\033[0m"
# define V_ORANGE(string)	"\033[38;5;202m" string "\033[0m"

# define HEADER_T(string)	"\033[1m\033[38;5;199m" string "\033[0m"
# define HEADER_L(string)	"\033[38;5;43m" string "\033[0m"
# define HEADER_A(string)	"\033[1m\033[38;5;23m" string "\033[0m"
# define PROVIDED(string)	"\033[32m" string "\033[0m"

void 			byte2binary(unsigned int n);
void 			print_binary_IP(unsigned int IP[4]);
void 			get_IP(char const *str, unsigned int IP[4]);
unsigned int	get_CIDR(char const *argv, unsigned int *mask);
unsigned int	get_mask(char const *argv, unsigned int *mask);

#endif
