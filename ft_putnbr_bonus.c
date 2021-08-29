/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:12:07 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:44:41 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnbr(int n, t_print *input)
{
	long long	number;

	number = (long long) n;
	if (n < 0)
		number = -number;
	if (n < 0 && !input->check_minus)
		input->write_len += write(1, "-", 1);
	if (number >= 10)
		ft_putnbr(number / 10, input);
	ft_putchar((number % 10) + '0', input);
}

void	ft_putnbr_uns(unsigned int n, t_print *input)
{
	if (n >= 10)
		ft_putnbr(n / 10, input);
	ft_putchar((n % 10) + '0', input);
}

void	ft_putnbr_abcd(unsigned long n, t_print *input)
{
	if (n >= 16)
		ft_putnbr_abcd(n / 16, input);
	ft_putchar_abcd(n % 16, input);
}
