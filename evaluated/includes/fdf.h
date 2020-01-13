/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:19:27 by spentti           #+#    #+#             */
/*   Updated: 2020/01/08 16:46:08 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

# define HEIGHT		1080
# define WIDTH		1620

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

# define WHITE		0xffffff
# define OLIVE		0x2f3d2f
# define BLACK		0x000000
# define MINT		0x28d6c0
# define DARK_BLUE	0x020036
# define PINK		0xe80073
# define PURPLE		0xc200db
# define LIGHT_BLUE	0x00cfe5
# define YELLOW		0xffd300
# define GREY		0x252526

typedef struct		s_xy
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

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	t_xy			*xy;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_camera
{
	double			alpha;
	double			beta;
	double			gamma;
}					t_camera;

typedef struct		s_info
{
	int				projection;
	int				color;
	int				b_color;
	int				menu_color;
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
	t_dot			*head;
}					t_info;

int					draw_line(t_xy *xy, t_info *info);
int					draw_map(t_info *info);
void				clear_map(char ***map);
int					ft_arrlen(char **s);
void				clear_info(t_info *info);
int					get_size(t_info *info);
int					key_hook(int keycode, t_info *info);
void				key_rotate(int key, t_info *info);
void				key_move(int key, t_info *info);
void				key_zoom(int key, t_info *info);
void				print_info(void *mlx_ptr, void *win_ptr, int color);
void				error_exit(char *s);
void				rotate_z(int *x, int *y, double gamma);
void				rotate_y(int *x, int *z, double beta);
void				rotate_x(int *y, int *z, double alpha);
int					save_map(t_info *info);
int					read_map(t_info *info, char *argv);

#endif
