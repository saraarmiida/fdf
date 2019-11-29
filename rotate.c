/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:58:22 by spentti           #+#    #+#             */
/*   Updated: 2019/11/29 14:44:52 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_dot *list)
{
	int x;
	int y;
	int i;
	
	i = 0;
	// while (list)
	// {
	// 	printf("i: %d\n", i);
	// 	list = list->next;
	// 	i++;
	// }
	while (list)
	{
		ft_putendl("WTF");
		list->x = list->x * cos(0.5) - list->y * sin(0.5);
		list->y = list->y * cos(0.5) - list->x * sin(0.5);
		// list->x = x;
		// list->y = y;
		if (list->next == NULL)
			return ;
		list = list->next;
	}
}

// void	rotate_x(t_dot *list)

// void	rotate_y(t_dot *list)