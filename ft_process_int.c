/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:10:28 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:44:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_zero(t_print *input)
{
	if (input->zero)
	{
		if (input->neg && !input->check_minus)
		{
			input->write_len += write(1, "-", 1);
			input->check_minus = 1;
		}
		while (input->width-- > 0)
			input->write_len += write(1, "0", 1);
	}
	else
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
		if (input->neg && !input->check_minus)
		{
			input->write_len += write(1, "-", 1);
			input->check_minus = 1;
		}
	}
}

void	ft_check_neg_acc(t_print *input)
{
	if (input->accuracy < 0 && input->star && input->zero)
	{
		if (input->number < 0 && input->width_copy < 0)
		{
			input->accuracy = 1;
			input->width -= input->accuracy;
		}
		else if (input->number < 0 && input->width_copy > 0)
		{
			input->accuracy = input->width - 1;
			input->width = 0;
		}
		else if (input->number >= 0 && input->width_copy < 0)
		{
			input->accuracy = 0;
			input->width -= input->accuracy;
		}
		else
		{
			input->accuracy = input->width;
			input->width = 0;
		}
		input->adjustment = 1;
	}
}

void	ft_right_adjustment_int(t_print *input)
{
	if (input->nb_len < input->accuracy)
		input->accuracy -= input->nb_len;
	else
		input->accuracy = 0;
	if ((input->width - input->neg - input->accuracy - input->nb_len) > 0)
		input->width -= (input->neg + input->accuracy + input->nb_len);
	else
		input->width = 0;
	if (input->width > 0 && !input->adjustment && input->dot)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
	if (input->neg && input->accuracy)
	{
		input->write_len += write(1, "-", 1);
		input->check_minus = 1;
	}
	if (input->accuracy > 0 && input->dot)
	{
		while (input->accuracy-- > 0)
			input->write_len += write(1, "0", 1);
	}
	if (input->width > 0 && !input->adjustment && !input->dot)
		ft_check_zero(input);
}

void	ft_left_adjustment_int(t_print *input)
{
	if (input->width > 0 && input->adjustment)
	{
		while (input->width-- > 0)
			input->write_len += write(1, " ", 1);
	}
}
