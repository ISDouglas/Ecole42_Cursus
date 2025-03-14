/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdwatch_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:14:43 by layang            #+#    #+#             */
/*   Updated: 2025/01/03 11:04:36 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    wdwatch(char    *s1, char   *s2)
{
    int len;
    int i;

    len = 0;
    i = 0;  
    while (s1[len])
        len++;
    while (*s2 && i < len)
    {
        if (*s2 == s1[i])
            i++;
        s2++;
    }
    if (i == len)
        write(1, s1, len);
}

int	main(int ac, char	**av)
{
	if (ac == 3)
		wdwatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
