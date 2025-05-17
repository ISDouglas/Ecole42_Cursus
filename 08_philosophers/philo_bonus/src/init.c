/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:26 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 14:23:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_philos(t_table	*tab)
{
	int	i;

	tab->philos = malloc(sizeof(t_philo *) * tab->nb_phi);
	if (!tab->philos)
		return (perror("malloc philos"), 4);
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->philos[i] = malloc(sizeof(t_philo) * 1);
		if (!tab->philos[i])
			return (perror("malloc each philo"), free_philos(tab, i), 5);
		tab->philos[i]->id = i;
		tab->philos[i]->nb_eatp = 0;
		tab->philos[i]->tab = tab;
		i++;
	}
	return (0);
}

static int	init_sems(t_table	*tab)
{
	sem_unlink("/sem_forks");
	sem_unlink("/s_print");
	sem_unlink("/eat_counter");
	tab->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, tab->nb_phi);
	if (tab->sem_forks == SEM_FAILED)
		return (perror("sem_open sem_forks failed"), 1);	
	tab->s_print = sem_open("/s_print", O_CREAT, 0644, 1);
	if (tab->s_print == SEM_FAILED)
		return (perror("sem_open s_print failed"), 2);
	if (tab->nb_eat > 0)
	{	
		tab->eat_counter = sem_open("/eat_counter", O_CREAT, 0644, 0);
		if (tab->eat_counter == SEM_FAILED)
			return (perror("sem_open eat_counter failed"), 3);
	}
	return (0);
}

int	wrong_input_check(t_table	*tab, char	*av5)
{
	if (av5)
	{
		if (ft_atoi(av5) < 0)
			return (printf("nb of times must eat should be positive.\n"), -1);
		else
			tab->nb_eat = ft_atoi(av5);
	}
	else
		tab->nb_eat = -1;
	if (tab->nb_eat == 0)
		return (printf("number of times must eat is 0.\n"), -1);
	if (tab->nb_phi <= 0)
		return (printf("number of philo must be 1-250.\n"), -1);
	if (tab->t_die < 0 || tab->t_eat < 0 || tab->t_sleep < 0)
		return (printf("time must be positive.\n"), -1);
	return (0);
}

int	init_table(t_table	**tab, char	**av)
{
	int	start_forks;
	int	start_philos;

	*tab = malloc(sizeof(t_table));
	if (!*tab)
		return (perror("malloc table"), -1);
	(*tab)->nb_phi = ft_atoi(av[1]);
	(*tab)->t_die = ft_atoi(av[2]);
	(*tab)->t_eat = ft_atoi(av[3]);
	(*tab)->t_sleep = ft_atoi(av[4]);
	if (wrong_input_check(*tab, av[5]))
		return (-1);
	start_sem = init_sems(*tab);
	if (start_sem)
		return (start_sem);
	start_philos = init_philos(*tab);
	if (start_philos)
		return (start_philos);
	return (0);
}

/* 
t_table *init_table(int argc, char **argv)
{
	t_table *table = malloc(sizeof(t_table));
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->nb_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;

	// 初始化信号量
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/eat_counter");

	table->forks = sem_open("/forks", O_CREAT, 0644, table->nb_philo);
	table->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	table->eat_counter = sem_open("/eat_counter", O_CREAT, 0644, 0);

	// 分配哲学家数组
	table->philos = malloc(sizeof(t_philo) * table->nb_philo);

	for (int i = 0; i < table->nb_philo; i++)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].table = table;
		table->philos[i].last_meal = current_timestamp_ms();
	}
	table->start_time = current_timestamp_ms();
	return table;
} */
