# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 19:50:53 by lsantand          #+#    #+#              #
#    Updated: 2025/09/04 20:38:25 by lsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
IFLAGS      = -Iinclude -ILibft -Iminilibx
SANITIZE    = -fsanitize=address

MLXFLAGS    = -Lminilibx -lmlx -lXext -lX11 -lm -lz

SRCS        = so_long.c \
              check_solvability.c \
              check.c \
              imgs.c \
              maps_functions.c \
              move.c \
              render.c \
              utils.c

SRC_DIR     = src
OBJ_DIR     = build
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DIR_LIBX    = minilibx
LIBX        = $(DIR_LIBX)/libmlx.a

DIR_LIBFT   = Libft
LIBFT       = $(DIR_LIBFT)/libft.a

HEADER      = include/so_long.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBX)
    $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBX):
    $(MAKE) -C $(DIR_LIBX)

$(LIBFT):
    $(MAKE) -C $(DIR_LIBFT)

clean:
    $(RM) -r $(OBJ_DIR)
    $(MAKE) -C $(DIR_LIBX) clean
    $(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
    $(RM) $(NAME)

re: fclean all

# Ativar sanitizer: make SANITIZE=1
ifeq ($(SANITIZE),1)
CFLAGS += -fsanitize=address
endif

.PHONY: all clean fclean re
