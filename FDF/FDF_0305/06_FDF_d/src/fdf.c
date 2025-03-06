/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/06 06:12:47 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	read_file_01(t_vars	*all, char	*file)
{
	int		fd;
	char	*line;
	int		cols;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("FDF: open file faile.m\n", 2);
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

void projection_scale_07(t_map *map)
{	
	if ((abs(map->min_z) + abs(map->max_z)) < map->cell_size)
		fdf_transform(map, (t_mat){1, 0, 0, 0, 1, 0, 0, 0, 10});
	rotate_z(map, M_PI_4);
	rotate_x(map, ISO_RADIAN);
	autoscale(map);
	printf("Autoscale.\n");
}

/* void projection_scale_07(t_map *map)
{
	rotate_x(map, -M_PI_2);
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO_RADIAN);
	autoscale(map);
} */

static int	loop_img(t_vars	*all)
{
	t_point	offset;
	
	if (!all->win)
		return (1);
	render_background(&all->img, BLACK);
	offset.x = WIDTH / 2;
	offset.y = HEIGHT / 2;
	offset.z = 0;
	if (all->animate)
		rotate_y(all->map, -0.01);
	map_to_img(&all->img, all->map, offset);
	mlx_put_image_to_window(all->mlx, all->win, all->img.mlx_img, 0, 0);
	//render_instructions(all, WHITE);
	return (0);
}

static int	start_win_img(t_vars	*all, char	*name)
{
	t_img	*img_data;
	
	all->mlx = mlx_init();
	if (all->mlx == NULL)
	{
		ft_putstr_fd("FDF: Failed to set up X server.\n", 2);
		return (-1);
	}
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, name);
	if (all->win == NULL)
	{
		ft_putstr_fd("FDF: Failed to build a window.\n", 2);
		return (-1);
	}
	all->img.mlx_img = 	mlx_new_image(all->mlx, WIDTH, HEIGHT);
	img_data = (t_img *)all->img.mlx_img;
	printf("img_mlx width: %d\n", img_data->width);
	printf("img_mlx height: %d\n", img_data->height);
	printf("my width: %d\n", WIDTH);
	printf("my height: %d\n", HEIGHT);
	if (!all->img.mlx_img)
	{
		ft_putstr_fd("FDF: Error initializing image.\n", 2);
		return (-1);
	}
	all->img.addr = mlx_get_data_addr(all->img.mlx_img, &all->img.bits_pix,
		&all->img.line_len, &all->img.endian);
	hook_control(all);
	mlx_loop_hook(all->mlx, loop_img, all);
	mlx_do_key_autorepeaton(all->mlx);
	mlx_loop(all->mlx);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	all;
	
	if (argc != 2)
	{
		ft_putstr_fd("FDF: ./fdf file.fdf\n", 2);
		return (-1);
	}
	all.map = malloc(sizeof(t_map));
	if (all.map == NULL)
		return (-1);
	if (read_file_01(&all, argv[1]) == 0)
		return (-1);
	fill_map_02(&all, argv[1]);
	if (color_and_save_05(&all) == -1)
		return (-1);
	projection_scale_07(all.map);
	all.animate = 0;
	if (start_win_img(&all, argv[1]) == -1)
		return (-1);
	return (0);
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
	** clear color, like set background:
	ft_bzero(all->img.addr, WIDTH * HEIGHT * (all->img.bits_pix / 8));
 */
