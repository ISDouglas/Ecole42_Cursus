/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:05:33 by layang            #+#    #+#             */
/*   Updated: 2025/02/07 16:13:09 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	input_here_doc(char *limiter, int *pipe_fd)
{
	char *line;

	close(pipe_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(line, limiter, (ft_strlen(limiter) + 1)) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, pipe_fd[1]);
		free(line);
	}
}

static void do_here_doc(char *limiter)
{
	int		pipe_fd[2];
	pid_t	pid;
	
	if (pipe(pipe_fd) == -1)
		error_bonus(1);
	pid = fork();
	if (pid == -1)
		error_bonus(1);
	if (pid == 0)
		input_here_doc(limiter, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		wait(NULL);
	}
}

static void do_multi_pipe(char *cmd, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		error_bonus(1);
	pid = fork();
	if (pid == -1)
		error_bonus(1);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		execute(cmd, env);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

int main(int ac, char **av, char **env)
{
	int	i;
	int	input;
	int	output;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			output = open_mode(av[5], 2);
			do_here_doc(av[2]);
		}	
		else
		{
			i = 2;
			input = open_mode(av[1], 0);
			output = open_mode(av[ac - 1], 1);
			dup2(input, 0);
		}
		while (i < ac - 2)
			do_multi_pipe(av[i++], env);
		dup2(output, 1);
		execute(av[ac - 2], env);
	}
	error_bonus(0);
}
