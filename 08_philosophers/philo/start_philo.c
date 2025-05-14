/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:06 by layang            #+#    #+#             */
/*   Updated: 2025/05/14 17:46:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->tab->nb_phi == 1)
		return (only_one_philo());
	
}

int ft_start_philo(t_table  *tab)
{
	unsigned int	i;

	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	i = 0;
	while (i < tab->nb_phi)
	{
		if (pthread_create(&tab->philos[i]->thread, NULL,
				&philosopher, tab->philos[i]) != 0)
			return (perror("create philo thread"), ft_free_philo(tab, 7), 1);
		i++;
	}
	if (pthread_create(&tab->end_thread, NULL, &check_end, tab) != 0)
		return (perror("create end thread"), ft_free_philo(tab, 7), 1);
	return (0);
}
