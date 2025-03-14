/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_me_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:38:14 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 23:07:02 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_atoi(char	*s)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result * sign);
}

void	put_nbr_hex(long	n)
{
	if (n > 15)
		put_nbr_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	main(int ac, char	**av)
{
	long	nb;
	
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb >= 0)
		{
			put_nbr_hex(nb);
		}
	}
	write(1, "\n", 1);
	return (0);
}
