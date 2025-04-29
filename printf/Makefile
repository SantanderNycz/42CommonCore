NAME = libftprintf.a

SRCS		= ft_printf.c ft_printf_utils.c \
			ft_puthex.c ft_print_pointer.c \
			ft_atoi.c ft_utoa.c ft_itoa.c ft_strchr.c\

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