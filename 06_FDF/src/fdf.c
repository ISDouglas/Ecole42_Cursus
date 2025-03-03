/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 20:34:17 by layang           ###   ########.fr       */
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



void	projection_scale_08(t_map	*map)
{
	rotate_y(map, -M_PI_4);
	rotate_x(map, -ISO_RADIAN);
	autoscale(map);	
}

int	start_win_img(t_vars	*all)
{
	all->mlx = mlx_init();
	if (all->mlx == NULL)
	{
		ft_putstr_fd("Failed to set up X server", 2);
		return (-1);
	}
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "Hello FDF!");
	if (all->win == NULL)
	{
		ft_putstr_fd("Failed to build a window", 2);
		return (-1);
	}
	all->img.mlx_img = 	mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.mlx_img, &all->img.bits_pix,
		&all->img.line_len, &all->img.endian);
	
	return (0);
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


