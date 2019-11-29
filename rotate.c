/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:58:22 by spentti           #+#    #+#             */
/*   Updated: 2019/11/29 13:27:39 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_dot *list)
{
	int x;
	int y;

	while (list)
	{
		x = list->x * cos(0.5) - list->y * sin(0.5);
		y = list->y * cos(0.5) - list->x * sin(0.5);
		list->x = x;
		list->y = y;
		list = list->next;
	}
}

// void	rotate_x(t_dot *list)

// void	rotate_y(t_dot *list)