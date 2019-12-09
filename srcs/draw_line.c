/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:54 by spentti           #+#    #+#             */
/*   Updated: 2019/12/09 16:28:30 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(t_info *info, int x, int y, int color)
{
	int i;

	if (x < WIDTH && x >= 0 && y >= 0 && y < HEIGHT)
	{
		i = (x * info->bits_per_pixel / 8) + (y * info->size_line);
		info->data_addr[i] = color;
		info->data_addr[++i] = color >> 8;
		info->data_addr[++i] = color >> 16;
	}
}

void	no_slope(t_xy *xy, int sign, t_info *info, int color)
{
	put_pixel(info, xy->x1, xy->y1, color);
	if (xy->y1 > xy->y2)
	{
		sign = -1;
		xy->dy = -xy->dy;
	}
	while (xy->y1 != xy->y2)
	{
		xy->y1 = xy->y1 + sign;
		put_pixel(info, xy->x1, xy->y1, color);
	}
}

void	low_slope(t_xy *xy, int sign, int xsign, t_info *info, int color)
{
	int p;

	p = 2 * xy->dy - xy->dx;
	while (xy->x1 != xy->x2)
	{
		if (p < 0)
		{
			xy->x1 = xy->x1 + xsign;
			put_pixel(info, xy->x1, xy->y1, color);
			p = p + (2 * xy->dy);
		}
		else
		{
			xy->x1 = xy->x1 + xsign;
			xy->y1 = xy->y1 + sign;
			put_pixel(info, xy->x1, xy->y1, color);
			p = p + (2 * xy->dy) - (2 * xy->dx);
		}
	}
}

void	high_slope(t_xy *xy, int sign, int xsign, t_info *info, int color)
{
	int p;

	p = (2 * xy->dx) - xy->dy;
	while (xy->y1 != xy->y2)
	{
		if (p < 0)
		{
			xy->y1 = xy->y1 + sign;
			put_pixel(info, xy->x1, xy->y1, color);
			p = p + (2 * xy->dx);
		}
		else
		{
			xy->x1 = xy->x1 + xsign;
			xy->y1 = xy->y1 + sign;
			put_pixel(info, xy->x1, xy->y1, color);
			p = p + (2 * xy->dx) - (2 * xy->dy);
		}
	}
}

void	signs(t_xy *xy, int *m, int *sign, int *xsign)
{
	*m = xy->dy / xy->dx;
	if (xy->dy < 0)
	{
		*sign = -1;
		xy->dy = -xy->dy;
	}
	if (xy->dx < 0)
	{
		*xsign = -1;
		xy->dx = -xy->dx;
	}
	if (*m < 0)
		*m = -*m;
}


int		draw_line(t_xy *xy, t_info *info, int color)
{
	int m;
	int sign;
	int xsign;

	sign = 1;
	xsign = 1;
	if (xy->x1 == xy->x2)
		no_slope(xy, sign, info, color);
	else
	{
		signs(xy, &m, &sign, &xsign);
		put_pixel(info, xy->x1, xy->y1, color);
		if (m < 1 && m >= 0)
			low_slope(xy, sign, xsign, info, color);
		if (m >= 1)
			high_slope(xy, sign, xsign, info, color);
	}
	return (0);
}
