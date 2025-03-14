/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:38:16 by layang            #+#    #+#             */
/*   Updated: 2025/03/14 13:09:39 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char	**av)
{
	int		a;
	int		b;
	long	re;
    
    if (ac == 4)
	{
        a = atoi(av[1]);
        b = atoi(av[3]);
		//re = 0;
        if (av[2][1] == '\0')
        {
			if (av[2][0] == '+')
				re = a + b;
			if (av[2][0] == '-')
				re = a - b;
			if (av[2][0] == '*')
				re = a * b;
			if (av[2][0] == '/')
			{
				if (b == 0)
					re = 0;
				else
					re = a / b;
			}
			if (av[2][0] == '%')
				re = a % b;
        }
		if (re)
			printf("%ld", re);
	}
	printf("\n");
	return (0);
}

//cc -Werror -Wall -Wextra
