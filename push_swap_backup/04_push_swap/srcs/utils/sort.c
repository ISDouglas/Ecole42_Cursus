/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:19:52 by layang            #+#    #+#             */
/*   Updated: 2025/01/13 21:08:27 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stacks(t_stack	t)
{
	free(t.a);
	free(t.b);
}

void	sort(t_stack	t, int nb)
{
	if (is_sorted(t.a, t.size_a))
		free_stacks(t);
	
}

void ft_min_int(int *tab, int size)
{
	int i;
	int j;
	int min;
	int	index;

	i = 0;
	min = tab[i];
	index = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				min=tab[j];
				index = j;
			}
			j++;
		}
		tmp->index = index;
		index++;
		i++;
	}
}
