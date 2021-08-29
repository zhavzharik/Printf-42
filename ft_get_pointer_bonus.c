/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:48:31 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:41:37 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_right_adjustment_pntr(t_print *input)
{
	if ((input->nb_len + 2) < input->accuracy)
		input->accuracy -= (input->nb_len + 2);
	else
		input->accuracy = 0;
	if ((input->width - input->accuracy - input->nb_len - 2) > 0)
		input->width -= (2 + input->accuracy + input->nb_len);
	else
		input->width = 0;
	if (input->width > 0 && !input->adjustment && input->dot)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
	if (input->accuracy > 0 && input->dot)
	{
		while (input->accuracy-- > 0)
			input->write_len += write(1, "0", 1);
	}
	if (input->width > 0 && !input->adjustment && !input->dot)
		ft_check_zero(input);
}

void	ft_get_null_rpntr(t_print *input)
{
	if (input->width > 0 && !input->adjustment)
	{
		if (!input->dot)
		{
			while (input->width-- > 3)
				input->write_len += write(1, " ", 1);
			input->write_len += write(1, "0x0", 3);
		}
		else
		{
			while (input->width-- > 2)
				input->write_len += write(1, " ", 1);
			input->write_len += write(1, "0x", 2);
		}
	}
	else if (input->width == 0 && !input->adjustment && !input->dot)
		input->write_len += write(1, "0x0", 3);
	else if (input->width == 0 && !input->adjustment && input->dot)
		input->write_len += write(1, "0x", 2);
}

void	ft_get_null_lpntr(t_print *input)
{
	if (input->width > 0 && input->adjustment && !input->dot)
	{
		input->write_len += write(1, "0x0", 3);
		while (input->width-- > 3)
			input->write_len += write(1, " ", 1);
	}
	if (input->width > 0 && input->adjustment && input->dot)
	{
		input->write_len += write(1, "0x", 2);
		while (input->width-- > 2)
			input->write_len += write(1, " ", 1);
	}
}

void	ft_get_pntr(t_print *input)
{
	input->pointer = va_arg(input->args, unsigned long);
	if (!input->pointer)
	{
		ft_process_input(input);
		ft_get_null_rpntr(input);
		ft_get_null_lpntr(input);
		return ;
	}
	input->nb_len = ft_abcd_nb_len(input->pointer);
	ft_process_input(input);
	ft_right_adjustment_pntr(input);
	input->write_len += write(1, "0x", 2);
	ft_putnbr_abcd(input->pointer, input);
	ft_left_adjustment_int(input);
}
