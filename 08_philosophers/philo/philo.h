/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:56 by layang            #+#    #+#             */
/*   Updated: 2025/05/12 19:58:49 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

typedef struct s_philo
{
	int				id;
	long			t_die;
	pthread_t		thread;
	unsigned int	fork[2];
	int				nb_eatp;
}   t_philo;

typedef struct s_table
{
	int				nb_phi;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				nb_eat;
	pthread_mutex_t	*forks_locks;
	pthread_mutex_t	log_lock;
	t_philo			*philos;
	bool			stop;
	pthread_mutex_t	stop_lock;	
	long			start_time;
}	t_table;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK_1 = 4,
	FORK_2 = 5
}	t_status;

int	ft_atoi(const char *str);

#endif