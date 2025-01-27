/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:24:13 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/28 14:44:42 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** INCLUDES:
** - stdbool.h: bool type
*/
# include <stdbool.h>

struct		s_args
{
	int		pid;
	char	*str;
};

bool		parse_args(struct s_args *args, int argc, char *argv[]);
void		send_message(struct s_args *args);

#endif
