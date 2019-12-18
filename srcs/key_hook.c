/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:06:24 by spentti           #+#    #+#             */
/*   Updated: 2019/12/18 19:54:00 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_move(int key, t_info *info)
{
	if (key == UP)
		info->y_off = info->y_off - 10;
	if (key == DOWN)
		info->y_off = info->y_off + 10;
	if (key == RIGHT)
		info->x_off = info->x_off + 10;
	if (key == LEFT)
		info->x_off = info->x_off - 10;
	mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
}

void	key_rotate(int key, t_info *info)
{
	if (key == NUM_2)
		info->camera->alpha += 0.05;
	if (key == NUM_8)
		info->camera->alpha -= 0.05;
	if (key == NUM_4)
		info->camera->beta += 0.05;
	if (key == NUM_6)
		info->camera->beta -= 0.05;
	if (key == NUM_7)
		info->camera->gamma += 0.05;
	if (key == NUM_3)
		info->camera->gamma -= 0.05;
	draw_map(info);
	mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
}

int		key_hook(int key, t_info *info)
{
	if (key == ESC)
		exit (EXIT_SUCCESS);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		move(key, info);
	if (key == NUM_2 || key == NUM_8 || key == NUM_4 || key == NUM_6 || key == NUM_7 || key == NUM_3)
		rotate(key, info);
	return (0);
}
