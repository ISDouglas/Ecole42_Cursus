/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:31:37 by layang            #+#    #+#             */
/*   Updated: 2025/05/18 21:59:47 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	run_child_philo(t_table	*tab, int i)
{
	pthread_t	tid_dead;

	if (pthread_create(&tid_dead, NULL, &monitor_death, tab->philos[i]) != 0)
		failed_thread("create monitor eat thread", 1, tab);
	if (pthread_detach(tid_dead) != 0)
	{
		pthread_join(tid_dead, NULL),
		failed_thread("detach monitor eat thread", 1, tab);
	}
	tab->philos[i]->last_meal = tab->start_time;
	philo->times.born_time = get_current_time();
	philo->times.last_meal = get_current_time();
}

static int	ft_start_philo(t_table	*tab)
{
	int			i;
	pthread_t	tid_meal;
	
	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	if (tab->nb_eat > 0)
	{
		if (pthread_create(&tid_meal, NULL, &monitor_eat, tab) != 0)
			return (failed_thread("create monitor eat thread", 0, tab), 1);
		if (pthread_detach(tid_meal) != 0)
			return (pthread_join(tid_meal, NULL),
					failed_thread("detach monitor eat thread", 0, tab), 1);
	}
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->pids[i] = fork();
		if (tab->philos[i] < 0)
			return (wait_some_philos(tab, i), 1);
		if (tab->pids[i] == 0)
			run_child_philo(tab, i);
		i++;
	}
	waitpid(-1, NULL, 0);
	return (0);
}

int main(int ac, char	**av)
{
    t_table		*tab;
	int			init;

	if (ac != 5 && ac != 6)
		return (printf("nb_phi, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	init = init_table(&tab, av); 
	if (init)
		return (ft_free_philo(tab, init), 0);
	if (ft_start_philo(tab))
		return (1);
	ft_free_philo(tab, 8);
	return (0);
}
