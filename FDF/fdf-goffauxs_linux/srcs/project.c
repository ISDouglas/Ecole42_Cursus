/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:45:49 by sgoffaux          #+#    #+#             */
/*   Updated: 2025/02/28 19:51:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_point	project(int x, int y, t_fdf *env)
{
	t_point	point;

	point.z = env->map->array[y][x][0];
	if (env->map->array[y][x][1] >= 0)
		point.color = env->map->array[y][x][1];
	else if (point.z == 0)
	{
		if ((x + 1 < env->map->width && env->map->array[y][x + 1][0] != 0) ||
			(y + 1 < env->map->height && env->map->array[y + 1][x][0] != 0))
			point.color = 0xFAAE7B;
		else
			point.color = 0xFFFFFF;
	}		
	else
		point.color = get_default_color(env->map->array[y][x][0], env->map);
	point.x = x * env->camera->zoom;
	point.y = y * env->camera->zoom;
	point.z *= env->camera->zoom/ env->camera->z_height;
	point.z *= 0.5;
	point.x -= (env->map->width * env->camera->zoom) / 2;
	point.y -= (env->map->height * env->camera->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, env->camera->x_angle);
	ft_rotate_y(&point.x, &point.z, env->camera->y_angle);
	ft_rotate_z(&point.x, &point.y, env->camera->z_angle);
	point.x += WIDTH / 2 + env->camera->x_offset;
	point.y += (HEIGHT + env->map->height / 2 * env->camera->zoom) / 2
		+ env->camera->y_offset;
	point.reverse = 0;
	return (point);
}
