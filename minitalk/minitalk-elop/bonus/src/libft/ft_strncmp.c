/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:22:07 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/24 19:27:27 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions
** stddef.h: size_t type
*/

#include <libft.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] && us2[i] && i < n)
	{
		if (us1[i] > us2[i])
			return (1);
		else if (us1[i] < us2[i])
			return (-1);
		i++;
	}
	if (i < n)
	{
		if (us1[i])
			return (1);
		else if (us2[i])
			return (-1);
	}
	return (0);
}
