/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:47:52 by layang            #+#    #+#             */
/*   Updated: 2025/01/02 15:06:13 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

/* int	main(int ac, char	**av)
{
	int	n1;
	int	n2;

	if (ac < 2)
	{
		printf("Put your number.");
		return (0);
	}
	n1 = ft_atoi(av[1]);
	n2 = atoi(av[1]);
	printf("ft_atoi: %d\n", n1);
	printf("atoi: %d\n", n2);
	return (0);
} */
