/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:51 by layang            #+#    #+#             */
/*   Updated: 2025/03/05 10:35:31 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


static char *get_line(char *res, int print)
{
	char *line;
	int len;
	int i;

	if (ft_strchr(res, '\n'))
		len = ft_strchr(res, '\n') - res + 1;
	else
		len = ft_strlen(res);
	if (ft_strchr(res, '\n') && print == 0)
		len--;
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

	if (ft_strchr(res, '\n'))
		new_res = ft_strdup(ft_strchr(res, '\n') + 1);
	else
		new_res = ft_strdup("");
	free(res);
	return (new_res);
}

static char *read_line(int fd, char **res, char *buffer, int print)
{
	ssize_t bytes;
	char *for_free;

	while (1)
	{
		if (ft_strchr(*res, '\n'))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break;
		buffer[bytes] = '\0';
		for_free = *res;
		*res = ft_strjoin(for_free, buffer);
		free(for_free);
		if (!*res)
			return (NULL);
	}
	if (**res == '\0')
		return (NULL);
	return (get_line(*res, print));
}

void free_res(int fd, char **res)
{
	if (fd == -1 && *res)
	{
		if (*res)
			free(*res);
		*res = NULL;
	}
}

char *get_next_line(int fd, int print)
{
	static char *res;
	char *line;
	char *buffer;

	free_res(fd, &res);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!res)
		res = ft_strdup("");
	line = read_line(fd, &res, buffer, print);
	free(buffer);
	if (!line)
	{
		if (res)
			free(res);
		res = NULL;
		return (NULL);
	}
	res = res_afterline(res);
	return (line);
}

static char **free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int ft_count_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char *ft_putword(char *word, char const *s, int i, int word_len)
{
	int j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char **split_words(char const *s, char c, char **s2, int num)
{
	int i;
	int word;
	int word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2[word])
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char **ft_split(char const *s, char c)
{
	char **s2;
	unsigned int num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	s2 = split_words(s, c, s2, num_words);
	return (s2);
}

static void renew_range_z_04(t_map *map, t_point *cur)
{
	if (cur->z < map->min_z)
		map->min_z = cur->z;
	if (cur->z > map->max_z)
		map->max_z = cur->z;
}

char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int ft_atoi(const char *str)
{
	int sign;
	int num;
	int i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static void fill_row_03(t_map *map, char **row, int *j)
{
	t_point *cur;
	t_point p;
	int col;

	p.x = -map->cell_size * map->dim_x / 2;
	p.y = map->cell_size * map->dim_y / 2 + map->cell_size * (*j);
	if (*j == 0 && ft_strchr(*row, ','))
		map->with_color = 1;
	printf("map->with_color: %d\n", map->with_color);
	col = 0;
	while (col < map->dim_x)
	{
		cur = map->grid + col + map->dim_x * (*j);
		*cur = p;
		cur->z = ft_atoi(row[col]);
		renew_range_z_04(map, cur);
		if (map->with_color == 1)
			cur->color = ft_atoi_base((ft_strchr(row[col], 'x') + 1), "0123456789abcdef");
		else
			cur->color = GROUND_COLOR;
		printf("cur->color: %d\n", cur->color);
		p.x += map->cell_size;
		col++;
	}
	(*j)++;
}

t_map *fill_map_02(t_vars *all, char *file)
{
	int fd;
	char *line;
	char **row;
	t_map *map;
	int j;

	fd = open(file, O_RDONLY);
	map = all->map;
	map->cell_size = (WIDTH / map->dim_x + HEIGHT / map->dim_y) / 4;
	map->grid = malloc(map->dim_x * map->dim_y * sizeof(t_point));
	if (map->grid == NULL)
		return (NULL);
	map->min_z = 0;
	map->max_z = 0;
	map->with_color = 0;
	j = 0;
	while ((line = get_next_line(fd, 0)) != NULL)
	{
		printf("line: %s\n", line);
		row = ft_split(line, ' ');
		fill_row_03(map, row, &j);
		free(row);
		free(line);
	}
	close(fd);
	return (map);
}

