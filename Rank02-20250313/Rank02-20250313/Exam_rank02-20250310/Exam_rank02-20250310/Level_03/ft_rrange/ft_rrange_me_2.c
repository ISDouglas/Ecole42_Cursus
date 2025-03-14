/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange_me_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:29:00 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 16:35:05 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*nb;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	nb = malloc(sizeof(int) * len);
	if (!nb)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nb[i] = end;
		if (start <= end)
			end--;
		else
			end++;
		i++;
	}
	return (nb);
}
