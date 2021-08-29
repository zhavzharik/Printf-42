/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:15:17 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:40:37 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_get_char(t_print *input)
{
	char	symb;

	symb = va_arg(input->args, int);
	ft_process_input(input);
	ft_right_adjustment_symb(input, 1);
	input->write_len += write(1, &symb, 1);
	ft_left_adjustment_str(input);
}

void	ft_get_str(t_print *input)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(input->args, char *);
	if (!str)
		str = "(null)";
	ft_process_input_str(input);
	len = ft_strlen(str);
	ft_right_adjustment_str(input, len);
	i = 0;
	while (str[i] && input->accuracy--)
		input->write_len += write(1, &str[i++], 1);
	ft_left_adjustment_str(input);
}

void	ft_get_number(t_print *input)
{
	input->type = 1;
	input->number = va_arg(input->args, int);
	if (!input->number)
		input->number = 0;
	input->nb_len = ft_nb_len(input->number);
	if (input->number < 0)
	{
		input->neg = 1;
		input->nb_len -= 1;
	}
	ft_process_input(input);
	ft_right_adjustment_int(input);
	if (input->number == 0 && input->dot && input->check)
		ft_putzero(input);
	else
		ft_putnbr(input->number, input);
	ft_left_adjustment_int(input);
}

void	ft_get_uns_number(t_print *input)
{
	input->type = 1;
	input->u_number = va_arg(input->args, unsigned int);
	if (!input->u_number)
		input->u_number = 0;
	input->nb_len = ft_uns_nb_len(input->u_number);
	ft_process_input(input);
	ft_right_adjustment_int(input);
	if (input->u_number == 0 && input->dot && input->check)
		ft_putzero(input);
	else
		ft_putnbr_uns(input->u_number, input);
	ft_left_adjustment_int(input);
}

void	ft_get_abcd_number(t_print *input)
{
	input->type = 1;
	input->u_number = va_arg(input->args, unsigned int);
	if (!input->u_number)
		input->u_number = 0;
	input->nb_len = ft_abcd_nb_len(input->u_number);
	ft_process_input(input);
	ft_right_adjustment_int(input);
	if (input->u_number == 0 && input->dot && input->check)
		ft_putzero(input);
	else
		ft_putnbr_abcd(input->u_number, input);
	ft_left_adjustment_int(input);
}
