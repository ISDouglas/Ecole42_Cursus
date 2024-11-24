/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:20 by layang            #+#    #+#             */
/*   Updated: 2024/11/24 12:40:15 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd)
{
	char buffer[BUFFER_SIZE];
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		for (ssize_t i = 0; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				char *new_line = malloc(len + i + 2);
				if (!new_line)
				{
					free(line);
					return NULL;
				}
				if (line)
				{
					memcpy(new_line, line, len);
					free(line);
				}
				memcpy(new_line + len, buffer, i + 1);
				new_line[len + i + 1] = '\0';
				lseek(fd, -(bytes_read - i - 1), SEEK_CUR);
				return new_line;
			}
		}
		char *new_line = malloc(len + bytes_read);
		if (!new_line)
		{
			free(line);
			return NULL;
		}
		if (line)
		{
			memcpy(new_line, line, len);
			free(line);
		}
		memcpy(new_line + len, buffer, bytes_read);
		len += bytes_read;
		line = new_line;
	}
	if (bytes_read == 0 && len > 0)
	{
		line[len] = '\0';
		return line;
	}
	free(line);
	return NULL;
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