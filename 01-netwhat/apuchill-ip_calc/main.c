/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/02/17 22:53:07 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char const *argv[])
{
	printf(CYAN("\n========================== ∙ netwhat - IP calculator ∙ =========================\n"));
	printf(VIOLET("                                                       by apuchill   @42saopaulo\n"));

	unsigned int	CIDR;
	unsigned int	mask[4] = { 0 };
	unsigned int 	IP[4] = { 0 };
	unsigned int 	subnet[4] = { 0 };
	unsigned int 	host[4] = { 0 };
	unsigned int 	range[4] = { 0 };
	int				i;
	int				avail_IP_addrs;

	CIDR = 0;
	i = 0;

/*
** If subnet mask or CIDR is provided
*/
	if (argc == 2)
	{
		if (strchr(argv[1], '.'))
			CIDR = get_CIDR(argv[1], mask);
		else
			CIDR = get_mask(argv[1], mask);

		avail_IP_addrs = pow(2, 32 - CIDR);

		printf(V_YELLOW("* Provided Mask:"));
		printf(" %u (CIDR) | %u.%u.%u.%u\n\t\t ", CIDR, mask[0], mask[1], mask[2], mask[3]);
		print_binary_IP(mask);
		printf(GREEN("\n\n* Max nbr of hosts:"));
		printf(" %d hosts\n", (avail_IP_addrs <= 2) ? avail_IP_addrs : avail_IP_addrs - 2);
		printf(GREEN("* Total addresses:") "  %d addresses (including host and broadcast)", avail_IP_addrs);
	}

/*
** If IP address is provided
*/
	else if (argc == 3)
	{
		get_IP(argv[1], IP);

		if (strchr(argv[2], '.'))
			CIDR = get_CIDR(argv[2], mask);
		else
			CIDR = get_mask(argv[2], mask);

		avail_IP_addrs = pow(2, 32 - CIDR);

		i = 0;
		while (i < 4)
		{
			subnet[i] = IP[i] & mask[i];
			range[i] = subnet[i];
			i++;
		}

		i = 0;
		while (i < 4)
		{
			host[i] = IP[i] & ~mask[i];
			i++;
		}

		range[3] += (avail_IP_addrs - 1);
		if (avail_IP_addrs > 255)
			range[3] -= (avail_IP_addrs % 256);

		i = 3;
		while (i > 0)
		{
			while (range[i] > 255)
			{
				range[i - 1]++;
				range[i] -= 256;
			}
			i--;
		}

		printf(V_YELLOW("* Provided IP:\t"));
		printf("%u.%u.%u.%u\n\t\t", IP[0], IP[1], IP[2], IP[3]);
		print_binary_IP(IP);

		printf(V_YELLOW("\n* Provided Mask:"));
		printf(" %u (CIDR)\n\t\t %u.%u.%u.%u\n\t\t ", CIDR, mask[0], mask[1], mask[2], mask[3]);
		print_binary_IP(mask);

		printf(GREEN("\n\n* Host:\t"));
		printf("%u.%u.%u.%u / %u\n\t", subnet[0], subnet[1], subnet[2], subnet[3], CIDR);
		print_binary_IP(subnet);

		printf(GREEN("\n* Host range:"));
		printf(" %u.%u.%u.%u - %u.%u.%u.%u", subnet[0], subnet[1], subnet[2], subnet[3], range[0], range[1], range[2], range[3]);

		printf(BLUE("\n\n* IP (No Host):\t"));
		printf("%u.%u.%u.%u\n\t\t", host[0], host[1], host[2], host[3]);
		print_binary_IP(host);

		printf(GREEN("\n\n* Max nbr of hosts:"));
		printf(" %d hosts\n", (avail_IP_addrs <= 2) ? avail_IP_addrs : avail_IP_addrs - 2);

		printf(GREEN("* Total addresses:"));
		printf("  %d addresses (including host and broadcast)", avail_IP_addrs);

	}

	else
	{
		printf(RED("\nError: Please provide a valid subnet mask, CIDR and/or IP address"));
	}

	printf(CYAN("\n\n================================================================================\n\n"));

	return (0);
}
