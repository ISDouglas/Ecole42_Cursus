/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum_me_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:50 by layang            #+#    #+#             */
/*   Updated: 2025/03/12 17:26:33 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(int n)
{
	if (n > 9)
		put_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);	
}

int	main(int ac, char	**av)
{
	int	i;
	
	if (ac > 1)
	{
		i = 1;
		while (av[i])
			i++;
		put_nbr(i - 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

/*int		main(int ac, char **av)
{
	(void)av;
	put_nbr(ac - 1);
	write(1, "\n", 1);
	return (0);
} */
