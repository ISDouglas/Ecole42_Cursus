/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:32 by layang            #+#    #+#             */
/*   Updated: 2025/04/18 13:33:20 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_schedule(t_schedule	*plan, char	**av)
{
	plan->nb_phi = ft_atoi(av[1]);
	plan->t_die = ft_atoi(av[2]);
	plan->t_eat = ft_atoi(av[3]);
	plan->t_sleep = ft_atoi(av[4]);
	if (av[5])
		plan->nb_eat = ft_atoi(av[5]);
	else
		plan->nb_eat = -1;
}

long	ft_get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

int	ft_init_table(t_schedule	*plan, t_table	*tab)
{
	tab->forks = malloc(sizeof(pthread_mutex_t) * plan->nb_phi);
	if (!tab->forks)
		return (1);
	if (pthread_mutex_init(&tab->log, NULL) != 0)
		return (2);
	tab->philos = malloc(sizeof(t_philo) * plan->nb_phi);
	if (!tab->philos)
		return (3);
	tab->dead = 0;
	tab->nb_eat = plan->nb_eat;
	tab->start_time = ft_get_time();
	return (0);
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
	t_schedule	plan;
	t_table		tab;
	int			init;

	if (ac != 5 || ac != 6)
		return(printf("nb_philo, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	// ctr on not more than 200 philos and not less than 60ms.
    ft_init_schedule(&plan, av);
	init = ft_init_table(&plan, &tab);
	if (init && init != 1)
		return (ft_free_philo(&tab, init), 1);
	ft_start_philo();
	return (0);
}
