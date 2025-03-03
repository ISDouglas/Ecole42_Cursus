/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:33:13 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 21:00:14 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void gradient_color_07(float_t r, int *rgb[3], int s, int e)
{
	rgb[0] = (int)roundf((1 - r) * ((s >> 16) & 0xFF) + r * ((e >> 16) & 0xFF));
	rgb[1] = (int)roundf((1 - r) * ((s >> 8) & 0xFF) + r * ((e >> 8) & 0xFF));
	rgb[2] = (int)roundf((1 - r) * (s & 0xFF) + r * (e & 0xFF));
}

int	get_pix_color(t_point	cur, t_point start, t_point end)
{
	t_point	delta;
	float_t	ratio;

	delta = vec_sub(end, start);
	
}
