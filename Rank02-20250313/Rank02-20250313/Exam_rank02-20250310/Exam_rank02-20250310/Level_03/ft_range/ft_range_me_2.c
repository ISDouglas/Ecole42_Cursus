/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_me_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:48:15 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 16:27:59 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*r;
	int	i;
	int	nb;

	if (start <= end)
		nb = end - start + 1;
	else
		nb = start - end + 1;
	r = malloc(sizeof(int) * nb);
	if (!r)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		r[i] = start;
		if (start <= end)
			start++;
		else
			start--;
		i++;	
	}
	return (r);
}
