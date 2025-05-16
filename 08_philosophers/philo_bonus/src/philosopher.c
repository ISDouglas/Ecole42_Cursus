/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:25:26 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 19:49:00 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// 在哲学家进程内部
void	philosopher(t_table	*tab)
{
	if (has_eaten_enough)
	{
		sem_post(tab->eat_counter);
		exit(0); // 正常退出
	}
	if (has_died)
	{
		sem_wait(tab->s_print);
		printf("%ld %d died\n", timestamp(), philo_id);
		sem_post(tab->s_print);
		exit(1); // 非正常退出，主进程识别到
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

