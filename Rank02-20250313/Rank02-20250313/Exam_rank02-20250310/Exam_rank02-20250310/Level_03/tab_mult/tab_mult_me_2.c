/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult_me_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:17:26 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 13:17:27 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char	*s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			return (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result <= 2147483647 / (10 * 9))
		{
			result = result * 10 + s[i] - '0';
			i++;
		}
		else
			return (-1);
	}
	return (result);
}

//r * 10 * 9 > 2147483647

void	put_nbr(int	n)
{
	if (n > 9)
		put_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);	
}

int	main(int ac, char	**av)
{
	int i;
	int	nb;

	if (ac == 2)
	{
		i = 1;
		nb = ft_atoi(av[1]);
		if (nb >= 0)
		{
			while (i <= 9)
			{
				put_nbr(i);
				write(1, " x ", 3);
				put_nbr(nb);
				write(1, " = ", 3);
				put_nbr(i * nb);
				if (i <= 8)
					write(1, "\n", 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
