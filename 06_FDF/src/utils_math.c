/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:02 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 20:57:32 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	vec_add(t_point	p1, t_point	p2)
{
	t_point	sum;

	sum.x = p1.x + p2.x;
	sum.y = p1.y + p2.y;
	sum.z = p1.z + p2.z;
	sum.color = p1.color;
	return (sum);
}

t_point vec_sub(t_point p1, t_point p2)
{
	t_point diff;

	diff.x = p1.x - p2.x;
	diff.y = p1.y - p2.y;
	diff.z = p1.z - p2.z;
	diff.color = p1.color;
	return (diff);
}

t_point	multi_mat(t_point p, t_mat mat)
{
	p.x = mat.x1y1 * p.x + mat.x2y1 * p.y + mat.x3y1 * p.z;
	p.y = mat.x1y2 * p.x + mat.x2y2 * p.y + mat.x3y2 * p.z;
	p.z = mat.x1y3 * p.x + mat.x2y3 * p.y + mat.x3y3 * p.z;
	return (p);
}

void autoscale(t_map *map)
{
	float_t scale_x;
	float_t scale_y;
	t_point *cur;
	int range[4];
	int i;

	ft_memset(range, 0, sizeof(range));
	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		if (cur->x < range[0])
			range[0] = cur->x;
		if (cur->x > range[1])
			range[1] = cur->x;
		if (cur->y < range[2])
			range[2] = cur->y;
		if (cur->y > range[3])
			range[3] = cur->y;
		i++;
	}
	scale_x = (WIDTH / 2 - 50) / fmaxf(abs(range[1]), abs(range[0]));
	scale_y = (HEIGHT / 2 - 50) / fmaxf(abs(range[3]), abs(range[2]));
	zoom(map, fminf(scale_x, scale_y));
}
