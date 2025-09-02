# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 19:50:53 by lsantand          #+#    #+#              #
#    Updated: 2025/09/02 17:21:39 by lsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
CC				= cc
FLAGS			= -Wextra -Werror -Wall -I -g
FLAGSSE 		= -fsanitize=address

MLXFLAGS		= -Imlx_linux -lXext -lX11 -lm -lz

SRCS 			= so_long.c \
				check_solvability.c \
				check.c \
				imgs.c \
				maps_functions.c \
				move.c \
				render.c \
				utils.c \

DIR_LIBX 		= minilibx/
LIBX			= $(addprefix $(DIR_LIBX), libmlx.a)

DIR_LIBFT 		= Libft/
LIBFT			= $(addprefix $(DIR_LIBFT), libft.a)

OBJS			= ${SRCS:%.c=./build/%.o}

HEADER 			= include/so_long.h 

all: 			${NAME}

${NAME}:		${OBJS} ${LIBFT} ${LIBX}
						${CC} $^ ${FLAGS} ${MLXFLAGS} -o ${NAME}

./build/%.o: 	./src/%.c ${HEADER}
								@mkdir -p build
								${CC} ${FLAGS} -Imlx_linux -c $< -o $@

${LIBX}: 			FORCE
						${MAKE} -s -C ${DIR_LIBX}


${LIBFT}: 			FORCE
						${MAKE} -s -C ${DIR_LIBFT}

bonus:				${NAME_B}

${NAME_B}:			${OBJS_BONUS} ${LIBFT} ${LIBX}
					${CC} $^ ${FLAGS} ${MLXFLAGS} -o ${NAME_B}

clean:
					${RM} -r ./build

fclean:			clean
					${RM} ${NAME}
					${MAKE} -s -C ${DIR_LIBX} clean
					${MAKE} -s -C ${DIR_LIBFT} clean

re:				fclean
					${MAKE} all

FORCE:

.PHONY: all clean fclean re FORCE
