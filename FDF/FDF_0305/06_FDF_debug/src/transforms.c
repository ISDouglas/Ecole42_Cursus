/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:04 by layang            #+#    #+#             */
/*   Updated: 2025/03/04 18:08:31 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void rotate_x(t_map *map, float_t angle)
{
	t_mat rot_mat;

	rot_mat = (t_mat){1, 0, 0,
					  0, cos(angle), -sin(angle),
					  0, sin(angle), cos(angle)};
	fdf_transform(map, rot_mat);
}

void rotate_y(t_map *map, float_t angle)
{
	t_mat rot_mat;

	rot_mat = (t_mat){cos(angle), 0, sin(angle),
					  0, 1, 0,
					  -sin(angle), 0, cos(angle)};
	fdf_transform(map, rot_mat);
}

void rotate_z(t_map *map, float_t angle)
{
	t_mat rot_mat;

	rot_mat = (t_mat){cos(angle), -sin(angle), 0,
					  sin(angle), cos(angle), 0,
					  0, 0, 1};
	fdf_transform(map, rot_mat);
}

void	scale_z(t_vars	*all, float_t	factor)
{
	t_mat scale_z;
	t_mat tmp;
	t_map *map;

	map = all->map;
	tmp = (t_mat){
		map->i.x, map->i.y, map->i.z,
		map->j.x, map->j.y, map->j.z,
		map->k.x, map->k.y, map->k.z};
	scale_z = (t_mat){1, 0, 0, 0, 1, 0, 0, 0, factor};
	reset_map(all);
	fdf_transform(map, scale_z);
	fdf_transform(map, tmp);
	re_translate(map);
}

void projection_scale_07(t_map *map)
{
	rotate_y(map, -M_PI_4);
	rotate_x(map, -ISO_RADIAN);
	autoscale(map);
}
