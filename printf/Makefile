NAME = libft.a

SRCS		= ft_printf.c

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