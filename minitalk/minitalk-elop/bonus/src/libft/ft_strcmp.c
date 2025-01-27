/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:58:41 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/26 18:35:45 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** INCLUDES:
** libft.h: This file implements one of its functions.
** ternary.h: tern_size_t()
*/

#include <libft.h>
#include <ternary.h>

/*
** strcmp(3) like function.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	biggest_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	biggest_len = tern_size_t(s1_len > s2_len, s1_len, s2_len);
	return (ft_strncmp(s1, s2, biggest_len));
}
