/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:51:07 by spentti           #+#    #+#             */
/*   Updated: 2019/11/16 18:01:48 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <fcntl.h>
#include "mlx.h"

int		window(char **line)
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mlx_42");
	while (line[2][x])
	{
		if (line[2][x] == '0')
			mlx_pixel_put(mlx_ptr, win_ptr, x * 10 + 100, y * 10 + 100, 0xFFFFFF);
		x++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}

int	read_file(fd)
{
	char **line;
	int i;

	i = 0;
	line = (char **)malloc(sizeof(char *) * 12);
	while (i < 11)
	{
		get_next_line(fd, &line[i]);
		ft_putendl(line[i]);
		i++;
	}
	line[i] = NULL;
	ft_putendl("HERE");
	window(line);
	
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		read_file(fd);
	}
	close(fd);
	return (0);
}
