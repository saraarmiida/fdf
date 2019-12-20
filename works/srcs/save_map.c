/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 17:19:25 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_size(t_info *info)
{
	info->bigger = info->x;
	if (info->height > info->x)
		info->bigger = info->height;
	if (info->bigger < 500)
		info->size = 500 / info->bigger;
	else
		info->size = info->bigger / 500;
}

t_dot	*save_map(t_info *info)
{
	t_dot	*dot;
	int		i;
	char	**ddot;

	info->y = 0;
	while (info->map[info->y])
	{
		info->x = 0;
		while (info->map[info->y][info->x])
		{
			if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
				return (NULL);
			ddot = ft_strsplit(info->map[info->y][info->x], ',');
			dot = dot->next;
			dot->y = info->y;
			dot->x = info->x;
			dot->color = 0xFFFFFF;                                                                                         
			dot->z = ft_atoi(ddot[0]);
			// if (ddot[1])
			// {
			// 	//ft_putendl(ddot[1]);
			// 	dot->color = ft_atoi_base(ddot[1], 16);
			// }
			dot->next = NULL;
			if (info->head == NULL)
				info->head = dot;
			arr_del(ddot);
			info->x++;
		}
		info->y++;
	}
	return (info->head);
}

// int		save_dot(char **point, t_info *info)
// {
// 	t_dot *dot;

// 	if (info->head != NULL)
// 	{
// 		dot = dot->next;
// 		ft_putarr(point);
// 	}
// 	if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
// 		return (1);
// 	dot = dot->next;
// 	dot->y = info->y;
// 	dot->x = info->x;
// 	dot->color = 0xFFFFFF;
// 	dot->z = ft_atoi(point[0]);
// 	if (point[1])
// 		dot->color = ft_atoi(point[1]);
// 	dot->next = NULL;
// 	if (info->head == NULL)
// 		info->head = dot;
// 	arr_del(point);
// 	return (0);
// }

// int		split_row(char **line, t_info *info)
// {
// 	info->x = 0;
// 	while (line[info->x])
// 	{
// 		if ((save_dot(ft_strsplit(line[info->x], ','), info)))
// 			return (1);
// 		ft_putendl("STAR");
// 		info->x++;
// 	}
// 	return (0);
// }

// int		read_map(t_info *info, char *argv)
// {
// 	char	*line;
// 	char	**row;
// 	int		fd;

// 	info->height = 0;
// 	fd = open(argv, O_RDONLY);
// 	while (get_next_line(fd, &line) > 0)
// 		info->height++;
// 	close(fd);
// 	fd = open(argv, O_RDONLY);
// 	info->y = 0;
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		row = ft_strsplit(line, ' ');
// 		if ((split_row(row, info)))
// 			return (1);
// 		info->y++;
// 		arr_del(row);
// 		ft_strdel(&line);
// 	}
// 	close(fd);
// 	return (0);
// }