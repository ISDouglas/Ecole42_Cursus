/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 01:05:48 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/27 02:47:04 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - server.h: this file implements one of its functions
** - libft.h: ft_itoa(), ft_putendl_fd()
** - unistd.h: getpid()
** - stdlib.h: free()
*/

#include <server.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

/*
** This function displays the PID of the current process to stdout.
*/
void	display_pid(void)
{
	pid_t	pid;
	char	*str_pid;

	pid = getpid();
	str_pid = ft_itoa(pid);
	if (!str_pid)
	{
		ft_putendl_fd("Error at ft_itoa()", 2);
		return ;
	}
	ft_putendl_fd(str_pid, 1);
	free(str_pid);
}
