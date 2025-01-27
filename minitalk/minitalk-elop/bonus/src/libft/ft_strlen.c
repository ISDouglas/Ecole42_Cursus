/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:50:08 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/22 19:57:53 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDE:
** libft.h: This file implements one of its functions
** stddef.h: size_t type
*/

#include <libft.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	acm;

	acm = 0;
	while (s[acm])
		acm++;
	return (acm);
}
