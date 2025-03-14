/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd_me_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:21:50 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 19:54:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char	**av)
{
	unsigned int	a;
 	unsigned int	b;
	
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (1)
		{
			if (a == 0)
				break ;
			b %= a;
			if (b == 0)
				break ;
			a %= b;
		}
		if (b == 0)
			printf("%d", a);
		else
			printf("%d", b);
	}
	printf("\n");
	return (0);
}

/* int	main(int ac, char	**av)
{
	unsigned int	a;
 	unsigned int	b;
	
	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		while (a != b)
		{
			if (a >= b)
				a -= b;
			else
				b -= a;
		}
		printf("%d", a);
	}
	printf("\n");
	return (0);
}
 */