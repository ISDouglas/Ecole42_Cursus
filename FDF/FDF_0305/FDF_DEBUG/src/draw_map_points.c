/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:16:34 by layang            #+#    #+#             */
/*   Updated: 2025/03/05 11:21:15 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void renew_range_z_04(t_map *map, t_point *cur)
{
	if (cur->z < map->min_z)
		map->min_z = cur->z;
	if (cur->z > map->max_z)
		map->max_z = cur->z;
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
	printf("map->with_color: %d\n\n", map->with_color);
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
		printf("line%d: %s\n",j, line);
		row = ft_split(line, ' ');
		fill_row_03(map, row, &j);
		free(row);
		free(line);
	}
	close(fd);
	return (map);
}
