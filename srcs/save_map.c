/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2019/12/19 16:39:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		save_xy(t_dot *dot, t_info *info)
{
	dot = dot->next;
	// dot->y = info->y;
	// dot->x = info->x;
	// dot->color = mlx_get_color_value(info->param[0], 0xFFFFFF);
	// dot->z = ft_atoi(&info->map[info->y][info->fake_x]);
	// dot->next = NULL;
}

void	get_size(t_info *info)
{
	info->bigger = info->x;
	if (info->height > info->x)
		info->bigger = info->height;
	if (info->bigger < 500)
	{
		printf("info->bigger: %f\n", info->bigger);
		info->size = 500 / info->bigger;
	}
	else
		info->size = info->bigger / 500;
	printf("height: %d\nx: %d\nsize: %f\ninfo->bigger / 600: %f\n", info->height, info->x, info->size, info->bigger / 600);
}

t_dot	*save_map(t_info *info)
{
	t_dot	*dot;

	info->y = 0;
	while (info->map[info->y])
	{
		info->x = 0;
		info->fake_x = 0;
		while (info->map[info->y][info->fake_x])
		{
			if ((info->map[info->y][info->fake_x] >= '0' && info->map[info->y][info->fake_x] <= '9') || info->map[info->y][info->fake_x] == '-')
			{
				if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
					return (NULL);
				// save_xy(dot, info);
				dot = dot->next;
				dot->y = info->y;
				dot->x = info->x;
				dot->color = mlx_get_color_value(info->param[0], 0xFFFFFF);
				dot->z = ft_atoi(&info->map[info->y][info->fake_x]);
				dot->next = NULL;
				if (info->head == NULL)
					info->head = dot;
				info->x++;
				while ((info->map[info->y][info->fake_x] >= '0' && info->map[info->y][info->fake_x] <= '9') || info->map[info->y][info->fake_x] == '-')
					info->fake_x++;
			}
			else
				info->fake_x++;
		}
		info->y++;
	}
	get_size(info);
	// while (info->map[info->y] != NULL)
	// 	ft_strdel(&info->map[info->y++]);
	// free(info->map);
	// info->map = NULL;
	return (info->head);
}
