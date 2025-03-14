/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:30:36 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 16:33:25 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char	**av)
{
	int	i;
	
	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                write(1, "_", 1);
                av[1][i] += 32;
            }	
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
