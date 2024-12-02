/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:51:31 by layang            #+#    #+#             */
/*   Updated: 2024/12/02 15:04:35 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd *get_fd_state(int fd)
{
	static t_fd *head = NULL;
	t_fd *current = head;
	// 在链表中查找对应的文件描述符的节点
	while (current)
	{
		if (current->fd == fd)
			return (current); // 返回该文件描述符的状态
		current = current->next;
	}
	// 如果找不到该文件描述符，创建一个新的节点
	t_fd *new_state = (t_fd *)malloc(sizeof(t_fd));
	if (!new_state)
		return (NULL);
	new_state->fd = fd;
	new_state->res = ft_strdup(""); // 初始化为空字符串
	new_state->next = head;
	head = new_state; // 将新节点插入到链表的头部
	return (new_state);
}

static char *get_line(char *res)
{
	char *line;
	int len;
	int i;

	if (!res || *res == '\0')
		return (NULL);
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

static char *res_afterline(char *res)
{
	char *new_res;

	if (!res || *res == '\0')
		return (NULL);
	if (ft_strchr(res, '\n'))
		new_res = ft_strdup(ft_strchr(res, '\n') + 1);
	else
		new_res = ft_strdup("");
	free(res);
	return (new_res);
}

static char *read_line(int fd, t_fd *state, char *buffer)
{
	ssize_t bytes;
	char *for_free;

	while (1)
	{
		if (ft_strchr(state->res, '\n'))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		for_free = state->res;
		state->res = ft_strjoin(for_free, buffer);
		free(for_free);
		if (!state->res)
			return (NULL);
	}
	if (state->res == NULL || *state->res == '\0')
		return (NULL);
	return (get_line(state->res));
}

char *get_next_line(int fd)
{
	t_fd *state;
	char *line;
	char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	state = get_fd_state(fd); // 获取该文件描述符的状态
	if (!state)
	{
		free(buffer);
		return (NULL);
	}
	line = read_line(fd, state, buffer);
	free(buffer);
	if (!line)
	{
		free(state->res);
		state->res = NULL;
		return (NULL);
	}
	state->res = res_afterline(state->res); // 读取一行后更新状态
	return (line);
}
