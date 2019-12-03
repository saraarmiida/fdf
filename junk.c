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


// int main()
// {
// 	void *param[2];
// 	int x;
// 	int y;

// 	param[0] = mlx_init();
// 	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
// 	x = 200;
// 	y = 200;
// 	while (x < 400)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 10;
// 		y += 5;
// 	}
// 	while (x < 500)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 5;
// 		y -= 12;
// 	}
// 	while (x < 600)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 5;
// 		y += 12;
// 	}
// 	while (x < 800)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 10;
// 		y -= 5;
// 	}
// 	y = 200;
// 	x = 200;
// 	while (y < 400)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 10;
// 		x += 5;
// 	}
// 	while (y < 500)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 5;
// 		x -= 12;
// 	}
// 	while (y < 600)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 5;
// 		x += 12;
// 	}
// 	while (y < 800)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 10;
// 		x -= 5;
// 	}
// 	x = 200;
// 	y = 800;
// 	while (x < 400)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 10;
// 		y -= 5;
// 	}
// 	while (x < 500)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 5;
// 		y += 12;
// 	}
// 	while (x < 600)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 5;
// 		y -= 12;
// 	}
// 	while (x < 800)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		x += 10;
// 		y += 5;
// 	}
// 	y = 200;
// 	x = 800;
// 	while (y < 400)
// 	{
// 		draw_line(500, 500, x, y, param);
// 		y += 10;
// 		x -= 5;
// 	}
// 	while (y < 500)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 5;
// 		x += 12;
// 	}
// 	while (y < 600)
// 	{
// 		draw_line(x, y, 500, 500, param);
// 		y += 5;
// 		x -= 12;
// 	}
// 	while (y <= 800)
// 	{
// 		draw_line(500, 500, x, y, param);
// 		y += 10;
// 		x += 5;
// 	}
	
// 	mlx_loop(param[0]);
// 	return (0);
// }

// int main()
// {
// 	void *param[2];
// 	int x;
// 	int y;

// 	param[0] = mlx_init();
// 	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
// 	draw_line(200, 400, 500, 100, param);
// 	draw_line(500, 100, 800, 300, param);
// 	draw_line(500, 100, 700, 400, param);
// 	draw_line(300, 300, 800, 300, param);
// 	draw_line(200, 400, 700, 400, param);
// 	draw_line(700, 400, 800, 300, param);
// 	//draw_line(100, 400, 500, 400, param);
// 	//draw_line(500, 300, 500, 400, param);
// 	mlx_string_put(param[0], param[1], 500, 100, 0xFF0000, "hello");
// 	mlx_string_put(param[0], param[1], 200, 400, 0x810202, "*");
// 	mlx_string_put(param[0], param[1], 300, 300, 0x830707, "*");
// 	mlx_string_put(param[0], param[1], 700, 400, 0xFf, "*");
// 	mlx_string_put(param[0], param[1], 800, 300, 0x0000FF, "*");

// 	mlx_loop(param[0]);
// 	return (0);
// }

xy->x1 = ((dot->x - dot->y) * cos(0.523599)) * 50 + 100;
	xy->y1 = (-(dot->z) + (dot->x + dot->y) * sin(0.523599)) * 50 + 100;
	xy->x2 = ((dot->x - dot->y) * cos(0.523599) + mode_x) * 50 + 100;
	xy->y2 = ((-(dot->z) + (dot->x + dot->y) * sin(0.523599)) + mode_y) * 50 + 100;
	xy->dx = xy->x2 - xy->x1;
	xy->dy = xy->y2 - xy->y1;