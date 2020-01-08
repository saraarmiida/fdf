/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2020/01/07 17:00:35 by spentti          ###   ########.fr       */
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
# include <errno.h>

# define HEIGHT		1080
# define WIDTH		1620
# define MENU_WIDTH	250

# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define ZOOM		24
# define DEZOOM		27
# define ESC		53
# define PROJ		18
# define COLOR		19
# define B_COLOR	20
# define LOWER		25
# define HIGHER		29
# define ROT_X1		45
# define ROT_X2		34
# define ROT_Y1		46
# define ROT_Y2		32
# define ROT_Z1		4
# define ROT_Z2		40

# define ORANGE		0xcff871f
# define WHITE		0xffffff
# define OLIVE		0x2f3d2f
# define BLACK		0x000000
# define DARKBLUE	0x050121
# define MINT		0x28d6c0
# define DARK_BLUE	0x020036
# define PINK		0xe80073
# define PINK2		0xff2079
# define PURPLE		0xc200db
# define MID_BLUE	0x440bd4
# define LIGHT_BLUE	0x00cfe5
# define YELLOW		0xffd300
# define GREY		0x252526
# define LIGHT_GREY	0xf5dcb5

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

typedef struct 		s_line
{
	t_dot			*start;
	t_dot			*end;
	int				dx;
	int				dy;
	int				sign;
	int				xsign;
}					t_line;


typedef struct		s_camera
{
	double			alpha;
	double			beta;
	double			gamma;
}					t_camera;


typedef struct 		s_info
{
	int				projection;
	int				color;
	int				b_color;
	int				menu_color;
	int				z_max;
	int				z_min;
	int				height;
	int				width;
	int				x_off;
	int				y_off;
	double			z_key;
	float			size;
	char			***map;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	float			bigger;
	t_camera		*camera;
	t_dot			*dot;
	t_dot 			*head;
}					t_info;


int					draw_line(t_line *line, t_info *info);
void				rotate_z(int *x, int *y, double gamma);
void				rotate_y(int *x, int *z, double beta);
void				rotate_x(int *y, int *z, double alpha);
int					draw_map(t_info *info);
int					save_map(t_info *info);
int					key_hook(int keycode, t_info *info);
int					line_len(t_dot *list, int lines);
int					read_map(t_info *info, char *argv);
void				arr_del(char **row);
int					get_size(t_info *info);
void				clear_map(char ***map);
void				clear_info(t_info *info);
void				draw_background(void *mlx_ptr, void *win_ptr, int color);
int					key_main(char *file, t_info *info);
void				key_rotate(int key, t_info *info);
void				key_move(int key, t_info *info);
void				key_zoom(int key, t_info *info);
void				print_info(void *mlx_ptr, void *win_ptr, int color);
void				error_exit(char *s);
void				check_line(char **line, int y, t_info *info);
void				check_dot(char *point);
	
#endif