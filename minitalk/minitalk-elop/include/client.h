/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:24:13 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/27 03:54:16 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** INCLUDES:
** - stdbool.h: bool type
*/
# include <stdbool.h>

/*
** The delay in micro-seconds to wait before sending each signal to the
** server.
*/
# define DELAY_US 200

struct		s_args
{
	int		pid;
	char	*str;
};

bool		parse_args(struct s_args *args, int argc, char *argv[]);
void		send_message(struct s_args *args);

#endif
