/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:28:08 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:42:03 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

int	ft_isflag(char c)
{
	if (c == 45 || c == 48)
		return (1);
	else
		return (0);
}
