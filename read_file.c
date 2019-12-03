/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:06:07 by spentti           #+#    #+#             */
/*   Updated: 2019/12/03 19:40:02 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		save_xy(t_dot *dot, int x, int y, char *z)
{
	if (!(dot = (t_dot *)malloc(sizeof(t_dot))))
		return (1);
	dot->z = ft_atoi(z);
	dot->y = y;
	dot->x = x;
	dot->next = NULL;
	return (0);
}

int		make_list(t_dot *head, t_dot *dot, int *x, int *y, char *z)
{
	if (head == NULL)
	{
		if (!(head = (t_dot *)malloc(sizeof(t_dot))))
			return (1);
		head->z = ft_atoi(z);
		head->y = *y;
		head->x = *x;
		dot = head;
		dot->next = NULL;
	}
	else
	{
		if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
			return (1);
		dot = dot->next;
		dot->y = *y;
		dot->x = *x;
		dot->z = ft_atoi(z);
		dot->next = NULL;
	}
	return (0);
}

t_dot	*save_coords(char **map, t_dot *head)
{
	t_dot	*dot;
	int		fake_x;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		fake_x = 0;
		while (map[y][fake_x])
		{
			if (map[y][fake_x] >= '0' && map[y][fake_x] <= '9')
			{
				if (head == NULL)
				{
					if (!(head = (t_dot *)malloc(sizeof(t_dot))))
						return (NULL);
					head->z = ft_atoi(&map[y][fake_x]);
					head->y = y;
					head->x = x;
					dot = head;
					dot->next = NULL;
					x++;
				}
				else
				{
					if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
						return (NULL);
					dot = dot->next;
					dot->y = y;
					dot->x = x;
					dot->z = ft_atoi(&map[y][fake_x]);
					dot->next = NULL;
					x++;
				}
				// if (make_list(head, dot, &x, &y, &map[y][fake_x]))
				// 	return (NULL);
				x++;
				while (map[y][fake_x] >= '0' && map[y][fake_x] <= '9')
					fake_x++;
			}
			else
				fake_x++;
		}
		y++;
	}
	return (head);
}

int		read_map(t_info *info, char *argv)
{
	int		y;
	char	*line;
	int		fd;

	info->line_nb = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		info->line_nb++;
	close(fd);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->line_nb + 1))))
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
	info->line_nb = 0;
	info->head = NULL;
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
	mlx_loop(info->param[0]);
	return (0);
}
