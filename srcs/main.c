/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:42:04 by spentti           #+#    #+#             */
/*   Updated: 2019/12/04 17:34:55 by spentti          ###   ########.fr       */
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
	return (info);
}

int		main(int argc, char **argv)
{
	t_info *info;

	if (argc != 2)
	{
		ft_putendl("Parameters not valid.");
		return (1);
	}
	if (!(info = create_info(info)))
		return (1);
	if (read_map(info, argv[1]))
		return (1);
	info->head = save_coords(info->map, info->head);
	info->param[0] = mlx_init();
	info->param[1] = mlx_new_window(info->param[0], 1000, 1000, "mlx_42");
	draw_map(info);
	// mlx_key_hook(info->param[1], ft_key_hook(), info->param);
	mlx_loop(info->param[0]);
	return (0);
}
