/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:24:52 by layang            #+#    #+#             */
/*   Updated: 2025/01/13 21:34:41 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void put_index(int *sort_a, t_list	*res)
{
	int	i;

	while (res)
	{
		i = 0;
		while (sort_a[i])
		{
			if (res->content == sort_a[i])
				res->index = i;
			i++;
		}
		res = res->next;
	}
}
void	index(char	**av, int nb)
{
	t_list	*t;
	t_list	*res;
	int	i;

	i = 0;
	res = NULL;
	while (av[i])
	{
		t = ft_lstnew(ft_atoi_ctl(av[i]));
		ft_lstadd_back(&res, t);
		t->index = -1;
		i++;
	}
	sort_int_tab(sort_a, nb);
	put_index(sort_a, &res);
}
