/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:51:41 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/21 20:44:23 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDE:
** libft.h: This file implements one of its functions
** unistd.h: write()
*/

#include <libft.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
