/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:06:07 by spentti           #+#    #+#             */
/*   Updated: 2019/11/27 18:06:26 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_coord(char **map, void **param)
{
	int x;
	int y;
	int y1;
	int y2;
	int x1;
	int x2;
	int xo;
	int xt;

	y = 0;
	x = 0;
	xo = 400;
	// while (map[y] != '\0')
	// {
	// 	x = 0;
	// 	while (map[y][x] != '\0')
	// 	{
	// 		while (map[y][x] == ' ')
	// 			x++;
	// 		y1 = (y - ft_atoi(&map[y][x])) * 50 + 500;
	// 		mlx_pixel_put(param[0], param[1], x * 50 + xo, y1, 0xFFFFFF);
	// 		x++;
	// 	}
	// 	xo = xo - 100;
	// 	y++;
	// }
	y = 0;
	xo = 400;
	while (map[y] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x + 1] != '\0')
			{
				while (map[y][x] == ' ')
					x++;
				y1 = (y - ft_atoi(&map[y][x])) * 50 + 100;
				xt = x + 1;
				while (map[y][xt] == ' ')
					xt++;
				y2 = (y - ft_atoi(&map[y][xt])) * 50 + 100;
				x1 = x * 50 + xo;
				x2 = xt * 50 + xo;
				draw_line(x1, y1, x2, y2, param);
			}
			if (map[y + 1] != '\0')
			{
				x1 = x * 50 + xo;
				y1 = (y - ft_atoi(&map[y][x])) * 50 + 100;
				y2 = ((y + 1) - ft_atoi(&map[y + 1][x])) * 50 + 100;
				x2 = x * 50 + xo - 100;
				draw_line(x1, y1, x2, y2, param);
			}
			x++;
			while (map[y][x] == ' ')
				x++;
		}
		xo = xo - 100;
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_nb;
	//t_list	*dot;
	char	**map;
	size_t	line_len;
	int		y;
	int		x;
	void *param[2];

	if (argc != 2)
	{
		ft_putendl("Parameters not valid.");
		return (1);
	}
	line_nb = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_nb++;
		line_len = ft_strlen(line);
	}
	close (fd);
	if (!(map = (char **)malloc(sizeof(char *) * (line_nb + 1))))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map[y] = ft_strdup(line);
		printf("line: %s\n", line);
		printf("map[%d]: %s\n", y, map[y]);
		y++;
		ft_strdel(&line);
	}
	map[y] = NULL;
	close (fd);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
	get_coord(map, param);
	mlx_loop(param[0]);
	return (0);
}