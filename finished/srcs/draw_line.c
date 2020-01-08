/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:54 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 12:08:36 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		  pixel_color(t_xy *xy)
{
	return (xy->color1);
}

void	no_slope(t_xy *xy, int sign, t_info *i)
{
	int	y;

	y = xy->y1;
	mlx_pixel_put(i->mlx_ptr, i->win_ptr, xy->x1, y, pixel_color(xy));
	if (xy->y1 > xy->y2)
	{
		sign = -1;
		xy->dy = -xy->dy;
	}
	while (y != xy->y2)
	{
		y = y + sign;
		mlx_pixel_put(i->mlx_ptr, i->win_ptr, xy->x1, y, pixel_color(xy));
	}
}

void	low_slope(t_xy *xy, int sign, int xsign, t_info *i)
{
	int p;
	int	x;
	int	y;

	x = xy->x1;
	y = xy->y1;
	p = 2 * xy->dy - xy->dx;
	while (x != xy->x2)
	{
		if (p < 0)
		{
			x += xsign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, x, y, pixel_color(xy));
			p = p + (2 * xy->dy);
		}
		else
		{
			x += xsign;
			y += sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, x, y, pixel_color(xy));
			p = p + (2 * xy->dy) - (2 * xy->dx);
		}
	}
}

void	high_slope(t_xy *xy, int sign, int xsign, t_info *i)
{
	int p;
	int	x;
	int	y;

	x = xy->x1;
	y = xy->y1;
	p = (2 * xy->dx) - xy->dy;
	while (y != xy->y2)
	{
		if (p < 0)
		{
			y = y + sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, x, y, pixel_color(xy));
			p = p + (2 * xy->dx);
		}
		else
		{
			x += xsign;
			y += sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, x, y, pixel_color(xy));
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

int		draw_line(t_xy *xy, t_info *info)
{
	int m;
	int sign;
	int xsign;
	int c;

	sign = 1;
	xsign = 1;
	c = pixel_color(xy);
	if (xy->x1 == xy->x2)
		no_slope(xy, sign, info);
	else
	{
		signs(xy, &m, &sign, &xsign);
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, xy->x1, xy->y1, c);
		if (m < 1 && m >= 0)
			low_slope(xy, sign, xsign, info);
		if (m >= 1)
			high_slope(xy, sign, xsign, info);
	}
	return (0);
}
