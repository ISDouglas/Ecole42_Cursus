/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_me2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:57:40 by layang            #+#    #+#             */
/*   Updated: 2025/03/13 19:58:12 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <unistd.h>

//#define malloc(size) NULL

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa(int nbr)
{
	int		flag;
	char	*str;
	int		size;
	int		tmp;

	flag = 0;
	size = 1;
	tmp = nbr;
	while (tmp /= 10)
		size++;
	if (nbr < 0)
		flag = 1;
	size = size + flag;
	str = malloc (size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (flag)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = ft_abs(nbr % 10) + '0';
		size--;
		nbr /= 10;
	}
	return (str);
}

/* int	main(void)
{
	int		i;
	int		nb1;
	char	*str;

	nb1 = -2147483648;
	str = ft_itoa(nb1);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(str);
	return (0);
} */

int	main(void)
{
	char *str = ft_itoa(12345);
	if (str == NULL)
		write(1, "Memory allocation failed!\n", 26);
	else
	{
		write(1, str, 5);  // 如果没有发生分配失败，输出 "12345"
		free(str);
	}
	return 0;
}



//git status
//git add .
//git push