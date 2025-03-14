/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:14:26 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 17:23:04 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char	**av)
{
    int i;
    int repeat;

    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            repeat = 1;
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
                repeat += av[1][i] - 'a';
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                repeat += av[1][i] - 'A';
            while (repeat)
            {
                write(1, &av[1][i], 1);
                repeat--;
            }    
            i++;
        }
    }
    write(1, "\n", 1);
	return (0);
}
