/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:15:12 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 08:25:38 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	int	i;
	int	max;
	
	if (len == 0)
		return (0);
	i = 1;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] < max)
			max = tab [i];
		i++;
	}
	return (max);
}
