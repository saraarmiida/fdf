/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:42:04 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 16:33:38 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_info	*create_info(t_info *info)
{
	if (!(info = malloc(sizeof(t_info))))
		error_exit("info initialization error");
	if (!(info->camera = (t_camera *)malloc(sizeof(t_camera))))
		error_exit("info->camera initialization error");
	info->height = 0;
	info->width = 0;
	info->head = NULL;
	info->x_off = 800;
	info->y_off = 600;
	info->color = MINT;
	info->b_color = BLACK;
	info->menu_color = WHITE;
	info->z_key = 1;
	info->projection = 1;
	info->camera->alpha = 0;
	info->camera->beta = 0;
	info->camera->gamma = 0;
	return (info);
}

int				main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		error_exit("usage: ./fdf map_file");
	info = create_info(info);
	read_map(info, argv[1]);
	if (save_map(info))
		error_exit("map initialization error");
	get_size(info);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fdf_42");
	draw_map(info);
	mlx_key_hook(info->win_ptr, key_hook, info);
	mlx_loop(info->mlx_ptr);
	clear_map(info->map);
	clear_info(info);
	return (0);
}
