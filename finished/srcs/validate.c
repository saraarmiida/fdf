/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:59:13 by spentti           #+#    #+#             */
/*   Updated: 2020/01/07 17:09:08 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_ishexdigit(char c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	check_dot(char *point)
{
	int	i;

	i = 0;
	if (point[i] == '-')
		i++;
	while (point[i] != ',' && point[i] != '\0')
	{
		if (!(ft_isdigit(point[i])))
			error_exit("incorrect map");
		i++;
	}
	if (point[i] == ',')
	{
		if (point[i + 1] != '0' || point[i + 2] != 'x')
			error_exit("incorrect map");
		i += 3;
		while (point[i] != '\0')
		{
			if (!(ft_ishexdigit(point[i])))
				error_exit("incorrect map");
			i++;
		}
	}
}

void	check_line(char **line, int y, t_info *info)
{
	if (y == 0)
		info->width = ft_arrlen(line);
	if (ft_arrlen(line) != info->width)
		error_exit("incorrect map");
}
