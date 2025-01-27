/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-r <elopez-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:45:58 by elopez-r          #+#    #+#             */
/*   Updated: 2021/03/28 18:41:54 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** INCLUDES:
** stddef.h: size_t type
*/

# include <stddef.h>

/*
** Reimplementations from the Libft with the Norm 3
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);

#endif
