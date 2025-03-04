/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:20:49 by layang            #+#    #+#             */
/*   Updated: 2025/03/04 19:32:39 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../fdf.h"

static int close_fdf(t_vars *all)
{
	mlx_destroy_window(all->mlx, all->win);
	all->win = NULL;
	mlx_destroy_image(all->mlx, all->img.mlx_img);
	mlx_destroy_display(all->mlx);
	free(all->map->grid);
	free(all->map);
	free(all->orig_map->grid);
	free(all->orig_map);
	free(all->mlx);
	exit(0);
	return (0);
}

static int key_hooks(int keycode, t_vars *all)
{
	if (keycode == XK_Escape)
		close_fdf(all);
	return (0);
}

void	hook_control(t_vars	*all)
{
	mlx_hook(all->win, DestroyNotify, 0, close_fdf, all);
	mlx_key_hook(all->win, key_hooks, all);
}
