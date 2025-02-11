/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:50 by layang            #+#    #+#             */
/*   Updated: 2025/02/11 19:14:10 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

char	*get_path(char	*cmd, char	**env)
{
	char	**paths;
	char	*path_f;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path_f = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_f, cmd);
		free(path_f);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	ft_free_array(paths);
	return (0);
}

/* void	execute(char	*cmd, char	**env)
{
	char	*path;
	char	**cmd_line;

	cmd_line = ft_split(cmd, ' ');
	path = get_path(cmd_line[0], env);
	if (execve(path, cmd_line, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_line[0], 2);
		ft_free_array(cmd_line);
		free(path);
		exit(0);
	}
} */

void	execute(char	*cmd, char	**env)
{
	char	*path;
	char	**cmd_line;

	cmd_line = ft_split(cmd, ' ');
	path = get_path(cmd_line[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_line[0], 2);
		ft_free_array(cmd_line);
		exit(127);
	}
	if (execve(path, cmd_line, env) == -1)
	{
		ft_free_array(cmd_line);
		free(path);
		error();
	}
}
