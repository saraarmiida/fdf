/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:42:04 by spentti           #+#    #+#             */
/*   Updated: 2020/01/07 13:42:53 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_info	*create_info(t_info *info)
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
	info->color = LIGHT_BLUE;
	info->b_color = BLACK;
	info->menu_color = WHITE;
	info->z_key = 1;
	info->projection = 1;
	info->camera->alpha = 0;
	info->camera->beta = 0;
	info->camera->gamma = 0;
	return (info);
}

void	print_info(void *mlx_ptr, void *win_ptr, int color)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, 15, color, "How to use:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 35, color, "Zoom:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 55, color, "Move:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 75, color, "Projection:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 95, color, "Color:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 115, color, "Background:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 135, color, "Rotate:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 155, color, "x-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 175, color, "y-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 195, color, "z-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 215, color, "Height:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 235, color, "Change map:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 255, color, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, 150, 35, color, "+/-");
	mlx_string_put(mlx_ptr, win_ptr, 150, 55, color, "arrow keys");
	mlx_string_put(mlx_ptr, win_ptr, 150, 75, color, "1");
	mlx_string_put(mlx_ptr, win_ptr, 150, 95, color, "2");
	mlx_string_put(mlx_ptr, win_ptr, 150, 115, color, "3");
	mlx_string_put(mlx_ptr, win_ptr, 150, 155, color, "N/I");
	mlx_string_put(mlx_ptr, win_ptr, 150, 175, color, "M/U");
	mlx_string_put(mlx_ptr, win_ptr, 150, 195, color, "H/K");
	mlx_string_put(mlx_ptr, win_ptr, 150, 215, color, "(/)");
	mlx_string_put(mlx_ptr, win_ptr, 150, 235, color, "</>");
	mlx_string_put(mlx_ptr, win_ptr, 150, 255, color, "esc");
}

void	error_exit(char *s)
{
	if ((ft_strcmp(s, "usage: ./fdf map_file")))
		ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(s, 2);
	exit(1);
}

int		main(int argc, char **argv)
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
