/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:58 by layang            #+#    #+#             */
/*   Updated: 2025/02/27 18:57:16 by layang           ###   ########.fr       */
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

# define ISO_MATRIX ((float_t[3][3]){            \
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
	char	**file;
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
	int x;
	int y;
	int	z;
	int	color;
}	t_point;

typedef struct	s_map
{
	t_point	*grid;
	int		cell_size;
	int		dim_x;
	int		dim_y;
	int		max_xp;
	int		min_xp;
	int		max_yp;
	int		min_yp;
	int		max_z;
	int		min_z;
	float_t	mat_b[3][3];	
}	t_map;

#endif