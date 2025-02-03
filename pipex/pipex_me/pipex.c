/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:24 by layang            #+#    #+#             */
/*   Updated: 2025/02/03 17:54:32 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char	*cmd, char	*file, int *pipe, char	**env)
{
	
}

void	parent(char	*cmd, char	*file, int *pipe, char	**env)
{
	
}

int	main(int ac, char	**av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	
	if (ac != 5)
	{
		ft_putstr_fd("./pipex input_file cmd1 amd2 output_file", 2);
		exit(0);
	}
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == 0)
		child(av[2], av[1], pipe_fd, env);
	parent(av[3], av[4], pipe_fd, env);
}

