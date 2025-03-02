/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/02 13:14:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	close_win_esc(int	keycode, t_vars	*vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
int	close_win_x(t_vars	*vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void mlx_pixel_put(t_img *pic, int x, int y, int color)
{
	char *dst;

	dst = pic->addr + (y * pic->line_len + x * (pic->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
} */


int	read_file_01(t_vars	*all, char	*file)
{
	int		fd;
	char	*line;
	int		cols;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("FDF: open file failed", 2);
		return (0);
	}
	all->map->dim_y = 0;
	while ((line = get_next_line(fd, 0)) != NULL)
	{
		cols = ft_count_words(line, ' ');
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
		{
			ft_putstr_fd("FDF: file error: Found wrong line length.\n", 2);
			return (0);
		}
		all->map->dim_x = cols;
		free(line);
		all->map->dim_y += 1;
	}
	close(fd);
	return (cols);
}

void	renew_range_z_04(t_map	*map, t_point	*cur)
{
	if (cur->z < map->min_z)
		map->min_z = cur->z;
	if (cur->z > map->max_z)
		map->max_z = cur->z;
}

void	fill_row_03(t_map	*map, char	**row, int	*j)
{
	t_point	*cur;
	t_point	p;
	int		col;
	
	p.x = -map->cell_size * map->dim_x / 2;
	p.y = map->cell_size * map->dim_y / 2 + map->cell_size * (*j);
	if (*j == 0 && ft_strchr(*row, ','))
		map->with_color = 1;
	col = 0;
	while (col < map->dim_x)
	{
		cur = map->grid + col + map->dim_x * (*j);
		*cur = p;
		cur->z = ft_atoi(row[col]);
		renew_range_z_04(map, cur);
		if (map->with_color == 1)
			cur->color = ft_atoi_base((ft_strchr(row[col], 'x') 
				+ 1), "0123456789abcdef");
		else
			cur->color = GROUND_COLOR;
		p.x += map->cell_size;
		col++;
	}
	*j++;
}

void gradient_color_07(float_t r, int *rgb[3], int s, int e)
{
	rgb[0] = (int)roundf((1 - r) * ((s >> 16) & 0xFF) + r * ((e >> 16) & 0xFF));
	rgb[1] = (int)roundf((1 - r) * ((s >> 8) & 0xFF) + r * ((e >> 8) & 0xFF));
	rgb[2] = (int)roundf((1 - r) * (s & 0xFF) + r * (e & 0xFF));
}

void color_points_06(t_map *map)
{
	float_t ratio;
	int		rgb[3];
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if (cur->z > 0)
		{
			ratio = cur->z / map->max_z;
			gradient_color_07(ratio, &rgb, GROUND_COLOR, HIGH_COLOR);
			cur->color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		}
		if (cur->z < 0)
		{
			ratio = (map->min_z - cur->z) / map->min_z;
			gradient_color_07(ratio, &rgb, LOW_COLOR, GROUND_COLOR);
			cur->color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		}
		i++;
	}
}

/* 		if (cur->z != 0)
		{
			if (cur->z > 0)
				gradient_color_07(ratio, &rgb, GROUND_COLOR, HIGH_COLOR);
			else
				gradient_color_07(ratio, &rgb, LOW_COLOR, GROUND_COLOR);
			cur->color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
		} */

int color_and_save_05(t_vars *all)
{
	int		i;
	t_point	*cur;
	
	if (all->map->max_z != 0 && all->map->with_color == 0)
		color_points_06(all->map);
	all->orig_map = malloc(sizeof(t_map));
	if (all->orig_map == NULL)
		return (-1);
	all->orig_map->grid = malloc(all->map->dim_x 
		* all->map->dim_y * sizeof(t_point));
	if (all->orig_map->grid == NULL)
		return (-1);
	i = 0;
	while (i < all->map->dim_x * all->map->dim_y)
	{
		cur = all->map->grid + i;
		*(all->orig_map->grid + i) = *cur;
		i++;
	}
	return (0);
}

t_map	*fill_map_02(t_vars *all, char *file)
{
	int		fd;
	char	*line;
	char	**row;
	t_map	*map;
	int		j;

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
		row = ft_split(line, ' ');
		fill_row_03(map, row, &j);
		free(row);
		free(line);
	}
	close(fd);
	return (map);
}

int main(int argc, char **argv)
{
	t_vars	all;
	
	if (argc != 2)
	{
		ft_putstr_fd("FDF: ./fdf file.fdf", 2);
		return (-1);
	}
	if (read_file_01(&all, argv[1]) == 0)
		return (-1);
	fill_map_02(&all, argv[1]);
	if (color_and_save_05(&all) == -1)
		return (-1);
	projection_scale_07(all.map);
	all.animate = 0;
	if (start_win_img_(&all) == -1)
		return (-1);
	return (0);
	//bresenham_line_();
}


int	draw_low_line(t_img	*img, t_point s, t_point e)
{
	double	err;
	double	slope;
	double	step;
	t_point	cur;
	
	slope = (double)(e.y - s.y) / (e.x - s.x);
	err = -0.5;
	step = fabs(slope);
	cur = s;
	while (cur.x < e.x)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (slope > 0)
				cur.y++;
			else
				cur.y--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.x++;
	}
}

int	draw_high_line(t_img	*img, t_point	s, t_point	e)
{
	double	err;
	double	slope;
	double	step;
	t_point	cur;

	slope = (double)(e.y - s.y) / (e.x - s.x);
	err = -0.5;
	step = fabs(slope);
	cur = s;
	while (cur.y < e.y)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (slope > 0)
				cur.x++;
			else
				cur.x--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.y++;
	}
}

/*
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "");

	float	rot_matrix[3][3];

	void print_matrix(float_t matrix[3][3]);

	float_t matrix[3][3] = {
	{1.0, 2.0, 3.0},
	{4.0, 5.0, 6.0},
	{7.0, 8.0, 9.0}
	};

	print_matrix(matrix);
	// argv control   *
	// collect pic    *
		// get grid(x, y, z and color) with cell_size, and max z and min
	// transform points and fit window
	// put pixel: x-step (draw low line, x++), y-step (draw high line, y++)
	//            slope positive (++), slope negative (--) when err > 0
	// put into window
	// hook and bonus(extra projection, zoom, translate and rotate)
 */

void	autoscale(t_map	*map)
{
	float_t scale_x;
	float_t scale_y;
	t_point	*cur;
	int		range[4];
	int		i;

	ft_memset(range, 0, sizeof(range));
	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if (cur->x < range[0])
			range[0] = cur->x;
		if (cur->x > range[1])
			range[1] = cur->x;
		if (cur->y < range[2])
			range[2] = cur->y;
		if (cur->y > range[3])
			range[3] = cur->y;
		i++;
	}
	scale_x = (WIDTH / 2 - 30) / fmaxf(abs(range[1]), abs(range[0]));
	scale_y = (HEIGHT / 2 - 30) / fmaxf(abs(range[3]), abs(range[2]));
	zoom(map, fminf(scale_x, scale_y));
}
