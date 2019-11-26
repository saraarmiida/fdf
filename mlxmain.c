/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:20:01 by spentti           #+#    #+#             */
/*   Updated: 2019/11/26 20:52:05 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
//#include "libft/includes/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // calc absolute value in some other way

/*
int deal_key(int key, void *param)
{
	ft_putchar('X');
	mlx_pixel_put(&param[0], &param[1], 200, 250, 0xFFFFFF);
	return (0);
}
*/
int	draw_line(int x1, int y1, int x2, int y2, void **param)
{
	
	int dx;
	int dy;
	int m;
	int p;
	int sign;
	int xsign;

	sign = 1;
	xsign = 1;
	if (x1 == x2)
	{
		mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
		if (y1 > y2)
		{
			sign = -1;
			dy = -dy;
		}
		while (y1 != y2)
		{
			y1 = y1 + sign;
			mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
		}
	}
	else
	{
		
		dx = x2 - x1;
		dy = y2 - y1;
		m = dy / dx;
		printf("m = dy / dx = %d / %d = %d\n", dy, dx, m);
		if (dy < 0)
		{
			sign = -1;
			dy = -dy;
		}
		if (dx < 0)
		{
			xsign = -1;
			dx = -dx;
		}
		if (m < 0)
			m = -m;
		mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
		if (m <= 1 && m >= 0)
		{
			p = 2 * dy - dx;
			while (x1 != x2)
			{
				if (p < 0)
				{
					x1 = x1 + xsign;
					mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
					p = p + (2 * dy);
				}
				else
				{
					x1 = x1 + xsign;
					y1 = y1 + sign;
					mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
					p = p + (2 * dy) - (2 * dx);
				}
			}
		}
		if (m > 1)
		{
			p = (2 * dx) - dy;
			while (y1 != y2)
			{
				if (p < 0)
				{
					y1 = y1 + sign;
					mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
					p = p + (2 * dx);
				}
				else
				{
					x1 = x1 + xsign;
					y1 = y1 + sign;
					mlx_pixel_put(param[0], param[1], x1, y1, 0xFFFFFF);
					p = p + (2 * dx) - (2 * dy);
				}
			}
		}
	}
	
	return (0);
}

/*int main()
{
	void *param[2];
	int x;
	int y;

	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
	x = 100;
	y = 100;
	while (x < 500)
	{
		draw_line(x, y, 500, 500, param);
		x += 10;
		y += 5;
	}
	while (x < 900)
	{
		draw_line(x, y, 500, 500, param);
		x += 10;
		y -= 5;
	}
	y = 100;
	x = 100;
	while (y < 500)
	{
		draw_line(x, y, 500, 500, param);
		y += 10;
		x += 5;
	}
	while (y < 900)
	{
		draw_line(x, y, 500, 500, param);
		y += 10;
		x -= 5;
	}
	x = 100;
	y = 900;
	while (x < 500)
	{
		draw_line(x, y, 500, 500, param);
		x += 10;
		y -= 5;
	}
	while (x < 900)
	{
		draw_line(x, y, 500, 500, param);
		x += 10;
		y += 5;
	}
	y = 100;
	x = 900;
	while (y < 500)
	{
		draw_line(500, 500, x, y, param);
		y += 10;
		x -= 5;
	}
	while (y <= 900)
	{
		draw_line(500, 500, x, y, param);
		y += 10;
		x += 5;
	}
	
	mlx_loop(param[0]);
	return (0);
}*/

int main()
{
	void *param[2];
	int x;
	int y;

	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
	//draw_line(200, 400, 500, 100, param);
	//draw_line(500, 100, 800, 300, param);
	draw_line(500, 100, 700, 400, param);
	//draw_line(300, 300, 800, 300, param);
	//draw_line(200, 400, 700, 400, param);
	//draw_line(700, 400, 800, 300, param);
	//draw_line(100, 400, 500, 400, param);
	//draw_line(500, 300, 500, 400, param);
	mlx_string_put(param[0], param[1], 500, 100, 0xFFFFFF, "*");
	mlx_string_put(param[0], param[1], 200, 400, 0xFFFFFF, "*");
	mlx_string_put(param[0], param[1], 300, 300, 0xFFFFFF, "*");
	mlx_string_put(param[0], param[1], 700, 400, 0xFFFFFF, "*");
	mlx_string_put(param[0], param[1], 800, 300, 0xFFFFFF, "*");

	mlx_loop(param[0]);
	return (0);
}