/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:18:12 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 17:21:46 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	arr_del(char **row)
{
	int i;

	i = 0;
	while (row[i])
	{
		ft_strdel(&row[i]);
		i++;
	}
	free(row);
	row = NULL;
}

void	clear_map(char ***map)
{
	int i;

	i = 0;
	while (map[i])
	{
		arr_del(map[i]);
		i++;
	}
	free(map);
	map[i] = NULL;
}

void	clear_info(t_info *info)
{
	t_dot	*temp;

	while (info->head)
	{
		temp = info->head->next;
		free(info->head);
		info->head = temp;
	}
	info->head = NULL;
	free(info);
	info = NULL;
}
