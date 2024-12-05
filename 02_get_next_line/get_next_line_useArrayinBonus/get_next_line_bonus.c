/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:51:31 by layang            #+#    #+#             */
/*   Updated: 2024/12/05 14:46:03 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* if (!res || *res == '\0')
	return (NULL);
 */
static char	*get_line(char	*res)
{
	char	*line;
	int		len;
	int		i;

	if (ft_strchr(res, '\n'))
		len = ft_strchr(res, '\n') - res + 1;
	else
		len = ft_strlen(res);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*res_afterline(char	*res)
{
	char	*new_res;

	if (ft_strchr(res, '\n'))
		new_res = ft_strdup(ft_strchr(res, '\n') + 1);
	else
		new_res = ft_strdup("");
	free(res);
	return (new_res);
}

static char	*read_line(int fd, char	**res, char	*buffer)
{
	ssize_t	bytes;
	char	*for_free;

	while (1)
	{
		if (ft_strchr(*res, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		for_free = *res;
		*res = ft_strjoin(for_free, buffer);
		free(for_free);
		if (!*res)
			return (NULL);
	}
	if (!*res || **res == '\0')
		return (NULL);
	return (get_line(*res));
}

char	*get_next_line(int fd)
{
	static char	*res[4096];
	char		*line;
	char		*buffer;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!res[fd])
		res[fd] = ft_strdup("");
	line = read_line(fd, &res[fd], buffer);
	free(buffer);
	if (!line)
	{
		free(res[fd]);
		res[fd] = NULL;
		return (NULL);
	}
	res[fd] = res_afterline(res[fd]);
	return (line);
}