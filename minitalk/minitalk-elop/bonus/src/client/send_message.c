/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:41:12 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/28 14:46:39 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - client.h: this file implements one of its functions
** - unistd.h: pause()
** - signal.h: kill()
*/

#include <client.h>
#include <unistd.h>
#include <signal.h>

/*
** This function sends the passed char to the server with the specified
** PID.
*/
static void	send_char(int pid, char character)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (character & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		current_bit++;
	}
}

/*
** This function sends the message stored in args to its destination.
*/
void	send_message(struct s_args *args)
{
	size_t	i;

	i = 0;
	while (args->str[i])
	{
		send_char(args->pid, args->str[i]);
		i++;
	}
}
