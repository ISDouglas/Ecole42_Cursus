/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:05:32 by layang            #+#    #+#             */
/*   Updated: 2025/01/07 12:53:46 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char	*str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
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

void	putnbr(int nb)
{
    long	n;

	n = nb;
	if (n > 9)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(int ac, char	**av)
{
	int	i;
	int	nb;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb >= 0 && nb * 9 <= 2147483647)
		{
			i = 1;
			while (i <= 9)
			{
				putnbr(i);
				write(1, " x ", 3);
				putnbr(nb);
				write(1, " = ", 3);
				putnbr(nb * i);
				if (i < 9)
					write(1, "\n", 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
