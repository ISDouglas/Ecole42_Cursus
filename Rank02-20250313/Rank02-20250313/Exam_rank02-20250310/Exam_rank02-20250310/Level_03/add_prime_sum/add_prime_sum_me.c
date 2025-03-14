/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum_me.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:52:20 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 12:46:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char	*s)
{
	int result;
	int	i;
	
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
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result);
}

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int n)
{
	char	c;
	
	if (n > 9)
		put_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char	**av)
{
	int	i;
	int	nbr;
	int	result;

	if (ac == 2 && ft_atoi(av[1]) > 1)
	{
		nbr = ft_atoi(av[1]);
		i = 2;
		result = 0;
		while (i <= nbr)
		{
			if (is_prime(i))
				result += i;
			i++;
		}
		put_nbr(result);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
