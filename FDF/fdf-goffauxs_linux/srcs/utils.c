/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:18:12 by sgoffaux          #+#    #+#             */
/*   Updated: 2025/02/28 19:44:01 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void	ft_get_z_min_max(t_map *map, int n)
{
	if (n > map->z_max)
		map->z_max = n;
	if (n < map->z_min)
		map->z_min = n;
}

void	ft_return_error(const char *err_msg, int system_function)
{
	if (!system_function)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	else
		perror(err_msg);
	exit(-1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_max - map->z_min;
	if (max == 0 || z == 0)
		return (0xFFFFFF);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0xFAAE7B);
	else if (percent < 0.4)
		return (0xFAAE7B);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else return (0x432371);
}
