/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:19:52 by layang            #+#    #+#             */
/*   Updated: 2024/12/26 11:11:34 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks	t)
{
	free(t.a);
	free(t.b);
}

void	sort(t_stacks	t, int nb)
{
	if (is_sorted(t.a, t.size_a))
		free_stacks(t);
	
}