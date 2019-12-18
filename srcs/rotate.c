/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:58:22 by spentti           #+#    #+#             */
/*   Updated: 2019/12/18 19:53:21 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_dot *list, double alpha)
{
	while (list)
	{
		int	y;

		y = list->y;
		list->y = y * cos(alpha) + list->z * sin(alpha);
		list->z = -y * sin(alpha) + list->z * cos(alpha);
		list = list->next;
	}
}

void	rotate_y(t_dot *list, double beta)
{
	while (list)
	{
		int	x;

		x = list->x;
		list->x = x * cos(beta) + list->z * sin(beta);
		list->z = -x * sin(beta) + list->z * cos(beta);
		list = list->next;
	}
}

void	rotate_z(t_dot *list, double gamma)
{
	while (list)
	{
		list->x = list->x * cos(gamma) - list->y * sin(gamma);
		list->y = list->y * cos(gamma) - list->x * sin(gamma);
		if (list->next == NULL)
			return ;
		list = list->next;
	}
}