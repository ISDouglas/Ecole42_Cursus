/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:07:40 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 07:40:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char	*s, const char	*accept)
{
	size_t	count;
	size_t	found;

	count = 0;
	while (*s)
	{
		found = 0;
		while (accept[count])
		{
			if (accept[count] == *s)
			{
				found = 1;
				break ;
			}
			count++;
		}
		if (found == 0)
			break ;
		count++;
		s++;
	}
	return (count);
}

int	main(void)
{
	char	haystack[] = "This is a test string";
	char	accept[] = "tgaThis";

	printf("ft_strspn: %zu\n", ft_strspn(haystack, accept));
	printf("strspn: %zu\n", ft_strspn(haystack, accept));
	return (0);
}
