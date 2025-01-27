/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:57:30 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/26 18:30:56 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDE:
** libft.h: This file implements one of its functions
*/

#include <libft.h>

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
