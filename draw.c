/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:57:28 by spentti           #+#    #+#             */
/*   Updated: 2019/11/28 20:00:23 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int line_len(t_dot *list, int lines)
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

int	draw_map(t_dot *dot, int lines, void **param)
{
	int len;

	len = line_len(dot, lines);
	ft_putstr("len: ");
	ft_putnbr(len);
	ft_putendl(" ");
	ft_putstr("lines: ");
	ft_putnbr(lines);
	ft_putendl(" ");
	printf("line_len: %dlines: %d", len, lines);
	while (dot->next)
	{
		if ((dot->next)->x < len)
		{
			draw_line(dot->x * 50 + 100, dot->y * 50 + 100, (dot->next)->x * 50 + 100, dot->y * 50 + 100, param);
		}
		if (dot->y < lines - 1)
		{
			draw_line(dot->x * 50 + 100, dot->y * 50 + 100, dot->x * 50 + 100, (dot->y + 1) * 50 + 100, param);
		}
		dot = dot->next;
	}
	return (0);
}