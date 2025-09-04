# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 23:16:47 by lsantand          #+#    #+#              #
#    Updated: 2025/09/04 23:16:47 by lsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS	= src/server.c src/utils.c
CLIENT_SRCS	= src/client.c src/utils.c
HEADERS		= include/minitalk.h

CC			= clang -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} $< -c -o $@

all:		libft server client

libft:
			@make -C libft

server:		${SERVER_SRCS:.c=.o} ${HEADERS}
			${CC} ${SERVER_SRCS} ${CC_FLAGS} -o server

client:		${CLIENT_SRCS:.c=.o} ${HEADERS}
			${CC} ${CLIENT_SRCS} ${CC_FLAGS} -o client

clean:
			rm -rdf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
			@make clean -C libft

fclean:		clean
			rm -rdf client server
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re
