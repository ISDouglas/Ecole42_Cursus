/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:47:59 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/25 20:57:35 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions.
** stdlib.h: malloc()
** ternary.h: tern_long()
*/

#include <libft.h>
#include <ternary.h>
#include <stdlib.h>

static int	count_chars(long n)
{
	int		chars;

	if (n > 0)
		chars = 0;
	else if (n < 0)
	{
		chars = 1;
		n *= -1;
	}
	else
		return (1);
	while (n > 0)
	{
		chars++;
		n /= 10;
	}
	return (chars);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_l;
	int		len;

	len = count_chars(n);
	str = NULL;
	str = malloc(len + 1);
	if (str)
	{
		str[len] = '\0';
		len--;
		if (n < 0)
			str[0] = '-';
		n_l = tern_long(n >= 0L, n, n * -1L);
		while (n_l >= 10)
		{
			str[len--] = n_l % 10 + '0';
			n_l /= 10;
		}
		str[len] = n_l + '0';
	}
	return (str);
}
