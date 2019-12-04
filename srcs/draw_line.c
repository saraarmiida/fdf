/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:54 by spentti           #+#    #+#             */
/*   Updated: 2019/12/04 14:18:27 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	no_slope(t_xy *xy, int sign, void **param)
{
	mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
	if (xy->y1 > xy->y2)
	{
		sign = -1;
		xy->dy = -xy->dy;
	}
	while (xy->y1 != xy->y2)
	{
		xy->y1 = xy->y1 + sign;
		mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
	}
}

void	low_slope(t_xy *xy, int sign, int xsign, void **param)
{
	int p;

	p = 2 * xy->dy - xy->dx;
	while (xy->x1 != xy->x2)
	{
		if (p < 0)
		{
			xy->x1 = xy->x1 + xsign;
			mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
			p = p + (2 * xy->dy);
		}
		else
		{
			xy->x1 = xy->x1 + xsign;
			xy->y1 = xy->y1 + sign;
			mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
			p = p + (2 * xy->dy) - (2 * xy->dx);
		}
	}
}

void	high_slope(t_xy *xy, int sign, int xsign, void **param)
{
	int p;

	p = (2 * xy->dx) - xy->dy;
	while (xy->y1 != xy->y2)
	{
		if (p < 0)
		{
			xy->y1 = xy->y1 + sign;
			mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
			p = p + (2 * xy->dx);
		}
		else
		{
			xy->x1 = xy->x1 + xsign;
			xy->y1 = xy->y1 + sign;
			mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
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

int		draw_line(t_xy *xy, void **param)
{
	int m;
	int sign;
	int xsign;

	sign = 1;
	xsign = 1;
	if (xy->x1 == xy->x2)
		no_slope(xy, sign, param);
	else
	{
		signs(xy, &m, &sign, &xsign);
		mlx_pixel_put(param[0], param[1], xy->x1, xy->y1, 0xFFFFFF);
		if (m < 1 && m >= 0)
			low_slope(xy, sign, xsign, param);
		if (m >= 1)
			high_slope(xy, sign, xsign, param);
	}
	return (0);
}
