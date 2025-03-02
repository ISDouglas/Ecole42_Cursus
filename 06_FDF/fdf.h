/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/02 18:29:46 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# define WHITE	0x00FFFFFF
# define PURPLE	0x00B491C8
# define BLUE	0x00000066
# define GROUND_COLOR	WHITE
# define HIGH_COLOR		PURPLE
# define LOW_COLOR		BLUE

# define ISO_MATRIX ((float_t[3][3]){          \
	{sqrt(3) / 3, -sqrt(6) / 6, -sqrt(6) / 6}, \
	{sqrt(3) / 3,  sqrt(6) / 6,  sqrt(6) / 6}, \
	{sqrt(3) / 3,  sqrt(3) / 3, -sqrt(3) / 3}})

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	*map;
	t_map	*orig_map;
	int		animate;
}	t_vars;

typedef struct s_img
{
	void	*mlx_img;
	void	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	float_t x;
	float_t y;
	float_t z;
	int		color;
}	t_point;

typedef	struct s_mat
{
	float_t	x1y1;
	float_t x1y2;
	float_t x1y3;
	float_t x2y1;
	float_t x2y2;
	float_t x2y3;
	float_t x3y1;
	float_t x3y2;
	float_t x3y3;
}	t_mat;


typedef struct	s_map
{
	t_point	*grid;
	int		cell_size;
	int		dim_x;
	int		dim_y;
	int		max_z;
	int		min_z;
	int		with_color;
	t_mat	b_mat;
}	t_map;

#endif