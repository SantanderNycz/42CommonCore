NAME = push_swap.a

SRC = 	src/main.c src/parse_args.c src/index_utils.c 
		src/stack_utils.c src/free_stack.c src/radix_sort.c
		parsing/is_empty.c parsing/pa.c parsing/pb.c 
		parsing/ra.c parsing/sa.c 

OBS = $(SRC:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -free

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclena re