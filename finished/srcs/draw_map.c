/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:00 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 12:28:22 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso_projection(int *x, int *y, int *z)
{
	int prev_x;

	prev_x = *x;
	*x = (prev_x - *y) * cos(0.523599);
	*y = (-(*z) + (prev_x + *y)) * sin(0.523599);
}

void	get_xy(t_dot *dot, int *x, int *y, t_info *info)
{
	int z;

	*x = dot->x * info->size;
	*y = dot->y * info->size;
	z = dot->z * info->size * info->z_key;
	*x -= ((info->width * info->size) / 2);
	*y -= ((info->height * info->size) / 2);
	rotate_x(y, &z, info->camera->alpha);
	rotate_y(x, &z, info->camera->beta);
	rotate_z(x, y, info->camera->gamma);
	if (info->projection == 1)
		iso_projection(x, y, &z);
	*x = *x + info->x_off;
	*y = *y + info->y_off;
}

void	get_xy_color(t_dot *dot, int *color)
{
	*color = dot->color;
}

t_xy	*make_xy(t_dot *dot, int mode, t_info *info)
{
	int		x;
	t_dot	*temp;

	if (!(dot->xy = (t_xy *)malloc(sizeof(t_xy))))
		return (NULL);
	get_xy(dot, &dot->xy->x1, &dot->xy->y1, info);
	get_xy_color(dot, &dot->xy->color1);
	if (mode == 0)
	{
		get_xy(dot->next, &dot->xy->x2, &dot->xy->y2, info);
		get_xy_color(dot->next, &dot->xy->color2);
	}
	else
	{
		x = dot->x;
		temp = dot->next;
		while (temp->x != x)
			temp = temp->next;
		get_xy(temp, &dot->xy->x2, &dot->xy->y2, info);
		get_xy_color(temp, &dot->xy->color2);
	}
	dot->xy->dx = dot->xy->x2 - dot->xy->x1;
	dot->xy->dy = dot->xy->y2 - dot->xy->y1;
	return (dot->xy);
}

void	draw_background(void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
			mlx_pixel_put(mlx_ptr, win_ptr, x++, y, color);
		y++;
	}
}

int		draw_map(t_info *info)
{
	t_dot	*dot;

	dot = info->head;
	if (info->b_color != BLACK)
		draw_background(info->mlx_ptr, info->win_ptr, info->b_color);
	print_info(info->mlx_ptr, info->win_ptr, info->menu_color);
	while (dot->next)
	{
		if (dot->x < info->x - 1)
		{
			draw_line(make_xy(dot, 0, info), info);
			free(dot->xy);
			dot->xy = NULL;
		}
		if (dot->y < info->y - 1)
		{
			draw_line(make_xy(dot, 1, info), info);
			free(dot->xy);
			dot->xy = NULL;
		}
		dot = dot->next;
	}
	return (0);
}
