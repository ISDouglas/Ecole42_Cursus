/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:31:48 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 15:36:30 by layang           ###   ########.fr       */
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

void	ft_inter(char *s1, char *s2)
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
}
int	main(int ac, char	**av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}