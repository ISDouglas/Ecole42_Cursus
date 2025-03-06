/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:04 by layang            #+#    #+#             */
/*   Updated: 2025/03/06 03:24:34 by layang           ###   ########.fr       */
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
	//int i;
	//t_point *cur;

	rot_mat = (t_mat){cos(angle), -sin(angle), 0,
					  sin(angle), cos(angle), 0,
					  0, 0, 1};
	fdf_transform(map, rot_mat);
/* 	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = multi_mat(rot_mat, *cur);
		i++;
	} */
}

void	scale_z(t_vars	*all, float_t	factor)
{
	t_mat scale_z;
	//t_mat tmp;
	t_map *map;

	map = all->map;
	map->zscale *= factor;
/* 	tmp = (t_mat){
		map->i.x, map->i.y, map->i.z,
		map->j.x, map->j.y, map->j.z,
		map->k.x, map->k.y, map->k.z}; */
/* 	tmp = (t_mat){
		map->i.x, map->j.x, map->k.x,
		map->i.y, map->j.y, map->k.y,
		map->i.z, map->j.z, map->k.z}; */
	scale_z = (t_mat){1, 0, 0, 0, 1, 0, 0, 0, map->zscale};
	reset_map(all);
	fdf_transform(map, scale_z);
	projection_scale_07(map);
	//fdf_transform(map, tmp);
	re_translate(map);
	//autoscale(map);
}

void	translate(t_map *map, t_point offset)
{
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = vec_add(*cur, offset);
		i++;
	}
	map->locate = vec_add(map->locate, offset);
}
