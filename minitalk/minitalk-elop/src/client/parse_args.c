/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:27:39 by elopez-r          #+#    #+#             */
/*   Updated: 2021/05/27 02:47:31 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** - client.h: this file implements one of its functions
** - libft.h: ft_isdigit()
*/

#include <client.h>
#include <libft.h>

/*
** This function checks if the passed string isn't empty and is only conformed
** by digits.
*/
static bool	is_natural(const char *str)
{
	size_t	i;
	bool	not_empty;

	not_empty = false;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			not_empty = true;
		else
			return (false);
		i++;
	}
	return (not_empty);
}

/*
** This function checks that the passed CLI arguments are valid and stores
** them into the struct args.
*/
bool	parse_args(struct s_args *args, int argc, char *argv[])
{
	if (!args || argc != 3 || !is_natural(argv[1]))
		return (false);
	args->pid = ft_atoi(argv[1]);
	args->str = argv[2];
	return (true);
}
