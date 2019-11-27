/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2019/11/27 13:39:33 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

// typedef struct 		s_list
// {
// 	int				x;
// 	int				y;
// 	int				z;
// 	int				color;
// 	struct s_list	*next;
// }					t_list;

int	draw_line(int x1, int y1, int x2, int y2, void **param);
	
#endif