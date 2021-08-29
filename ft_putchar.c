/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:21:45 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:44:33 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_print *input)
{
	if (c < 0)
	{
		c = -c;
		input->write_len += write(1, "-", 1);
		input->write_len += write(1, &c, 1);
	}
	input->write_len += write(1, &c, 1);
}

void	ft_putchar_abcd(int n, t_print *input)
{
	char	*abcd;
	char	*ABCD;

	abcd = "0123456789abcdef";
	ABCD = "0123456789ABCDEF";
	if (input->gross)
		input->write_len += write(1, &ABCD[n], 1);
	else
		input->write_len += write(1, &abcd[n], 1);
}

void	ft_putzero(t_print *input)
{
	if (!input->accuracy && !input->width_copy && input->dot)
		write(1, "", 0);
	else
		input->write_len += write(1, " ", 1);
}
