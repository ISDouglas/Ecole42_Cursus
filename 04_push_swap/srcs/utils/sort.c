/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:19:52 by layang            #+#    #+#             */
/*   Updated: 2025/01/14 12:03:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stacks(t_stack **t)
{
	t_list *tmp;
	t_list *next;
	
	tmp = (*t)->a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = (*t)->b;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*t);
}

void	is_sort(t_list	**t)
{
	t_list	*tmp;

	tmp = *t;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);	
}

void	sort_2_or_3_nbr(t_stack *tab, int nb)
{
	
}