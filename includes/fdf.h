/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2019/12/04 16:32:21 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct 		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_dot	*next;
}					t_dot;

typedef struct 		s_info
{
	int				height;
	int				width;
	char			**map;
	void 			*param[2];
	t_dot 			*head;
}					t_info;

typedef struct 		s_xy
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
}					t_xy;


int					draw_line(t_xy *xy, void **param);
void				rotate_z(t_dot *list);
int					draw_map(t_info *info);
t_dot				*save_coords(char **map, t_dot *head);
	
#endif