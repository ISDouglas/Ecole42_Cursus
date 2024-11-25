/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:51:19 by layang            #+#    #+#             */
/*   Updated: 2024/11/25 13:39:10 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char buffer[BUFFER_SIZE];

static void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static void *ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dst);
}

static char *alloc_copy(char *line, size_t len, char *buffer, size_t copy_len)
{
	char *new_line;

	new_line = malloc(len + copy_len + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
		ft_memcpy(new_line, line, len);
		free(line);
	}
	ft_memcpy(new_line + len, buffer, copy_len);
	new_line[len + copy_len] = '\0';
	return (new_line);
}

static int find_newline(char *buffer, size_t bytes_read, size_t *index)
{
	size_t i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char *process_buffer(char *line, size_t *len, ssize_t *bytes_read)
{
	size_t index;

	if (find_newline(buffer, *bytes_read, &index))
	{
		line = alloc_copy(line, *len, buffer, index + 1);
		if (!line)
			return (NULL);
		ft_memmove(buffer, buffer + index + 1, *bytes_read - index - 1);
		buffer[*bytes_read - index - 1] = '\0';
		return (line);
	}
	line = alloc_copy(line, *len, buffer, *bytes_read);
	if (!line)
		return (NULL);
	*len += *bytes_read;
	return (line);
}

char *read_and_process(int fd, char *line, size_t *len)
{
	ssize_t bytes_read;

	bytes_read = ft_strlen(buffer);
	while (bytes_read > 0 || (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line = process_buffer(line, len, &bytes_read);
		if (line)
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && *len > 0)
		return (line);
	free(line);
	return (NULL);
}
