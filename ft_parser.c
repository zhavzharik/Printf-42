/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:17:03 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:42:29 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_flags(const char *quote, t_print *input, int indx)
{
	while (ft_isflag(quote[indx]) == 1)
	{
		if (quote[indx] == '-')
		{
			input->adjustment = 1;
			indx++;
		}
		if (quote[indx] == '0')
		{
			input->zero = 1;
			indx++;
		}
	}
	return (indx);
}

int	ft_check_nb(const char *quote, t_print *input, int indx)
{
	int		digit;
	int		len;

	len = indx;
	if (input->dot == 0)
	{
		digit = ft_atoi(&quote[indx]);
		input->width = digit;
		input->width_copy = digit;
		if (quote[indx] == '0' && digit > 0)
			len += (ft_nb_len(digit) + 1);
		else
			len += ft_nb_len(digit);
	}
	return (len);
}

int	ft_parser_digit(const char *quote, t_print *input, int indx)
{
	int		digit;
	int		len;

	len = indx;
	if (ft_isdigit(quote[indx]) == 1)
	{
		if (input->dot == 0)
			len = ft_check_nb(quote, input, indx);
		else if (input->dot == 1)
		{
			digit = ft_atoi(&quote[indx]);
			input->accuracy = digit;
			if (input->accuracy == 0)
				input->check = 1;
			if (quote[indx] == '0' && digit > 0)
				len += (ft_nb_len(digit) + 1);
			else
				len += ft_nb_len(digit);
		}
	}
	return (len);
}

int	ft_parser_star(const char *quote, t_print *input, int indx)
{
	if (quote[indx] == '*' && quote[indx - 1] != '.')
	{
		input->width = va_arg(input->args, int);
		input->width_copy = input->width;
		input->star += 1;
		indx++;
	}
	indx = ft_parser_digit(quote, input, indx);
	if (quote[indx] == '.')
	{
		input->dot = 1;
		indx++;
	}
	if (quote[indx] == '*' && quote[indx - 1] == '.')
	{
		input->accuracy = va_arg(input->args, int);
		input->star += 1;
		if (input->accuracy == 0)
			input->check = 1;
		indx++;
	}
	indx = ft_parser_digit(quote, input, indx);
	return (indx);
}

int	ft_parser_type(const char *quote, t_print *input, int indx)
{
	if (quote[indx] == 'c')
		ft_get_char(input);
	else if (quote[indx] == 's')
		ft_get_str(input);
	else if (quote[indx] == 'p')
		ft_get_pntr(input);
	else if (quote[indx] == 'd' || quote[indx] == 'i')
		ft_get_number(input);
	else if (quote[indx] == 'u')
		ft_get_uns_number(input);
	else if (quote[indx] == 'x')
		ft_get_abcd_number(input);
	else if (quote[indx] == 'X')
	{
		input->gross = 1;
		ft_get_abcd_number(input);
	}
	else if (quote[indx] == '%')
		ft_get_percent(input);
	else
		indx--;
	indx++;
	return (indx);
}
