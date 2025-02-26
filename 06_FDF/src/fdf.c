/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:00:58 by layang            #+#    #+#             */
/*   Updated: 2025/02/26 19:41:05 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_vars *vars)
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

void mlx_pixel_put(t_pic *pic, int x, int y, int color)
{
	char *dst;

	dst = pic->addr + (y * pic->line_len + x * (pic->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char	**argv)
{
	t_vars	all;
	
	// argv control
	if (argc != 2)
	{
		ft_putstr_fd("FDF: ./fdf file.fdf", 2);
		return (-1);
	}
	// collect pic
	
	// transform points and fit window
	// put into window
	// hook and bonus(extra projection, zoom, translate and rotate)

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
		 */
}