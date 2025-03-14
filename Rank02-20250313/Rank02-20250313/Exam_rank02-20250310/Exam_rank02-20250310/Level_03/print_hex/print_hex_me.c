/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:52:53 by layang            #+#    #+#             */
/*   Updated: 2025/01/04 11:17:49 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char	*str)
{
	char	sign;
	long	nb;

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
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

/* int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
} */

void	ft_putnbr(int nb)
{
	long	ln;
	char	ch;

	ln = nb;
	if (ln > 15)
		ft_putnbr(ln / 16);
	ch = "0123456789abcdef"[ln % 16];
	write(1, &ch, 1);
}
int		main(int ac, char **av)
{
    if (ac == 2 && ft_atoi(av[1]) >= 0)
	    ft_putnbr(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
