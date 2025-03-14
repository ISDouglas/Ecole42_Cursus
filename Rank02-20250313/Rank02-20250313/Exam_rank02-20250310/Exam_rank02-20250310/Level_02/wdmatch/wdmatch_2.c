/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:40:14 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 15:47:40 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_wdmatch(char	*s1, char   *s2)
{
	int	i;
	int	j;

	i = 0;
    j = 0;
	while (s2[j])
	{
		if (s1[i] == s2[j])
            i++;
		j++;
	}
	if (!s1[i])
		write(1, s1, i);
}

int	main(int ac, char	**av)
{
	if (ac == 3)
        ft_wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}