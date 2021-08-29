/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:18:17 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:40:17 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_minus(char temp)
{
	int	minus;

	if (temp == 45)
		minus = (-1);
	else
		minus = 1;
	return (minus);
}

static int	ft_convert(char temp, int result)
{
	if (temp >= 48 && temp <= 57)
		result = result * 10 + (temp - 48);
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	res = 0;
	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		minus = ft_minus(str[i]);
		i++;
	}
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = ft_convert(str[i], res);
			i++;
		}
	}
	return ((res * minus));
}
