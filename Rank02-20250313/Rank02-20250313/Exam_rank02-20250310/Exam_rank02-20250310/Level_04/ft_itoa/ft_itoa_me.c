/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_me.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:10:14 by layang            #+#    #+#             */
/*   Updated: 2025/03/09 12:26:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	count_char(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		len;

	len = count_char(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	str[len--] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i++;
	}
	while (len >= i)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

int	main(void)
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
	if (nb1 != -2147483648)
		free(str);
	return (0);
}

//nb2 = -12;
//nb3 = 2147483648; 
/* 	if (nbr == -2147483648)
		return ("-2147483648\0"); */
