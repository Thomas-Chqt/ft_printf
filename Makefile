# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 19:15:34 by tchoquet          #+#    #+#              #
#    Updated: 2023/05/31 19:14:13 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR	= ${ROOT}/includes
LIBFT_DIR		= ${ROOT}/Libft

SRC	= ${wildcard ${SRCS_DIR}/*.c}

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: all clean fclean re


all: ${NAME}

${NAME}: ${OBJ}
	make -C ${LIBFT_DIR} all
	ar rc "$@" $^

clean:
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJ}

fclean: clean
	make -C ${LIBFT_DIR} fclean
	rm -rf ${NAME}

re: fclean all


%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR} -I${LIBFT_DIR}