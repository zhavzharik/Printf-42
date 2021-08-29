/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:10:55 by abridger          #+#    #+#             */
/*   Updated: 2021/07/25 16:43:40 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_print
{
	va_list				args;
	int					adjustment;
	int					zero;
	int					width;
	int					width_copy;
	int					neg;
	int					number;
	unsigned int		u_number;
	unsigned long		pointer;
	int					nb_len;
	int					star;
	int					dot;
	int					accuracy;
	int					check;
	int					type;
	int					gross;
	int					write_len;
	int					check_minus;

}						t_print;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_nb_len(int nb);
size_t	ft_uns_nb_len(unsigned int nb);
size_t	ft_abcd_nb_len(unsigned long nb);
void	ft_putchar(char c, t_print *input);
void	ft_putchar_abcd(int n, t_print *input);
void	ft_putzero(t_print *input);
void	ft_putnbr(int n, t_print *input);
void	ft_putnbr_uns(unsigned int n, t_print *input);
void	ft_putnbr_abcd(unsigned long n, t_print *input);
int		ft_isdigit(char c);
t_print	*ft_init(t_print *input);
t_print	*ft_reset(t_print *input);
int		ft_isflag(char c);
int		ft_parser_flags(const char *quote, t_print *input, int indx);
int		ft_parser_digit(const char *quote, t_print *input, int indx);
int		ft_parser_star(const char *quote, t_print *input, int indx);
int		ft_parser_type(const char *quote, t_print *input, int indx);
int		ft_parser_after_percent(const char *quote, t_print *input, int indx);
void	ft_process_input(t_print *input);
void	ft_process_percent(t_print *input);
void	ft_check_neg_acc(t_print *input);
void	ft_process_input_str(t_print *input);
void	ft_right_adjustment_str(t_print *input, int len);
void	ft_right_adjustment_symb(t_print *input, int len);
void	ft_left_adjustment_str(t_print *input);
void	ft_check_zero(t_print *input);
void	ft_right_adjustment_int(t_print *input);
void	ft_right_adjustment_pntr(t_print *input);
void	ft_left_adjustment_int(t_print *input);
void	ft_get_char(t_print *input);
void	ft_get_percent(t_print *input);
void	ft_get_str(t_print *input);
void	ft_get_null_rpntr(t_print *input);
void	ft_get_null_lpntr(t_print *input);
void	ft_get_pntr(t_print *input);
void	ft_get_number(t_print *input);
void	ft_get_uns_number(t_print *input);
void	ft_get_abcd_number(t_print *input);
int		ft_printf(const char *quote, ...);

#endif
