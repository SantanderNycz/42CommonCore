# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 19:50:53 by lsantand          #+#    #+#              #
#    Updated: 2025/08/04 20:13:35 by lsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_B 			= so_long_bonus
FLAGS			= -Wextra -Werror -Wall -I -g3
FLAGSSE 		= -fsanitize=adress

MLXFLAGS		= -Imlx_linux -lXext -lX11 -lm -lz

SRCS 			= so_long.c \
				check_solvability.c \
				check.c \
				imgs.c \
				maps_functions.c \
				move.c
				render.c \
				utils.c \

SRCS_BONUS		= so_long.c \
				animation.c \
				check_solvability.c \
				check.c \
				enemy_functions.c \
				imgs.c \
				maps_functions.c \
				move.c
				render.c \
				utils.c \

DIR_LIBX 		= minilibx/
LIBX			= $(addprefix $(DIR_LIBX), libmlx.a)

DIR_LIBX 		= Libft/
LIBFT			= $(addprefix $(DIR_LIBFT), libft.a)

OBJS			= ${SRCS:%.c=./build/%.o}
OBJS_BONUS		= ${SRCS_BONUS:%.c=./build_bonus/%.o}

HEADER 			= include/so_long.h 
BONUS_HEADER	= include_bonus/so_long.h 

all: 			${NAME}

${NAME}:		${OBJS} ${LIBFT} ${LIBX}
						${CC} $^ ${FLAGS} ${MLXFLAGS} -o ${NAME}

./build/%.o: 	./src/%.c ${HEADER}
								@mkdir -p build
								${CC} ${FLAGS} -Imlx_linux -c $< -o $@

./build_bonus/%.o: ./src_bonus/%.c ${BONUS_HEADER}
								@mkdir -p build_bonus
								${CC} ${FLAGS} -Imlx_linux -c $< -o $@

${MLX}: 			FORCE
						make -s -C ${DIR_LIBX}


${LIBFT}: 			FORCE
						make -s -C ${DIR_LIBFT}

bonus:				${NAME_B}

${NAME_B}:			${OBJS_BONUS} ${LIBFT} ${LIBX}
					${CC} $^ ${FLAGS} ${MLXFLAGS} -o ${NAME_B}

clean:
					${RM} -r ./build
					${RM} -r ./build_bonus

fclean:			clean
					${RM} ${NAME}
					${RM} so_long_bonus
					make -s -C ${DIR_LIBX} clean
					make -s -C ${DIR_LIBFT} clean

re:					fclean
					${MAKE} all

FORCE:

.PHONY: all clean fclean re FORCE