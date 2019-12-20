/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:42:04 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 17:24:17 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		read_map(t_info *info, char *argv)
{
	int		y;
	char	*line;
	int		fd;

	info->height = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		info->height++;
		ft_strdel(&line);
	}
	close(fd);
	if (!(info->map = (char ***)malloc(sizeof(char **) * (info->height + 1))))
		return (1);
	fd = open(argv, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info->map[y] = ft_strsplit(line, ' ');
		y++;
		ft_strdel(&line);
	}
	info->map[y] = NULL;
	close(fd);
	return (0);
}

t_info	*create_info(t_info *info)
{
	if (!(info = malloc(sizeof(t_info))))
		return (NULL);
	if (!(info->camera = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	info->height = 0;
	info->width = 0;
	info->head = NULL;
	info->x_off = 600;
	info->y_off = 400;
	info->key_z = 0;
	if (info->gammamode != 1)
		info->camera->gamma = 0.523599;
	return (info);
}

int		main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
	{
		ft_putendl("Parameters not valid.");
		return (1);
	}
	if (!(info = create_info(info)))
		return (1);
	if (read_map(info, argv[1]))
		return (1);
	info->head = save_map(info);
	get_size(info);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "mlx_42");
	draw_map(info);
	mlx_key_hook(info->win_ptr, key_hook, info);
	mlx_loop(info->mlx_ptr);
	clear_map(info->map);
	clear_info(info);
	while (1);
	return (0);
}
