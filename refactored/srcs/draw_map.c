/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:00 by spentti           #+#    #+#             */
/*   Updated: 2020/01/07 16:45:35 by spentti          ###   ########.fr       */
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

t_dot	*get_xy(t_dot *dot, t_info *info)
{
	dot->x = dot->x * info->size;
	dot->y = dot->y * info->size;
	dot->z = dot->z * info->size * info->z_key;
	dot->x -= ((info->width * info->size) / 2);
	dot->y -= ((info->height * info->size) / 2);
	rotate_x(&dot->y, &dot->z, info->camera->alpha);
	rotate_y(&dot->x, &dot->z, info->camera->beta);
	rotate_z(&dot->x, &dot->y, info->camera->gamma);
	if (info->projection == 1)
		iso_projection(&dot->x, &dot->y, &dot->z);
	dot->x += info->x_off;
	dot->y += info->y_off;
	return (dot);
}

t_line	*make_xy(t_dot *dot, int mode, t_info *info)
{
	int		x;
	t_line	*line;
	t_dot	*temp;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		error_exit("line initialization error");
	line->start = get_xy(dot, info);
	if (mode == 0)
	{
		line->end = get_xy(dot->next, info);
	}
	else
	{
		x = dot->x;
		temp = dot->next;
		while (temp->x != x)
			temp = temp->next;
		line->end = get_xy(temp, info);
	}
	line->dx = line->end->x - line->start->x;
	line->dy = line->end->y - line->start->y;
	ft_putendl("RAINBOW");
	return (line);
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
	t_line	*line;

	dot = info->head;
	if (info->b_color != BLACK)
		draw_background(info->mlx_ptr, info->win_ptr, info->b_color);
	print_info(info->mlx_ptr, info->win_ptr, info->menu_color);
	while (dot->next)
	{
		if (dot->x < info->x - 1)
		{
			draw_line((line = make_xy(dot, 0, info)), info);
			free(line);
			line = NULL;
		}
		if (dot->y < info->y - 1)
		{
			draw_line((line = make_xy(dot, 1, info)), info);
			free(line);
			line = NULL;
		}
		dot = dot->next;
	}
	return (0);
}
