/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:18:26 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:41:31 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_percent(t_print *input)
{
	if (input->width < 0 && input->star)
	{
		input->width *= -1;
		input->adjustment = 1;
	}
	if (input->adjustment && input->zero)
		input->zero = 0;
}

void	ft_get_percent(t_print *input)
{
	ft_process_percent(input);
	if (input->adjustment && input->zero)
	{
		input->write_len += write(1, "%", 1);
		while (input->width-- > 1)
			input->write_len += write(1, "0", 1);
	}
	else if (input->adjustment && !input->zero)
	{
		input->write_len += write(1, "%", 1);
		while (input->width-- > 1)
			input->write_len += write(1, " ", 1);
	}
	else if (!input->adjustment && input->zero)
	{
		while (input->width-- > 1)
			input->write_len += write(1, "0", 1);
		input->write_len += write(1, "%", 1);
	}
	else
	{
		while (input->width-- > 1)
			input->write_len += write(1, " ", 1);
		input->write_len += write(1, "%", 1);
	}
}
