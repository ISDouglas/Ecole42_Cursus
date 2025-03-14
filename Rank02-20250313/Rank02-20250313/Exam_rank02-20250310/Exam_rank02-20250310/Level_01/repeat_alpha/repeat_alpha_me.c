/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha_me.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:51:50 by layang            #+#    #+#             */
/*   Updated: 2024/12/29 12:29:07 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char	**av)
{
	int	repeat;

	if (ac == 2)
	{
		while (*av[1])
		{
			repeat = 1;
			if (*av[1] >= 'A' && *av[1] <= 'Z')
				repeat = *av[1] - 64;
			else if (*av[1] >= 'a' && *av[1] <= 'z')
				repeat = *av[1] - 96;
			while (repeat--)
				write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
