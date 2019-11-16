/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:20:01 by spentti           #+#    #+#             */
/*   Updated: 2019/11/16 14:01:02 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/includes/libft.h"
#include <unistd.h>
/*
int deal_key(int key, void *param)
{
	ft_putchar('X');
	mlx_pixel_put(&param[0], &param[1], 200, 250, 0xFFFFFF);
	return (0);
}
*/
int	main()
{
	void *param[2];
	int x;

	x = 9;
	param[0] = mlx_init();
	param[1] = mlx_new_window(param[0], 500, 500, "mlx_42");
	mlx_pixel_put(param[0], param[1], 250, 250, 0xFFFFFF);
	//mlx_key_hook(param[1], deal_key, param);
	mlx_loop(param[0]);
	return (0);
}
