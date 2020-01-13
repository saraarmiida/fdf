/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:41:58 by spentti           #+#    #+#             */
/*   Updated: 2020/01/09 12:42:11 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	print_info(void *mlx_ptr, void *win_ptr, int color)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, 15, color, "How to use:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 35, color, "Zoom:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 55, color, "Move:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 75, color, "Projection:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 95, color, "Color:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 115, color, "Background:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 135, color, "Rotate:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 155, color, "x-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 175, color, "y-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 35, 195, color, "z-axis:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 215, color, "Height:");
	mlx_string_put(mlx_ptr, win_ptr, 15, 235, color, "Exit:");
	mlx_string_put(mlx_ptr, win_ptr, 150, 35, color, "+/-");
	mlx_string_put(mlx_ptr, win_ptr, 150, 55, color, "arrow keys");
	mlx_string_put(mlx_ptr, win_ptr, 150, 75, color, "1");
	mlx_string_put(mlx_ptr, win_ptr, 150, 95, color, "2");
	mlx_string_put(mlx_ptr, win_ptr, 150, 115, color, "3");
	mlx_string_put(mlx_ptr, win_ptr, 150, 155, color, "N/I");
	mlx_string_put(mlx_ptr, win_ptr, 150, 175, color, "M/U");
	mlx_string_put(mlx_ptr, win_ptr, 150, 195, color, "H/K");
	mlx_string_put(mlx_ptr, win_ptr, 150, 215, color, "(/)");
	mlx_string_put(mlx_ptr, win_ptr, 150, 235, color, "esc");
}

void	error_exit(char *s)
{
	if ((ft_strcmp(s, "usage: ./fdf map_file")))
		ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(s, 2);
	exit(1);
}
