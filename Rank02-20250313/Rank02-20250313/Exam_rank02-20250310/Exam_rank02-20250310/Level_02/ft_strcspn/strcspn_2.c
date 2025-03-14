/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:17:30 by layang            #+#    #+#             */
/*   Updated: 2025/03/14 10:16:06 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include <stdlib.h>

size_t	ft_strcspn(const char	*s, const char	*reject)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j] && s[i] != reject[j])
			j++;
		if (!reject[j])
			i++;
		else
			return (i);
	}
	return (i);
}

/* size_t	ft_strcspn(const char	*s, const char	*reject)
{
	int	i;
	size_t	nb;

	nb = 0;
	while (*s)
	{
		i = 0;
		while (reject[i] && reject[i] != *s)
			i++;
		if (!reject[i])
		{
			nb++;
			s++;
		}	
		else
			return (nb);
	}
	return (nb);
} */
