/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:51:09 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/25 13:27:40 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions.
*/

#include <libft.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
