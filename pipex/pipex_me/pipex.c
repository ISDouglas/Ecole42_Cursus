/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:24 by layang            #+#    #+#             */
/*   Updated: 2025/02/04 20:12:42 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char	*cmd, char	*file, int *pipe, char	**env)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	dup2(fd, 0);
	dup2(pipe[1], 1);
	close(pipe[0]);
	execute(cmd, env);
}

void	parent(char	*cmd, char	*file, int *pipe, char	**env)
{
	int	fd;
	
	fd = open(file, O_RDONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(pipe[1]);
	execute(cmd, env);
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
		error();
	pid = fork();
	if (pid == 0)
		child(av[2], av[1], pipe_fd, env);
	parent(av[3], av[4], pipe_fd, env);
}
//./pipex infile "ls -l" "wc -l" outfile
