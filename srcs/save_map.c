/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:59 by spentti           #+#    #+#             */
/*   Updated: 2019/12/04 17:47:50 by spentti          ###   ########.fr       */
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
			if ((map[y][fake_x] >= '0' && map[y][fake_x] <= '9') || map[y][fake_x] == '-')
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
				}
				// if (make_list(head, dot, &x, &y, &map[y][fake_x]))
				// 	return (NULL);
				x++;
				while ((map[y][fake_x] >= '0' && map[y][fake_x] <= '9') || map[y][fake_x] == '-')
					fake_x++;
			}
			else
				fake_x++;
		}
		y++;
	}
	return (head);
}
