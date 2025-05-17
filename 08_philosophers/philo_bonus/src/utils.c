/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:53:20 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 15:09:10 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	philo_pass_time(t_table	*tab, time_t	delay)
{
	time_t	wait_until;

	wait_until = ft_get_time() + delay;
	while (ft_get_time() < wait_until)
	{
		if (stop_arrived(tab))
			break ;
		usleep(100);
	}
}
