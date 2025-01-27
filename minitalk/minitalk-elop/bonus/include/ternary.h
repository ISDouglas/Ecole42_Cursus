/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:26:16 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/26 18:42:25 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERNARY_H
# define TERNARY_H

/*
** INCLUDES:
** stddef.h: size_t type
*/

# include <stddef.h>

/*
** So ternaries are now forbidden, huh...
*/

long	tern_long(int condition, long if_true, long if_false);
int		tern_int(int condition, int if_true, int if_false);
size_t	tern_size_t(int condition, size_t if_true, size_t if_false);
char	*tern_str(int condition, char *if_true, char *if_false);

#endif
