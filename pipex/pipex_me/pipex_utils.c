/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:50 by layang            #+#    #+#             */
/*   Updated: 2025/02/04 20:53:52 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

char	*get_path(char	*cmd, char	**env)
{
	char	**cmd_line;
	char	*command;
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	cmd_line = ft_split(cmd, ' ');
	command = cmd_line[0];
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	
	
}

void	execute(char	*cmd, char	**env)
{
	int	i;

	i = 0;
	
}