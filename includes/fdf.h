/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2019/12/18 19:52:01 by spentti          ###   ########.fr       */
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
# define UP		126
# define DOWN	125
# define RIGHT	124
# define LEFT	123
# define ZOOM	69
# define DEZOOM	78
# define ESC	53
# define HEIGHT	1080
# define WIDTH	1420
# define NUM_4	86
# define NUM_6	88
# define NUM_8	91
# define NUM_2	84
# define NUM_7	89
# define NUM_3	85


typedef struct 		s_xy
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				sign;
	int				xsign;
}					t_xy;

typedef struct 		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
	t_xy			*xy;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_camera
{
	double			alpha;
	double			beta;
	double			gamma;
}					t_camera;


typedef struct 		s_info
{
	int				height;
	int				width;
	int				x_off;
	int				y_off;
	int				size;
	char			**map;
	void 			*param[3];
	char			*data_addr;
	int				fake_x;
	int				x;
	int				y;
	int				bits_per_pixel;
	int				size_line;
	t_camera		*camera;
	t_dot			*dot;
	t_dot 			*head;
}					t_info;


int					draw_line(t_xy *xy, t_info *info, int color);
void				rotate_z(t_dot *list, double gamma);
void				rotate_x(t_dot *list, double alpha);
void				rotate_y(t_dot *list, double beta);
int					draw_map(t_info *info);
t_dot				*save_map(t_info *info);
int					key_hook(int keycode, t_info *info);
int					line_len(t_dot *list, int lines);
	
#endif