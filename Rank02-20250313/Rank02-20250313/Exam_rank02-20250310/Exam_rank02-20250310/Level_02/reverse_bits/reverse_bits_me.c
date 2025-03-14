/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_me.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 02:21:16 by layang            #+#    #+#             */
/*   Updated: 2025/01/02 02:36:21 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char	octet)
{
	int	i;
	unsigned char	re;

	i = 8;
	re = 0;
	while (i > 0)
	{
		re = re * 2 + octet % 2;
		octet /= 2;
		i--;
	}
	return (re);
}

int	main(void)
{
	unsigned char oc;

	oc = 38;
	printf("octet is: %d\n", oc);
	printf("reverse octet is: %d\n", reverse_bits(oc));
	return (0);
}
