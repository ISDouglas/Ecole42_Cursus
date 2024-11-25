/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:20 by layang            #+#    #+#             */
/*   Updated: 2024/11/25 13:36:21 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	size_t	len;

	line = NULL;
	len = 0;
	line = read_and_process(fd, line, &len);
	return (line);
}

/* int main()
{
	int fd = open("your_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	char *line;
	while ((line = read_line(fd)) != NULL)
	{
		write(1, line, strlen(line));
		free(line);
	}

	close(fd);
	return 0;
} */
/* 
#include <fcntl.h>	// open
#include <unistd.h> // read, write, close
#include <stdio.h>	// perror

int main()
{
	char buffer[128];
	ssize_t bytesRead;

	// open file
	int fd = open("example.txt", O_RDONLY); // read only
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	// read file content
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytesRead] = '\0';	 // make sure string end of NULL
		write(1, buffer, bytesRead); // standart output: 1
	}

	if (bytesRead == -1)
	{
		perror("Error reading file");
		close(fd);
		return (1);
	}

	// close file
	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}
 */