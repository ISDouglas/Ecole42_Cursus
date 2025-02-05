/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:05:33 by layang            #+#    #+#             */
/*   Updated: 2025/02/05 14:19:39 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child(char *cmd, char *file, int *pipe, char **env)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error();
	dup2(fd, 0);
	dup2(pipe[1], 1);
	close(pipe[0]);
	execute(cmd, env);
}

void parent(char *cmd, char *file, int *pipe, char **env)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error();
	dup2(pipe[0], 0);
	dup2(fd, 1);
	close(pipe[1]);
	execute(cmd, env);
}

int main(int ac, char **av, char **env)
{
	int pipe_fd[2];
	pid_t pid;

	if (ac >= 5)
	{
		if (av[1] == "here_doc")
	}
	ft_putstr_fd("./pipex <file1> cmd1 cmd2 cmd3 cmd4... <file2>\n", 2);
	ft_putstr_fd("or\n", 2);
	ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 <file>\n", 2);
	exit(0);

	if (pipe(pipe_fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child(av[2], av[1], pipe_fd, env);
	waitpid(pid, NULL, 0);
	parent(av[3], av[4], pipe_fd, env);
}
