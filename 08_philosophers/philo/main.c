/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:32 by layang            #+#    #+#             */
/*   Updated: 2025/05/09 10:32:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

int	ft_init_table(t_table	*tab, char	**av)
{
	tab->nb_phi = ft_atoi(av[1]);
	tab->t_die = ft_atoi(av[2]);
	tab->t_eat = ft_atoi(av[3]);
	tab->t_sleep = ft_atoi(av[4]);
	if (av[5])
		tab->nb_eat = ft_atoi(av[5]);
	else
		tab->nb_eat = 0;
	tab->forks = malloc(sizeof(pthread_mutex_t) * tab->nb_phi);
	if (!tab->forks)
		return (1);
	if (pthread_mutex_init(&tab->log, NULL) != 0)
		return (2);
	tab->philos = malloc(sizeof(t_philo) * tab->nb_phi);
	if (!tab->philos)
		return (3);
	tab->dead = 0;
	tab->start_time = ft_get_time();
	return (init_philos(&tab->philos));
}

void	ft_free_philo(t_table	*tab, int sign)
{
	if (sign == 2 || sign == 3)
	{
		free(tab->forks);
		if (sign == 3)
			pthread_mutex_destroy(&tab->log);
	}
}

int	main(int	ac, char	**av)
{
	t_table		tab;
	int			init;

	if (ac != 5 || ac != 6)
		return(printf("nb_philo, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	// ctr on not more than 200 philos and not less than 60ms.
    init = ft_init_table(&tab, av);
	if (init && init != 1)
		return (ft_free_philo(&tab, init), 1);
	ft_start_philo();
	return (0);
}
