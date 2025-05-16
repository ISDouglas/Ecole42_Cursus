/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:19:02 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 18:50:46 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				nb_phi;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				nb_eat;
	sem_t			*sem_forks;
	sem_t			s_print;
	sem_t			eat_counter;
	t_philo			**philos;
	long			start_time;
}	t_table;

typedef struct s_philo
{
	unsigned int	id;
	pid_t			pid;
	int				nb_eatp;
	time_t			last_meal;
	t_table			*tab;
}	t_philo;

typedef enum e_status
{
	FORK_1 = 0,
	FORK_2 = 1,
	EATING = 2,
	SLEEPING = 3,
	THINKING = 4,
	DIED = 5,
}	t_status;

#endif