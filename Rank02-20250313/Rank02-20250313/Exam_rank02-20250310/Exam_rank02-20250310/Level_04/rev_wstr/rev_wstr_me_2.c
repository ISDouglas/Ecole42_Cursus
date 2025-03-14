/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr_me_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:17:40 by layang            #+#    #+#             */
/*   Updated: 2025/03/11 13:35:37 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	put_word(char	*s, int start)
{
	while (s[start] && s[start] != ' ' && s[start] != '\t')
	{
		write(1, &s[start], 1);
		start++;
	}
}

int	main(int	ac, char	**av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i--;
			while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
				i--;
			put_word(av[1], i + 1);
			if (i != -1)
				write(1, " ", 1);	
		}
	}
	write(1, "\n", 1);
	return (0);
}
