/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:19:16 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:43:52 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_process_input(t_print *input)
{
	if (input->width < 0)
	{
		input->adjustment = 1;
		input->width *= -1;
	}
	ft_check_neg_acc(input);
	if (input->adjustment && input->zero)
		input->zero = 0;
	if (input->type && input->accuracy)
		input->zero = 0;
}

void	ft_process_input_str(t_print *input)
{
	if (input->width < 0)
	{
		input->width *= -1;
		input->adjustment = 1;
	}
	if (input->accuracy < 0)
	{
		input->accuracy = 0;
		input->dot = 0;
		input->check = 1;
	}
	if (input->adjustment && input->zero)
		input->zero = 0;
	if (input->type && input->accuracy > 0)
		input->zero = 0;
}

void	ft_right_adjustment_str(t_print *input, int len)
{
	if (len && (len < input->accuracy || !input->dot))
		input->accuracy = len;
	if (input->accuracy < input->width)
		input->width -= input->accuracy;
	else
		input->width = 0;
	if (input->width > 0 && !input->adjustment)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
}

void	ft_right_adjustment_symb(t_print *input, int len)
{
	if (len < input->width)
		input->width -= len;
	else
		input->width = 0;
	if (input->width > 0 && !input->adjustment)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
}

void	ft_left_adjustment_str(t_print *input)
{
	if (input->width > 0 && input->adjustment)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
}
