/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer_me.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:45:10 by layang            #+#    #+#             */
/*   Updated: 2025/03/14 10:24:49 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_lower(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

void	to_recap(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i + 1] == '\0' && s[i] != ' ' && s[i] != '\t')
				s[i] -= 32;
			if ((s[i + 1] == ' ' || s[i + 1] == '\t') 
				&& s[i] != ' ' && s[i] != '\t')
					s[i] -= 32;
		}
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char	**av)
{
	int	i;
	
	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			to_lower(av[i]);
			to_recap(av[i]);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
