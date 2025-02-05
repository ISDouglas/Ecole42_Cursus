/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:50 by layang            #+#    #+#             */
/*   Updated: 2025/02/05 12:35:49 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
char	**ft_free_array(char **ptr)
{
	int	i;
	
	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	return (0);
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
	return (cmd);
}

void	execute(char	*cmd, char	**env)
{
	int		i;
	char	*path;
	char	**cmd_line;

	i = 0;
	cmd_line = ft_split(cmd, ' ');
	path = get_path(cmd_line[0], env);
	if (execve(path, cmd_line, env) == -1)
	{
		ft_free_array(cmd_line);
		free(path);
		error();
	}
}
