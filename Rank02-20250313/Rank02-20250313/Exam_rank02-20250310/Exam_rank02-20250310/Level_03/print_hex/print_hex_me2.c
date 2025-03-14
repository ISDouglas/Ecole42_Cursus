/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_me2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:58:47 by layang            #+#    #+#             */
/*   Updated: 2025/01/07 10:17:02 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char	*str)
{
	long	nb;
	int		sign;

	sign = 1;
	nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

void	put_hex(long nb)
{
	if (nb > 15)
		put_hex(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int	main(int ac, char	**av)
{
	if (ac == 2)
	{
		if (ft_atoi(av[1]) && ft_atoi(av[1]) >= 0)
			put_hex((long)ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
