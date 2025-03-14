/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:03:42 by layang            #+#    #+#             */
/*   Updated: 2025/03/14 10:36:04 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list*	lst, int (*cmp)(int, int))
{
    t_list	*tmp;
	int		swap;
	int		is_sorted;
	
	if (!lst || !cmp)
		return (0);
	is_sorted = 0;
	while(is_sorted == 0)
	{
		is_sorted = 1;
		tmp = lst;
		while (tmp->next)
		{
			if (cmp(tmp->data, tmp->next->data) == 0)
			{
				swap = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = swap;
				is_sorted = 0;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}
