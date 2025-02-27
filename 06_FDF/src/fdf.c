/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/02/27 20:18:29 by layang           ###   ########.fr       */
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

int fill_map_02(t_vars *all, char *file)
{
	int		fd;
	char	*line;
	char	**row;

	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd, 0)) != NULL)
	{
		row = ft_split(line, ' ');
		// get grid(x, y, z and color) with cell_size, and max z and min z
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
		{
			ft_putstr_fd("FDF: file error: Found wrong line length.\n", 2);
			return (0);
		}

		free(line);

	}
	close(fd);
	return ();
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
	// transform points and fit window
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
