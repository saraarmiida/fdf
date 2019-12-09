/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:06:24 by spentti           #+#    #+#             */
/*   Updated: 2019/12/09 18:04:35 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_info *info)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	if (keycode == UP)
	{
		info->y_off = info->y_off - 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	if (keycode == DOWN)
	{	
		info->y_off = info->y_off + 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	if (keycode == RIGHT)
	{
		info->x_off = info->x_off + 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	if (keycode == LEFT)
	{
		info->x_off = info->x_off - 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	if (keycode == ZOOM)
	{
		info->size = info->size + 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	if (keycode == DEZOOM)
	{
		info->size = info->size - 10;
		mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	}
	return (0);
}
