/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:42:04 by spentti           #+#    #+#             */
/*   Updated: 2019/12/19 16:47:02 by spentti          ###   ########.fr       */
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
		info->height++;
	close(fd);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->height + 1))))
		return (1);
	fd = open(argv, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info->map[y] = ft_strdup(line);
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
	info->height = 0;
	info->width = 0;
	info->head = NULL;
	info->x_off = 300;
	info->y_off = 100;
	info->bits_per_pixel = 24;
	info->endian = 1;
	return (info);
}

void	clear(t_info *info)
{
	int x;
	int y;

	while (info->head)
	{
		free(info->head->xy);
		info->head = info->head->next;
		free(info->head);
	}
	free(info->dot);
	free(info->data_addr);
	x = 0;
	y = 0;
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
	info->param[0] = mlx_init();
	info->param[1] = mlx_new_window(info->param[0], WIDTH, HEIGHT, "mlx_42");
	info->param[2] = mlx_new_image(info->param[0], WIDTH, HEIGHT);
	info->size_line = WIDTH * 24;
	info->data_addr = mlx_get_data_addr(info->param[2], &info->bits_per_pixel, &info->size_line, &info->endian);
	draw_map(info);
	mlx_key_hook(info->param[1], key_hook, info);
	mlx_put_image_to_window(info->param[0], info->param[1], info->param[2], info->x_off, info->y_off);
	mlx_loop(info->param[0]);
	// clear(info);
	return (0);
}
