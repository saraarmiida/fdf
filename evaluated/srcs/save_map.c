/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2020/01/09 12:41:21 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			save_map(t_info *info)
{
	t_dot	*dot;
	int		i;

	info->y = 0;
	while (info->map[info->y])
	{
		info->x = 0;
		while (info->map[info->y][info->x])
		{
			if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
				error_exit("dot initialization error");
			dot = dot->next;
			dot->y = info->y;
			dot->x = info->x;
			dot->z = ft_atoi(info->map[info->y][info->x]);
			dot->next = NULL;
			if (info->head == NULL)
				info->head = dot;
			info->x++;
		}
		info->y++;
	}
	return (0);
}

static void	check_line_len(char **line, int y, t_info *info)
{
	if (y == 0)
		info->width = ft_arrlen(line);
	if (ft_arrlen(line) != info->width)
		error_exit("incorrect map");
}

static void	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((!(ft_isdigit(line[i]))) && line[i] != '-' && line[i] != ' ')
			error_exit("incorrect map");
		i++;
	}
}

static int	count_height(int fd, char *line, t_info *info)
{
	if (fd < 0)
		error_exit("invalid parameter");
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		info->height++;
		ft_strdel(&line);
	}
	return (info->height);
}

int			read_map(t_info *info, char *argv)
{
	char	*line;
	int		fd;

	info->height = 0;
	fd = open(argv, O_RDONLY);
	info->height = count_height(fd, line, info);
	close(fd);
	if (!(info->map = (char ***)malloc(sizeof(char **) * (info->height + 1))))
		error_exit("info->map initialization error");
	fd = open(argv, O_RDONLY);
	info->y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		info->map[info->y] = ft_strsplit(line, ' ');
		check_line_len(info->map[info->y], info->y, info);
		info->y++;
		ft_strdel(&line);
	}
	info->map[info->y] = NULL;
	close(fd);
	return (0);
}
