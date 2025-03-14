/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:22:08 by layang            #+#    #+#             */
/*   Updated: 2025/03/11 03:27:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);

int	main(int ac, char	**av)
{
	char	**re;
	int		i;

	if (ac == 1 || ac != 2)
	{
		printf("Put 1 string as parameters\n");
		return (0);
	}
	re = ft_split(av[1]);
	i = 0;
	while (re[i] != NULL)
	{
		printf("%d: %s\n", i, re[i]);
		free(re[i]);
		i++;
	}
	free(re);
	return (0);
}
