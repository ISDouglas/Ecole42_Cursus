/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternaries_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:29:37 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/26 18:42:40 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** ternary.h: This file implements some of its functions
*/

#include <ternary.h>

long	tern_long(int condition, long if_true, long if_false)
{
	if (condition)
		return (if_true);
	else
		return (if_false);
}

int	tern_int(int condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	else
		return (if_false);
}

size_t	tern_size_t(int condition, size_t if_true, size_t if_false)
{
	if (condition)
		return (if_true);
	else
		return (if_false);
}

char	*tern_str(int condition, char *if_true, char *if_false)
{
	if (condition)
		return (if_true);
	else
		return (if_false);
}
