/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:06:15 by layang            #+#    #+#             */
/*   Updated: 2025/03/08 14:47:58 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_to_lower(char	*str)
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

void	str_capitalize(char	*str)
{
	int	i;

	str_to_lower(str);
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i - 1] && (str[i - 1] == ' '
				|| str[i - 1] == '\t') && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char	**argv)
{
	if (argc >= 2)
	{
		argv++;
		while (*argv)
		{
			str_capitalize(*argv);
			argv++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
