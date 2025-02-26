/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:42:58 by layang            #+#    #+#             */
/*   Updated: 2025/02/26 18:50:14 by layang           ###   ########.fr       */
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
	void	*win;
	void	*mlx;
}	t_vars;

typedef struct s_pic
{
	void	*mlx_img;
	void	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_pic;

typedef struct s_point
{
	int x;
	int y;
	int	z;
	int	color;
}	t_point;

typedef struct	s_img
{
	t_point	*map;
	int	cell_size;
}	t_img;

#endif