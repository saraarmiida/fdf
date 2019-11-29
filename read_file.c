/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:06:07 by spentti           #+#    #+#             */
/*   Updated: 2019/11/29 13:27:57 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	*save_coords(int **map)
{
	t_dot *dot;
	t_dot *head;
	int x;
	int y;

	y = 0;
	head = NULL;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != -1)
		{
			if (head == NULL)
			{
				if (!(head = (t_dot *)malloc(sizeof(t_dot))))
					return (NULL);
				head->y = y;
				head->x = x;
				head->z = map[y][x];
				dot = head;
			}
			else
			{
				if (!(dot->next = (t_dot *)malloc(sizeof(t_dot))))
					return (NULL);
				dot = dot->next;
				dot->y = y;
				dot->x = x;
				dot->z = map[y][x];	
			}
			x++;
		}
		y++;
	}
	return (head);
}

int	**char_to_int(char **c_map, int line_nb)
{
	int **i_map;
	int y;
	int xc;
	int xi;

	if (!(i_map = (int **)malloc(sizeof(int *) * line_nb + 1)))
		return (NULL) ;
	y = 0;
	while (c_map[y] != '\0')
	{
		if (!(i_map[y] = (int *)malloc(sizeof(int) * ft_strlen(c_map[y]) + 1)))
			return (NULL);
		xi = 0;
		xc = 0;
		while (c_map[y][xc] != '\0')
		{
			while (c_map[y][xc] == ' ')
				xc++;
			i_map[y][xi] = ft_atoi(&c_map[y][xc]);
			xi++;
			xc++;
			while (c_map[y][xc] == ' ')
				xc++;
		}
		i_map[y][xi] = -1;
		y++;
	}
	i_map[y] = NULL;
	return (i_map);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_nb;
	int		line_len;
	char	**map;
	int		y;
	void *param[2];
	int **i_map;
	int x;
	t_dot *head;

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
		// printf("line: %s\n", line);
		// printf("map[%d]: %s\n", y, map[y]);
		y++;
		ft_strdel(&line);
	}
	
	map[y] = NULL;
	close (fd);
	i_map = char_to_int(map, line_nb);
	head = save_coords(i_map);
	// while (head)
	// {
	// 	printf("y: %d x: %d z: %d\n", head->y, head->x, head->z);
	// 	head = head->next;
	// }
	// y = 0;
	// while (i_map[y] != NULL)
	// {
		
	// 	x = 0;
	// 	while (i_map[y][x] != -1)
	// 	{
	// 		printf("%d ", i_map[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	rotate_z(head);
	// rotate_z(head);
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 1000, 1000, "mlx_42");
	draw_map(head, line_nb, param);
	mlx_loop(param[0]);
	return (0);
}