NAME = libftprintf.a

LIST = 	ft_atoi.c			\
		ft_strlen.c			\
		ft_nb_len.c			\
		ft_putchar.c		\
		ft_putnbr.c			\
		ft_isdigit.c		\
		ft_parser.c			\
		ft_process_int.c	\
		ft_printf.c			\
		ft_process.c		\
		ft_get_arguments.c  \
		ft_get_pointer.c	\
		ft_get_percent.c

LIST_BONUS = 	ft_atoi_bonus.c				\
				ft_strlen_bonus.c			\
				ft_nb_len_bonus.c			\
				ft_putchar_bonus.c			\
				ft_putnbr_bonus.c			\
				ft_isdigit_bonus.c			\
				ft_parser_bonus.c			\
				ft_process_int_bonus.c		\
				ft_printf_bonus.c			\
				ft_process_bonus.c			\
				ft_get_arguments_bonus.c	\
				ft_get_pointer_bonus.c		\
				ft_get_percent_bonus.c

OBJ = $(LIST:.c=.o)

OBJ_BONUS = $(LIST_BONUS:.c=.o)

CC = gcc

REM = rm -f

LIBH = ft_printf.h

LIBBH = ft_printf_bonus.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(LIBH)
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

%.o : %.c $(LIBBH)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(REM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(REM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
