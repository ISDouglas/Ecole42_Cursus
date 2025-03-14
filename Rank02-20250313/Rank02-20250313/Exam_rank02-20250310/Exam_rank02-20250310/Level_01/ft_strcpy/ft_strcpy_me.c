/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:06:56 by layang            #+#    #+#             */
/*   Updated: 2024/12/30 12:21:37 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <stdlib.h>
 */
char	*ft_strcpy(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;

	s2 = "call12345";
	s1 = (char *)malloc(10 * sizeof(char));
	if (s1 == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("%s\n", ft_strcpy(s1, s2));
	free(s1);
	return (0);
} */
