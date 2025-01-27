/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:02:39 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/24 20:05:09 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions.
** stdlib.h: malloc()
*/

#include <libft.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s_allocated;
	void	*allocated;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	s_allocated = nmemb * size;
	if (s_allocated <= 0)
		return (NULL);
	allocated = malloc(s_allocated);
	if (allocated)
	{
		ft_bzero(allocated, s_allocated);
		return (allocated);
	}
	else
		return (NULL);
}
