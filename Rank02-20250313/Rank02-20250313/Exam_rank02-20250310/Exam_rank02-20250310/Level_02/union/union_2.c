/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:49:42 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 15:58:24 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_new(char *str, char  c, int  end)
{
    int i;
    
    i = 0;
    while (i < end)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

void	ft_union(char	*s1, char   *s2)
{
	int	i;
	int	j;

	i = 0;
    j = 0;
	while (s1[i])
	{
		if (is_new(s1, s1[i], i))
            write(1, &s1[i], 1);
		i++;
	}
    while (s2[j])
	{
		if (is_new(s1, s2[j], i) && is_new(s2, s2[j], j))
            write(1, &s2[j], 1);
		j++;
	}
}

int	main(int ac, char	**av)
{
	if (ac == 3)
        ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}