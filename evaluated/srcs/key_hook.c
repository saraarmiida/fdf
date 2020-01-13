/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:06:24 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 16:41:06 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	key_height(int key, t_info *info)
{
	t_dot *dot;

	dot = info->head;
	if (key == LOWER)
		info->z_key -= 0.1;
	else if (key == HIGHER)
		info->z_key += 0.1;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

static void	key_color(int key, t_info *info)
{
	static int i;

	if (!i || i == 5)
		i = 1;
	else
		i++;
	if (i == 1)
		info->color = PINK;
	if (i == 2)
		info->color = PURPLE;
	if (i == 3)
		info->color = LIGHT_BLUE;
	if (i == 4)
		info->color = YELLOW;
	if (i == 5)
		info->color = MINT;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

static void	key_projection(t_info *info)
{
	if (info->projection == 1)
		info->projection = 0;
	else
		info->projection = 1;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

static void	key_background(t_info *info)
{
	static int i;

	if (!i || i == 3)
		i = 1;
	else
		i++;
	if (i == 1)
		info->b_color = GREY;
	if (i == 2)
		info->b_color = OLIVE;
	if (i == 3)
		info->b_color = BLACK;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

int			key_hook(int key, t_info *info)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		key_move(key, info);
	if (key == ZOOM || key == DEZOOM)
		key_zoom(key, info);
	if (key == ROT_X1 || key == ROT_X2 || key == ROT_Y1 \
	|| key == ROT_Y2 || key == ROT_Z1 || key == ROT_Z2)
		key_rotate(key, info);
	if (key == COLOR)
		key_color(key, info);
	if (key == LOWER || key == HIGHER)
		key_height(key, info);
	if (key == PROJ)
		key_projection(info);
	if (key == B_COLOR)
		key_background(info);
	return (0);
}
