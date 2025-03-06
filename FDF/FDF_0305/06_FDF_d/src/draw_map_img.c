/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:57:54 by layang            #+#    #+#             */
/*   Updated: 2025/03/06 14:54:03 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void render_background(t_pic	*img, int	color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(img, (t_point){j, i, 0, color});
			j++;
		}
		i++;
	}
}


void map_to_img(t_pic	*img, t_map	*map, t_point	offset)
{
	int		i;
	t_point *cur;
	t_point	point;
	t_point	point_right;
	t_point point_down;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		point = vec_add(*cur, offset);
		if (i % map->dim_x != map->dim_x - 1)
		{
			point_right = vec_add(*(cur + 1), offset);
			draw_bresenham_line(img, point, point_right);
		}
		if (i < map->dim_x * map->dim_y - map->dim_x)
		{
			point_down = vec_add(*(cur + map->dim_x), offset);
			draw_bresenham_line(img, point, point_down);
		}
		i++;
	}
}
