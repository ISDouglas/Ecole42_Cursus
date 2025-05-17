/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:25:26 by layang            #+#    #+#             */
/*   Updated: 2025/05/17 15:10:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// 在哲学家进程内部
void	philosopher(t_philo	*phi)
{
	long	now;
	
	now = ft_get_time();
	while (1)
	{
		sem_wait(phi->tab->sem_forks);
		sem_wait(phi->tab->s_print);
		printf("%ld %d has taken a fork\n", now - phi->tab->start_time,
			phi->id + 1);
		sem_post(phi->tab->s_print);
		sem_wait(phi->tab->sem_forks);
		sem_wait(phi->tab->s_print);
		printf("%ld %d has taken a fork\n", now - phi->tab->start_time,
			phi->id + 1);
		sem_post(phi->tab->s_print);
		sem_wait(phi->tab->s_print);
		printf("%ld \e[32m%d is eating\e[0m\n", now - phi->tab->start_time,
			phi->id + 1);
		sem_post(phi->tab->s_print);
		philo_pass_time(phi->tab, tab->t_eat);
		if(stop_arrived(phi->tab))
			break ;
		
		
	}
	
	
	if (!monitor_death(tab, i))
	{
		
		exit(0);
	}
	else
	{
		sem_wait(tab->s_print);
		printf("%ld %d died\n", timestamp(), philo_id);
		sem_post(tab->s_print);
		exit(1);
	}
}

/* 
// 哲学家拿叉子（等待叉子）
sem_wait(table->forks);  // 拿第一个叉子
print_action(philo, "has taken a fork");
sem_wait(table->forks);  // 拿第二个叉子
print_action(philo, "has taken a fork");

// 吃饭
philo->last_meal = current_timestamp_ms();
print_action(philo, "is eating");
usleep(table->time_to_eat * 1000);

// 放回叉子
sem_post(table->forks);  // 放回第一个叉子
sem_post(table->forks);  // 放回第二个叉子 
// */

void	fork_philos(t_table	*tab, pid_t	**pids)
{
	int	i;
	
	i = 0;
	while (i < tab->nb_phi)
	{
		*pids[i] = fork();
		if (*pids[i] < 0)
		{
			perror("fork() pid");
			break ;
		}
		else if (*pids[i] == 0)
			philosopher(tab->philos[i]);
		else
			i++;
	}
	return (i);
}
