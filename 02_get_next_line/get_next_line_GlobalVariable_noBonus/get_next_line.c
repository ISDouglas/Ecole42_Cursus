/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:47:20 by layang            #+#    #+#             */
/*   Updated: 2024/11/27 10:57:21 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	buffer[BUFFER_SIZE];

static char	*process_buffer(char	*line, size_t *len, ssize_t *bytes, int fd)
{
	size_t	index;

	if (find_newline(buffer, *bytes, &index))
	{
		line = alloc_copy(line, *len, buffer, index + 1);
		if (!line)
			return (NULL);
		ft_memmove(buffer, buffer + index + 1, *bytes - index - 1);
		buffer[*bytes - index - 1] = '\0';
		return (line);
	}
	line = alloc_copy(line, *len, buffer, *bytes);
	if (!line)
		return (NULL);
	*len += *bytes;
	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes <= 0)
	{
		return (line);
	}
	return (process_buffer(line, len, bytes, fd));
}

static char *read_and_process(int fd, char *line, size_t *len)
{
	ssize_t bytes_read;

	bytes_read = ft_strlen(buffer);
	while (bytes_read > 0 || (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line = process_buffer(line, len, &bytes_read, fd);
		if (line)
			return (line);
		if (bytes_read == 0)
			break;
	}
	if (*len > 0)
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	len;

	line = NULL;
	len = 0;
	line = read_and_process(fd, line, &len);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	// Check for correct argument count
	if (argc != 2)
	{
		write(2, "Usage: ./a.out <filename>\n", 24);
		return 1;
	}
	// Open the file for reading
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	// Read lines from the file using get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		// Print the line (don't forget to handle newline in the output)
		printf("%s", line);
		free(line);
	}
	// Close the file when done
	close(fd);
	return (0);
}
/* 
cc get_next_line.c get_next_line_utils.c -Wall -Wextra -Werror 
./a.out test.txt 
 */
