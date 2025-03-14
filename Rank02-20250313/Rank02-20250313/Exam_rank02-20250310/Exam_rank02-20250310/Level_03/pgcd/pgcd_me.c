/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:29:30 by layang            #+#    #+#             */
/*   Updated: 2025/01/07 10:26:30 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int pgcd(unsigned int a, unsigned int b)
{
	int	gcd;

	gcd = 0;
	while (1)
	{
		if (a == 0)
			break;
		b %= a;
		if (b == 0)
			break;
		a %= b;
	}
	if (b == 0)
		gcd = a;
    else
        gcd = b;
	return (gcd);
}
int	main(int ac, char	**av)
{
	if (ac == 3)
	{
		if (atoi(av[1]) > 0 && atoi(av[2]) > 0)
			printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	}
	printf("\n");
	return (0);
}
