/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:41:04 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 20:43:16 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map *fdf_transform(t_map *map, t_mat rot_mat)
{
	int i;
	t_point *cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = multi_mat(*cur, rot_mat);
		i++;
	}
	map->i = multi_mat(map->i, rot_mat);
	map->j = multi_mat(map->j, rot_mat);
	map->k = multi_mat(map->k, rot_mat);
	return (map);
}

void reset_map(t_map *map)
{
	
}

void re_translate(t_map *map)
{
	int i;
	t_point *cur;

	i = 0;
	while (i < map->dim_x * map->dim_y)
	{
		cur = map->grid + i;
		*cur = vec_add(*cur, map->locate);
		i++;
	}
}