/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:50:54 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/28 15:00:51 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - server.h: display_pid()
** - libft.h: ft_putchar_fd()
** - unistd.h: pause()
** - signal.h: signal(), sigaction(), kill()
** - stdlib.h: exit()
*/

#include <server.h>
#include <libft.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
** This function is the handler for messaging signals (SIGUSR1 = 0,
** SIGUSR2 = 1). It will keep tracking of the received bits until it has
** a full character, printing it and resetting.
** After receiving each bit, it will send a SIGUSR1 to the client to notify it
** that the server is ready to receive the next bit.
*/
static void	handler_msg(int sig, siginfo_t *info, void *ucontext)
{
	static struct s_character	chr = {0, 0};

	(void)ucontext;
	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/*
** This function is the handler for terminating signals. It just calls to
** exit(0).
*/
static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	struct sigaction sa;

	display_pid();
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = handler_msg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
