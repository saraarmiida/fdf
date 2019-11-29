// int	get_coord(char **map, void **param)
// {
// 	int x;
// 	int y;
// 	int y1;
// 	int y2;
// 	int x1;
// 	int x2;
// 	int xo;
// 	int xt;

// 	// while (map[y] != '\0')
// 	// {
// 	// 	x = 0;
// 	// 	while (map[y][x] != '\0')
// 	// 	{
// 	// 		while (map[y][x] == ' ')
// 	// 			x++;
// 	// 		y1 = (y - ft_atoi(&map[y][x])) * 50 + 500;
// 	// 		mlx_pixel_put(param[0], param[1], x * 50 + xo, y1, 0xFFFFFF);
// 	// 		x++;
// 	// 	}
// 	// 	xo = xo - 100;
// 	// 	y++;
// 	// }
// 	y = 0;
// 	xo = 400;
// 	while (map[y] != '\0')
// 	{
// 		x = 0;
// 		while (map[y][x] != '\0')
// 		{
// 			if (map[y][x + 1] != '\0')
// 			{
// 				while (map[y][x] == ' ')
// 					x++;
// 				y1 = (y - ft_atoi(&map[y][x])) * 50 + 100;
// 				xt = x + 1;
// 				while (map[y][xt] == ' ')
// 					xt++;
// 				y2 = (y - ft_atoi(&map[y][xt])) * 50 + 100;
// 				x1 = x * 50 + xo;
// 				x2 = xt * 50 + xo;
// 				draw_line(x1, y1, x2, y2, param);
// 			}
// 			if (map[y + 1] != '\0')
// 			{
// 				x1 = x * 50 + xo;
// 				y1 = (y - ft_atoi(&map[y][x])) * 50 + 100;
// 				y2 = ((y + 1) - ft_atoi(&map[y + 1][x])) * 50 + 100;
// 				x2 = x * 50 + xo - 100;
// 				draw_line(x1, y1, x2, y2, param);
// 			}
// 			x++;
// 			while (map[y][x] == ' ')
// 				x++;
// 		}
// 		xo = xo - 100;
// 		y++;
// 	}
// 	return (0);
// }