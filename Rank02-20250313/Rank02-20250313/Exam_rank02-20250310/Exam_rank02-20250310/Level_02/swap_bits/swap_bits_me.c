/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 02:30:45 by layang            #+#    #+#             */
/*   Updated: 2025/01/02 02:52:02 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	swap_bits(unsigned char	octet)
{
	return ((octet >> 4) | (octet << 4));
}

void print_bts(unsigned char	c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			write(1, "1", 1);
			c %= i;
			i /= 2;
		}
		else
		{
			write(1, "0", 1);
			i /= 2;
		}
	}
}

int	main(void)
{
	unsigned char	c;

	c = 65;
	write(1, "c is:\n", 6);
	print_bts(c);
	write(1, "\n", 1);
	write(1, "swap c is:\n", 11);
	print_bts(swap_bits(c));
	write(1, "\n", 1);
	return (0);
}
