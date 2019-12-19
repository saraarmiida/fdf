/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:00 by spentti           #+#    #+#             */
/*   Updated: 2019/12/19 16:39:39 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		line_len(t_dot *list, int lines)
{
	int len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len / lines);
}

void	get_xy(t_dot *dot, int *x, int *y, t_info *info)
{
	if (info->bigger < 500)
	{
		*x = (dot->x - dot->y) * cos(0.523599) * info->size + 300;
		*y = (-(dot->z) + (dot->x + dot->y))\
		* sin(0.523599) * info->size + 300;
	}
	else
	{
		*x = ((dot->x - dot->y) * cos(0.523599)) / info->size + 300;
		*y = ((-(dot->z) + (dot->x + dot->y))\
		* sin(0.523599)) / info->size + 300;
	}
	
}

t_xy	*make_xy(t_dot *dot, int mode, t_info *info)
{
	t_xy	*xy;
	int		x;

	if (!(xy = (t_xy *)malloc(sizeof(t_xy))))
		return (NULL);
	get_xy(dot, &xy->x1, &xy->y1, info);
	if (mode == 0)
	{
		get_xy(dot->next, &xy->x2, &xy->y2, info);
	}
	else
	{
		x = dot->x;
		dot = dot->next;
		while (dot->x != x)
			dot = dot->next;
		get_xy(dot, &xy->x2, &xy->y2, info);
	}
	xy->dx = xy->x2 - xy->x1;
	xy->dy = xy->y2 - xy->y1;
	return (xy);
}

int		draw_map(t_info *info)
{
	t_dot	*dot;
	int		i;

	i = 0;
	dot = info->head;
	info->width = line_len(dot, info->height);
	dot = info->head;
	while (dot->next)
	{
		if (dot->x < info->width - 1)
		{
			draw_line(make_xy(dot, 0, info), info, dot->color);
		}
		if (dot->y < info->height - 1)
		{
			draw_line(make_xy(dot, 1, info), info, dot->color);
		}
		dot = dot->next;
	}
	return (0);
}
