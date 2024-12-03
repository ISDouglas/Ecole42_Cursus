/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:51:50 by layang            #+#    #+#             */
/*   Updated: 2024/12/03 14:15:37 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_fd
{
	int			fd;
	char		*res;
	struct s_fd	*next;
}	t_fd;

size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*src);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strchr(const char	*s, int c);
void	free_list(t_fd	*head);

char	*get_next_line(int fd);

#endif