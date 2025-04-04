/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:48 by decortejohn       #+#    #+#             */
/*   Updated: 2025/01/13 20:04:41 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_init(char **ag, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nbr;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (ag[i])
	{
		nbr = ft_atoi(ag[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_check(res, nbr, ag[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

/* void print_result(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putnbr_fd(tmp->content, 1);
		if (tmp->next)
			ft_putstr_fd(" ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
} */

int main(int ac, char **ag)
{
	t_swap	*tab;
	char	**args;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (ac == 2)
		args = ft_split(ag[1], ' ');
	else
		args = ag;
	tab->stack_a = ft_init(args, ac);
	if (tab->stack_a == NULL)
		return (-1);
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
	//print_result(tab->stack_a);
}
