/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:48:42 by layang            #+#    #+#             */
/*   Updated: 2025/02/11 20:11:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

// Mandatory part
void	error(void);
void	ft_free_array(char	**ptr);
char	*get_path(char	*cmd, char	**env);
void	execute(char	*cmd, char	**env);
void	child(char	*cmd, char	*file, int *pipe, char	**env);
void	parent(char	*cmd, char	*file, int *pipe, char	**env);

// Bonus part
int		check_args(char	**av, int ac);
void	error_bonus(int sign);
int		open_mode(char	*file, int mode);

#endif