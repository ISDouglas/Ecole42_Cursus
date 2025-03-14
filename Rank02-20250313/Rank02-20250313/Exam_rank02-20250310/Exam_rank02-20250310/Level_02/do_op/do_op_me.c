/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:26:11 by layang            #+#    #+#             */
/*   Updated: 2025/01/02 11:53:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int	ac, char	**av)
{
	int	av1;
	int	av3;
	int	result;
	
	if (ac == 4)
	{
		av1 = atoi(av[1]);
		av3 = atoi(av[3]);
		if (*av[2] == '*')
			result = av1 * av3;
		else if (*av[2] == '+')
			result = av1 + av3;
		else if (*av[2] == '-')
			result = av1 - av3;
		else if (*av[2] == '%')
			result = av1 % av3;
		else if (*av[2] == '/')
			result = av1 / av3;
		if (result)
			printf("%d", result);
	}
	printf("\n");
	return (0);
}

