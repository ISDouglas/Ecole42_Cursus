/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:49 by layang            #+#    #+#             */
/*   Updated: 2025/02/22 11:14:59 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"

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
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev


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


typedef struct s_vars
{
	void	*win;
	void	*mlx;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	close_win(int	keycode, t_vars	*vars)
{
	if (keycode == 65307)
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

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	t_vars	vars;
/* 	t_data	img;
	int		x;
	int		y; */

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello FDF world!");
/* 	img.img = mlx_new_image(vars.mlx, 1920, 1080);
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
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0); */
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars.win, 17, 0, close_win_x, &vars);
//	mlx_expose_hook(vars.win, );
	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_mouse_hook();
//	mlx_mouse_get_pos();
	mlx_loop(vars.mlx);
	return (0);
}
/* 
颜色数据在不同位深的模式下存储方式不同：

32-bit（ARGB8888）
0xAARRGGBB，每个通道 8-bit（Alpha, Red, Green, Blue）
直接使用 color 不需要转换
24-bit（RGB888）
0xRRGGBB，没有 Alpha 通道
需要调整颜色格式
16-bit（RGB565 / ARGB1555）
0bRRRRRGGGGGGBBBBB
颜色存储方式完全不同，需要 mlx_get_color_value() 进行转换
所以，当 bpp != 32 时，我们必须让 mlx_get_color_value() 适配当前位深，以免颜色错误。 
*/