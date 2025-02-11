/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:06:03 by layang            #+#    #+#             */
/*   Updated: 2025/02/11 20:10:15 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(char **av, int ac)
{
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	error_bonus(int sign)
{
	if (sign == 0)
	{
		ft_putstr_fd("./pipex <file1> cmd1 cmd2 cmd3 cmd4... <file2>\n", 2);
		ft_putstr_fd("or\n", 2);
		ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 <file>\n", 2);
		exit(0);
	}
	else if (sign == 1)
	{
		perror("\033[31mError");
		exit(EXIT_FAILURE);
	}
}

int	open_mode(char	*file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error_bonus(1);
	return (fd);
}
