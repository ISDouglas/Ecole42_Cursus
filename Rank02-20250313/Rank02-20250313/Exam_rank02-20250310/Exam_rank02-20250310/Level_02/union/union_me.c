/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:38:41 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 08:47:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_new(char *s, int max, char c)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s2[j])
			j++;
	while (s1[i])
	{
		if (is_new(s1, i, s1[i]) && !is_new(s2, j, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
    j = 0;
    while (s2[j])
	{
		if (is_new(s2, j, s2[j]) && is_new(s1, i, s2[j]))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int ac, char	**av)
{
	int	repeat;

	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
