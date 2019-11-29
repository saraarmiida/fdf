/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2019/11/28 20:01:48 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/includes/libft.h"
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

int					draw_line(int x1, int y1, int x2, int y2, void **param);
void				rotate_z(t_dot *list);
int					draw_map(t_dot *dot, int lines, void **param);
	
#endif