/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:21:10 by layang            #+#    #+#             */
/*   Updated: 2025/05/13 12:24:23 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* Description: Converts the initial portion of the string pointed to by str  */
/* to int.                                                                    */
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}
