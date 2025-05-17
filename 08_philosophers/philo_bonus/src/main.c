/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:31:37 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 15:14:59 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* static int	ft_start_philo(t_table	*tab)
{
	int		i;
	pid_t	*pids;

	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	pids = malloc(sizeof(pid_t) * tab->nb_phi);
	if (!pids)
		return (perror("malloc pids"), ft_free_philo(tab, 6), -1);	
		i = fork_philos(tab, &pids);
	if (i == tab->nb_phi)
		monitor_death(tab, pids);
	else
		kill_philos(tab, pids, i);
	free(pids);
	pids = NULL;
} */

static int	ft_start_philo(t_table	*tab)
{
	int		i;

	i = 0;
	while (i < tab->nb_phi)
	{
		if ()
		i++;
	}
}

int main(int ac, char	**av)
{
    t_table		*tab;
	int			init;

	if (ac != 5 && ac != 6)
		return (printf("nb_phi, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	init = init_table(&tab, av); 
	if (init < 0)
		return (0);
	if (init)
		return (ft_free_philo(tab, init), 0);
	if (ft_start_philo(tab))
		return (1);
	ft_free_philo(tab, 6);
	return (0);
}
