/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:39:04 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 20:42:02 by layang           ###   ########.fr       */
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

void	scale_z(t_map	*map, float_t	f)
{
	
}


