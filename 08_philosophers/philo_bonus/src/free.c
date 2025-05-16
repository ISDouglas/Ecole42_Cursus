/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:12:14 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 19:43:25 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    free_philos(t_table	*tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab->philos[i]);
		tab->philos[i] = NULL;
		i++;
	}
}

void	ft_free_philo(t_table	*tab, int sign)
{
	if (sign > 5 && tab->philos)
		free_philos(tab, tab->nb_phi);
	if (sign > 4)
	{
		free(tab->philos);
		tab->philos = NULL;
	}
	if (sign >= 3)
	{
		if (tab->sem_forks != SEM_FAILED)
			sem_close(tab->sem_forks);
		if (tab->s_print != SEM_FAILED)
			sem_close(tab->s_print);
		if (tab->eat_counter != SEM_FAILED)
			sem_close(tab->eat_counter);
		sem_unlink("/sem_forks");
		sem_unlink("/s_print");
		sem_unlink("/eat_counter");
	}
	free(tab);
}
    