/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 13:13:27 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_color(char *dot)
{
	int i;

	i = 0;
	while (dot[i] != ',')
		i++;
	if (dot[i] == '\0')
		return (WHITE);
	else
		return (ft_atoi_base(&dot[i + 3], "16"));
}

void	set_zvalues(int z, t_info *info)
{
	if (info->z_max == '\0')
	{
		info->z_max = z;
		info->z_min = z;
	}
	if (z > info->z_max)
		info->z_max = z;
	if (z < info->z_min)
		info->z_min = z;
}

int		save_map(t_info *info)
{
	t_dot	*dot;
	int		i;

	info->y = 0;
	while (info->map[info->y])
	{
		info->x = 0;
		while (info->map[info->y][info->x])
		{
			check_dot(info->map[info->y][info->x]);
			if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
				error_exit("dot initialization error");
			dot = dot->next;
			dot->y = info->y;
			dot->x = info->x;
			dot->z = ft_atoi(info->map[info->y][info->x]);
			set_zvalues(dot->z, info);
			dot->color = get_color(info->map[info->y][info->x]);
			dot->next = NULL;
			if (info->head == NULL)
				info->head = dot;
			info->x++;
		}
		info->y++;
	}
	return (0);
}

int		read_map(t_info *info, char *argv)
{
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
		error_exit("info->map initialization error");
	fd = open(argv, O_RDONLY);
	info->y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info->map[info->y] = ft_strsplit(line, ' ');
		check_line(info->map[info->y], info->y, info);
		info->y++;
		ft_strdel(&line);
	}
	info->map[info->y] = NULL;
	close(fd);
	return (0);
}
