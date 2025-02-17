/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:49 by layang            #+#    #+#             */
/*   Updated: 2025/02/17 19:33:50 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

/* int main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello FDF!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
	return 0;
} */

/*
cc -o my_fdf main.c -L. -lmlx -lm -lpthread -lX11 -lXext
./my_fdf

/usr/include/X11/Xlib.h
/usr/include/X11/extensions/XShm.h
*/

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello FDF world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	x = 100;
	while (x < 150)
	{
		y = 100;
		while (y < 300)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	x = 150;
	while (x < 250)
	{
		y = 150;
		while (y < 200)
		{
			my_mlx_pixel_put(&img, x, y, 0x000080);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
