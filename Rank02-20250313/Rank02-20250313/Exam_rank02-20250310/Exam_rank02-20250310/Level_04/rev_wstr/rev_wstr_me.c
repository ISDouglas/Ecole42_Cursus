/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:13:30 by layang            #+#    #+#             */
/*   Updated: 2025/01/07 12:52:14 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_word(int start, char	*str)
{
	while (str[start] && str[start] != ' ' && str[start] != '\t')
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int ac, char	**av)
{
	int	i;
	
	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			print_word(i + 1, av[1]);
			if (i != -1)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
