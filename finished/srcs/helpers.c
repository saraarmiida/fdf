/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:57:42 by spentti           #+#    #+#             */
/*   Updated: 2020/01/07 17:01:44 by spentti          ###   ########.fr       */
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
	free(info->camera);
	info->camera = NULL;
	free(info);
	info = NULL;
}

int		ft_arrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		get_size(t_info *info)
{
	info->bigger = info->width;
	if (info->height > info->width)
		info->bigger = info->height;
	if (info->bigger < 500)
		info->size = 500 / info->bigger;
	else
		info->size = info->bigger / 500;
	return (0);
}
