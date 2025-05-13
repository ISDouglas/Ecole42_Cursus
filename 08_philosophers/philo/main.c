/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:32 by layang            #+#    #+#             */
/*   Updated: 2025/05/13 12:19:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ctr on not more than 200 philos and not less than 60ms.
int	main(int	ac, char	**av)
{
	t_table		tab;
	int			init;

	if (ac != 5 && ac != 6)
		return(printf("nb_philo, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
    init = init_table(&tab, av);
	if (init < 0)
		return (0);
	if (init)
		return (ft_free_philo(&tab, init), 0);
	ft_start_philo(&tab);
	ft_free_philo(&tab, 7);
	return (0);
}
