/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 12:52:26 by layang           ###   ########.fr       */
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

void gradient_color_07(float_t r, int *rgb[3], int s, int e)
{
	rgb[0] = (int)roundf((1 - r) * ((s >> 16) & 0xFF) + r * ((e >> 16) & 0xFF));
	rgb[1] = (int)roundf((1 - r) * ((s >> 8) & 0xFF) + r * ((e >> 8) & 0xFF));
	rgb[2] = (int)roundf((1 - r) * (s & 0xFF) + r * (e & 0xFF));
}


t_point	multi_mat(t_point	p, t_mat	mat)
{
	p.x = mat.x1y1 * p.x + mat.x2y1 * p.y + mat.x3y1 * p.z;
	p.y = mat.x1y2 * p.x + mat.x2y2 * p.y + mat.x3y2 * p.z;
	p.z = mat.x1y3 * p.x + mat.x2y3 * p.y + mat.x3y3 * p.z;
	return (p);
}

void rotate_x(t_map *map, float_t angle)
{
	t_mat	rot_mat;

	rot_mat = (t_mat){1, 0, 0,
					  0, cos(angle), -sin(angle),
					  0, sin(angle), cos(angle)};
	fdf_transform(map, rot_mat);
}

t_map	*fdf_transform(t_map	*map, t_mat	rot_mat)
{
	int	i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = multi_mat(*cur, rot_mat);
		i++;
	}
	map->i = multi_mat(map->i, rot_mat);
	map->j = multi_mat(map->j, rot_mat);
	map->k = multi_mat(map->k, rot_mat);
	return (map);
}

void	rotate_y(t_map *map, float_t	angle)
{
	t_mat	rot_mat;
	
	rot_mat = (t_mat){cos(angle), 0, sin(angle),
					0, 1, 0,
					-sin(angle), 0, cos(angle)};
	fdf_transform(map, rot_mat);
}

void rotate_z(t_map *map, float_t angle)
{
	t_mat rot_mat;

	rot_mat = (t_mat){cos(angle), -sin(angle), 0,
					  sin(angle), cos(angle), 0,
					  0, 0, 1};
	fdf_transform(map, rot_mat);
}

void	projection_scale_08(t_map	*map)
{
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO_RADIAN);
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
	projection_scale_08(all.map);
	all.animate = 0;
	if (start_win_img(&all) == -1)
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
	scale_x = (WIDTH / 2 - 50) / fmaxf(abs(range[1]), abs(range[0]));
	scale_y = (HEIGHT / 2 - 50) / fmaxf(abs(range[3]), abs(range[2]));
	zoom(map, fminf(scale_x, scale_y));
}
