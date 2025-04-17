/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:56 by layang            #+#    #+#             */
/*   Updated: 2025/04/17 16:07:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_schedule
{
	int		nb_phi;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		nb_eat;
}	t_schedule;

typedef struct s_philo
{
	int			id;
	long		t_die;
	pthread_t	thread;
	int			nb_eatp;
}   t_philo;

typedef struct s_table
{
	pthread_mutex_t *forks;
	pthread_mutex_t	log;
	t_philo			*philos;
	int				dead;
	int				nb_eat;
	long			start_time;
}	t_table;

int	ft_atoi(const char *str);

#endif