/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:46:00 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 17:16:11 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso_projection(t_dot *dot, int *x, int *y, t_info *info)
{
	if (info->bigger < 500)
	{
		*x = (dot->x - dot->y) * cos(info->camera->gamma) * info->size + info->x_off;
		*y = (-(dot->z) + (dot->x + dot->y))\
		* sin(info->camera->gamma) * info->size + info->y_off;
	}
	else
	{
		*x = ((dot->x - dot->y) * cos(info->camera->gamma)) / info->size + info->x_off;
		*y = ((-(dot->z) + (dot->x + dot->y))\
		* sin(info->camera->gamma)) / info->size + info->y_off;
	}
	
}

t_xy	*make_xy(t_dot *dot, int mode, t_info *info)
{
	int		x;
	t_dot	*temp;

	if (!(dot->xy = (t_xy *)malloc(sizeof(t_xy))))
		return (NULL);
	iso_projection(dot, &dot->xy->x1, &dot->xy->y1, info);
	if (mode == 0)
		iso_projection(dot->next, &dot->xy->x2, &dot->xy->y2, info);
	else
	{
		x = dot->x;
		temp = dot->next;
		while (temp->x != x)
			temp = temp->next;
		iso_projection(temp, &dot->xy->x2, &dot->xy->y2, info);
	}
	dot->xy->dx = dot->xy->x2 - dot->xy->x1;
	dot->xy->dy = dot->xy->y2 - dot->xy->y1;
	return (dot->xy);
}

int		draw_map(t_info *info)
{
	t_dot	*dot;
	int		i;

	i = 0;
	dot = info->head;
	while (dot->next)
	{
		if (dot->x < info->x - 1)
		{
			draw_line(make_xy(dot, 0, info), info, dot->color);
			free(dot->xy);
			dot->xy = NULL;
		}
		if (dot->y < info->y - 1)
		{
			draw_line(make_xy(dot, 1, info), info, dot->color);
			free(dot->xy);
			dot->xy = NULL;
		}
		dot = dot->next;
	}
	return (0);
}
