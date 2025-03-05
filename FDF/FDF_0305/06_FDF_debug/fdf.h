/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:58 by layang            #+#    #+#             */
/*   Updated: 2025/03/05 10:35:38 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
# include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# define BUFFER_SIZE 1000

# define WHITE	0x00FFFFFF
# define PURPLE	0x00B491C8
# define BLUE	0x00000066
# define BLACK	0x00000000
# define GROUND_COLOR	WHITE
# define HIGH_COLOR		PURPLE
# define LOW_COLOR		BLUE
#define ISO_RADIAN 0.6154797

typedef struct s_pic
{
	void *mlx_img;
	void *addr;
	int bits_pix;
	int line_len;
	int endian;
} t_pic;

typedef struct s_point
{
	float_t x;
	float_t y;
	float_t z;
	int color;
}	t_point;

typedef struct s_mat
{
	float_t x1y1;
	float_t x2y1;
	float_t x3y1;
	float_t x1y2;
	float_t x2y2;
	float_t x3y2;
	float_t x1y3;
	float_t x2y3;
	float_t x3y3;
}	t_mat;

typedef struct s_map
{
	t_point *grid;
	int cell_size;
	int dim_x;
	int dim_y;
	int max_z;
	int min_z;
	int with_color;
	t_point i;
	t_point j;
	t_point k;
	t_point locate;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_pic	img;
	t_map	*map;
	t_map	*orig_map;
	int		animate;
}	t_vars;

// math tools:
t_point	multi_mat(t_point p, t_mat mat);
t_point	vec_add(t_point p1, t_point p2);
t_point vec_sub(t_point p1, t_point p2);

// transformation founctions
void rotate_x(t_map *map, float_t angle);
void rotate_y(t_map *map, float_t angle);
void rotate_z(t_map *map, float_t angle);
void scale_z(t_vars *all, float_t factor);
void zoom(t_map *map, float_t factor);
void autoscale(t_map *map);
void projection_scale_07(t_map *map);
t_map *fdf_transform(t_map *map, t_mat rot_mat);
void reset_map(t_vars *all);
void re_translate(t_map *map);

// grid and image drawing
t_map *fill_map_02(t_vars *all, char *file);
int color_and_save_05(t_vars *all);
void render_background(t_pic *img, int color);
void map_to_img(t_pic *img, t_map *map, t_point offset);
void gradient_color(float_t r, int rgb[3], int s, int e);
int get_pix_color(t_point cur, t_point start, t_point end);
void put_pixel(t_pic *img, t_point pt);
int draw_bresenham_line(t_pic *img, t_point start, t_point end);

// hook controls
void hook_control(t_vars *all);

#endif