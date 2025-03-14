/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:46:17 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 12:55:48 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	if (len == 0)
		return (0);
	max = tab[0];
	i = 0;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
