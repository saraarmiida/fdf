/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:21:48 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 16:38:44 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_zoom(int key, t_info *info)
{
	if (key == ZOOM)
		info->size = info->size + 1;
	if (key == DEZOOM)
		info->size = info->size - 1;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

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
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}

void	key_rotate(int key, t_info *info)
{
	if (key == ROT_X1)
		info->camera->alpha += 0.05;
	else if (key == ROT_X2)
		info->camera->alpha -= 0.05;
	else if (key == ROT_Y1)
		info->camera->beta += 0.05;
	else if (key == ROT_Y2)
		info->camera->beta -= 0.05;
	else if (key == ROT_Z1)
		info->camera->gamma += 0.05;
	else if (key == ROT_Z2)
		info->camera->gamma -= 0.05;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_map(info);
}
