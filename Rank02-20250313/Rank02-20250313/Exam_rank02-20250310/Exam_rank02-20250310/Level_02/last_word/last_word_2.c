/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:51:26 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 15:08:47 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char	*s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] >= 33 && s[i + 1] < 127)
			j = i + 1;
		i++;
	}
	while (s[j] >= 33 && s[j] < 127)
	{
		write(1, &s[j], 1);
		j++;
	}
}

int	main(int ac, char	**av)
{
	if (ac == 2)
        last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
