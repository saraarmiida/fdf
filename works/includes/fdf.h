/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 17:22:30 by spentti          ###   ########.fr       */
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
# define LOWER	27
# define HIGHER	24


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
	float			size;
	char			***map;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	float			bigger;
	int				gammamode;
	int				key_z;
	t_camera		*camera;
	t_dot			*dot;
	t_dot 			*head;
}					t_info;


int					draw_line(t_xy *xy, t_info *info, int color);
void				rotate(t_dot *head, t_camera *camera);
int					draw_map(t_info *info);
t_dot				*save_map(t_info *info);
int					key_hook(int keycode, t_info *info);
int					line_len(t_dot *list, int lines);
int					read_map(t_info *info, char *argv);
void				arr_del(char **row);
void				ft_putarr(char **arr);
void				get_size(t_info *info);
void				clear_map(char ***map);
void				clear_info(t_info *info);
	
#endif