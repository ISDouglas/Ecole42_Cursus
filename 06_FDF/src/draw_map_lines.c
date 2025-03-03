/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:39 by layang            #+#    #+#             */
/*   Updated: 2025/03/03 20:53:25 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
Line drawing implementation using Bresenham's Line Algorithmm.
See:
https://www.markwrobel.dk/post/amiga-machine-code-letter12-linedraw/
*/

void	put_pixel()
{
	
}

int draw_low_line(t_img *img, t_point s, t_point e)
{
	double err;
	double slope;
	double step;
	t_point cur;

	slope = (double)(e.y - s.y) / (e.x - s.x);
	err = -0.5;
	step = fabs(slope);
	cur = s;
	while (cur.x < e.x)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (slope > 0)
				cur.y++;
			else
				cur.y--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.x++;
	}
}

int draw_high_line(t_img *img, t_point s, t_point e)
{
	double err;
	double tr_slope;
	double step;
	t_point cur;

	tr_slope = (double)(e.x - s.x) / (e.y - s.y);
	err = -0.5;
	step = fabs(tr_slope);
	cur = s;
	while (cur.y < e.y)
	{
		put_pixel(img, cur);
		err += step;
		if (err >= 0)
		{
			if (tr_slope > 0)
				cur.x++;
			else
				cur.x--;
			err--;
		}
		cur.color = get_pix_color(cur, s, e);
		cur.y++;
	}
}
