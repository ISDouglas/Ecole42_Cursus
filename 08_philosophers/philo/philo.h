/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:56 by layang            #+#    #+#             */
/*   Updated: 2025/05/09 10:35:14 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int			id;
	long		t_die;
	pthread_t	thread;
	int			nb_eatp;
}   t_philo;

typedef struct s_table
{
	int		nb_phi;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		nb_eat;
	pthread_mutex_t *forks;
	pthread_mutex_t	log;
	t_philo			*philos;
	int				dead;
	long			start_time;
}	t_table;

int	ft_atoi(const char *str);

#endif