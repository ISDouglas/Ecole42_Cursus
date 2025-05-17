/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:12:14 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 14:24:50 by layang           ###   ########.fr       */
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
		if (tab->nb_eat > 0 && tab->eat_counter != SEM_FAILED)
		{
			sem_close(tab->eat_counter);
			sem_unlink("/eat_counter");
		}
		sem_unlink("/sem_forks");
		sem_unlink("/s_print");
	}
	free(tab);
}

void	wait_some_philos(t_table *tab, pid_t *pids, int nb_created)
{
	int	j;

	j = 0;
	while (j < nb_created)
	{
		kill(pids[j], SIGTERM);
		j++;
	}
	j = 0;
	while (j < nb_created)
	{
		waitpid(pids[j], NULL, 0);
		j++;
	}
	ft_free_philo(tab, 7);
	free(pids);
}
