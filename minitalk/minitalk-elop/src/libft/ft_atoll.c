/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:42:03 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/28 18:37:58 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions.
** ternary.h: tern_int()
*/

#include <libft.h>
#include <ternary.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r');
}

long long	ft_atoll(const char *nptr)
{
	long long	acm;
	int			sign;

	while (*nptr && is_space(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		sign = tern_int(*nptr == '+', 1, -1);
		nptr++;
	}
	else
		sign = 1;
	acm = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		acm = acm * 10 + (*nptr - '0');
		nptr++;
	}
	acm *= sign;
	return (acm);
}
