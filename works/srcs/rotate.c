/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:58:22 by spentti           #+#    #+#             */
/*   Updated: 2019/12/19 17:53:32 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_dot *list, double alpha)
{
	int	y;

	y = list->y;
	list->y = y * cos(alpha) + list->z * sin(alpha);
	list->z = -y * sin(alpha) + list->z * cos(alpha);
}

void	rotate_y(t_dot *list, double beta)
{
	int	x;

	x = list->x;
	list->x = x * cos(beta) + list->z * sin(beta);
	list->z = -x * sin(beta) + list->z * cos(beta);
}

void	rotate_z(t_dot *list, double gamma)
{
	int	x;

	x = list->x;
	list->x = x * cos(gamma) - list->y * sin(gamma);
	list->y = list->y * cos(gamma) - x * sin(gamma);
}

void	rotate(t_dot *head, t_camera *camera)
{
	t_dot *list;

	list = head;
	while (list)
	{
		rotate_x(list, camera->alpha);
		rotate_y(list, camera->beta);
		rotate_z(list, camera->gamma);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
}