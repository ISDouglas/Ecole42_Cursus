/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:06 by layang            #+#    #+#             */
/*   Updated: 2025/05/14 13:44:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	
}

int ft_start_philo(t_table  *tab)
{
	unsigned int	i;

	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	i = 0;
	while (i < tab->nb_phi)
	{
		if (pthread_create(&tab->philos[i]->thread, NULL,
				&philosopher, tab->philos[i]) != 0)  //add table in philo
			return (ft_free_philo(tab, 7), 1);
		i++;
	}
	if (tab->nb_phi == 1)
		return (only_one_philo());
	return (0);
}