/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:05:28 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:43:17 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init(t_print *input)
{
	input->adjustment = 0;
	input->zero = 0;
	input->width = 0;
	input->width_copy = 0;
	input->neg = 0;
	input->number = 0;
	input->u_number = 0;
	input->pointer = 0;
	input->nb_len = 0;
	input->star = 0;
	input->dot = 0;
	input->accuracy = 0;
	input->check = 0;
	input->type = 0;
	input->gross = 0;
	input->write_len = 0;
	input->check_minus = 0;
	return (input);
}

t_print	*ft_reset(t_print *input)
{
	input->adjustment = 0;
	input->zero = 0;
	input->width = 0;
	input->width_copy = 0;
	input->neg = 0;
	input->number = 0;
	input->u_number = 0;
	input->pointer = 0;
	input->nb_len = 0;
	input->star = 0;
	input->dot = 0;
	input->accuracy = 0;
	input->check = 0;
	input->type = 0;
	input->gross = 0;
	input->check_minus = 0;
	return (input);
}

int	ft_parser_after_percent(const char *quote, t_print *input, int indx)
{
	indx = ft_parser_flags(quote, input, indx);
	indx = ft_parser_star(quote, input, indx);
	if (input->accuracy == 0 && input->number == 0)
		input->check = 1;
	indx = ft_parser_type(quote, input, indx);
	ft_reset(input);
	return (indx);
}

int	ft_printf(const char *quote, ...)
{
	t_print	*input;
	int		indx;
	int		len;

	input = (t_print *)malloc(sizeof(t_print));
	if (!input)
		return (-1);
	ft_init(input);
	va_start(input->args, quote);
	indx = -1;
	len = 0;
	while (quote[++indx] && indx < (int)ft_strlen(quote))
	{
		if (quote[indx] == '%')
		{
			len = ft_parser_after_percent(quote, input, indx + 1);
			indx = len - 1;
		}
		else
			input->write_len += write(1, &quote[indx], 1);
	}
	va_end(input->args);
	free(input);
	return (input->write_len);
}
