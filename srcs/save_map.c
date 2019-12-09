/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2019/12/09 15:16:42 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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



t_dot	*save_map(t_info *info)
{
	t_dot	*dot;
	int		fake_x;
	int		x;
	int		y;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		fake_x = 0;
		while (info->map[y][fake_x])
		{
			if ((info->map[y][fake_x] >= '0' && info->map[y][fake_x] <= '9') || info->map[y][fake_x] == '-')
			{
				if (info->head == NULL)
				{
					if (!(info->head = (t_dot *)malloc(sizeof(t_dot))))
						return (NULL);
					info->head->z = ft_atoi(&info->map[y][fake_x]);
					info->head->y = y;
					info->head->x = x;
					info->head->color = mlx_get_color_value(info->param[0], 0xFFFFFF);
					dot = info->head;
					dot->next = NULL;

				}
				else
				{
					if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
						return (NULL);
					dot = dot->next;
					dot->y = y;
					dot->x = x;
					dot->color = mlx_get_color_value(info->param[0], 0xFFFFFF);
					dot->z = ft_atoi(&info->map[y][fake_x]);
					dot->next = NULL;
				}
				// if (make_list(info->head, dot, &x, &y, &info->map[y][fake_x]))
				// 	return (NULL);
				x++;
				while ((info->map[y][fake_x] >= '0' && info->map[y][fake_x] <= '9') || info->map[y][fake_x] == '-')
					fake_x++;
				if (info->map[y][fake_x] == ',' && info->map[y][fake_x + 1] == '0' && info->map[y][fake_x + 2] == 'x')
				{
					dot->color = ft_atoi_base(&info->map[y][fake_x + 3], 16);
					while (info->map[y][fake_x] != ' ')
						fake_x++;
				}
			}
			else
				fake_x++;
		}
		y++;
	}
	return (info->head);
}
