/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:16:23 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/27 03:02:31 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - client.h: parse_args(), send_message()
** - libft.h: ft_putendl_fd()
*/

#include <client.h>
#include <libft.h>

int	main(int argc, char *argv[])
{
	struct s_args	args;

	if (!parse_args(&args, argc, argv))
	{
		ft_putendl_fd("Invalid CLI arguments", 2);
		return (1);
	}
	send_message(&args);
	return (0);
}
