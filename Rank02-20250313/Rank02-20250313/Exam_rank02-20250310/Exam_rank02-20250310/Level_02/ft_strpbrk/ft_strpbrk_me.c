/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:19:35 by layang            #+#    #+#             */
/*   Updated: 2025/01/02 15:29:34 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char	*s1, const char	*s2)
{
	int	j;

	while (*s1)
	{
		j = 0;
		while (s2[j])
		{
			if (*s1 == s2[j])
				return ((char	*)s1);
			j++;
		}
		s1++;
	}
	return (NULL);
}


int		main(void)
{
	printf("ft: %s; real: %s\n", \
		ft_strpbrk("This is a string to search in", "qxd"), \
		strpbrk("This is a string to search in", "qxd")
		);

	printf("ft: %s; real: %s\n", \
		ft_strpbrk("This is a string to search in", "sh"), \
		strpbrk("This is a string to search in", "sh")
		);
}