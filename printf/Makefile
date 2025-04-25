NAME = libftprintf.a

SRCS		= ft_printf.c ft_printf
*ft_strchr
ft_putchar
ft_putstr
ft_putnbr
ft_putnbr_u
ft_puthex
ft_print_pointer
ft_atoi

OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re