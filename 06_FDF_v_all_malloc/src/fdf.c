/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:47:15 by layang            #+#    #+#             */
/*   Updated: 2025/03/10 09:48:17 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* static int	read_file_01(t_vars	*all, char	*file)
{
	int		fd;
	char	*line;
	int		cols;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("FDF: open file failed.\n", 2);
	if (fd == -1)
		return (free(all->map), 0);
	all->map->dim_y = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		cols = ft_count_words(line, ' ');
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
			ft_putstr_fd("FDF: file error: Found wrong line length.\n", 2);
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
			return (free(all->map), free(line), get_next_line(-1, 0), 0);
		all->map->dim_x = cols;
		free(line);
		all->map->dim_y += 1;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (cols);
} */

static int	read_file_01(t_vars	*all, char	*file)
{
	int		fd;
	char	*line;
	int		cols;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("FDF: open file failed.\n", 2);
	if (fd == -1)
		return (free_fdf(0, all->map, NULL), 0);
	all->map->dim_y = 0;
	all->map->dim_x = 0;
	cols = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		cols = ft_count_words(line, ' ');
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
			ft_putstr_fd("FDF: file error: Found wrong line length.\n", 2);
		if (all->map->dim_y != 0 && all->map->dim_x != cols)
			return (free_fdf(-1, all->map, line, NULL), close(fd), 0);
		all->map->dim_x = cols;
		free(line);
		all->map->dim_y += 1;
		line = get_next_line(fd, 0);
	}
	close(fd);
	printf("dim_x : %d, cols : %d", all->map->dim_x, cols);
	printf(" dim_y : %d\n", all->map->dim_y);
	return (cols);
}

static int	loop_img(t_vars	*all)
{
	t_point	offset;

	if (!all->win)
		return (1);
	render_background(&all->img, BLACK);
	offset.x = WIDTH / 2;
	offset.y = HEIGHT / 2;
	offset.z = 0;
	map_to_img(&all->img, all->map, offset);
	mlx_put_image_to_window(all->mlx, all->win, all->img.mlx_img, 0, 0);
	return (0);
}

int	build_mlx_win(t_vars	*all, char	*name)
{
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
	return (0);
}

static int	start_win_img(t_vars	*all, char	*name)
{

	if (build_mlx_win(all, name) == -1)
		return (-1);
	all->img.mlx_img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
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

int	main(int argc, char **argv)
{
	t_vars	all;

	if (argc != 2)
		ft_putstr_fd("FDF: ./fdf file.fdf\n", 2);
	if (argc != 2)
		return (-1);
	all.map = malloc(sizeof(t_map));
	if (all.map == NULL)
		return (ft_putstr_fd("FDF: failed to build map.\n", 2), -1);
	ft_memset(all.map, 0, sizeof(t_map));
	if (ft_strnstr(argv[1], "42.fdf", ft_strlen(argv[1])))
		all.map->fdf42 = 1;
	else
		all.map->fdf42 = 0;
	if (read_file_01(&all, argv[1]) == 0)
		return (ft_putstr_fd("FDF: empty file.\n", 2),
			free_fdf(0, all.map, NULL), -1);
	printf("\n\n keep on file\n\n");
	//all.map->min_z = 0;
	//all.map->max_z = 0;
	fill_map_02(&all, argv[1]);
	if (color_and_save_05(&all) == -1)
		return (ft_putstr_fd("FDF: save orig map failed.\n", 2), -1);
	projection_scale_07(all.map);
	all.animate = 0;
	if (start_win_img(&all, argv[1]) == -1)
		return (-1);
	return (0);
}
