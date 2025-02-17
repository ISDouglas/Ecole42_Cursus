/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:49 by layang            #+#    #+#             */
/*   Updated: 2025/02/17 12:27:09 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
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
}

/*
cc -o my_fdf main.c -L. -lmlx -lm -lpthread -lX11 -lXext
./my_fdf

/usr/include/X11/Xlib.h
/usr/include/X11/extensions/XShm.h
*/

