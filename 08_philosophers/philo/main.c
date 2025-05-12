/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:32 by layang            #+#    #+#             */
/*   Updated: 2025/05/12 20:19:45 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

int	init_philos(t_philo	**philos, int nb)
{
	
}

int	wrong_input_check(t_table	*tab, char	*av5)
{
	if (av5)
	{
		if (ft_atoi(av5) <= 0)
			return (printf("nb of eat times must be positive.\n"), -1);
		else
			tab->nb_eat = ft_atoi(av5);			
	}
	else
		tab->nb_eat = -1;
	if (tab->nb_eat == 0)
		return (printf("number of eating is 0.\n"), -1);
	if (tab->nb_phi < 0 || tab->t_die < 0 || tab->t_eat < 0
			|| tab->t_sleep < 0)
		return (printf("time must be positive.\n"), -1);
	return (0);
}

int	init_forks(t_table	*tab)
{
	
}

int	init_table(t_table	*tab, char	**av)
{
	tab->nb_phi = ft_atoi(av[1]);
	tab->t_die = ft_atoi(av[2]);
	tab->t_eat = ft_atoi(av[3]);
	tab->t_sleep = ft_atoi(av[4]);
	if (wrong_input_check(tab, av[5]))
		return (-1);
	tab->forks_locks = init_forks(tab);   //need to finish
	if (!tab->forks_locks)
		return (1);
	//return (perror("malloc forks locks"), 1);
	if (pthread_mutex_init(&tab->log_lock, NULL) != 0)
		return (perror("pthread mutex log lock"), 2);
	tab->philos = malloc(sizeof(t_philo) * tab->nb_phi);
	if (!tab->philos)
		return (perror("malloc philos"), 3);
	tab->stop =  false;
	if (pthread_mutex_init(&tab->stop_lock, NULL) != 0)
		return (perror("pthread mutex stop lock"), 4);
	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	return (init_philos(&tab->philos, tab->nb_phi));
}

void	ft_free_philo(t_table	*tab, int sign)
{
	if (sign == 2 || sign == 3)
	{
		free(tab->forks_locks);
		if (sign == 3)
			pthread_mutex_destroy(&tab->log_lock);
	}
}

int	main(int	ac, char	**av)
{
	t_table		tab;
	int			init;

	if (ac != 5 || ac != 6)
		return(printf("nb_philo, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	// ctr on not more than 200 philos and not less than 60ms.
    init = init_table(&tab, av);
	if (init < 0)
		return (0);
	if (init && init != 1)
		return (ft_free_philo(&tab, init), 1);
	ft_start_philo();
	return (0);
}
