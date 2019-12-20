/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:46:52 by spentti           #+#    #+#             */
/*   Updated: 2019/12/20 15:42:34 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		help(int c, int base)
{
	char	*str;
	int		i;

	str = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i])
			return (i);
	}
	return (-1);
}

int		ft_atoi_base(const char *str, int base)
{
	int					sign;
	int					res;
	int					i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (base == 10 && str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (help(str[i], base) != -1)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	ft_putnbr(res);
	ft_putendl("");
	return ((int)res * sign);
}
