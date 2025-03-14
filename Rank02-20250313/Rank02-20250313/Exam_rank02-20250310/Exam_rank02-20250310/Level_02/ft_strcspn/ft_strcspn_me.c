/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn_me.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:13:24 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 10:43:19 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char	*s, const char	*reject)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(void)
{
	const char *s = "hello world";
	const char *reject = "i";
	
	printf("strcspn: %zu\n", strcspn(s, reject));
	printf("ft_strcspn: %zu\n", ft_strcspn(s, reject));
	
	const char *s2 = "123456789";
	const char *reject2 = "0";
	
	printf("strcspn: %zu\n", strcspn(s2, reject2));
	printf("ft_strcspn: %zu\n", ft_strcspn(s2, reject2));
	
	return 0;
}
