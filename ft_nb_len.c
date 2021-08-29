/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:15:15 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:42:16 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nb_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb == INT_MIN)
		return (11);
	if (nb < 0)
	{
		len = 1;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	len +=1;
	return (len);
}

size_t	ft_uns_nb_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	len +=1;
	return (len);
}

size_t	ft_abcd_nb_len(unsigned long nb)
{
	size_t	len;

	len = 0;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	len +=1;
	return (len);
}
